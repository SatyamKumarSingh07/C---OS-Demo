#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    const char* source_file = argv[1];
    const char* destination_file = argv[2];

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process (Read from pipe and write to destination file)
        close(pipefd[1]);  // Close write end of the pipe (not used by child)

        int dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (dest_fd == -1) {
            perror("Destination file open failed");
            exit(1);
        }

        char buffer[BUFSIZE];
        ssize_t bytesRead;
        while ((bytesRead = read(pipefd[0], buffer, BUFSIZE)) > 0) {
            if (write(dest_fd, buffer, bytesRead) == -1) {
                perror("Write to destination file failed");
                exit(1);
            }
        }

        close(pipefd[0]);
        close(dest_fd);
    } else {
        // Parent process (Read from source file and write to pipe)
        close(pipefd[0]);  // Close read end of the pipe (not used by parent)

        int source_fd = open(source_file, O_RDONLY);
        if (source_fd == -1) {
            perror("Source file open failed");
            exit(1);
        }

        char buffer[BUFSIZE];
        ssize_t bytesRead;
        while ((bytesRead = read(source_fd, buffer, BUFSIZE)) > 0) {
            if (write(pipefd[1], buffer, bytesRead) == -1) {
                perror("Write to pipe failed");
                exit(1);
            }
        }

        close(pipefd[1]);
        close(source_fd);
    }

    return 0;
}

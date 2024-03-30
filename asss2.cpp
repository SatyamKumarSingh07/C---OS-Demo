#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    pid_t child_pid;
    int status;

    std::cout << "Parent process (PID=" << getpid() << ")" << std::endl;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        // This code is executed by the child process

        // Get the child's process ID
        std::cout << "Child process (PID=" << getpid() << ")" << std::endl;

        // Execute a program in the child process (e.g., ls)
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl fails, an error will be printed
        perror("execl");
        exit(1);
    } else {
        // This code is executed by the parent process

        // Wait for the child process to finish
        wait(&status);

        if (WIFEXITED(status)) {
            std::cout << "Child process (PID=" << child_pid << ") exited with status: " << WEXITSTATUS(status) << std::endl;
        }

        // Close any open file descriptors if necessary
        // close(fd);

        std::cout << "Parent process (PID=" << getpid() << ") exiting." << std::endl;
    }

    return 0;
}

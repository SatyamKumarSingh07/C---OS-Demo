#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cerrno>

int main() {
    const char* fileName = "unix_demo.txt";
    const char* fileContent = "Hello, This is the file which demonstrates the open, read, write UNIX commands.";

    // Create or open the file for writing (create if it doesn't exist, truncate if it does)
    int fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        std::cerr << "Error opening/creating the file: " << strerror(errno) << std::endl;
        return 1;
    }

    // Write the content to the file
    ssize_t bytesWritten = write(fd, fileContent, strlen(fileContent));
    if (bytesWritten == -1) {
        std::cerr << "Error writing to the file: " << strerror(errno) << std::endl;
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    // Open the file for reading
    fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        std::cerr << "Error opening the file for reading: " << strerror(errno) << std::endl;
        return 1;
    }

    char buffer[4096];
    ssize_t bytesRead;

    // Read and display the content of the file
    std::cout << "Contents of the file '" << fileName << "':" << std::endl;
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead); // Display to standard output
    }

    if (bytesRead == -1) {
        std::cerr << "Error reading from the file: " << strerror(errno) << std::endl;
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    return 0;
}

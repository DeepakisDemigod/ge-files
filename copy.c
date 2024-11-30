#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int source_fd, dest_fd;
    ssize_t bytes_read, bytes_written; // Number of bytes read and written
    char buffer[BUFFER_SIZE]; // Buffer to store data during copying

    // Check if correct number of arguments is passed
    if (argc != 3) {
        write(STDERR_FILENO, "Usage: cp <source> <destination>\n", 32);
        return 1; // Return error code if wrong number of arguments
    }

    // Open the source file for reading
    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return 1; // Return error if opening source file fails
    }

    // Open/create the destination file for writing, and set file permissions
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd); // Ensure source file is closed if destination open fails
        return 1; // Return error if opening destination file fails
    }

    // Copy data from source to destination
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return 1; // Return error if writing to destination file fails
        }
    }

    // Handle read errors
    if (bytes_read == -1) {
        perror("Error reading from source file");
    }

    // Close both files
    close(source_fd);
    close(dest_fd);

    return 0;
}


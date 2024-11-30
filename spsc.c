#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        // Child process
        printf("This is the child process. PID: %d, Parent PID: %d\n", getpid(), getppid());
        printf("Child process is doing its own work.\n");
    } 
    else {
        // Parent process
        printf("This is the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
        printf("Parent process is waiting for the child to finish...\n");
        wait(NULL);  // Parent waits for the child process to finish
        printf("Child process has finished. Parent can now terminate.\n");
    }

    return 0;
}


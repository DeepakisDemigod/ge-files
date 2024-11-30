#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  // Child Process
        printf("Child Process Sleeping ...\n");
        sleep(100);
        printf("Child Process Done. PID: %d\n", getpid());
    } else {
        printf("This is the parent process. PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}


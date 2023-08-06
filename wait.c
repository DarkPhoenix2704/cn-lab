#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Hello, I am the child process!\n");
        sleep(2);
        printf("Child process is done!\n");
    } else {
        printf("Hello, I am the parent process! My child's PID is %d.\n", pid);
        int status;
        wait(&status);
        printf("Child process has terminated.\n");
    }

    return 0;
}

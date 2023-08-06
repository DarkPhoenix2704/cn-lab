#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Hello, I am the child process!\n");
    } else {
        printf("Hello, I am the parent process! My child's PID is %d.\n", pid);
    }

    return 0;
}

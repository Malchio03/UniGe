#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork();

    if (pid1 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Primo processo
        dup2(fd[1], STDOUT_FILENO); // Redirige stdout alla pipe
        close(fd[0]);
        close(fd[1]);
        execlp("ps", "ps", "aux", (char *)NULL);
        perror("exec ps failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid2 = fork();

    if (pid2 == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Secondo processo
        dup2(fd[0], STDIN_FILENO); // Redirige stdin dalla pipe
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "bash", (char *)NULL);
        perror("exec grep failed");
        exit(EXIT_FAILURE);
    }

    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}

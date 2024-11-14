#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        dup2(fd, STDOUT_FILENO); // Redirige lo stdout
        close(fd);
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {
        close(fd);
        wait(NULL);
    }

    return 0;
}

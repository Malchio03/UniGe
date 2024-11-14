#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Processo figlio
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        perror("exec failed"); // In caso di errore
        exit(EXIT_FAILURE);
    } else {
        // Processo padre
        wait(NULL); // Aspetta che il figlio termini
        printf("Il processo figlio ha terminato\n");
    }

    return 0;
}

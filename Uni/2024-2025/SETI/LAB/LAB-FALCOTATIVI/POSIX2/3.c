#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char command[256];

    while (1) {
        printf("nano-shell $ ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // EOF
        }
        
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execlp(command, command, (char *)NULL);
            perror("exec failed");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL); // Aspetta che il figlio termini
        }
    }

    return 0;
}

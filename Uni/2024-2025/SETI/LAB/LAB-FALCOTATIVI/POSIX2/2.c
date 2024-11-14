#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char command[256];
    
    printf("Inserisci il nome del comando da eseguire: ");
    if (fgets(command, sizeof(command), stdin) == NULL) {
        perror("Input error");
        exit(EXIT_FAILURE);
    }
    
    // Rimuove il carattere di newline
    command[strcspn(command, "\n")] = '\0';
    
    if (execl(command, command, (char *)NULL) == -1) {
        perror("Errore nell'esecuzione del comando");
    }
    
    return 0;
}

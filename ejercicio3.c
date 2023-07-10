// Integrantes: Matías Fonseca, Raimundo Oliva.
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Implementar solución en C Linux que mediante uso de la función fork() 
el programa principal cree un proceso hijo H1 el cual crea un proceso hijo H1, y H1 
crea otro proceso hijo H3. Cada proceso hijo se identifica al momento de ser creado y 
al momento de terminar su ejecución. Por ejemplo, “H1 creado” y “H1 termina”.*/

int main(){

    pid_t PidAbuelo = getpid();
    pid_t PidHijo;
    if ((PidHijo = fork()) == 0){
        pid_t PidPadre = getpid();
        pid_t PidHijo;
        if ((PidHijo = fork()) == 0) {
            printf("Soy proceso H3. Mi ID es %d, H2 ID:%d es mi padre y H1 ID:%d es mi abuelo. \n", getpid(), PidPadre, PidAbuelo);
            printf("Proceso H3 termina.\n");
            exit(0);
        } else {
            // PidPadre = getpid()
            printf("Soy proceso H2. Mi ID es %d, H3 ID:%d es mi hijo Y H1 ID:%d es mi padre.\n", getpid(), PidHijo, PidAbuelo);
            printf("Proceso H2 termina.\n");
            exit(0);
        }
    } else {
        // PidAbuelo == getpid()
        printf("Soy proceso H1. Mi ID es %d y proceso H2 ID:%d es mi hijo.\n", getpid(), PidHijo);
        printf("Proceso H1 termina.\n");
        exit(0);
    }
    printf("\n");
}

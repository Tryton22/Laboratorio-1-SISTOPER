// Integrantes: Matías Fonseca, Raimundo Oliva.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Implementar solución en C Linux que mediante uso de la función fork() el programa principal 
cree exactamente 3 procesos hijos H1, H2 y H3 (los hijos no creen procesos), donde cada proceso hijo 
se identifica al momento de ser creado (envía un mensaje tal como “H1 creado!”. */

int main(){
    int i;
    //creacion de datos en memoria
    pid_t hijo[4];
    
    for(i=0; i < 3; i++){
       //asignacion de procesos hijos
       hijo[i] = fork();
       //procesos hijos tienen valor 0
       if (hijo[i] == 0)
       {
          printf("H%d creado!\n" , i+1);
          break;
       }
    }
}
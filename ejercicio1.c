// Integrantes: Matías Fonseca, Raimundo Oliva.
#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* implementar solución en C Linux que mediante uso de la función fork() el programa principal y 
sus hijos restantes creen exactamente 8 procesos en total, donde cada proces muestra su PID. */

int main(){
    int i;
    //creacion de datos en memoria
    pid_t hijo[8];
    
    for(i=0; i < 7; i++){
    	//asignacion de procesos hijos
       hijo[i] = fork();
      //procesos hijos tienen valor 0
       if (hijo[i] == 0)
       {
          printf("Soy proceso hijo %d y mi ID es  =  %d. " , i+1, getpid());
          printf("Mi padre es = %d\n", getppid());
          break;
       }
    }

    if (i == 7){  
        int estado;
        printf("Soy proceso padre y mi ID es = %d\n" , getpid());
        for(int j=0; j < 7; j++){
           //control de error
           if (waitpid(hijo[j], &estado, 0) == -1){
              printf("Error\n");
              exit(0);
            }
        }
    }
}

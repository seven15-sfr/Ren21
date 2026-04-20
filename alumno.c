#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct alumno{
    char nombre [100];
    int calif [5][5];
    };

int main(void){

    struct alumno A[5];
    srand(time(NULL));
    
    for(int k=0; k<5; k++){
        fgets(A.nombre,sizeof(A.nombre),stdin);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            A.calif[j][i]=rand( )%5+6;
            }
        }
    }
    printf("nombre es: %s \n",A.nombre);
    for(int i=0; i<5; i++){
        
        for(int j=0; j<5; j++){
            printf("Las calificaciones son: %d \n",A.calif[j][i]);
            }
        }

    
    return 0;
    }

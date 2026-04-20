#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Punto{
    int x,y;
};

int menu(void){
    int op;
    printf(" MENU \n");
    printf("1. Meter datos aleatorios\n");
    printf("2. Imprimir datos y direcciones\n");
    printf("3. Salir\n");
    printf("Escoja la opcion a ocupar: ");
    scanf("%d", &op);

};
int ReservarMemoria(void){
    int Ptr=NULL;
    Ptr=(int*)malloc(sizeof(int)*10);

};
int leerDatos(void){
    int dx, dy;

    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
        punto[i].x= rand()%9+1;
        punto[i].y= rand()%9+1;
        dx=(Punto[i].x-Punto[j].x);
        dx=(Punto[i].y-Punto[j].y);

        }
    }
};

int main(void) {
    int op;
    int *Ptr = NULL;
    
    printf("Memoria \n");

    do {
        

        switch(op) {
            case 1:
                printf("Generar datos aleatorios\n");
                break;

            case 2:
                printf(" Datos en memoria \n");
                for (int i = 0; i<10; i++) {
                    printf("Indice:%d Valor: %d Direccion: %p \n", i, Ptr[i], (void*)&Ptr[i]);
                }
                printf("Direccion de Ptr: %p\n", (void*)Ptr);
                break;

            case 3:
                printf("Salir \n");
                break;
            
            default:
                printf("No valida\n");
        }
    } while(op != 3);

    free(Ptr);
    
    return 0;
}

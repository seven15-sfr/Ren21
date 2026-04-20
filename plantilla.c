#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(void){
    printf("  MENU  \n");
    printf("1. Meter datos aleatorios\n");
    printf("2. Imprimir datos y direcciones\n");
    printf("3. Salir\n");
    printf("Escoja la opcion a ocupar: ");
    scanf("%d",&op);
    return op;
}

struct Punto* reservar(){
    struct Punto *p;
    p = (struct Punto*) malloc(sizeof(struct Punto) * 10);
    return p;
}

void LeerDatos(struct Punto *p){
    for(int i = 0; i < 10; i++){
        printf("Punto %d\n", i+1);
        printf("x: ");
        scanf("%d", &p[i].x);
        printf("y: ");
        scanf("%d", &p[i].y);
    }
}

void MostrarDatos(struct Punto *p){
    printf("Puntos guardados:\n");
    for(int i = 0; i < 10; i++){
        printf("%d %d %d", i+1, p[i].x, p[i].y);
    }
}

void Liberar(struct Punto **p){
    free(*p);
    *p = NULL;
}

int main(void) {
    int op;
    struct Punto *punto;
 
    do {
       
        switch(op) {
            case 1:
                printf("Generar datos aleatorios\n");
                break;

            case 2:
                printf(" Datos en memoria \n"(Ptr));
                break;

            case 3:
                printf("Salir \n");
                break;
            
            default:
                printf("Opcion no valida.\n");
        }
    } while(op != 4);

    
    return 0;
}
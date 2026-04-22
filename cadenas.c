#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *Ptisig;
    };
    
    int menu(void){
    int op;
    printf(" MENU \n");
    printf("1. Crear dato\n");
    printf("2. Mostrar dato\n");
    printf("3. Liberar \n");
    printf("4. Salir: ");
    scanf("%d",&op);
    return op;
    };
    
    struct Dato* crearDato(){
    struct Dato *nuevo=(struct Dato*)malloc(sizeof(struct Dato));
    if(nuevo==NULL){
    return NULL;
    }else{
    printf("Ingrese el valor entero: ");
    scanf("%d",&nuevo->d);
    nuevo->d==dato;
    nuevo->Ptisig=NULL;
    printf("Modulo creado en memoria.\n");
    
    return nuevo;
    }
    }
    
int main(void){
    int op;
    struct Dato *Ptr=NULL;

    do {
        op = menu();
        switch(op) {
              case 1:
                Ptr = crearDato();
                if(nuevo==NULL){
                    printf("No se reservo memoria");
                }else{
                    if(Ptr==NULL){
                    Ptr==nuevo;
                    }
                break;

            case 2:
                if (Ptr != NULL) {
                    printf("Dato almacenado: %d\n", Ptr *d);
                } else {
                    printf("No hay datos creados.\n");
                }
                break;

            case 3:
                if (Ptr != NULL) {
                    free(Ptr);
                    Ptr = NULL;
                    printf("Memoria liberada.\n");
                } else {
                    printf("Nada que liberar.\n");
                }
                break;

            case 4:
                free(Ptr);
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción no válida\n");
        }
    } while(op != 4);
return 0;
}

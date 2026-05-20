#include <stdio.h>
#include <stdlib.h>

struct arbol{
    int dato;
    struct arbol *izq, *der;
    
};

int menu(void) {
    int op;
    printf("\n MENU \n");
    printf("1. Insertar \n");
    printf("5. Salir \n");
    scanf("%d", &op);
    return op;
}

struct arbol* crearNodo() {
    struct arbol *Ptrtemp = (struct arbol*)malloc(sizeof(struct arbol));
    if (Ptrtemp == NULL) {
        return NULL;
    }
    printf("Ingrese el valor entero: ");
    scanf("%d", &Ptrtemp->d);
    return Ptrtemp;
}

int main(void){
    int op;
    struct arbol *raiz,*Ptrtemp;
    raiz=NULL;

do{
    op=menu();
    switch (op){
    case 1://insertar
        Ptrtemp=crearNodo();
        if(Ptrtemp==NULL){
            printf("No se creo el nodo \n");
        }else{
            if(raiz==NULL){
                raiz=Ptrtemp;
            }
        }else{

        }
        
        break;
    case 2:

        break;
    default:
        printf("Opcion no valida \n");
        break;
    }
}while (op!=3);

    return 0;
};

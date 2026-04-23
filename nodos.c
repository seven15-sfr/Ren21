#include <stdio.h>
#include <stdlib.h>

struct Dato {
    int d;
    struct Dato *Ptisig; 
};

int menu(void) {
    int op;
    printf("MENU \n");
    printf("1. Crear un dato \n");
    printf("2. Mostrar todos los datos\n");
    printf("3. Eliminar ultimo campo\n");
    printf("4. Salir: ");
    scanf("%d", &op);
    return op;
}

struct Dato* crearDato() {
    struct Dato *Ptrtemp = (struct Dato*)malloc(sizeof(struct Dato));
    if (Ptrtemp == NULL) {
        return NULL;
    }
    printf("Ingrese el valor entero: ");
    scanf("%d", &Ptrtemp->d);
    Ptrtemp->Ptisig = NULL;
    printf("Campo de memoria creado\n");
    return Ptrtemp;
}

int main(void) {
    int op;
    struct Dato *Ptr = NULL;    
    struct Dato *Ptraux = NULL;  
    struct Dato *Ptrtemp = NULL; 

    do {
        op = menu();
        switch(op) {
            case 1:
                Ptrtemp = crearDato();
                if (Ptrtemp == NULL) {
                    printf("No se pudo reservo memoria\n");
                } else {
                    if (Ptr == NULL) {
                        Ptr = Ptrtemp;
                    } else {
                        Ptraux = Ptr;
                        while (Ptraux->Ptisig != NULL) {
                            Ptraux = Ptraux->Ptisig;
                        }
                        Ptraux->Ptisig = Ptrtemp;
                    }
                }
                break;

            case 2:
                if (Ptr == NULL) {
                    printf("La lista vacia\n");
                } else {
                    Ptraux = Ptr;
                    printf("Contenido: ");
                    while (Ptraux != NULL) {
                        printf("%d ", Ptraux->d);
                        Ptraux = Ptraux->Ptisig;
                    }
                    printf("NULL\n");
                }
                break;

            case 3: 
                if (Ptr == NULL) {
                    printf("Nada que eliminar.\n");
                } else if (Ptr->Ptisig == NULL) {
                    free(Ptr);
                    Ptr = NULL;
                    printf("Lista vacia\n");
                } else {
                    Ptraux = Ptr;
                    while (Ptraux->Ptisig->Ptisig != NULL) {
                        Ptraux = Ptraux->Ptisig;
                    }
                    free(Ptraux->Ptisig);
                    Ptraux->Ptisig = NULL;
                    printf("Ultimo nodo eliminado\n");
                }
                break;

            case 4:
                while (Ptr != NULL) {
                    Ptraux = Ptr;
                    Ptr = Ptr->Ptisig;
                    free(Ptraux);
                }
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion no valida\n");
        }
    } while(op != 4);

    return 0;
}

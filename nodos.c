#include <stdio.h>
#include <stdlib.h>

struct Dato {
    int d;
    struct Dato *Ptisig; 
};

int menu(void) {
    int op;
    printf("\n MENU \n");
    printf("1. Crear un dato \n");
    printf("2. Sub menu/ Funciones \n");
    printf("3. Mostrar los datos \n");
    printf("4. Eliminar ultimo campo \n");
    printf("5. Salir \n");
    scanf("%d", &op);
    return op;
}
int submenu(void){
    int sub;
    printf("\n SUB-MENU \n");
    printf("1. Buscar \n");
    printf("2. Contar \n");
    printf("3. Remplazr \n");
    printf("4. Ordenar \n");
    printf("5. Regresar \n");
    scanf("%d",&sub);
    return sub;
}

struct Dato* crearDato() {
    struct Dato *Ptrtemp = (struct Dato*)malloc(sizeof(struct Dato));
    if (Ptrtemp == NULL) {
        return NULL;
    }
    printf("Ingrese el valor entero: ");
    scanf("%d", &Ptrtemp->d);
    Ptrtemp->Ptisig = NULL;
    printf("Campo de memoria creado \n");
    return Ptrtemp;
}

int main(void) {
    int op,sub;
    struct Dato *Ptr = NULL;    
    struct Dato *Ptraux = NULL;  
    struct Dato *Ptrtemp = NULL; 

    do {
        op = menu();
        switch(op) {
            case 1:
                Ptrtemp = crearDato();
                if (Ptrtemp == NULL) {
                    printf("No se pudo reservo memoria \n");
                } else {
                    if (Ptr == NULL) {
                        Ptr = Ptrtemp;
                    } else {
                        Ptraux = Ptr;
                    while(Ptraux->Ptisig != NULL){
                        Ptraux = Ptraux->Ptisig;
                        }
                        Ptraux->Ptisig = Ptrtemp;
                    }
                }
                break;

            case 2://Sub menu
                do{
                sub=submenu();
                switch (sub){
                case 1: 
                    if(Ptr==NULL){
                    printf("Nada que buscar \n");
                }else{
                    printf("Si existe el dato buscado \n");
                }
                break;
                case 2:
                    if(Ptr==NULL){
                        printf("Nada que contar \n");
                    }else{
                        while (Ptr!= NULL){
                            Ptr++;
                        printf("Total de contenido: %d\n");

                        }
                    }
                break;
                case 3:
                 if(Ptr==NULL){
                    printf("Nada que remplazar \n");
                }
                break;
                case 4:
                    if(Ptr==NULL){
                        printf("Nada que ordenar \n");
                    }
                break;
                case 5:
                        printf("Regresar \n");
                break;
                }
            }while(sub!=5);
                break;

            case 3://Menu
                if (Ptr == NULL) {
                    printf("Lista vacia \n");
                } else {
                    Ptraux = Ptr;
                    printf("Contenido: \n");
                    while (Ptraux != NULL){
                        printf("%d -> ",Ptraux->d);
                        Ptraux = Ptraux->Ptisig;
                    }
                }
                break;

            case 4: 
                if (Ptr == NULL) {
                    printf("Nada que eliminar \n");
                    }
                else{
                    Ptraux = Ptr;
                    if (Ptraux->Ptisig == NULL){
                        free(Ptraux);
                        Ptr = NULL;
                        }
                 
                    else{//si hay mas de un nodo
                        Ptraux=Ptr;
                        while (Ptraux->Ptisig->Ptisig!=NULL){
                            Ptraux=Ptraux->Ptisig;
                            }
                        free(Ptraux->Ptisig);
                        Ptraux->Ptisig=NULL;
                        printf("Ultimo nodo eliminado \n");
                        }
                    }
                
                break;

            case 5:
                while (Ptr !=NULL){
                    Ptraux = Ptr;
                    Ptr = Ptr->Ptisig;
                    free(Ptraux);
                    }
                printf("Saliendo\n");
                break;

            default:
                printf("Opcion no valida \n");
        }
    } while(op != 5);

    return 0;
}

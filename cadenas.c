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
    printf("3. Remplazar \n");
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

int contar(struct Dato *Ptr){
    int i=0;
    if(Ptr!=NULL){ 
        i=1;
        while(Ptr->Ptisig!=NULL){
            i++;
            Ptr=Ptr->Ptisig;
            }
        }
    return i;

}


int main(void) {
    int op, sub, buscar, remplazar, nuevoVal, contador,nnodos,i;    
    struct Dato *Ptr = NULL;    
    struct Dato *Ptraux = NULL;  
    struct Dato *Ptrtemp = NULL; 
    struct Dato *Ptrant = NULL;

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
                case 1://Buscar
                    if(Ptr == NULL) {
                        printf("Lista vacia \n");
                    } else {
                        printf("Valor a buscar: ");
                        scanf("%d", &buscar);
                        Ptraux = Ptr;
                    }
                        while(Ptraux != NULL) {
                            if(Ptraux->d == buscar){
                            Ptraux = Ptraux->Ptisig;
                            }
                        if (printf("El dato %d ya existe en la lista \n", buscar));
                        else (printf("No encontrado \n"));
                            
                        }
                break;

                case 2://contar
                        contador = 0;
                        Ptraux = Ptr;
                        while (Ptraux != NULL) {
                            contador++;
                            Ptraux = Ptraux->Ptisig;
                        }
                        printf("Total de nodos: %d \n", contador);
                break;

                case 3://remplazar
                        if(Ptr == NULL) {
                            printf("Nada que reemplazar.\n");
                        } else {
                            printf("Valor a cambiar: "); 
                            scanf("%d", &remplazar);
                            printf("Nuevo valor: "); 
                            scanf("%d", &nuevoVal);
                            Ptraux = Ptr;
                            while(Ptraux != NULL) {
                        if(Ptraux->d == remplazar){ 
                            Ptraux->d = nuevoVal;
                            Ptraux = Ptraux->Ptisig;
                             }
                            }
                        printf("Proceso terminado \n");
                            }
                break;

                case 4://ordenamiento por burbuja
                    if(Ptr==NULL){
                        printf("Nada que ordenar \n");
                    }else{
                        nnodos=contar(Ptr);
                        do{ 
                            for(int i=0;Ptraux->Ptisig!=NULL; i++){
                                if(Ptraux->d>(Ptraux->Ptisig)->d){
                                    Ptrtemp=Ptraux;
                                    Ptraux=Ptraux->Ptisig;
                                    Ptraux->Ptisig=Ptraux->Ptisig;
                                    Ptraux->Ptisig=Ptrtemp;
                                }else{
                                    Ptrant=Ptraux;
                                    Ptraux=Ptraux->Ptisig;
                                    }
                                }    
                            i--;
                            }while(i>0);
                    }
                break;
                case 5://salir
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

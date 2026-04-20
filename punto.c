#include <stdio.h>
#include <math.h>
#include <time.h>

struct Punto{
    int x,y;
}

int main(void){
    struct Punto punto[5];
    int d;

    //para 2 puntos a seleccionar
    for(int i=0; i<5; i++){
        punto[i].x= rand()%9+1;
        punto[i].y= rand()%9+1;
    }

    printf("cuales puntos desea ocupar para clacular distancia entre dos puntos? \n");
    scanf("%d %d",&p1,&p2);
    dx=(punto[p2].x-punto[p1].x);
    dx*=dx;
    dx=(punto[p2].y-punto[p1].y);
    dy*=dy;
    d=sqrt(dx+dy);

    //para hacer un todos * todos
    for(int i=0; i<4; i++){
        for(int j=i+1; j<5; j++){
        dx=(punto[i].x-punto[j].x);
        dx=(punto[i].y-punto[j].y);

        }
    }

}
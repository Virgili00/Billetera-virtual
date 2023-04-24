#include <stdlib.h>
#include<stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif


void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
void ingresar_dinero(float*total,float*cartera){
    float ingreso;
    printf("\ningrese un monto\n");
    scanf("%f",&ingreso);
    *total=*total+ingreso;
    *cartera=*cartera+ingreso;



}
void trans_cart_ahorros(float*cartera,float*ahorros){
    float ingreso;
    printf("\ningrese el valor que quiere transferir de ahorros\n");
    scanf("%f",&ingreso);
    while (ingreso>*cartera){


    printf("\ningrese el valor que quiere transferir de ahorros(menor o igual al que posee en cartera)\n");
    scanf("%f",&ingreso);}
    *cartera=(*cartera-ingreso);
    *ahorros=(*ahorros+ingreso);

}
void trans_ahorros_cart(float*cartera,float*ahorros){
    float ingreso;
    printf("\ningrese el valor que quiere transferir a su cartera\n");
    scanf("%f",&ingreso);
    while (ingreso>*ahorros){

    printf("\ningrese el valor que quiere transferir a su cartera (menor o igual al que posee en ahorros)\n");
    scanf("%f",&ingreso);}

    *cartera=(*cartera+ingreso);
    *ahorros=(*ahorros-ingreso);


}

int main() {
float total,ahorros,cartera;
int suich,i=1;
FILE* pa;

pa=fopen("montos.txt","r");


fscanf(pa,"%f,%f,%f", &total,&ahorros,&cartera);





fclose(pa);

pa=fopen("montos.txt","w");

    while (i!=0){
    printf("Total= %f \nAhorros=%f \nLibre=%f\n",total,ahorros,cartera);
    printf("elige una opcion\n1-ingresar dinero\n2-transferir dinero de la cartera a ahorros\n3-transferir dinero de ahorros a cartera\n4-salir\n");
    scanf("%d",&suich);
    switch(suich){
    case 1: ingresar_dinero(&total,&cartera);


    break;
    case 2: if(total!=0){
        trans_cart_ahorros(&cartera,&ahorros);


    }
    break;
    case 3: if(total!=0){
        trans_ahorros_cart(&cartera,&ahorros);


    }
    break;
    case 4:

            i=0;
            fprintf(pa,"%f,%f,%f",total,ahorros,cartera);
    }


    limpiar_pantalla();
    }
fclose(pa);
 return 0;
 }

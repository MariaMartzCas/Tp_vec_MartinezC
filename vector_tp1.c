#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int contar_repetidos(int vec[],int cantidad);
void mostrar_sin_repetidos(int vec[],int cantidad);
void mostrar_vector(int vec[],int cantidad);
void Union_Vectores(int vec1[],int vec2[],int vecAux[],int cantidad_elementos);
void Interseccion_vectores(int vec1[],int vec2[],int vecAux[],int cantidad_elementos);
void Inicializar_vector(int vec[],int cantidad);
void Resta_A_menos_B(int vec1[],int vec2[],int vecAux[],int cantidad);
void Resta_B_menos_A(int vec1[],int vec2[],int vecAux[],int cantidad);
int main()
{
    int vect1[10];
    int vect2[10];
    int vecAux[20]={0};///Tiene 20 para la union entre los 2 vec de 10 y puede servir para la interseccion
    int rep;
    int i,opcion;
    srand(time(NULL));
/// SE CARGAN LOS VECTORES EN FORMA ALEATORIA
    for(i=0; i<10; i++)
    {

        vect1[i]=rand()%16+20;
    }
    for(i=0; i<10; i++)
    {
        vect2[i]=rand()%16+20;
    }
    do
    {
    printf("\nMENU DE VECTORES: Elija una opcion\n");
    printf("1-Mostrar vectores y cuantos se repiten de cada vector\n");
    printf("2-Mostrar vectores pero sin que los datos se repitan\n");
    printf("3-Mostrar los datos de la union entre ambos vectores\n");
    printf("4-Mostrar los datos de interseccion entre ambos vectores\n");
    printf("5-Mostrar datos de la resta de vector A menos vector B\n");
    printf("6-Mostrar datos de la resta de vector B menos vector A\n");
    printf("0-Salir\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
    {
        printf("VECTOR NRO 1: \n");
        mostrar_vector(vect1,10);
        rep=contar_repetidos(vect1,10);
        printf("\nREPETIDOS DEL VEC1:%d\n",rep);
        puts("\n");
        printf("VECTOR NRO 2: \n");
        mostrar_vector(vect2,10);
        rep=contar_repetidos(vect2,10);
        printf("\nREPETIDOS DEL VEC2:%d\n",rep);
        break;
    }
    case 2:
        {
        contar_repetidos(vect1,10);
        contar_repetidos(vect2,10);
        mostrar_sin_repetidos(vect1,10);
        printf("\n");
        mostrar_sin_repetidos(vect2,10);
        break;
        }
    case 3:
        {
        printf("LA UNION DE AMBOS VECTORES:\n ");
        Inicializar_vector(vecAux,20);
        Union_Vectores(vect1,vect2,vecAux,10);
        mostrar_sin_repetidos(vecAux,20);
        break;
        }
    case 4:
        {
        printf("LA INTERSECCION ENTRE AMBOS VECTORES:\n ");
        Inicializar_vector(vecAux,20);
        Interseccion_vectores(vect1,vect2,vecAux,10);
        mostrar_sin_repetidos(vecAux,10);
        break;
        }
    case 5:
        {
        printf("LA RESTA DEL VECTOR A CON B ES:\n");
        Inicializar_vector(vecAux,20);
        Resta_A_menos_B(vect1,vect2,vecAux,10);
        mostrar_sin_repetidos(vecAux,10);
        break;
        }
    case 6:
         {
        printf("LA RESTA DEL VECTOR B CON A ES:\n");
        Inicializar_vector(vecAux,20);
        Resta_B_menos_A(vect1,vect2,vecAux,10);
        mostrar_sin_repetidos(vecAux,10);
        break;
        }

    }
    }while(opcion!=0);
    return 0;
}

int contar_repetidos(int vec[],int cantidad)
{

    int i,j,a,aux,repetido=0;
    for(i=0; i<cantidad; i++)
    {
        for(j=i+1; j<cantidad-repetido; j++)
        {
            if(vec[i]==vec[j])
            {
                vec[j]=0;
                repetido=repetido+1;
                for(a=j; a<cantidad-repetido; a++)
                {
                    if(vec[a]<vec[a+1])
                    {
                        aux=vec[a];
                        vec[a]=vec[a+1];
                        vec[a+1]=aux;
                    }
                }
            }
        }
    }
    return repetido;
}

void mostrar_sin_repetidos(int vec[],int cantidad)
{
    int i=0;
    while (vec[i]!=0 && i<cantidad)
    {
        printf("%d ",vec[i]);
        i=i+1;
    }
}

void mostrar_vector(int vec[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
        printf("%d ",vec[i]);
}

void Union_Vectores(int vec1[],int vec2[],int vecAux[],int cantidad_elementos)
{
    int i=0,j=0;
    while((i<cantidad_elementos)&&(vec1[i]!=0))
    {
        vecAux[i]=vec1[i];
        i=i+1;
    }
    while((j<cantidad_elementos)&&(vec2[j]!=0))
    {
        vecAux[i]=vec2[j];
        j=j+1;
        i=i+1;
    }
}

void Interseccion_vectores(int vec1[],int vec2[],int vecAux[],int cantidad_elementos)
{
    int i,j,a=0;
    for(i=0;i<cantidad_elementos;i++)
    {
        for(j=0;j<cantidad_elementos;j++)
        {
        if((vec1[i]==vec2[j]))
        {
            vecAux[a]=vec1[i];
            a=a+1;
        }

        }
    }
}

void Inicializar_vector(int vec[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        vec[i]=0;
    }
}
void Resta_A_menos_B(int vec1[],int vec2[],int vecAux[],int cantidad)
{
     int i,j,a=0,repetido;
    for(i=0;i<cantidad;i++)
    {
        repetido=0;
        for(j=0;j<cantidad;j++)
        {
        if((vec1[i]==vec2[j]))
        {
           repetido=1;
        }
        }
            if(repetido==0)
            {
            vecAux[a]=vec1[i];
            a=a+1;
            }
    }
}

void Resta_B_menos_A(int vec1[],int vec2[],int vecAux[],int cantidad)
{
     int i,j,repetido,a=0;
    for(i=0;i<cantidad;i++)
    {
        repetido=0;
        for(j=0;j<cantidad;j++)
        {
        if((vec2[i]==vec1[j]))
        {
            repetido=1;
        }
        }
            if(repetido==0)
            {
            vecAux[a]=vec2[i];
            a=a+1;
            }
        }
}
















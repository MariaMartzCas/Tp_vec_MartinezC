#include<stdio.h>
int main(){
int mat [3][5];
char materia[5][11]={
                    {"MATEMATICA"},
                    {"LENGUA"},
                    {"FISICA"},
                    {"INGLES"},
                    {"HISTORIA"}
                    };
char nomb_ap[30];
int t,m,sumas,suma,sumaNotaAprobada,contador=0;
float prom_gral,prom1,PorcentajeNotaAprob;
suma=0;
sumas=0;
puts("Ingrese el nombre y apellido del alumno");
gets(nomb_ap);
for(t=0;t<3;t++){
    for(m=0;m<5;m++){
        printf("ingrese la nota del trimestre [%d] de la materia [%d]",t+1,m+1);
        scanf("%d",&mat[t][m]);
        suma=suma+mat[t][m];
    }
}
printf("----------------------------------------------------------------------\n");
printf("\n");
printf("INFORME DE NOTAS DE ALUMNO\n");
printf("Nombre y Apellido: ");
puts(nomb_ap);
for(m=0;m<5;m++){
        sumas=0;

    for(t=0;t<3;t++)
    {
        sumas=sumas+mat[t][m];
        }
    printf("%s: %f\n",materia[m],(float)sumas/3);
}

///promedio general
prom_gral=(float)suma/15;
for(t=0;t<3;t++){
    contador=0;
    sumaNotaAprobada=0;
    for(m=0;m<5;m++){
        if(mat[t][m]>=6)
        {
            sumaNotaAprobada=sumaNotaAprobada+mat[t][m];
            contador=contador+1;
        }
    }
   // PorcentajeNotaAprob=((float)sumaNotaAprobada*100)/contador;
   PorcentajeNotaAprob=(contador*100)/5;
    printf("Porcentaje de notas aprobadas con 6 o mas del trimestre %d:%.2f porciento\n",t+1,PorcentajeNotaAprob);
}

printf("promedio general:%f\n",prom_gral);
printf("\n tabla de notas\n");
for(t=0;t<3;t++){
    for(m=0;m<5;m++){
        printf("%d\t",mat[t][m]);
    }
    printf("\n");
}
return 0;
}

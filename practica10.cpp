#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "meraz.h"
#define N 500
typedef struct talum
{
    int matri;
    char nom [50];
    char appat [50];
    char apmat [50];
    int edad;
    char sexo [50];
    long matricula;
    int status;
}talum;

int msge();
void menu();
talum gendatos();
talum manual();
void impreg (talum vect[], int n, talum manual[], int j);
void buscar(talum vect[], int n);
void eliminar(talum vect[], int n);
talum ordenar(talum vect[], int n);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msges()
{
    int op, menu;
    system("CLS");
    printf ("   M  E   N   U \n");
    printf("1.- AGREGAR AUTOMATICAMENTE \n");
    printf("2.- AGREGAR MANUAL \n");
    printf("3.- IMPRIMIR \n");
    printf("4.- BUSCAR \n");
    printf("5.- ELIMINAR REGISTRO \n");
    printf("6.- ORDENAR REGISTROS \n");
    printf("0.- SALIR  \n");
    op = validanum_int(0,6,"Elige una opcion:", "ERROR");
    return op;
}

void menu()
{
    int i, op, total, tam=0,j,k=0,l;
    talum vect[N], man[10];
    talum reg;
    do{
        l = k+10;
        op = msges();
        switch(op)
            {
                case 1:
                    for(i=k; i<l; i++)
                    {
                        vect[i]=gendatos();
                        k++;
                    }
                    break;
                case 2:
                    vect[k] = manual();
                    k++;
                    break;
                case 3:
                    impreg(vect,k,man,j);
                    break;
                case 4:
                    buscar(vect,i);
                    break;
                case 5:
                    eliminar(vect,i);
                    break;
                case 6:
                    ordenar(vect, i);
                    break;
            } 
        }while(op != 0);
        system("PAUSE");
}

talum gendatos()
{
    talum reg;
    char nombres [20][20] = {"ROBERTO","PEDRO","CARLOS", "JOAQUIN", "ALEXIS", "FERNANDO", "GAEL", "DANIEL", "OSCAR", "MELVIN", "OSVALDO"};
    char mujeres[20][20]={"ANA","SAMANTHA","KARLA","NANCY","ALEXA","PERLA","DANIELA","LOURDES","HANNA","LANNA","MIA"};
	char ApPat[20][20]={"JIMENEZ","MERAZ","PEREZ","ARREDONDO","KHALIFA","OCHOA","ROJAS","LUNA","HERNANDEZ","GARCIA","SHADE","YEPIZ"};
	char ApMat[20][20]={"MORENO","AVILA","MEDINA","LOPEZ","CALDERON","CHAVEZ","QUINTERO","CARRILLO","GARCIA","GUZMAN","DIAZ","DIAZ"};
    int sexo, status = 1;
    int rango, rf=20, ri=12;
    int rango2, rf2=2, ri2=1;
    long ri3=300000, rf3=399999, rango3;
    rango=(rf-ri)+1;
    reg.edad=(rand()%rango)+ri;
    reg.matri=rand()%100;

    strcpy(reg.appat,ApPat[rand()%12]);
    strcpy(reg.apmat,ApMat[rand()%12]);

    rango2=(rf2-ri2)+1;
    sexo=(rand()%rango2)+ri2;
    if(sexo == 1)
    {
        strcpy(reg.sexo,"HOMBRE");
        strcpy(reg.nom,nombres[rand()%11]);
    }
    else
    {
        strcpy(reg.sexo,"MUJER");
        strcpy(reg.nom,mujeres[rand()%11]);
    }
    rango3 = (rf3 - ri3)+1;
    reg.matricula = (rand()%rango3)+ri3;
    reg.status=status;
    return reg; 
}

void impreg(talum vect[], int n, talum man[],int j)
{
    system("CLS");
    int i;
    printf("   MATRICULA      NOMBRE       APELLIDO PAT    APELLIDO MAT     EDAD        SEXO   \n");
    for(i=0; i<n; i++)
    {
        if(vect[i].status==1)
        {
            printf("    %6d    %10s    %12s    %12s     %6d    %10s   \n",vect[i].matricula,vect[i].nom,vect[i].appat,vect[i].apmat,vect[i].edad,vect[i].sexo);

        }
    }
    system("PAUSE");
}

talum manual()
{
    system("CLS");
    talum reg;
    reg.matricula = validanum_long(300000,399999,"Ingresa tu matricula", "Rango dado 300000-399999");
    printf("Ingresa tu nombre: ");
    scanf("%s",&reg.nom);
    printf("Ingresa tu apellido paterno: ");
    scanf("%s", &reg.appat);
    printf("Ingresa tu apellido materno: ");
    scanf("%s", &reg.apmat);
    reg.edad = validanum_int(10,100,"Ingresa tu edad: ", "NOTA: DEBE DE SER UNA EDAD REAL. ");
    printf("Ingresa tu sexo\n");
    printf("Hombre - Mujer\n");
    scanf("%s",&reg.sexo);
    return reg;
}

void buscar(talum vect[], int n)
{
    system("CLS");
    int mati,i,j,com=0;
    mati = validanum_long(300000,399999,"Ingrese la matricula que deseas buscar: ", "NOTA: DEBE DE ESTAR EN EL RANGO DE 300000 - 399999");
    for(i=0; i<=n; i++)
    {
        if(vect[i].matricula==mati)
        {
            for(j=i; j==i; j++)
            {
                printf("N.    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO \n");
				printf("%d.-   %6ld        %8s    %14s       %14s        %5d       %7s      \n",i,vect[i].matricula,vect[i].nom,vect[i].appat,vect[i].apmat,vect[i].edad,vect[i].sexo);	
				com=1;
            }
        }
    }
    if(com==0)
    {
        printf("USUARIO NO ENCONTRADO\n");
    }
    system("PAUSE");
}

void eliminar(talum vect[], int n)
{
    system("CLS");
    int mati,i,j,com=0;
    printf("ELIMINAR MATRICULA\n");
    mati = validanum_long(300000,399999,"Ingrese la matricula que desea eliminar: ", "ERROR");
    for(i=0; i<=n; i++)
    {
        if(vect[i].matricula==mati)
        {
            vect[i].status=0;
			printf("N.    MATRICULA        NOMBRE           APELLIDO PAT        APELLIDO MAT     EDAD        SEXO \n");
			printf("%d.-   %6ld        %8s    %14s       %14s        %5d       %7s      \n",i,vect[i].matricula,vect[i].nom,vect[i].appat,vect[i].apmat,vect[i].edad,vect[i].sexo);	
			com=1;
        }
        printf("LA MATRICULA HA SIDO ELIMINADA\n");
    }
    if(com==0)
    {
    printf("USUARIO NO ENCONTRADO\n");
    }
    system("PAUSE");
}

talum ordenar(talum vect[], int n)
{
    int i,j;
    talum burb;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<i;j++)
        {
            if(vect[i].matricula > vect[j].matricula)
            {
                burb = vect[i];
                vect[i] = vect[j];
                vect[j] = burb;
            }
        }
    }
    printf("EL VECTOR HA SIDO ORDENADO POR MATRICULAS");
    return vect[n];
}

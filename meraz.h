#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int vali_num(int ri,int rf,const char msge[]);
int busquedasec(int vector1[],int tam,int val);
void ordenavector(int vector1[],int tam);

int busquedasec(int vector1[], int tam, int num)
{
    int i;
    for (i = 0; i < tam; i++)
    {

        if (num == vector1[i])
        {
            return i;
        }
    }
    return -1;
}

int vali_num(int ri, int rf, const char msge[])
{
    char xnum[30];
    int num;
    do
    {
        printf("%s:", msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if (num < ri || num > rf)
        {
            printf("QUE ESTE DENTRO DEL RANGO(%d a %d) \n", ri, rf);
            system("PAUSE");
        }
    } while (num < ri || num > rf);
    return num;
}

void ordenavector(int vector1[], int tam)
{
    int i, j;
    int burb;
    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (vector1[j] < vector1[i])
            {
                burb = vector1[j];
                vector1[j] = vector1[i];
                vector1[i] = burb;
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validanum_int(int ri, int rf ,const char msg[],const char msger[]);
long validanum_long(long ri, long rf ,const char msg[],const char msger[]);
char* valida_enie(char* cadena);

int validanum_int(int ri, int rf , const char msg[], const char msger[])
{
	char xnum[30];
	int num;
	do{
		puts(msg);
		fflush(stdin);
		gets(xnum);
		num=atoi(xnum);
		if (num<ri || num> rf)
		{
			printf("%s \n",msger);
		}	
	}while(num<ri||num>rf);
	return num;
    system("PAUSE");	
	
}

long validanum_long(long ri, long rf ,const char msg[],const char msger[])
{
	char xnum[50];
	long num;
	do{
		puts(msg);
		fflush(stdin);
		gets(xnum);
		num=atol(xnum);
		if (num<ri || num> rf)
		{
			printf("%s \n",msger);
		}	
	}while(num<ri||num>rf);
	return num;
    system("PAUSE");
}

char* valida_enie(char* cadena)
{
    int tam,i;
    tam = strlen(cadena);
    for(i=0; i<tam; i++)
    {
        if(cadena[i] == -61)
        {

            cadena[i] = 'X';
        }
    }
    return cadena;
}
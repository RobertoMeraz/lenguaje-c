//369754-Meraz Quintero Roberto
//practica 9

#include "meraz.h"

void msges();
void menu();
void llenavectorsr(int vector1[], int tam, int ri, int rf);
void llenamatriz(int matriz[][4], int m, int ri, int rf);
void imprimirvect(int vector1[], int tam);
void imprimirmatriz(int matriz[][4], int m);
void buscar(int vector1[], int tam);

main()
{
    menu();
    return 0;
}

void msges()
{
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.-Llenar vector \n");
    printf("2.-Llenar matriz \n");
    printf("3.-Imprimir vector \n");
    printf("4.-Imprimir matriz \n");
    printf("5.-Ordenar vector \n");
    printf("6.-Buscar valor en vector \n");
    printf("0.-Salir \n");
}
void menu()
{
    int op, i;
    int vector1[15];
    int m = 4, matriz[4][4];
    char msge[30] = {"Selecciona una opcion: "};

    do
    {
        msges();
        op = vali_num(0, 6, msge);
        switch (op)
        {

        case 1:
            llenavectorsr(vector1, 15, 100, 200);
            break;
        case 2:
            llenamatriz(matriz, m, 1, 16);
            break;
        case 3:
            imprimirvect(vector1, 15);
            break;
        case 4:
            imprimirmatriz(matriz, m);
            break;
        case 5:
            ordenavector(vector1, 15);
            break;
        case 6:
            buscar(vector1, 15);
            break;
        }
    } while (op != 0);
}

void llenavectorsr(int vector1[], int tam, int ri, int rf)
{
    int i, j, num, rango;
    bool band;
    rango = (rf - ri) + 1;
    if (rango >= tam)
    {
        for (i = 0; i < tam; i++)
        {
            do
            {
                num = (rand() % rango) + ri;
                j = 0;
                band = false;
                while (j < i && band == false)
                {
                    if (num == vector1[j])
                    {
                        band = true;
                    }
                    j++;
                }
            } while (band == true);
            vector1[i] = num;
        }
    }
}

void llenamatriz(int matriz[][4], int m, int ri, int rf)
{
    srand(time(NULL));
    int i, j, k = 0, l, num, rango;
    bool band;
    rango = (rf - ri) + 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            matriz[i][j] = 0;
        }
    }
    if (rango >= m * m)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                do
                {
                    num = (rand() % rango) + ri;
                    band = false;
                    k = 0;
                    while (k < 4 && band == false)
                    {
                        l = 0;
                        while (l < 4 && band == false)
                        {
                            if (matriz[k][l] == num)
                            {
                                band = true;
                            }
                            l++;
                        }
                        k++;
                    }

                } while (band == true);
                matriz[i][j] = num;
            }
        }
    }
}

void imprimirvect(int vector1[], int tam)
{
    int i;
    system("CLS");
    printf("VECTOR 1: \n");
    for (i = 0; i < tam; i++)
    {
        printf("Vector 1[%d]:%d \n", i, vector1[i]);
    }
    system("PAUSE");
}

void imprimirmatriz(int matriz[][4], int m)
{
    int i, j;
    system("CLS");
    printf("MATRIZ: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("[%3d]", matriz[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}

void buscar(int vector1[], int tam)
{
    int pos, num;
    system("CLS");
    num = vali_num(100, 200, "Que numero buscas");
    pos = busquedasec(vector1, tam, num);
    if (pos != -1)
    {
        printf("El numero %d esta en el indice %d \n", num, pos);
    }
    else
    {
        printf("%d NO se encuentra en el vector \n", num);
    }
    system("PAUSE");
}

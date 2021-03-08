#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int **alocaMatriz(int LINHAS, int COLUNAS)
{
    int **MATRIZ;

    MATRIZ = (int**)malloc(LINHAS * sizeof(int*));
    if(MATRIZ == NULL)
        exit(1);

    for(int i = 0; i < LINHAS; i++)
    {
        MATRIZ[i] = (int*)malloc(COLUNAS * sizeof(int));
        if(MATRIZ[i] == NULL)
            exit(1);

    }

    return MATRIZ;

}

int **copiando_matriz(int **pt_matriz)
{
    
    int **MATRIZ, linhas, colunas;
    
    linhas = malloc_usable_size(pt_matriz) / sizeof(int*); 
    colunas = (malloc_usable_size(*pt_matriz) - malloc_usable_size(pt_matriz)) / sizeof(int);  

    MATRIZ = (int**)malloc(linhas * sizeof(int*));


    for(int i = 0; i < linhas; i++)
        MATRIZ[i] = (int*)malloc(colunas * sizeof(int));
     
     
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            MATRIZ[i][j] = pt_matriz[i][j];

    

    return MATRIZ; 
}



void liberaMatriz(int **pt_matriz)
{
    int linhas = malloc_usable_size(pt_matriz) / sizeof(int**); //O tamanho de um int* são 8 bytes

    for(int i = 0; i < linhas; i++)
        free(pt_matriz[i]);

    free(pt_matriz);
}


//FUNÇÕES PARA COLOCAR VALORES E TESTAR AS FUNÇÕES ACIMA

void preencheMatriz(int **matriz, int linhas, int colunas)
{

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
            matriz[i][j] = i+j;
    }

}


void imprimeMatriz(int **matriz, int linhas, int colunas)
{

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
            printf("%d\t", matriz[i][j]);

        printf("\n");
    }    
}



int main()
{
    int linhas, colunas, **matriz, **copia_matriz;



    printf("Digite o número de linhas:\n");
    scanf("%d", &linhas);
    printf("Digite o número de colunas:\n");
    scanf("%d", &colunas);

    copia_matriz = (int**)malloc(38);

    matriz = alocaMatriz(linhas, colunas); 
    preencheMatriz(matriz, linhas, colunas);
    imprimeMatriz(matriz, linhas, colunas);
    
    int k = malloc_usable_size(copia_matriz);
    
    printf("%d bytes\n", k);

    //copia_matriz = copiando_matriz(matriz);


    //imprimeMatriz(copia_matriz, linhas, colunas);

    
    //liberaMatriz(matriz);
    //liberaMatriz(copia_matriz);

    return 0;
}

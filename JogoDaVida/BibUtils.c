#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BibUtils.h"

#ifdef __unix__
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)
    #define OS_WINDOWS
    
    #include <windows.h>

#endif

void limpatela()
{
    #ifdef OS_WINDOWS
        system("cls");

    #else
        system("clear");
    
    #endif
}

void pausa()
{
    #ifdef OS_WINDOWS
        system("timeout 1");

    #else
        system("sleep 0.5");
    
    #endif

}

void Menu()
{
    printf("Escolha uma opção de inicialização:\n");
    printf("Opção 1: Inicialização randômica\n");
    printf("Opção 2: Usuário indicando onde deve começar as células\n");
}

void InicializaMatriz(int *Matriz, int linhas, int colunas, int escolha)
{
    srand(time(NULL));

    int x = 0, y = 0;
    
    if(escolha == 1)
    {
        for(int i = 0; i < linhas * colunas; i++)
        {
           Matriz[i] = rand() % 2;
        } 

    }
    else if(escolha == 2)
    {
        while(x != -1 && y != -1)
        {
            scanf("%d %d", &x, &y);

            Matriz[x*colunas+y] = 1;
        }
    }
    else
    {
        printf("Opção inválida.");
    }
}

        
int verificacaoVizinhos(int *Matriz, int posicao)
{
    
        int vizinhos = 0;
        
        if(posicao == 0)
        {   
            if(Matriz[1] == 1)
                vizinhos++;

            if(Matriz[30] == 1)
                vizinhos++;
            
            if(Matriz[31] == 1)
                vizinhos++;

        }
        
        if(posicao == 29)
        {   
            if(Matriz[59] == 1)
                vizinhos++;
            
            if(Matriz[28] == 1)
                vizinhos++;
            
            if(Matriz[58] == 1)
                vizinhos++;    
            
        }
        
        if(posicao == 870)
        {   
            if(Matriz[840] == 1)
                vizinhos++;

            if(Matriz[871] == 1)
                vizinhos++;    
            
            if(Matriz[872] == 1)
                vizinhos++;

        }

        if(posicao == 899)
        {   
            if(Matriz[868] == 1)
                vizinhos++;

            if(Matriz[869] == 1)
                vizinhos++;
            
            if(Matriz[898] == 1)
                vizinhos++;
        }

        if(posicao % 30 == 0 && posicao != 0)
        {
            if(Matriz[posicao+1] == 1)
                vizinhos++;

            if(Matriz[posicao-29] == 1)
                vizinhos++;

            if(Matriz[posicao-30] == 1)
                vizinhos++;
            
            if(Matriz[posicao+30] == 1)
                vizinhos++;
            
            if(Matriz[posicao+31] == 1)
                vizinhos++;
        }

        if(posicao % 30 == 29 && posicao != 29)
        {
            if(Matriz[posicao-1] == 1)
                vizinhos++;

            if(Matriz[posicao-30] == 1)
                vizinhos++;
            
            if(Matriz[posicao-31] == 1)
                vizinhos++;


            if(Matriz[posicao+29] == 1)
                vizinhos++;

            if(Matriz[posicao+30] == 1)
                vizinhos++;
            
        }
        
        if(posicao > 0 && posicao < 30)
        {
            if(Matriz[posicao-1] == 1)
                vizinhos++;

            if(Matriz[posicao+1] == 1)
                vizinhos++;
            
            if(Matriz[posicao+29] == 1)
                vizinhos++;

            if(Matriz[posicao+30] == 1)
                vizinhos++;
            
            if(Matriz[posicao+31] == 1)
                vizinhos++;
            
        }
 
        if(posicao > 870 && posicao < 900)
        {
            if(Matriz[posicao-1] == 1)
                vizinhos++;

            if(Matriz[posicao+1] == 1)
                vizinhos++;

            if(Matriz[posicao-30] == 1)
                vizinhos++;

            if(Matriz[posicao-29] == 1)
                vizinhos++;

            if(Matriz[posicao-31] == 1)
                vizinhos++;

        }

        if(posicao % 30 != 0 && posicao % 30 != 29 && posicao > 29 && posicao < 869)
        {
            if(Matriz[posicao+1] == 1)
                vizinhos++;

            if(Matriz[posicao-1] == 1)
                vizinhos++;
             
            if(Matriz[posicao+29] == 1)
                vizinhos++;

            if(Matriz[posicao+30] == 1)
                vizinhos++;
            
            if(Matriz[posicao+31] == 1)
                vizinhos++;
            
            if(Matriz[posicao-30] == 1)
                vizinhos++;
        
            if(Matriz[posicao-31] == 1)
                vizinhos++;

            if(Matriz[posicao-29] == 1)
                vizinhos++;
        }

        return vizinhos;
}

void CicloVidaCelula(int *Matriz, int *CopiaMatriz, int posicao)
{
    if(verificacaoVizinhos(CopiaMatriz, posicao) < 2)
        Matriz[posicao] = 0;
    
    if(verificacaoVizinhos(CopiaMatriz, posicao) > 3 && Matriz[posicao] == 1)
        Matriz[posicao] = 0;
    
    if((verificacaoVizinhos(CopiaMatriz, posicao) == 2 || verificacaoVizinhos(CopiaMatriz, posicao) == 3) && Matriz[posicao] == 1)
        Matriz[posicao] = 1;
    
    if(verificacaoVizinhos(CopiaMatriz, posicao) == 3 && Matriz[posicao] == 0)
        Matriz[posicao] = 1;

}

void CopiandoMatriz(int *MatrizOrig, int *CopiaMatriz, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        CopiaMatriz[i] = MatrizOrig[i];
    }
}

void imprimeMatriz(int *Matriz, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        { 
            if(Matriz[i*colunas+j] == 1)
                printf("O");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void simulacaoDoJogo(int *Matriz, int *CopiaMatriz, int linhas, int colunas, int geracoes)
{
    for(int n = 0; n < geracoes; n++)
    {
        limpatela();

        CopiandoMatriz(Matriz, CopiaMatriz, linhas * colunas);
        
        for(int i = 0; i < linhas * colunas; i++)
        {
            CicloVidaCelula(Matriz, CopiaMatriz, i);
        }

        imprimeMatriz(Matriz, linhas, colunas);
        pausa();
        
    }
}


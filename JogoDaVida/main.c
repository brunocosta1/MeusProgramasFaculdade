#include <stdio.h>
#include <stdlib.h>
#include "BibUtils.h"

#define L 30
#define C 30

int main(){
    
    int geracoes, escolha, matriz[L * C] = {0}, MatrizCopia[L * C];
    
    
    Menu();
    scanf("%d", &escolha);

    InicializaMatriz(matriz, L, C, escolha); 

    printf("Digite o número de gerações que você deseja simular:\n");
    scanf("%d", &geracoes);
   

    simulacaoDoJogo(matriz, MatrizCopia, L, C, geracoes);
    

    return 0;
}

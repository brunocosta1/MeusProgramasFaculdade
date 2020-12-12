//NOME: BRUNO COSTA DOS PASSOS
//QUESTÃO 5

#include <stdio.h>
#include <stdbool.h>

#define QTD_DIAS 30 

typedef struct
{
    float jejum;
    float prandial;
} Exame;

bool entradaExames(float resultado1, float resultado2, Exame *exame, int *dias)
{
    if(*dias < QTD_DIAS)
    {
        exame[*dias].jejum = resultado1;
        exame[*dias].prandial = resultado2; 
        
        *dias = *dias + 1;

        return true;
    }
    else
        return false;
}

bool resultadoDiabete(Exame *exame, int *dias)
{
    int ct = 0;
    
    for(int i = 0; i < *dias; i++)
    {
        if(exame[i].jejum > 100.0 && exame[i].prandial > 140.0)
            ct++;
        else
            ct = 0;
        
        if(ct == 5)
            return true;
    } 
    
    ct = 0;

    for(int i = 0; i < *dias; i++)
    {
        if(exame[i].jejum > 100.0)
            ct++;
        else
            ct = 0;
     
        if(ct == 10)
            return true;
    }
    
    ct = 0;

    for(int i = 0; i < *dias; i++)
    {
        if(exame[i].prandial > 140.0)
            ct++;
        else
            ct = 0;
     
        if(ct == 10)
            return true;
    }

    ct = 0;

    for(int i = 0; i < *dias; i++)
    {
        if(exame[i].jejum > 100.0 || exame[i].prandial > 140.0)
            ct++;
        else
            ct = 0;
        
        if(ct == 15)
            return true;
    }

    return false;


}

float mediaExame_p(Exame *exame, int *dias)
{
    int media, soma = 0.0;

    for(int i = 0; i < *dias; i++)
    {
        soma += exame[i].prandial; 
    }

    media = soma / *dias;

    return media;
}

float mediaExame_j(Exame *exame, int *dias)
{
    int media, soma = 0.0;

    for(int i = 0; i < *dias; i++)
    {
        soma += exame[i].jejum; 
    }

    media = soma / *dias;

    return media;
}

void diagnostico(Exame *exame, int *dias)
{
    
    int **pt = &dias;
    

    if(resultadoDiabete(exame, *pt))
       printf("Alterado.\n");
    else
       printf("Normal.\n");

    printf("Jejum: %.2f\n", mediaExame_j(exame, *pt));
    printf("Pós-prandial %.2f\n", mediaExame_p(exame, *pt));
}

int main()
{
    Exame exames[QTD_DIAS];
    int dias = 0;
    float resultado_j = 0, resultado_p = 0, media_j = 0, media_p = 0;
    

    for(int i = 0; i < QTD_DIAS; i++)
    {
        printf("Exame %d, em jejum e pós-prandial: \n", i+1);
        
        scanf("%f %f", &resultado_j, &resultado_p);
        entradaExames(resultado_j, resultado_p, exames, &dias);

    } 
    
    diagnostico(exames, &dias);


    return 0;
}

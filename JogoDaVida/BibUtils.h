#ifndef BibUtils
#define BibUtils

void Menu();

void InicializaMatriz(int *Matriz, int linhas, int colunas, int escolha);

void imprimeMatriz(int *Matriz, int linhas, int colunas);

int verificacaoVizinhos(int *Matriz, int posicao);

void CopiandoMatriz(int *MatrizOrig, int *CopiaMatriz, int tam);

void CicloVidaCelula(int *Matriz,int *CopiaMatriz, int posicao);

void simulacaoDoJogo(int *Matriz, int *CopiaMatriz, int linhas, int colunas, int geracoes);

void limpatela();

void pausa();



#endif

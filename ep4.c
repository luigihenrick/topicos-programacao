#include <stdio.h>
#include <stdlib.h>

#define LIN 5
#define COL 6

typedef struct no No;
struct no {
    int linha;
    int coluna;
    No * prox;
};

typedef struct fila Fila;
struct fila {
    No * inicio;
    No * fim ;
    int tamanho;
};

void insereFila (int linha, int coluna, Fila * f){
    No * novo;

    novo = malloc(sizeof(No));
    novo->linha  = linha;
    novo->coluna = coluna;
    novo->prox   = NULL;

    if(f->inicio == NULL){
        f->inicio = novo;
        f->tamanho = 0;
    }else{
        f->fim->prox = novo;
        f->tamanho++;
    }
    f->fim = novo;
}

No * removeFila (Fila * f){
    No * remove;
    No * retorna;

    remove = f->inicio;
    retorna = remove;
    f->inicio = remove->prox;

    if(f->inicio == NULL)
        f->fim = NULL;

    f->tamanho--;
    free(remove);
    return retorna;
}

void imprimeFila (Fila * f){
    No * r;
    r = f->inicio;
    while(r != NULL){
        printf("(%d, %d)\n", r->linha, r->coluna);
        r = r->prox;
    }
}

void caminhoPercorrido (Fila * f){
    No * r;
    r = f->inicio;
    while(r->prox != NULL){
        printf("(%d, %d) -> ", r->linha, r->coluna);
        r = r->prox;
    }
    printf("(%d, %d)\n", r->linha, r->coluna);
}

/* Percorre o labirinto do final, (m-1, n-1), até o inicio (0, 0)
   Retorna 1 para labirinto atravessado e 0 para nenhum caminho encontrado. */
int labirintoR (int labirinto[LIN][COL], int m, int n, Fila * f){

    /* Variável responsável por apontar se labirinto foi atravessado */
    int x = 0;

    /* Caso tenha chegado até (0,0), insiro na fila a posição (0, 0)
        Retorno 1 para indicar que o labirinto foi atravessado */
    if (m == 0 && n == 0){
        insereFila(m, n, f);
        return 1;
    }

    /* Verifico se não estou tentando acessar uma posição inválida */
    if (m < 0) m = 0;
    if (n < 0) n = 0;

    /* Verifico se a posição atual não é um obstaculo, se não foi percorrida
       E se o labirinto ainda não foi atravessado. */
    if (labirinto[m][n] == 0 && x == 0){

        /* Utilizo o -1 para indicar que o algoritmo já passou por esta celula */
        labirinto[m][n] = -1;

        /* Verifico em qual posição prosseguir */
        /* Posso ir para cima? */
        if(labirinto[m-1][n] == 0 && x == 0)
            x = labirintoR(labirinto, m-1, n, f);

        /* Posso ir para esquerda? */
        if(labirinto[m][n-1] == 0 && x == 0)
            x = labirintoR(labirinto, m, n-1, f);

        /* Posso ir para baixo? */
        if(labirinto[m+1][n] == 0 && x == 0)
            x = labirintoR(labirinto, m+1, n, f);

        /* Posso ir para direita? */
        if(labirinto[m][n+1] == 0 && x == 0)
            x = labirintoR(labirinto, m, n+1, f);

        /* Fim da linha */
        /* Caso não tenha atravessado o labirinto,
           Zera a posição atual e retorno para a anterior */
        if((labirinto[m+1][n] == -1 || labirinto[m][n+1] == -1 || labirinto[m-1][n] == -1 || labirinto[m][n-1] == -1) && (x == 0)){
            labirinto[m][n] = 0;
            return 0;
        }

        insereFila(m, n, f);
        return x;
    }
    return x;
}

int resolveLabirinto (int labirinto[LIN][COL], int m, int n){
    Fila * f;
    int x = 0;

    f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;

    x = labirintoR(labirinto, m-1, n-1, f);

    if(x == 1){
        printf("Distancia da casa inicial a casa final: %d\n", f->tamanho);
        printf("Caminho percorrido: \n");
        caminhoPercorrido(f);
    }
    return x;
}


int main(){
    int m, n;
    /* Declaracao dos labirintos */
    /* int labirinto1 [3][3] = {{0, 1, 1}, {0, 0, 0}, {1, 1, 0}}; */
    /* int labirinto2 [4][4] = {{0, 0, 1, 1}, {1, 0, 1, 0},
    {1, 0, 1, 0}, {1, 0, 1, 0}}; */
    int labirinto3 [5][6] = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
    m = LIN;
    n = COL;
    /* resolveLabirinto (labirinto1, m, n); */
    /* resolveLabirinto (labirinto2, m, n); */
    /* resolveLabirinto (labirinto3, m, n); */

    printf("Labirinto = %d\n", resolveLabirinto (labirinto3, m, n));
    return 0;
}

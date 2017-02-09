/* Luigi Henrick Feitoza Silva
   Tópicos de Programação */
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa {
  int posicao;
  Pessoa *prox;
};

Pessoa *inicio = NULL;

/* 2.1.1 Insere Lista */
void insereLista(int x)
{
  Pessoa *nova;
  nova = malloc(sizeof(Pessoa));
  nova->posicao = x;
  if(inicio == NULL)
  {
    inicio = nova;
    nova->prox = inicio;
  }
  else
  {
    Pessoa *p;
    p = inicio;
    while(p->prox != inicio)
      p = p->prox;
    p->prox = nova;
    nova->prox = inicio;
  }
}
/* 2.1.2 Remove Lista */
void removeLista(Pessoa *p)
{
  Pessoa *morta;
  morta = p->prox;
  p->prox = p->prox->prox;
  free(morta);
}
/* 2.1.3 Imprime Lista */
void imprimeLista()
{
  Pessoa *p;
  for(p = inicio; p->prox != inicio; p = p->prox)
    printf("%d ", p->posicao);
  printf("%d\n", p->posicao);
}
/* 2.2 Resolve Josephus */
void resolveJosephus(int n, int m)
{
  Pessoa *p, *morta;
  int i;
  p = inicio;
  morta = p;
  for(i = 1; p->prox != p; i++)
  {
    morta = morta->prox;
    if(m == 1)
    {
      /*printf("%d mata %d\n", p->posicao, p->prox->posicao); */
      printf("%d ", p->prox->posicao);
      removeLista(p);
      p = p->prox;
      inicio = p;
    }
    else if(m - 1 == i)
    {
      i = 0;
      if(p->posicao == morta->prox->posicao)
        morta = morta->prox;
      /*printf("%d mata %d\n", p->posicao, morta->prox->posicao); */
      printf("%d ", p->prox->posicao);
      p = morta->prox->prox;
      removeLista(morta);
      morta = p;
      inicio = p;
    }
  }
  printf("%d\n", inicio->posicao);
}

int main()
{
  int i;
  for(i = 1; i <= 41; i++)
    insereLista(i);
  printf("Lista:\n");
  imprimeLista();
  printf("\nResolve Josephus: \n");
  resolveJosephus(41, 1);
  printf("\nLista Atualizada: \n");
  imprimeLista();
  return 0;
}

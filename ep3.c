#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;
struct no{
  char conteudo;
  No *prox;
};

void empilha (char conteudo, No ** pilha)
{
  No *nova;
  nova = malloc(sizeof(No));
  nova->conteudo = conteudo;
  nova->prox     = *pilha;
  *pilha         = nova;
}

char desempilha (No ** pilha)
{
    No *temp;
  char c;

  if((*pilha) == NULL) return '\0';

  temp = *pilha;
  c    = temp->conteudo;
  *pilha = temp->prox;
  free(temp);
  return c;
}

void imprimePilha (No * pilha)
{
  No *temp;
  temp = pilha;
  while (temp != NULL)
  {
    printf("%c\n", temp->conteudo);
    temp = temp->prox;
  }
  printf("\n");
}

int bemFormada (char str [])
{
  No *pilha;
  int i;
  char a;

  pilha = NULL;
  for (i = 0; i <= strlen(str); i++)
  {
    switch (str[i])
    {
      case '(':
      case '[':
      case '{':
      {
        empilha(str[i], &pilha);
        break;
      }
      case ')':
      {
        a = desempilha(&pilha);
        if (a == '\0' || a != '(') return 0;
        break;
      }
      case ']':
      {
        a = desempilha(&pilha);
        if (a == '\0' || a != '[') return 0;
        break;
      }
      case '}':
      {
        a = desempilha(&pilha);
        if (a == '\0' || a != '{') return 0;
        break;
      }
      case '\0':
      {
        if(pilha != NULL) return 0;
      }
    }
  }
  return 1;
}

int main()
{
  char str[] = "()[{()}]";
  printf("%s, bem formada = %d\n", str, bemFormada(str));
  return 0;
}

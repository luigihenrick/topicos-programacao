/* Nome:  Luigi Henrick Feitoza Silva
   Curso: Tópicos de Programação      */

#include <stdio.h>
#include <string.h>

// Função auxiliar 2.1 Palindromo
int pali (char *c, int i, int j)
{
    int x;
    //printf(" i = %u j = % u \n", i, j);
    if (i < j && c[i] == c[j])
        x = x + pali(c, ++i, --j);
    else
    {
        if (c[i] != c[j])
          return 0;
        else
          return 1;
    }
}

// 2.1 Palindromo
int palindromo (char *n)
{
    size_t j = strlen(n);
    if (pali(n, 0, --j) == 0)
      printf("Nao e' palindromo\n");
    else
      printf("E' palindromo\n");
    return 0;
}

// 2.2 Inversa
int inversa (char *str)
{
    size_t j = strlen(str);
    if(j != 0)
    {
        printf("%c", str[j-1]);
        str[j-1] = '\0';
        inversa(str);
    }
    return 0;
}

// Função auxiliar 2.3 Fibonacci
int fibo(int x, int y, int n)
{
    if (n > 0)
    {
        printf("%u ", x);
        return fibo(y, (x + y), --n);
    }
    return y;
}

// 2.3 Fibonacci
int fibonacci (int n){return fibo (0, 1, n);}

// 2.4 Piso Log2
int pisoLog (int x)
{
    int aux;
    if (x < 2)
        return 0;
    else
    {
        aux = 1 + pisoLog(x/2);
    }
    return aux;
}

int main()
{
    printf("2.1 - Palindromo\n");
    char n[] = {'1','2','3','4','3','2','1'};
    char* p = n;
    printf("%s -> ", n);
    palindromo(p);
    printf("\n");

    printf("2.2 - Inversa\n");
    char str[] = {'a','b','c','d','e','f'};
    char* ptr = str;
    printf("%s -> ", str);
    inversa(ptr);
    printf("\n\n");

    printf("2.3 - Fibonacci\n");
    printf("N = 8  -> ");
    fibonacci(8);
    printf("\n\n");

    printf("2.4 - Piso Log2\n");
    printf("N = 500 -> %u\n", pisoLog(500));
    printf("N = 520 -> %u", pisoLog(520));
    printf("\n");
}
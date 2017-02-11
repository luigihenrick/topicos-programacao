#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 30

char ** ordenacaoCrescente (char palavras[N][M]){
    char aux[M];
    int i, j, max = 0;
    
    for(j = N; j > 0; j--){
        for(i = 0; i < j; i++){
            if(strcmp(palavras[max], palavras[i]) < 0)  max = i;
        }
        
        if(max != j-1){
            strcpy(aux, palavras[j-1]);
            strcpy(palavras[j-1], palavras[max]);
            strcpy(palavras[max], aux);
        }else
            max = 0;
    }
    return palavras;
}

char ** ordenacaoDecrescente (char palavras[N][M]){
    char aux[M];
    int i, j, min = 0;
    
    for(j = N; j > 0; j--){
        for(i = 0; i < j; i++){
            if(strcmp(palavras[min], palavras[i]) > 0)  min = i;
        }
        
        if(min != j-1){
            strcpy(aux, palavras[j-1]);
            strcpy(palavras[j-1], palavras[min]);
            strcpy(palavras[min], aux);
        }else
            min = 0;
    }
    return palavras;
}

int main () {
    int i;
    char str[N][M] = {"lovelace", "snyder", "jennings", "meltzer", "wescoff",
    "bilas", "mcnulthy", "lichterman", "hopper", "hamilton"};
    /* char str1 [6][M] = {"heinlein", "gibson", "clarke", "asimov", "wallace", "kindred" }; */
    
    for(i = 0; i < N; i++)
        printf("%s ", str[i]);

    printf("\nOrdenado: \n");
    
    ordenacaoCrescente(str);
    
    for(i = 0; i < N; i++)
        printf("%s ", str[i]); 
    printf("\n");   

    printf("\nDecrescente: \n");

    ordenacaoDecrescente(str);

    for(i = 0; i < N; i++)
        printf("%s ", str[i]); 
    return 0;
}
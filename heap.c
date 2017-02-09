#include <stdio.h>

int fEsq (int p){
    return 2*p + 1;
}

int fDir (int p){
    return 2*p + 2;
}

int pai (int p){
    return (p-1) / 2;
}

/* Sobe a última posição para o lugar correto em um heap v[0..m-1] */
void sobeHeap (int *v, int m){
    int f = m-1;
    int p, aux;
    while (f > 0 && v[p = pai(f)] < f){
        aux = v[f];
        v[f] = v[p];
        v[p] = aux;
        f = p;
    }
}

void insereHeap (int *v, int *m, int x){
    
    v[*m] = x;
    *m = *m + 1;
    
    sobeHeap(v, *m);
}

void desceHeap (int *v, int m){
    int p = 0, fe, fd, fmax, aux;

    fe = fEsq(p);
    fd = fDir(p);

    while (fe < m) {
        if (fd < m && v[fd] > v[fe])
            fmax = fd;
        else 
            fmax = fe;

        if (v[p] < v[fmax]) {
            aux = v[p];
            v[p] = v[fmax];
            v[fmax] = aux;
            p = fmax;
            fe = fEsq(p);
            fd = fDir(p);
        } else 
            break;
    }
}
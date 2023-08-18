#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 256
#define MAXSTR 4
#define bin(A) l+count[A]

unsigned char *aux[MAXSTR];

void msd_radix(unsigned char **a, int l, int r, int w) {
    int count[R+1];
  
    for (int j = 0; j <= R; ++j) count[j] = 0;
  
    for (int i = l; i <= r; ++r) {
        count[a[i][w]+1]++;
        printf("count[%d] = %d\n", a[i][w]+1, count[a[i][w]+1]);
    }
    printf("\n");
    for (int j = 1; j <= R; ++j) {
        count[j] += count[j-1];
        printf("count[%d] = %d\n", j, count[j]);
    }
    
    for (int i = l; i <= r; ++i)
        aux[count[a[i][w]]++] = a[i];

    // debug
    for (int i = 0; i < MAXSTR; ++i) printf("%s\n", aux[i]);
    printf("\n");
    
    //for (int j = 0; j < R-1; ++j)
    //    msd_radix(a, bin(j), bin(j+1)-1, w+1);
}

int main() {
    char *strings[MAXSTR] = {"tagca", "ggcta", "actga", "atcga"};
    unsigned char **v = malloc(MAXSTR * sizeof(unsigned char *));

    for (int i = 0; i < MAXSTR; ++i) {
        v[i] = malloc(strlen(strings[i])+1 * sizeof(unsigned char));
        strcpy(v[i], strings[i]);
    }

    for (int i = 0; i < MAXSTR; ++i) printf("%s\n", v[i]);
    msd_radix(v, 0, MAXSTR-1, 0);
}

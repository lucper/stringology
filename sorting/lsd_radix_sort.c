#include <stdlib.h>

/* TODO: review mask to extract digit. */
void int_lsd_radix_sort() {
    ;
}

/* Each unsigned char * has W chars (goes from 0 to W-1). */
void str_lsd_radix_sort(unsigned char **v, int n, int W) {
    int occ_pred[R+1] = malloc((R+1) * sizeof(int));
    unsigned char **aux = malloc(n * sizeof(unsigned char *));
    
    int R = 256; 
    // Because an unsigned char varies in {0,...,255};
    // this is the range of the digits.

    for (int digit = W - 1; digit >= 0; --digit) {
        for (int val = 0; val <=R; ++val) occ_pred[val] = 0;

        for (int i = 0; i < n; ++i) ++occ_pred[v[i][digit]+1];
        // occ_pred[val] stores the # of occurrences of val-1, where val is v[i][digit].
        
        for (int val = 1; val <= R; ++val) occ_pred[val] += occ_pred[val-1];
        // occ_pred[val] now stores the # of occurrences of predecessors of val.
        // (Recall that the semantics changes iteratively.)

        for (int i = 0; i < n; ++i) aux[occ_pred[v[i][digit]]++] = v[i];
        // val = v[i][digit];          sorting by digit
        // aux[occ_pred[val]] = v[i];  moving entire string
        // occ_pred[val]++;            update for next position
    }

    for (int i = 0; i < n; ++i) v[i] = aux[i]; // use memcpy?
}

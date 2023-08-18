#include "pat_match.h"

/* Z-based. */
void z_sp_vals(const char *s, int n, int z[], int sp[]) {
    for (int i = 0; i < n; ++i) sp[i] = 0;
    for (int j = n - 1, i = 0; j > 0; --j) {
        i = j + z[j] - 1;
        sp[i] = z[j];
    }
}

/* TODO: Prove correctness using Lemma 3.3.1; pay special attention to the
 * general reduction. */
void sp_vals(const char *s, int n, int sp[]) {
    sp[0] = 0;
    for (int k = 1; k < n; ++k) {
        char x = s[k];  // current val we want for which we want to compute sp
        int v = sp[k-1];  // previous sp val of x
        while (s[v] != x && v != 0)
            v = sp[v];
        if (s[v] == x)
            sp[k] = v+1;
        else
            sp[k] = 0;
    }
}

/* This is the next array presented in class. 
 * I think this is not even needed... */
void fail_func(int sp[], int f[], int n) {
    f[0] = 0; // because sp[-1] is defined to be zero
    for (int i = 1; i < n; ++i)
        f[i] = sp[i-1]; // dont sum 1 for 0-based index
}

void kmp_pmatch(const char *pat, int n, const char *txt, int m, int f[]) {
    int c = 0, p = 0;
    while (n - p <= m - c) {
        while (p < n && pat[p] == txt[c]) 
            ++p, ++c;
        if (p == n)
            printf("occurrence in %d\n", c - n);
        if (p == 0) // while failed => shift by 1
            ++c;
        p = f[p];   // shift rule
    }
}

void kmp_pmatch2(const char *pat, int n, const char *txt, int m, int sp[]) {
    int c = 0, p = 0;
    while (n - p <= m - c) {
        while (p < n && pat[p] == txt[c]) 
            ++p, ++c;
        if (p == n)
            printf("occurrence in %d\n", c - n);
        if (p >= 1) p = sp[p-1];   // shift rule
        else ++c;                  // while failed
    }
}

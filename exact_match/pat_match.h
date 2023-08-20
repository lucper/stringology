#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void z_array(const char *s, int n, int z[]);

void z_sp_vals(const char *pat, int n, int z[], int sp[]);
void sp_vals(const char *pat, int n, int sp[]);
void fail_func(int sp[], int f[], int n);
void kmp_pmatch(const char *pat, int n, const char *txt, int m, int f[]);
void kmp_pmatch2(const char *pat, int n, const char *txt, int m, int sp[]);

void N_vals(const char *pat, int n, int N[]);
void L_vals(const char *pat, int n, int L[]);
void l_vals(const char *pat, int n, int l[]);
void bm_pmatch(const char *pat, int n, const char *txt, int m, int L[], int l[], int R[]);

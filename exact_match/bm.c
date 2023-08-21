#include "pat_match.h"

/* Length of longest suffix of P[0..i] that matches a suffix of P. */
void N_vals(const char *pat, int n, int N[]) {
    // assume pat ends with \0, but n does not include it
    char *pat_rev = malloc(n * sizeof(char));
    for (int i = 0; i < n; ++i)
        pat_rev[i] = pat[n-i-1]; // -1 to ignore \0, but what is \0 is not there?

    int z[n];
    z_array(pat_rev, n, z);
    for (int j = 0; j < n; ++j)
        N[j] = z[n-j-1];
    free(pat_rev);
}

 /* Right end position of right-most copy of P[i..n-1] that's NOT suffix of P, with
  * the condition that its preceding character is not P[i-1]).
  *
  * Theorem 2.2.2. L'(i) is the largest index j < n-1 such that N_j = |P[i..n-1]|. */
void L_vals(const char *pat, int n, int L[]) {
    for (int i = 0; i < n; ++i) L[i] = 0;

    int N[n];
    N_vals(pat, n, N);
    for (int j = 0; j < n-1; ++j)
        if (N[j] > 0)
            L[n-N[j]] = j;
}

/* Length of largest suffix of P[i..n-1] that is also prefix of P; if none exists,
 * then set to zero.
 *
 * Theorem 2.2.4. l'(i) is the largest j < |P[i..n-1]| such that N_j = j. */
void l_vals(const char *pat, int n, int l[]) {
    for (int i = 0; i < n; ++i) l[i] = 0;

    int N[n];
    N_vals(pat, n, N);
    for (int j = 0; j < n; ++j)
        if (N[j] == j+1)
            l[n-j-1] = j+1;
    for (int j = n-2; j >= 0; --j) // "smear" them out to the left
        if (l[j] == 0)
            l[j] = l[j+1];
}

void bm_pmatch(const char *pat, int n, const char *txt, int m, int L[], int l[], int R[]);

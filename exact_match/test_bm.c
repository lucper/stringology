#include "pat_match.h"

int main(int argc, char **argv) {
    // strdup copies string to allocated space in the heap, must free later
    if (argc != 3) {
        printf("usage: bm <pattern> <text>\n");
        return EXIT_FAILURE;
    }
    
    char *pat = argv[1];
    char *txt = argv[2];
    int n = strlen(pat), m = strlen(txt);

    printf("Z values (length of longest prefix of P[i..n-1] that matches a prefix of P)\n");
    int z_arr[n];
    z_array(pat, n, z_arr);
    for (int i = 0; i < n; ++i)
        printf("%d %c = %d\n", i, pat[i], z_arr[i]);

    printf("\n");

    printf("N values (length of longest suffix of P[0..i] that matches a suffix of P)\n");
    int N[n];
    N_vals(pat, n, N);
    for (int i = 0; i < n; ++i)
        printf("%d %c = %d\n", i, pat[i], N[i]);

    printf("\n");

    printf("L' values (right end position of right-most copy of P[i..n-1] that's NOT suffix of P,\n"
        "           with the condition that its preceding character is not P[i-1])\n");
    printf("    Theorem 2.2.2. L'(i) is largest index j < n-1 such that N_j = |P[i..n-1]| (look at N values)\n");
    int L[n];
    L_vals(pat, n, L);
    for (int i = 0; i < n; ++i)
        printf("%d %c = %d\n", i, pat[i], L[i]);

    return EXIT_SUCCESS;
}

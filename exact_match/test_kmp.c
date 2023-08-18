#include "pat_match.h"

int main(int argc, char **argv) {
    // strdup copies string to allocated space in the heap, must free later
    if (argc != 3) {
        printf("usage: kmp <pattern> <text>\n");
        return EXIT_FAILURE;
    }

    char *pat = argv[1];
    char *txt = argv[2];
    int n = strlen(pat), m = strlen(txt);

    int z_arr[n];
    z_array(pat, n, z_arr);
    for (int i = 0; i < n; ++i)
        printf("%d %c = %d\n", i, pat[i], z_arr[i]);

    printf("\n");

    int sp[n];
    sp_vals(pat, n, sp);
    for (int i = 0; i < n; ++i)
        printf("%d %c = %d\n", i, pat[i], sp[i]);

    printf("\n");

    int f[n+1];
    fail_func(sp, f, n+1);
    for (int i = 0; i < n+1; ++i) { 
        if (i == n)
            printf("%d # = %d\n", i, f[i]);
        else
            printf("%d %c = %d\n", i, pat[i], f[i]);
    }

    printf("\n");

    //kmp_pmatch(pat, n, txt, m, f);
    kmp_pmatch2(pat, n, txt, m, sp);

    return EXIT_SUCCESS;
}

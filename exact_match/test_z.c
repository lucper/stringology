#include "pat_match.h"

int main(int argc, char **argv) {
    // strdup copies string to allocated space in the heap, must free later
    if (argc != 3) {
        printf("usage: z_algorithm <pattern> <text>\n");
        return EXIT_FAILURE;
    }
    
    char *pat = argv[1];
    char *txt = argv[2];
    int n = strlen(pat), m = strlen(txt);
    char s[n+m+1];
    sprintf(s, "%s$%s", pat, txt);
    printf("%s\n", s);

    int z_arr[n+m+1];
    z_array(s, n+m+1, z_arr);
    for (int i = 0; i < n+m+1; ++i)
        printf("%d %c = %d\n", i, s[i], z_arr[i]);

    return EXIT_SUCCESS;
}

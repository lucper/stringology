#include "radix_sort_msd.h"

int main() {
    char *strings[6] = {"she", "sells", "seashells", "by", "the", "sea"};
    for (int i = 0; i < 6; ++i)
        printf("%s\n", strings[i]);

    printf("\n");

    msd_radixsort_ceo(strings, 6, 0);

    for (int i = 0; i < 6; ++i)
        printf("%s\n", strings[i]);
}

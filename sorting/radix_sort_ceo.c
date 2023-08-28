#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void msd_radixsort_ceo(char** strings, size_t n, size_t depth)
{
    /* We assume that |Sigma| = 256; hence, 'bucketsize' stores the
     * bucket size of 256 charaters, some of which are possibly 0 (empty). */
    size_t bucketsize[256] = {0};

    for (size_t i = 0; i < n; ++i)
        /* Pick d-th character of i-th string and use it to index array storing
         * size of bucket for each character.
         * Another semantic for bucketsize is
         *      bucketsize[i] stores the number of occurrences of d-th character. */
        ++bucketsize[strings[i][depth]];

    char** sorted = malloc(n * sizeof(char*));
    
    /* External array for index of each bucket.
     * Another semantic for bucketindex is
     *      bucketindex[i] stores the number of occurrences of (i-1)-th character,
     * where bucketindex[0] is deined to be 0. */
    static size_t bucketindex[256];
    bucketindex[0] = 0;

    for (size_t i = 1; i < 256; ++i)
        /* Recurrence relation to count previous character:
         * (#occurences of previous of i-1) + (#occurrences of i-1) */
        bucketindex[i] = bucketindex[i - 1] + bucketsize[i - 1];

    for (size_t i = 0; i < n; ++i)
        sorted[bucketindex[strings[i][depth]]++] = strings[i];

    memcpy(strings, sorted, n * sizeof(char*));
    
    free(sorted);

    size_t bsum = bucketsize[0];
    for (size_t i = 1; i < 256; ++i) {
        if (bucketsize[i] == 0)
            continue;
        msd_radixsort_ceo(strings + bsum, bucketsize[i], depth + 1);
        bsum += bucketsize[i];
    }
}

int main() {
    char *strings[6] = {"she", "sells", "seashells", "by", "the", "sea"};
    for (int i = 0; i < 6; ++i)
        printf("%s\n", strings[i]);

    printf("\n");

    msd_radixsort_ceo(strings, 6, 0);

    for (int i = 0; i < 6; ++i)
        printf("%s\n", strings[i]);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void msd_radixsort_ceo(byte** strings, size_t n, size_t depth)
{
    /* We assume that |Sigma| = 256; hence, 'bucketsize' stores the
     * bucket size of 256 charaters, some of which are possibly 0 (empty). */
    size_t bucketsize[256] = {0};

    for (size_t i = 0; i < n; ++i)
        /* Pick d-th character of i-th string and
         * use it to index array storing size of
         * bucket for each character. */
        ++bucketsize[strings[i][depth]];

    byte** sorted = (byte**) malloc(n * sizeof(byte*));
    
    /* Exterbal array for index of each bucket. */
    static size_t bucketindex[256];
    bucketindex[0] = 0;

    for (size_t i = 1; i < 256; ++i)
        bucketindex[i] = bucketindex[i - 1] + bucketsize[i - 1];

    for (size_t i = 0; i < n; ++i)
        sorted[bucketindex[strings[i][depth]]++] = strings[i];

    memcpy(strings, sorted, n * sizeof(byte*));
    
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
    byte** strings = {"teste", "teste2", "teste3"};
    for (int i = 0; i < 3; ++i)    
        printf("%s\n", strings[i]);
}

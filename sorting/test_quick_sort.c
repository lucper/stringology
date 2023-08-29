#include <stdio.h>
#include "quick_sort.h"

int main() {
    int v[6] = {5,2,1,3,2,2};
    qsort_3way_partition(v, 0, 5);
    for (int i = 0; i < 6; ++i)
        printf("%d ", v[i]);
    printf("\n");
}

#include <stdio.h>
#include "quick_sort.h"

int main() {
    int v[6] = {5,2,1,3,2,2};
    int i = three_way_partition(v, 0, 5);
    printf("pivot pos: %d\n", i);
    for (int i = 0; i < 6; ++i)
        printf("%d ", v[i]);
    printf("\n");
}

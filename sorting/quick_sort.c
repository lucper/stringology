#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"

static
void iswap(int i, int j, int v[]) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* Lomuto's scheme, shown in CLRS; potentially performs lots
 * of swaps. */
static
int lomuto_partition(int v[], int p, int r) {
    int i = p, pivot = v[r];
    for (int j = p; j < r; ++j)
        if (v[j] <= pivot) {
            iswap(i, j, v);
            i++;
        }
    iswap(i, r, v);
    return i;
}

/* Performs unnecessary comparisons of repeated elements,
 * but performs three times fewer swaps on average when
 * compared to Lomuto's scheme. */
static
int hoare_partition(int v[], int p, int r) {
    int pivot = v[p]; // could be last I think..
    int i = p - 1, j = r + 1;
    for (;;) {
        while (v[++i] < pivot) ;
        while (v[--j] > pivot) if (j == p) break;
        if (i >= j) return j;
        iswap(i, j, v);
    }
}

/* I think this scheme has the advantages of Hoare's scheme,
 * and, in addition, does not compare repeated elements. */
static
int partition(int v[], int p, int r) {
    int pivot = v[r];
    int i = p, j = r - 1;
    for (;;) {
        // while (v[++i] < pivot) ;
        while (i < r && v[i] <= pivot) ++i;

        // while (v[--j] < pivot) if (j == l) break; 
        while (j > i && v[j] > pivot) --j;

        if (i >= j) break;
        iswap(i, j, v);
    }
    iswap(i, r, v);
    return i;
}

//static
int three_way_partition(int v[], int l, int r) {
    int pivot = v[r];
    int i = l - 1, p = l; // my modification, p = l, elements to the left of p are 'equal'
    int j = r, q = r - 1; // my modification, q = r - 1, elements to the right of q are 'equal'

    for (;;) {
        while (v[++i] < pivot) ;
        while (v[--j] > pivot) if (j == l) break;
        if (i >= j) break;
        iswap(i, j, v);
        if (v[i] == pivot)
            iswap(i, p++, v); // my modification, increment then swap
        if (v[j] == pivot)
            iswap(j, q--, v); // my modification, increment then swap
    }

    // Put pivot after equal part.
    iswap(i, r, v);

    j = i - 1; // put before pivot
    i = i + 1; // put after pivot

    // Now, we need to move the 'equal' part accordingly;
    // Notice that we run through v[l..p-1] and v[q+1..r-1],
    // the two extremities with 'equal' elements.
    for (int k = l; k < p; ++k, --j)
        iswap(k, j, v);
    for (int k = r - 1; k > q; --k, ++i)
        iswap(k, i, v);

    // Idea is to qsort just v[l..j] and v[i..r].
    // Recursive calls would come here.

    return ; // need to return i and j? [l..i..j..r] ?
}

/* v[p..r] */
void qsortR(int v[], int p, int r) {
    if (p < r) {
        int i = partition(v, p, r);
        qsortR(v, p, i - 1);
        qsortR(v, i + 1, r);
    }
}
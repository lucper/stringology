#include <iostream>
#include <string>

void bad_counting_sort(int a[], int n, int R) {
    int occ[R+1] = {0};
    int occ_pred[R+1] = {0};
    int aux[n] = {0};

    for (int i = 0; i < n; ++i)
        occ[a[i]]++;

    for (int val = 1; val <= R; ++val)
        occ_pred[val] = occ_pred[val-1] + occ[val-1];

    for (int i = 0; i < n; ++i)
        aux[occ_pred[a[i]]++] = a[i];

    for (int i = 0; i < n; ++i)
        a[i] = aux[i];
}

/* Key-indexed counting, from Sedgewick. */
void counting_sort(int a[], int n, int R) {
    int count[R+1] = {0};
    int aux[n] = {0};

    // Let val = a[i].
    // Recall that occ_pred[val] = occ_pred[val-1] + occ[val-1].
    
    // count[i] stores the number of occurrences of a[i]-1, i.e. occ[val-1].
    for (int i = 0; i < n; ++i)
        count[a[i]+1]++;

    // Since count[i] stores occ[val-1], it suffices to add occ_pred[val-1].
    // Now, count[i] stores the position that a[i] starts occupying in aux
    // (equivalently, the number of elements before a[i]).
    // Notice that we change the semantics of count after the following loop.
    // (The semantics changes iteratively after each iteration.)
    for (int i = 1; i <= R; ++i)
        count[i] += count[i-1];

    // Copy val to correct position and increment count[val] for next occurrences.
    for (int i = 0; i < n; ++i)
        aux[count[a[i]]++] = a[i];

    for (int i = 0; i < n; ++i)
        a[i] = aux[i];
}

int main() {
    int a[6] = {10,8,2,2,3,5};
    bad_counting_sort(a, 6, 10);
    for (int i : a)
        std::cout << i << " ";
    std::cout << std::endl;
}

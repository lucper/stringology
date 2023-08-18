#include "pat_match.h"

void z_array(const char *s, int n, int z[]) {
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
        if (r < i) {
            r = l = i;
            while (r < n && s[r-l] == s[r])
                ++r;
            z[i] = r-l;
            --r;
        } else {
            if (z[i-l] < r-i+1)
                z[i] = z[i-l];
            else { // need to compare when z[i-l] == r-i+1
                l = i;
                // if z[i-l] > r-i+1, this loop does not run
                while (r < n && s[r-l] == s[r])
                    ++r;
                z[i] = r-l;
                --r;
            }
        }
}

#include <iostream>
#include <vector>
#include <string>

inline int left_binsearch(const std::string& p, const std::string& t, const std::vector<int>& sa) {
    int lo = -1, L = 0, R = sa.size() - 1;
    while (L < R) {
        int M = (L + R) / 2;

        int i = 0;
        while (i < p.length() && t[sa[M] + i] == p[i]) ++i;

        if (i == p.length())
            lo = M, R = M - 1;
        else {
            if (t[sa[M] + i] < p[i])
                L = M + 1;
            else if (t[sa[M] + i] > p[i])
                R = M - 1;
        }
    }
    return lo;
}

inline int right_binsearch(const std::string& p, const std::string& t, const std::vector<int>& sa) {
    int hi = -1, L = 0, R = sa.size() - 1;
    while (L < R) {
        int M = (L + R + 1) / 2;

        int i = 0;
        while (i < p.length() && t[sa[M] + i] == p[i]) ++i;

        if (i == p.length())
            hi = M, L = M + 1;
        else {
            if (t[sa[M] + i] < p[i])
                L = M + 1;
            else if (t[sa[M] + i] > p[i])
                R = M - 1;
        }
    }
    return hi;
}

void query(const std::string& p, const std::string& t, const std::vector<int>& sa) {
    int L, R;

    L = 0, R = sa.size() - 1;

    /* 7.14.3. A simple accelerant
     * l holds the length of the longest prefix of t starting at sa[L] that matches p.
     * Similarly, r holds the length of the longest prefix of t starting at sa[R] that matches p.
     * We keep tracj of the minimum between the two; this is the number of comparisons tha can be skipped. */
    int l = 0;
    while (t[sa[L] + l] == p[l]) ++l;
    int r = 0;
    while (t[sa[R] + r] == p[r]) ++r;
    int mlr = std::min(l, r);

    int lo = left_binsearch(p, t, sa);
    int hi = right_binsearch(p, t, sa);

    std::cout << lo << std::endl;
    std::cout << hi << std::endl;
}

int main() {
    std::string text = "mississippi";
    // TODO: add algorithm to build SA
    std::vector<int> sa = {10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2};

    std::string pattern = "ssi";
    query(pattern, text, sa);
}

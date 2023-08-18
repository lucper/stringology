#include <string>
#include <iostream>
#include <vector>

/* z_arr[i] = length of longest substring starting
 * at i that matches a prefix of s. */
std::vector<int> z_array(const std::string& s) {
    std::vector<int> z_arr(s.length(), 0);
    z_arr[0] = s.length();
    int l = 0, r = 0;
    for (int i = 1; i < z_arr.size(); i++) {
        // Assume inductively that we know z_arr[j] for j < i
        // and the values of l and r from last iteration.

        // Case 1: r < i
        if (r < i) {
            int j = 0;
            while (j < s.length() && s[j] == s[i+j])
                j++;
            z_arr[i] = j;
            if (j > 0)
                l = i, r = i + j - 1;

        // Case 2: r >= i
        } else {
            // Case 2.a: z[i-l] > |beta|
            if (z_arr[i-l] >= r-i+1) {
                int j = 1;
                while (j < s.length() && s[r-l+j] == s[r+j])
                    j++;
                if (j > 1) {
                    z_arr[i] = j - i;
                    l = i, r = j - 1;
                } else
                    z_arr[i] = z_arr[i-l];
            } else
            // Case 2a: z[i-l] < |beta|
                z_arr[i] = z_arr[i-l]; // r and l unchanged
        }
    }
    return z_arr;
}

int main() {
    std::string s = "aabcaabxaaz";
    std::vector<int> z_arr = z_array(s);
    for (int i = 0; i < z_arr.size(); ++i) {
        std::cout << s[i] << ": " << z_arr[i] << std::endl;
    }
}

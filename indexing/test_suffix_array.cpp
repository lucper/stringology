#include <iostream>
#include <vector>
#include <string>

std::vector<int> query(const std::string& p, const std::string& t, const std::vector<int>& sa) {
    int l = 0, r = sa.size() - 1;
    std::vector<int> occurrs;
    while (l < r) {
        int m = (l+r) / 2;
        std::string suffix = t.substr(sa[m], t.length()-sa[m]);
        std::cout << sa[m] << ": " << suffix << std::endl;
        if (p.compare(suffix) < 0) // p smaller
            r = m-1;
        else if (p.compare(suffix) > 0) // p greater
            l = m+1;
        else {
            occurrs.push_back(sa[m]);
            break;
        }
    }
    return occurrs;
}

int main() {
    std::string text = "mississippi";
    // TODO: add algotihm to build SA
    std::vector<int> sa = {10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2};

    std::vector<int> pos = query("ppi", text, sa);
}

#include <iostream>
#include <string>
#include <algorithm>

int edist(const std::string& x, const std::string& y) {
    int n = y.length(), m = x.length();
    int dist[m+1][n+1] = {0};
    for (int i = 1; i <= m; ++i)
        dist[i][0] = dist[i-1][0] + 1;
    for (int j = 1; j <= n; ++j)
        dist[0][j] = dist[0][j-1] + 1;
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= m; ++i) {
            int cost = x[i] == y[j] ? 0 : 1;
            dist[i][j] = std::min({
                    dist[i-1][j-1]+cost,
                    dist[i-1][j]+1,
                    dist[i][j-1]+1
                });
        }
    return dist[m][n];
}

int main() {
    std::string x = "att";
    std::string y = "atg";
    std::cout << edist(x, y) << std::endl;
}

#include <iostream>
#include <vector>
#include <algorithm>

int V, N;
std::vector<int> C, W;
int * dp;

int solve(int c)
{
    if (dp[c] != -1) {
        return dp[c];
    }
    int i;
    dp[c] = 0;
    for (i = 0;i < N;i++) {
        if (c >= C[i]) {
            dp[c] = std::max(dp[c], solve(c - C[i]) + W[i]);
        }
    }
    return dp[c];
}

int main()
{
    std::cin >> V >> N;

    int i;
    int temp;
    for (i = 0;i < N;i++) {
        std::cin >> temp;
        C.push_back(temp);
        std::cin >> temp;
        W.push_back(temp);
    }

    dp = new int[V + 1];
    for (i = 0;i <= V;i++) {
        dp[i] = -1;
    }
    for (i = 0;i < N;i++) {
        dp[V] = std::max(dp[V], solve(V - C[i]) + W[i]);
    }

    std::cout << dp[V] << std::endl;
}

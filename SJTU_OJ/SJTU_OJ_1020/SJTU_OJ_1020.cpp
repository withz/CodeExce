#include <iostream>
#include <vector>

/*

Unsolved 
Time limit

*/

int next(int n)
{
    int i, j;
    if (n < 2) {
        return 2;
    }
    else {
        while (++n) {
            if (n % 2 == 0) {
                continue;
            }
            for (i = 2;i < n;i++) {
                if (n % i == 0) {
                    break;
                }
            }
            if (i == n) {
                return n;
            }
        }
    }
}

int main()
{
    int x = 1;
    int N;
    std::vector<int> num;
    std::vector<int> cnt;

    std::cin >> N;
    int origin = N;
    while (N != 1 && x < N) {
        x = next(x);
        
        int c = 0;
        while (N % x == 0) {
            N = N / x;
            c++;
        }
        if (c != 0) {
            num.push_back(x);
            cnt.push_back(c);
        }

    }

    std::cout << origin << '=';
    for (x = 0;x < num.size();x++) {
        std::cout << num[x];
        std::cout << '(';
        std::cout << cnt[x];
        std::cout << ')';
    }
    std::cout << std::endl;
}
#include <iostream>
#include <vector>

#define MAX(x,y)   x > y ? x : y
const int min_val = -999999999;

int main()
{
    int N = 0;
    std::vector<int> keys;
    std::cin >> N;

    int i, temp;
    for (i = 0;i < N;i++) {
        std::cin >> temp;
        keys.push_back(temp);
    }

    int sum = keys[0] + keys[1];
    int max_val = sum;
    for (i = 2;i < N;i++) {
        if (sum > keys[i - 1]) {
            sum += keys[i];
        }
        else {
            sum = keys[i - 1] + keys[i];
        }
        max_val = MAX(max_val, sum);
    }

    if (max_val <= 0) {
        std::cout << "Game Over" << std::endl;
    }
    else {
        std::cout << max_val << std::endl;
    }
    
}

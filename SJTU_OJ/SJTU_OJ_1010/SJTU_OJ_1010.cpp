#include <iostream>
#include <vector>

int main()
{
    int i, temp;
    std::vector<int> money;

    for (i = 0;i < 12;i++) {
        std::cin >> temp;
        money.push_back(temp);
    }

    int save = 0;
    int have = 0;
    int reserve = 0;

    for (i = 0;i < 12;i++) {
        have += 300;
        reserve = have - money[i];
        if (reserve < 0) {
            std::cout << -i - 1 << std::endl;
            break;
        }
        else {
            save += reserve / 100;
            reserve = reserve - (reserve / 100) * 100;
            have = reserve;
        }
        
    }
    if (i == 12) {
        std::cout << save * 100 * 1.2 + have<< std::endl;
    }
}

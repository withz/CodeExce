#include <iostream>
#include <vector>


/*

Unsolved 

Data Too Long

Example 100 100 100 1000

*/

int a, b, c, N;
std::vector<unsigned long long> rabbits;

int main()
{
    std::cin >> a >> b >> c >> N;

    int i;
    unsigned long long sum = 0;

    rabbits.push_back(1);

    for (i = 1;i <= N;i++) {
        if (i == 1) {
            rabbits.push_back(rabbits[0] * a);
        }
        if (i == 2) {
            rabbits.push_back(rabbits[1] * a + rabbits[0] * b);
        }
        if (i >= 3) {
            sum += (rabbits[i - 3]);
            rabbits.push_back(rabbits[i - 1] * a + rabbits[i - 2] * b + sum * c);
        }
    }
    
    sum = 0;
    for (i = 0;i <= N;i++) {
        sum += rabbits[i];
    }

    std::cout << sum;
    std::cout << std::endl;
}

#include <iostream>
#include <iomanip>

/*

Unsolved 


*/

int ** map;

int main()
{
    int N;
    std::cin >> N;

    int i, j;
    map = new int*[N];
    for (i = 0;i < N;i++) {
        map[i] = new int[N];
    }
    
    int dir = 0;
    int x = 0;
    i = j = 0;

    while (x < N * N) {
        
    }

    for (i = 0;i < N;i++) {
        for (j = 0;j < N;j++) {
            std::cout << std::setw(6) << map[i][j];
        }
        std::cout << std::endl;
    }
}

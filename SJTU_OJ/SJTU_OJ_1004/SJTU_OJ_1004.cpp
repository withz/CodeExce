#include <iostream>
#include <vector>



int main()
{
    int M, T, U, F, D;
    std::vector<int> S;

    std::cin >> M >> T >> U >> F >> D;

    int i;
    char temp;
    for (i = 0;i < T;i++) {
        std::cin >> temp;
        switch (temp)
        {
        case 'u':S.push_back(U + D);break;
        case 'f':S.push_back(F + F);break;
        case 'd':S.push_back(D + U);break;
        default:break;
        }
    }

    int total_count = 0;
    int total_length = 0;
    for (i = 0;i < T;i++) {
        total_length += S[i];
        
        if (total_length > M) {
            break;
        }
        else {
            total_count++;
        }
    }
    
    std::cout << total_count << std::endl;
}

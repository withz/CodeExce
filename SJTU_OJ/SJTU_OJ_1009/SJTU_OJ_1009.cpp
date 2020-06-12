#include <iostream>
#include <iomanip> 
#include <vector>

int main()
{
    int M, N;
    int temp, i, j;
    double money = 0;

    std::vector<int> time_m;
    std::vector<int> A;
    std::vector<int> D;

    std::vector<int> time_n;
    std::vector<int> V;

    std::cin >> M;
    for (i = 0;i < M;i++) {
        std::cin >> temp;
        time_m.push_back(temp);
        std::cin >> temp;
        A.push_back(temp);
        std::cin >> temp;
        D.push_back(temp);
    }

    std::cin >> N;
    for (i = 0;i < N;i++) {
        std::cin >> temp;
        time_n.push_back(temp);
        std::cin >> temp;
        V.push_back(temp);
    }
    time_n.push_back(200000000);
    V.push_back(temp);

    for (i = 0;i < M;i++) {
        int price = 0;
        int j = 0;
        while (time_m[i] >= time_n[j]) {
            j++;
        }
        price = V[j - 1];

        double total = A[i] * 100 * price;
        if (D[i] == 1) {
            money -= total;
        }
        if (D[i] == 2) {
            money += total;
            money -= total * 0.001;
        }

        double fee = total * 0.002;
        if (fee < 5) {
            fee = 5;
        }
        money -= fee;

        fee = A[i] * 1.0 / 10.0;
        money -= fee;

        money -= 1;
    }

    printf("%.2f\n", money);
}

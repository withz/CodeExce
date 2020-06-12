#include <iostream>
#include <vector>

int main()
{
    int L = 0, W = 0;
    std::cin >> L >> W;

    std::vector<std::vector<int> > power;
    std::vector<std::vector<int> > power_row_sum;
    int iter, jter;
    int temp = 0;

    for (iter = 0;iter < L;iter++) {
        std::vector<int> row;
        for (jter = 0;jter < W;jter++) {
            std::cin >> temp;
            row.push_back(temp);
        }
        power.push_back(row);
    }

    int a, b;
    std::cin >> a >> b;

    for (iter = 0;iter < L;iter++) {
        std::vector<int> row;
        int row_sum = 0;
        for (jter = 0;jter < b;jter++) {
            row_sum += power[iter][jter];
        }
        row.push_back(row_sum);
        for (jter = 1;jter <= W - b;jter++) {
            row_sum -= power[iter][jter - 1];
            row_sum += power[iter][jter + b - 1];
            row.push_back(row_sum);
        }
        power_row_sum.push_back(row);
    }

    int max_power = 0;
    int k;

    for (iter = 0;iter <= L - a;iter++) {
        for (jter = 0;jter <= W - b;jter++) {
            int col_sum = 0;
            for (k = 0;k < a;k++) {
                col_sum += power_row_sum[iter + k][jter];
            }
            if (max_power < col_sum) {
                max_power = col_sum;
            }
        }
    }

    std::cout << max_power << std::endl;
}

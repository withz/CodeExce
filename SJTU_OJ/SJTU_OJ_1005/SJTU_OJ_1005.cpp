#include <iostream>
#include <vector>

bool check_row(int space[9][9], int index)  //true -> Wrong ; false -> Right
{
    int i;
    int check_bits = 0;
    for (i = 0;i < 9;i++) {
        check_bits |= (1 << (space[index][i] - 1));
    }
    if (check_bits == 0b111111111) {  // 1 * 9
        return false;
    }
    else {
        return true;
    }
}

bool check_col(int space[9][9], int index)
{
    int i;
    int check_bits = 0;
    for (i = 0;i < 9;i++) {
        check_bits |= (1 << (space[index][i] - 1));
    }
    if (check_bits == 0b111111111) {
        return false;
    }
    else {
        return true;
    }
}

bool check_square(int space[9][9], int index)
{
    int a, b;
    a = index / 3;
    b = index % 3;

    int i, j;
    int check_bits = 0;
    for (i = a * 3;i < a * 3 + 3;i++) {
        for (j = b * 3;j < b * 3 + 3;j++) {
            check_bits |= (1 << (space[i][j] - 1));
        }
    }
    if (check_bits == 0b111111111) {
        return false;
    }
    else {
        return true;
    }
}

int main()
{
    int N = 0;
    int space[9][9];
    std::vector<int> result;  //1 -> Wrong ; 0 -> Right

    std::cin >> N;

    int iter, i, j;
    for (iter = 0;iter < N;iter++) {
        for (i = 0;i < 9;i++) {
            for (j = 0;j < 9;j++) {
                int temp;
                std::cin >> temp;
                space[i][j] = temp;
            }
        }

        for (i = 0;i < 9;i++) {
            if (check_row(space, i)) {
                result.push_back(1);
                break;
            }
            if (check_col(space, i)) {
                result.push_back(1);
                break;
            }
            if (check_square(space, i)) {
                result.push_back(1);
                break;
            }
        }
        if (9 == i) {
            result.push_back(0);
        }
    }

    for (iter = 0;iter < N;iter++) {
        if (result[iter] == 1) {
            std::cout << "Wrong" << std::endl;
        }
        else {
            std::cout << "Right" << std::endl;
        }
    }
}

#include <iostream>
#include <vector>

int L;
std::vector<std::vector<int> > space;
std::vector<int> modify_list;

bool check_modify(int i, int j)
{
    if (i < 0 || j < 0 || i >= L || j >= L) {
        return false;
    }
    if (space[i][j] == 1) {
        return true;
    }
    if (space[i][j] == 2) {
        return false;
    }
    if (space[i][j] == 0) {
        return false;
    }
}


int main()
{
    int i, j;

    int temp = 0;
    std::cin >> L;
    for (i = 0;i < L;i++) {
        std::vector<int> row;
        for (j = 0;j < L;j++) {
            std::cin >> temp;
            row.push_back(temp);
        }
        space.push_back(row);
    }

    bool loop = true;
    int loop_time = 0;
    
    while (loop) {
        for (i = 0;i < L;i++) {
            for (j = 0;j < L;j++) {
                if (space[i][j] == 0) {
                    if (check_modify(i - 1, j)) {
                        modify_list.push_back(i * 100 + j);
                        continue;
                    }
                    if (check_modify(i + 1, j)) {
                        modify_list.push_back(i * 100 + j);
                        continue;
                    }
                    if (check_modify(i, j - 1)) {
                        modify_list.push_back(i * 100 + j);
                        continue;
                    }
                    if (check_modify(i, j + 1)) {
                        modify_list.push_back(i * 100 + j);
                    }
                }
            }
        }

        int modify_list_size = modify_list.size();
        if (modify_list_size <= 0) {
            loop = false;
        }
        else {
            loop_time++;
        }
        for (i = 0;i < modify_list_size;i++) {
            int a, b;
            a = modify_list[i] / 100;
            b = modify_list[i] % 100;
            space[a][b] = 1;
        }

        modify_list.clear();
    }

    std::cout << loop_time << std::endl;

    return 0;
}

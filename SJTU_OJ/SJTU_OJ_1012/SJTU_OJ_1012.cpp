#include <iostream>
#include <vector>

/*

Not Solved

*/

int S, T;
int * length;
int max_length = 0;


int get_max_length(int t)
{
    int j;
    for (j = t - 1;j >= 0;j--) {
        if (length[j] != 0) {
            break;
        }
    }
    return j + 1;
}


int get_next(int s, int depth)
{
    int i;
    if (T - s + depth + 1< max_length) {
        return 0;
    }

    std::vector<int> next_step;
    for (i = s + 1;i <= T;i++) {
        if (i * 100 % s == 0) {
            next_step.push_back(i);
        }
    }

    if (next_step.size() <= 0) {
        length[depth]++;
        max_length = get_max_length(T);
    }
    else {
        for (i = 0;i < next_step.size();i++) {
            get_next(next_step[i], depth + 1);
        }
    }
    return 0;
}

int main()
{
    std::cin >> S >> T;
    length = new int[T];

    int i;
    for (i = 0;i < T;i++) {
        length[i] = 0;
    }

    for (i = S;i <= T;i++) {
        int depth = 0;
        get_next(i, depth);
    }
    
    max_length = get_max_length(T);
    std::cout << max_length << std::endl;
    std::cout << length[max_length - 1] << std::endl;
}






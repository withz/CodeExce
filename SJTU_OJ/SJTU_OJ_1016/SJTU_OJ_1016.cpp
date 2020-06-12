#include <iostream>
#include <vector>

/*

Not Solved
Reason: comp & minus not suit
Example: 12121212 / 6565656

*/

std::vector<char> A;
int A_size;
std::vector<char> B;
int B_size;
std::vector<char> C;
int C_size;

void init()
{
    int i, j;
    char input = 0;
    while ((input = getchar()) != '\n') {
        A.push_back(input - '0');
    }
    input = 0;
    while ((input = getchar()) != '\n') {
        B.push_back(input - '0');
    }

    A_size = A.size();
    B_size = B.size();
    C_size = A_size;

    for (i = 0;i < A_size;i++) {
        C.push_back(0);
    }
}

int comp(int a, int b, int a_size, int b_size)
{
    int i;
    if (a_size < b_size) {
        return -1;
    }
    if (a_size > b_size) {
        return 1;
    }
    for (i = 0;i < a_size;i++) {
        if (A[a + i] > B[b + i]) {
            return 1;
        }
        if (A[a + i] < B[b + i]) {
            return -1;
        }
    }
    return 0;
}

void minus(int a, int b, int a_size, int b_size)
{
    int i;
    int remove = 0;

    for (i = 0;i < b_size;i++) {
        A[a + a_size - i - 1] -= B[b + b_size - i - 1] + remove;
        if (A[a + a_size - i - 1] < 0) {
            remove = (A[a + a_size - i - 1] + 20) / 10;
            A[a + a_size - i - 1] = (A[a + a_size - i - 1] + 10) % 10;
        }
        else {
            remove = 0;
        }
    }
    while (remove != 0) {
        A[a + a_size - i - 1] -= remove;
        if (A[a + a_size - i - 1] < 0) {
            remove = (A[a + a_size - i - 1] + 20) / 10;
            A[a + a_size - i - 1] = (A[a + a_size - i - 1] + 10) % 10;
        }
        else {
            remove = 0;
        }
        i--;
        if (a + a_size - i - 1 < a) {
            std::cout << "error" << std::endl;
            break;
        }
    }
}

int main()
{
    int i, j = 0;
    init();
    for (i = B_size - 1;i < A_size;i++) {
        int cp = 0;
        int flag = 0;
        while (cp >= 0) {
            cp = comp(i - B_size + 1 - j, 0, B_size + j, B_size);
            if (cp < 0) {
                flag = 1;
                break;
            }
            minus(i - B_size + 1 - j, 0, B_size + j, B_size);
            C[i]++;
        }
        if (flag == 1) {
            j = 1;
        }
        else {
            j = 0;
        }
    }
    
    i = 0;
    while (C[i] == 0) {
        i++;
    }
    for (;i < C_size;i++) {
        std::cout << (int)C[i];
    }
    std::cout << std::endl;
}

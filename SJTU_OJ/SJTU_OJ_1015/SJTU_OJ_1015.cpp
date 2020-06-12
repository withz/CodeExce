#include <iostream>
#include <vector>

std::vector<char> A;
std::vector<char> B;
std::vector<char> C;

int main()
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
    int A_size = A.size();
    int B_size = B.size();
    for (i = 0;i < A_size + B_size;i++) {
        C.push_back(0);
    }
    for (i = B_size - 1;i >= 0;i--) {
        int addin = 0;
        for (j = A_size - 1;j >= 0;j--) {
            int res = A[j] * B[i] + addin;
            int pos = A_size - j - 1 + B_size - i - 1;
            C[pos] += res;
            addin = C[pos] / 10;
            C[pos] = C[pos] % 10;
        }
        if (addin != 0) {
            C[A_size - j - 1 + B_size - i - 1] += addin;
        }
    }
    i = A_size + B_size - 1;
    while (C[i] == 0) {
        i--;
    }
    for (;i >= 0;i--) {
        std::cout << (int)C[i];
    }
    std::cout << std::endl;
}

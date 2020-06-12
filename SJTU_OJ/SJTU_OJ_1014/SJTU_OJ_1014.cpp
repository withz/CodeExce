#include <iostream>
#include <stack>

std::stack<char> A;
std::stack<char> B;
std::stack<char> C;

int main()
{
    int i;
    char input = '\0';
    while ((input = getchar()) != '\n') {
        A.push(input - '0');
    }
    input = '\0';
    while ((input = getchar()) != '\n') {
        B.push(input - '0');
    }
    int addin = 0;
    while (!A.empty() && !B.empty()) {
        int sum = A.top() + B.top() + addin;
        C.push(sum % 10);
        addin = sum / 10;
        A.pop();
        B.pop();
    }
    while (!A.empty()) {
        C.push(A.top() + addin);
        addin = 0;
        A.pop();
    }
    while (!B.empty()) {
        C.push(B.top() + addin);
        addin = 0;
        B.pop();
    }
    if (addin != 0) {
        C.push(addin);
    }
    while (!C.empty()) {
        std::cout << (int)C.top();
        C.pop();
    }
    std::cout << std::endl;
}


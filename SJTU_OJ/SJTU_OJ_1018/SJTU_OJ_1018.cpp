#include <iostream>
#include <stack>

int main()
{
    std::stack<int> add;

    int i = 0;
    int ch;
    while (std::cin >> ch) {
        i++;
        add.push(ch);

        if (i % 2 == 0) {
            int a, b;
            a = add.top();
            add.pop();
            b = add.top();
            add.pop();
            std::cout << a + b << std::endl;
        }
    }
}

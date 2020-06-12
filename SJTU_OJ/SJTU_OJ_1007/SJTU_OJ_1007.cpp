#include <iostream>
#include <stack>

int main()
{
    std::stack<int>  a;  // a + b = c
    std::stack<int>  b;
    std::stack<int>  c;

    char input;
    int i;

    bool remove_zero = true;
    while ((input = getchar()) != '\n') {
        if (input == '.') {
            continue;
        }
        if (remove_zero) {
            if (input <= '9' && input > '0') {
                a.push(input - '0');
                remove_zero = false;
            }
        }
        else {
            if (input <= '9' && input >= '0') {
                a.push(input - '0');
            }
        }
    }

    remove_zero = true;
    while ((input = getchar()) != '\n') {
        if (input == '.') {
            continue;
        }
        if (remove_zero) {
            if (input <= '9' && input > '0') {
                b.push(input - '0');
                remove_zero = false;
            }
        }
        else {
            if (input <= '9' && input >= '0') {
                b.push(input - '0');
            }
        }
    }
    
    int addin = 0;
    while (!(a.empty() || b.empty())) {
        int bit = a.top() + b.top() + addin;
        addin = bit / 10;
        bit = bit % 10;
        c.push(bit);
        a.pop();
        b.pop();
    }
    while (!a.empty()) {
        c.push(a.top() + addin);
        addin = 0;
        a.pop();
    }
    while (!b.empty()) {
        c.push(b.top() + addin);
        addin = 0;
        b.pop();
    }
    if (addin > 0) {
        c.push(addin);
    }

    int point_out = c.size();
    while (!c.empty()) {
        if (point_out == 2) {
            std::cout << '.';
            point_out--;
            continue;
        }
        std::cout << c.top();
        c.pop();
        point_out--;
    }
}

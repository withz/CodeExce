#include <iostream>
#include <stack>
#include <string>

int main()
{
    int N;
    std::cin >> N;

    
    int item, i;
    for (item = 0;item < N;item++) {
        std::stack<int> left;
        std::string chs;
        bool result = true;

        std::cin >> chs;

        for (i = 0;i < chs.length();i++) {
            if (chs[i] == '(') {
                left.push(1);
            }
            if (chs[i] == ')') {
                if (left.empty()) {
                    break;
                }
                else {
                    left.pop();
                }
            }
        }
        if (!left.empty()) {
            result = false;
        }
        if (i != chs.length()) {
            result = false;
        }


        if (result) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
}

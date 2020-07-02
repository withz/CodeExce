#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
        
    }
};

int main()
{
    double x = 2.1;
    int n = 3;

    Solution s;
    cout<<s.myPow(x, n)<<endl;
}

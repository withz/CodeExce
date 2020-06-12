#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long y = x;
        bool negative = false;
        if(y == 0){
            return 0;
        }
        if(y < 0){
            negative = true;
            y = -y;
        }

        do{
            int bit = y % 10;
            if(bit != 0){
                break;
            }
            y /= 10;
        }while(true);

        long long result = 0;
        while(true){
            result += y % 10;
            y /= 10;
            if(y <= 0){
                break;
            }
            result *= 10;
        }

        if(negative){
            result = -result;
        }

        if(result > 0x7FFFFFFF - 1 || 
        result < -0x7FFFFFFF){
            return 0;
        }
        return result;
    }
};

int main()
{
    Solution s;
    int r = s.reverse(-2147483648);
    cout << r << endl;
    return 0;
}

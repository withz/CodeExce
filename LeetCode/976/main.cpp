#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int largestPerimeter(vector<int>& A) {
        vector<int> nums(A);
        sort(nums.begin(), nums.end());

        int last = nums.size() - 1;
        while(last >= 2){
            if(isTrangle(nums[last - 2], nums[last - 1], nums[last])){
                return nums[last - 2] + nums[last - 1] + nums[last];
            }
            last--;
        }
        return 0;
    }
private:
    bool isTrangle(int x, int y, int z) {
        if(x + y <= z){
            return false;
        }else{
            return true;
        }
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    Solution solution;
    cout<<solution.largestPerimeter(nums)<<endl;

    return 0;
}
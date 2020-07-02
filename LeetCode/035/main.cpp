#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left, right, mid;
        left = 0;
        right = len - 1;
        mid = left + (right - left) / 2;
        while(right >= left){
            if(nums[mid] > target){
                right = mid - 1;
                mid = left + (right - left) / 2;
            }else if(nums[mid] < target){
                left = mid + 1;
                mid = left + (right - left) / 2;
            }else{
                return mid;
            }
        }
        return mid;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 5, 7};
    int target = 6;

    Solution solution;
    int result = solution.searchInsert(nums, target);

    cout<<result<<endl;
    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> result;
        int nums_len = nums.size();
        int i, j;
        for(i = 0; i < nums_len - 1; i++){
            for(j = i + 1; j < nums_len; j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
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
    vector<int> result = solution.twoSum(nums, 9);


    for(int i=0;i<result.size();i++){
        cout<<result[i];
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
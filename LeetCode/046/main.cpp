#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) {
            return result;
        }
        if(nums.size() == 1){
            vector<int> item = {nums[0]};
            result.push_back(item);
            return result;
        }
        int x = nums.at(nums.size() - 1);
        nums.pop_back();
        vector<vector<int>> sub_result = permute(nums);
        int i,j;
        for(i=0;i<sub_result.size();i++){
            for(j=0;j<=sub_result[i].size();j++){
                vector<int> cp(sub_result[i]);
                cp.insert(cp.begin() + j, 1, x);
                result.push_back(cp);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1,2,3};

    Solution s;
    vector<vector<int>> result = s.permute(nums);
    int i,j;
    for(i=0;i<result.size();i++){
        for(j=0;j<result[i].size();j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result, sub_result;
        if(nums.size() == 0){
            return result;
        }
        vector<int> empty;
        result.push_back(empty);
        int n = nums.size();

        this->dp = new vector<vector<int>>**[n];
        for(int i=0;i<n;i++){
            this->dp[i] = new vector<vector<int>>*[n];
            for(int j=0;j<n;j++){
                this->dp[i][j] = nullptr;
            }
        }

        sort(nums.begin(), nums.end());
        sub_result = this->core(nums, 0, n - 1);
        sub_result.push_back(empty);
        result = sub_result;
        return result;
    }
private:
    vector<vector<int>> ***dp;
    vector<vector<int>> *core(vector<int>& nums, int x, int y){
        if(this->dp[x][y] != nullptr){
            return (this->dp[x][y]);
        }
        vector<vector<int>> *result, *sub_result;
        result = new vector<vector<int>>;
        if(x == y){
            vector<int> *item = new vector<int> ({nums[x]});
            result->push_back(*item);
            return result;
        }
        if(x > y){
            return nullptr;
        }
        sub_result = this->core(nums, x, y - 1);
        for(int i=0;i<sub_result->size();i++){
            result->push_back(sub_result->at(i));
        }
        for(int i=0;i<sub_result->size();i++){
            vector<int> *temp = new vector<int>(sub_result->at(i));
            temp->push_back(nums[y]);
            result->push_back(*temp);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,10,0};

    Solution solution;
    vector<vector<int>> result = solution.subsetsWithDup(nums);

    int i,j;
    for(i=0;i<result.size();i++){
        for(j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> A(nums);
        sort(A.begin(), A.end());
        int sum = A[0] + A[1] + A[2];
        int a, b, c;
        int n = A.size();
        int near = abs(sum - target);
        int result = sum;
        for(a=0;a<n-2;a++){
            b=a+1;
            c=n-1;
            while(b<c){
                sum=A[a]+A[b]+A[c];
                if(near > abs(sum - target)){
                    near = abs(sum - target);
                    result = sum;
                }
                if(sum>target){
                    c--;
                }else if(sum<target){
                    b++;
                }else{
                    return sum;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {0,1,2,-3};
    int target = 1;

    Solution solution;
    cout<<solution.threeSumClosest(nums, target)<<endl;

    return 0;
}
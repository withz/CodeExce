#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1; 
        vector<int> B = nums2; 
        if(B.size() < A.size()){
            vector<int> temp = A;
            A = B;
            B = temp;
        }

        int m = A.size();
        int n = B.size();
        int half_part = (m + n + 1) / 2; 
        int i, j, low, high;
        i = j = low = 0;
        high = m;

        while(low <= high){
            i = (low + high) / 2;
            j = half_part - i;

            if(i < high && B[j - 1] > A[i]){
                low = i + 1;
            }
            else if(i > low && B[j] < A[i - 1]){
                high = i - 1;
            }
            else{
                int left_part_max = 0;
                if(i == 0){
                    left_part_max = B[j - 1];
                }
                else if(j == 0){
                    left_part_max = A[i - 1];
                }
                else{
                    left_part_max = std::max(B[j - 1], A[i - 1]);
                }
                if((m + n) % 2 == 1){
                    return left_part_max;
                }

                int right_part_min = 0;
                if(i == m){
                    right_part_min = B[j];
                }
                else if(j == n){
                    right_part_min = A[i];
                }else{
                    right_part_min = std::min(B[j], A[i]);
                }
                return (left_part_max + right_part_min) / 2.0;
            }
        }
        return 0.0;
    }
};

int main()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    // nums1.push_back(6);
    // nums1.push_back(8);
    // nums1.push_back(15);

    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(4);
    // nums2.push_back(3);
    // nums2.push_back(7);
    // nums2.push_back(9);

    Solution solution;
    double result = solution.findMedianSortedArrays(nums1, nums2);

    cout << result << endl;
    return 0;
}


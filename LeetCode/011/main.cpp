#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;

        int i, j;
        i = 0; j = height.size() - 1;
        while(i < j){
            int area = 0;
            int dx = j - i;
            if(height[i] <= height[j]){
                area = dx * height[i];
                max_area = std::max(max_area, area);
                i++;
            }else {
                area = dx * height[j];
                max_area = std::max(max_area, area);
                j--;
            }
        }

        return max_area;
    }
};


// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int max_area = 0;

//         int i, j;
//         for(i = 0; i < height.size() - 1; i++){
//             for(j = i + 1; j < height.size(); j++){
//                 int area = 0;
//                 int dx = j - i;
//                 int y = std::min(height[i], height[j]);
//                 area = dx * y;
//                 if(max_area < area){
//                     max_area = area;
//                 }
//             }
//         }

//         return max_area;
//     }
// };

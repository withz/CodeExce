#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i;
        int max_value = -1;
        int max_pos = 0;

        for (i = 0;i < height.size();i++) {
            int temp = height[i];
            if (max_value < temp) {
                max_value = temp;
                max_pos = i;
            }
        }

        int water = 0;
        int last_num = 0;
        for (i = 0;i < max_pos;i++) {
            if (last_num < height[i]) {
                last_num = height[i];
            }
            water += last_num - height[i];
        }

        last_num = 0;
        for (i = height.size() - 1;i > max_pos;i--) {
            if (last_num < height[i]) {
                last_num = height[i];
            }
            water += last_num - height[i];
        }
        
        return water;
    }
};


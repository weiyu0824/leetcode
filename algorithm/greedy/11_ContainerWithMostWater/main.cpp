#include <vector>
/*
* greedy, array
* complexity = O(n)
*/
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_ptr = 0;
        int right_ptr = height.size() - 1;
        int max_area = -1;
        int area;
        while (left_ptr < right_ptr){
            area = (right_ptr - left_ptr) * min(height[left_ptr], height[right_ptr]);
            if (area > max_area) 
                max_area = area;
            if (height[left_ptr] < height[right_ptr])
                left_ptr ++;
            else
                right_ptr --;
        }
        return max_area;
    }
};
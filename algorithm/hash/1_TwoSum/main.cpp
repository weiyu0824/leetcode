#include <iostream>
#include <vector>
#include <unordered_map>
/*
tags: Array & Hash Map
note: Instread of using brute force which check all of the combination O(n^2),
    using hash map can acheive only O(n) in time complexity. 
    Remember to use "unordered_map", which is implemented based on hash map.
*/
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> indices;
        
        int complement;
        unordered_map<int, int>::iterator iter;
        for (int i=0; i<nums.size(); i++){
            complement = target - nums[i];
            iter = indices.find(complement);
            if (iter != indices.end()) {
                ans.push_back(i);
                ans.push_back((iter->second));
            }
            indices[nums[i]] = i;
        }
        return ans;
    }
};
int main(){
    Solution solution;
    int target = 6;
    vector<int> nums {3,2,4};
    vector<int> ans;
    ans = solution.twoSum(nums, target);
    for(int n : ans){
        cout << n << " ";
    }
}
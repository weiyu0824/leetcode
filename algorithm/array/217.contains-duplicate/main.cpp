#include<unordered_set>
#include<vector>
/*
* array, hashmap
* time = o(n), 這題要注意 for loop 傳 reference 跟 int 速度會差很多。
*/
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int &num : nums){
            if (num_set.find(num) == num_set.end()){
                num_set.insert(num);
            }else {
                return true;
            }
        }
        return false;
    }
};
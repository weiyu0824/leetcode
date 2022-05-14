#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        int num_of_node = 1;
        TreeNode* cur_node;
        while (!q.empty()){
            
            int num_of_node_next = 0;
            vector<int> node_in_same_level;
            while (num_of_node > 0){
                cur_node = q.front();
                q.pop();
                
                if (cur_node -> left != nullptr){
                    q.push(cur_node -> left);
                    num_of_node_next ++;
                }
                if (cur_node -> right != nullptr){
                    q.push(cur_node -> right);
                    num_of_node_next ++;
                }
                node_in_same_level.push_back(cur_node -> val);
                num_of_node --;
            }
            num_of_node = num_of_node_next;
            res.push_back(node_in_same_level);
        }
        
        return res;
    }
};
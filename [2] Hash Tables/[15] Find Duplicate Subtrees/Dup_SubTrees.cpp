#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<Treenode*> findDuplicateSubTrees(Treenode* root){


}

int main(){
    TreeNode root = {2,2,2,3,null,3,null} 
    //Output = [[2,3],[3]]
    return 0;
}

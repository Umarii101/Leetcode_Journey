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

std::vector<TreeNode*> findDuplicateSubTrees(TreeNode* root){
    std::vector<TreeNode*> Result;

    return Result;

}

int main(){
                                                                TreeNode* root = new TreeNode(1);
                                        TreeNode* n2 = new TreeNode(2);             TreeNode* n3 = new TreeNode(3);     
         TreeNode* n4 = new TreeNode(4);                                        TreeNode* n5 = new TreeNode(2);  TreeNode* n7 = new TreeNode(4);   
                                                                            TreeNode* n6 = new TreeNode(4);
    

    n3->right = n7;
    n5->left = n6;
    n3->left = n5;
    n2->left = n4;
    root->left = n2;
    root->right = n3;

    //The Tree has been Created. Lets Verify it.
    std::cout<<root->left->left->val<<std::endl;

    std::cout<<root->right->left->left->val<<std::endl;


    //{2,2,2,3,null,3,null} 
    //Output = [[2,3],[3]]
    return 0;
}

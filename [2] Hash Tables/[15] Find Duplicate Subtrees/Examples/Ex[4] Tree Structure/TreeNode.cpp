#include <iostream>

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr){} //Constructor To make sure we initialize our Tree with a value x and the left right pointing to Nullptr.
           
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    std::cout<<root->value<<std::endl;

    std::cout<<root->left->value<<std::endl;

    std::cout<<root->right->value<<std::endl;

    return 0;
}

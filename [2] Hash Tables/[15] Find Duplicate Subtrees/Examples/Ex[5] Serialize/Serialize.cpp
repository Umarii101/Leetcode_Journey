#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){} //Constructor To make sure we initialize our Tree with a val x and the left right pointing to Nullptr.
           
};

std::string Serialize(TreeNode* node){
    // 1. Base Case: If the node is null, return a placeholder character
    if(node == nullptr){
        return "#";
    }
    // 2. Recursively get the strings for left and right subtrees
    std::string leftPath  = Serialize(node->left);
    std::string rightPath = Serialize(node->right);
    // 3. Create the "Fingerprint" for the current subtree
    // We use commas to separate vals so '1' and '11' don't become '111'
    std::string subTreeSerialized = std::to_string(node->val) + "," + leftPath + "," + rightPath;
    std::cout<<subTreeSerialized<<std::endl;
    return subTreeSerialized;
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

    
    std::string Result = Serialize(root);
    return 0;
}

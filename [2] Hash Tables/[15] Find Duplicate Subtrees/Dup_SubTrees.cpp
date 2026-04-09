#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::string Serialize(TreeNode* node, std::unordered_map<std::string,int> counts, std::vector<TreeNode*>& Result){
    // 1. Base Case: If the node is null, return a placeholder character
    if(node == nullptr){
        return "#";
    }

    // 2. Recursively get the strings for left and right subtrees
    std::string leftPath  = Serialize(node->left,counts,Result);
    std::string rightPath = Serialize(node->right,counts,Result);

    // 3. Create the "Fingerprint" for the current subtree
    // We use commas to separate vals so '1' and '11' don't become '111'
    std::string subTreeSerialized = std::to_string(node->val) + "," + leftPath + "," + rightPath;
    //std::cout<<subTreeSerialized<<std::endl;
    
    // 4. Now Let me just Store the Subtree Occurence in our Map.
    counts[subTreeSerialized]++;

    // 5. Two Trees are duplicates when they have the same Structure and same node Values.
    if(counts[subTreeSerialized] == 2){
        Result.push_back(node);
    }

    return subTreeSerialized;
}

std::vector<TreeNode*> findDuplicateSubTrees(TreeNode* root){
    std::vector<TreeNode*> Result;
    std::unordered_map<std::string, int> counts;
    //Lets Call The serializing Function,
    Serialize(root,counts,Result);

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

    std::vector<TreeNode*> Result = findDuplicateSubTrees(root);
    //{2,2,2,3,null,3,null} 
    //Output = [[2,3],[3]]
    return 0;
}

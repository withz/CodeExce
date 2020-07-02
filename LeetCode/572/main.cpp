#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution{
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr){
            return true;
        }
        if(s == nullptr || t == nullptr){
            return false;
        }

        if(equalSubTree(s, t)){
            return true;
        }else{
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
private:
    bool equalSubTree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr){
            return true;
        }
        if(s == nullptr || t == nullptr){
            return false;
        }

        if(s->val == t->val){
            return equalSubTree(s->left, t->left) && equalSubTree(s->right, t->right);
        }
        return false;
    }
};

int main()
{
    TreeNode tree(3);
    tree.left = new TreeNode(4);
    tree.right = new TreeNode(5);
    tree.left->left = new TreeNode(1);
    tree.left->right = new TreeNode(2);
    // tree.left->right->left = new TreeNode(0);

    TreeNode subtree(4);
    subtree.left = new TreeNode(1);
    subtree.right = new TreeNode(2);

    // TreeNode tree(1);
    // tree.left = new TreeNode(1);

    // TreeNode subtree(1);

    Solution s;
    cout<<s.isSubtree(&tree, &subtree)<<endl;

    return 0;
}
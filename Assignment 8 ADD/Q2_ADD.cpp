#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generate(int start, int end) {
    vector<TreeNode*> allTrees;
    if (start > end) {
        allTrees.push_back(NULL);
        return allTrees;
    }

    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftTrees = generate(start, i - 1);
        vector<TreeNode*> rightTrees = generate(i + 1, end);

        for (int j = 0; j < leftTrees.size(); j++) {
            for (int k = 0; k < rightTrees.size(); k++) {
                TreeNode* root = new TreeNode(i);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> result;
    if (n == 0) return result;
    return generate(1, n);
}

void printPreorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> trees = generateTrees(n);
    for (int i = 0; i < trees.size(); i++) {
        printPreorder(trees[i]);
        cout << endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    TreeNode* tree;
    unordered_set<int> values;

    FindElements(TreeNode* root) {
        tree = new TreeNode;
        values.insert(0);

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({ root, tree });
        while (!q.empty())
        {
            auto p = q.front(); q.pop();
            TreeNode* src = p.first;
            TreeNode* dst = p.second;

            TreeNode* left = src->left;
            if (left) {
                TreeNode* cl = new TreeNode(dst->val * 2 + 1);
                values.insert(cl->val);
                q.push({ left, cl });
            }

            TreeNode* right = src->right;
            if (right) {
                TreeNode* cr = new TreeNode(dst->val * 2 + 2);
                values.insert(cr->val);
                q.push({ right, cr });
            }
        }
    }

    bool find(int target) {
        return values.count(target);
    }
};

int main()
{
    return 0;
}

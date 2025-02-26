
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int n;
    vector<int> pres, posts;
    vector<bool> visited;
    unordered_map<int, int> postIdx;
    unordered_map<int, int> preIdx;

    TreeNode* construct(int preStart, int preEnd, int postStart, int postEnd) {
        TreeNode* rs = new TreeNode(pres[preStart]);
        visited[pres[preStart]] = true;
        cout << " > build tree with root " << rs->val << " (" << preStart << "," << preEnd << "," << postStart << "," << postEnd << ")" << endl;

        // build left sub tree
        int leftValue = pres[preStart + 1];
        if (preStart + 1 == preEnd) {
            cout << "   > make left node " << leftValue << " for parent " << rs->val << endl;
            TreeNode* left = new TreeNode(leftValue);
            rs->left = left;
            visited[leftValue] = true;
            return rs;
        }

        int idxInPost = postIdx[leftValue];
        int leftLength = idxInPost - postStart;
        if (leftLength == 0) {
            cout << "   > make left node " << leftValue << " for parent " << rs->val << endl;
            TreeNode* left = new TreeNode(leftValue);
            visited[leftValue] = true;
            rs->left = left;
        }
        else {
            cout << "   > CONSTRUCT left node " << leftValue << " for parent " << rs->val << endl;
            TreeNode* left = construct(preStart + 1, preStart + 1 + leftLength, postStart, idxInPost);
            rs->left = left;
        }


        // build right sub tree
        int rightValue = posts[postEnd - 1];
        if (visited[rightValue])
            return rs;

        cout << "   > CONSTRUCT right node" << endl;
        TreeNode* right = construct(preStart + 1 + leftLength + 1, preEnd, idxInPost + 1, postEnd - 1);
        rs->right = right;

        return rs;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty())
            return NULL;
;
        n = preorder.size();
        if (n == 1)
            return new TreeNode(preorder[0]);

        pres = preorder;
        posts = postorder;

        for (int i = 0; i < n; i++)
        {
            preIdx[preorder[i]] = i;
            postIdx[postorder[i]] = i;
        }

        visited = vector<bool>(n+1, false);
        TreeNode* rs = construct(0, n-1, 0, n-1);

        return rs;
    }
};

int main()
{
    Solution sln;
    vector<int> preorder({ 1,2,4,5,3,6,7 });
    vector<int> postorder({ 4,5,2,6,7,3,1 });
    sln.constructFromPrePost(preorder, postorder);
    //cout << sln << endl;

    return 0;
}

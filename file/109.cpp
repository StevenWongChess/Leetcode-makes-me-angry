/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *dfs(ListNode *&head, int n)
    {
        if (n < 1)
            return nullptr;
        TreeNode *root = new TreeNode;
        root->left = dfs(head, (n - 1) - (n - 1) / 2);
        root->val = head->val;
        head = head->next;
        root->right = dfs(head, (n - 1) / 2);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        ListNode *it = head;
        int n = 0;
        while (it)
        {
            n++;
            it = it->next;
        }
        return dfs(head, n);
    }
};
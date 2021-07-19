#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    
public:
    Solution();
    ~Solution();
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);  // 04二维数组中找值
    string replaceSpace(string s);                                      // 05替换空格
    vector<int> reversePrint(ListNode* head);                           // 06反向打印链表
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);   // 07建立二叉树
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right);
private:
    unordered_map<int, int> index;

};



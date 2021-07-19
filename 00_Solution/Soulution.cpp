#include "Solution.h"

Solution::Solution()
{
}

Solution::~Solution()
{
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i) {
        index[inorder[i]] = i;
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
}
TreeNode* Solution::myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
    //-------------------------------1.递归终止条件-------------------------------//
    if (preorder_left > preorder_right) {
        return nullptr;
    }
    
    //-------------------------------2.此次递归要做什么-------------------------------//
    // 前序遍历中的第一个节点就是根节点
    int preorder_root = preorder_left;
    // 在中序遍历中定位根节点
    int inorder_root = index[preorder[preorder_root]];
    
    // 先把根节点建立出来
    TreeNode* root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
    root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    //-------------------------------3.递归返回值-------------------------------//
    return root;
}

vector<int> Solution::reversePrint(ListNode* head) {
    vector<int> tmp;    // 作为栈使用
    vector<int> ret;    // 返回值
    // 链表为空时
    if (head == nullptr) return ret;

    while(head != nullptr) {
        tmp.push_back(head->val);
        head = head->next;
    }
    while(!tmp.empty()){
        ret.push_back(tmp.back());
        tmp.pop_back();
    }

    return ret;
}


string Solution::replaceSpace(string s)
{
    int originLength = s.size();    // s.size()同s.length()
    int newLength = 0;
    int numBlank = 0;

    if (originLength == 0) return s;
    // 计算空格数量
    for (int i = 0; i < originLength; i++) {
        if(s[i] == ' ') {
            numBlank++;
        }
    }

    newLength = originLength + 2 * numBlank;            // 新字符串长度
    string str_patch(newLength - originLength, 'a');    // 在原字符串后面扩充的内存
    s += str_patch;                                     // 得到扩容后的新字符串

    int pOrigin = originLength - 1;                     // 原字符串最后一个字符位置下标 
    int pNew = newLength - 1;                           // 新字符串最后一个字符位置下标
    while (pOrigin >= 0 && pOrigin < pNew)
    {
        if (s[pOrigin] == ' ') {
            s[pNew--] = '0';
            s[pNew--] = '2';
            s[pNew--] = '%';  
        }
        else {
            s[pNew--] = s[pOrigin];
        }
        pOrigin--;
    }
    
    return s;
}

bool Solution::findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
    bool found = false;
    if (matrix.empty()) return found;
    int rows = matrix.size();
    int columns = matrix[0].size();

    int row = 0;
    int column = columns - 1;
    if (rows > 0 && columns > 0) {
        while (row < rows && column >= 0) {
            if (matrix[row][column] == target){
                found = true;
                break;
            }
            else if (matrix[row][column] > target)
                column--;
            else
                row++;
        }
    }

    return found;
}
#include "Solution.h"

Solution::Solution()
{
}

Solution::~Solution()
{
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
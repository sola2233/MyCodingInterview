#include "Solution.h"

ListNode* CreateList();

int main(int argc, char* argv[])
{
    Solution leetcode;

    ListNode* head = CreateList();

    vector<int> a = leetcode.reversePrint(head);

    for(auto i : a){
        cout << i << endl;
    }

    return 0;
}

// 1->2->3->4->5
ListNode* CreateList()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    pNode1->next = pNode2;
    pNode2->next = pNode3;
    pNode3->next = pNode4;
    pNode4->next = pNode5;
    pNode5->next = nullptr;

    return pNode1;
}
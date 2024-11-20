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

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
//  构造函数
    Solution()
    {
        myglobal = 0;
    }


    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        return mydelete(head, n);
    }

    // 两个基础情况要不就是删除 传递下一个 要不就是保留下来。

    ListNode *mydelete(ListNode *head, int n)
    {

        if (head == nullptr)
        {
            myglobal++;
            return nullptr;
        }
        head->next = mydelete(head->next, n);
        if (myglobal == n)
        {
            myglobal++;
            return head->next;
        }
        myglobal++;
        return head;
    }
    private:
    int myglobal;
};

// 打印链表
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // 创建生成有4个节点的链表
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    printList(head);
    Solution * solution = new Solution();
    head = solution->removeNthFromEnd(head,3);
    printList(head);


    
    return 0;
}
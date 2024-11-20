

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head;                // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode *cur = dummyHead;
        while (!(cur->next == nullptr || cur->next->next == nullptr)) //结束条件是cur的下一个节点和下下一个节点都不为空
        {  //只要任意一种情况都要结束循环 1. cur的下一个节点为空 2. cur的下下一个节点为空cur->next != nullptr && cur->next->next != nullptr


            ListNode *tmp = cur->next;              // 记录临时节点
            ListNode *tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;  // 步骤一
            cur->next->next = tmp;        // 步骤二
            cur->next->next->next = tmp1; // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

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
    // ListNode *node4 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    // node3->next = node4;

    printList(head);
    Solution *solution = new Solution();

    head = solution->swapPairs(head);
    printList(head);
}
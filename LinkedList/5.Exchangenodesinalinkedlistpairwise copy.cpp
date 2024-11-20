

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
        int size = 0;
        ListNode *tmp = head;
        ListNode *rehead = nullptr;

        while (tmp != nullptr)
        {
            size++;
            tmp = tmp->next;
        }
        printf("size = %d\n", size);

        if (size % 2 == 0)
        {
            if (head == nullptr)
            {
                return rehead;
            }

            else
            {

                ListNode *pre = head;
                ListNode *cur;
                ListNode *temp;

                rehead = pre->next;
                while (pre != nullptr)
                { // 做法要一致循环才好用

                    cur = pre->next;    
                    temp = cur->next;

                    cur->next = pre;   //指向前面


                    if (temp != nullptr) // 后面还有要交换 temp2 始终指向交换的后面的节点
                    {
                        pre->next = temp->next;
                    }
                    else
                    {
                        pre->next = temp;
                    }

                    pre = temp;  //更新节点
                }

                return rehead;
            }
        }

        else
        {
            if (head->next == nullptr)
            {
                return rehead = head;
            }

            else
            {

                ListNode *pre = head;
                ListNode *cur;
                ListNode *temp;

                rehead = pre->next;
                while (pre->next != nullptr)
                { // 做法要一致循环才好用

                    cur = pre->next;    
                    temp = cur->next;

                    cur->next = pre;   //指向前面


                    if (temp->next != nullptr) // 后面还有要交换 temp2 始终指向交换的后面的节点
                    {
                        pre->next = temp->next;
                    }
                    else
                    {
                        pre->next = temp;
                    }

                    pre = temp;  //更新节点
                }

                return rehead;
            }
        }
    }
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main()
{

    // 创建生成有4个节点的链表
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    // 
    ListNode *node4 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printList(head);
    printf("\n");

    Solution s;
    ListNode *result = s.swapPairs(head);
    printList(result);
}
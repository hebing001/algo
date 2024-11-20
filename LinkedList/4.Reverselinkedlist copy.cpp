

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *fake_rehead = new ListNode(0);
        // 循环取出来就行了
        while (head != nullptr)
        {
            ListNode *tmp = head;
            ListNode *newnode = new ListNode(head->val);
            newnode->next = fake_rehead->next;
            fake_rehead->next = newnode;

            head = head->next;
            delete tmp;
        }

        return fake_rehead->next;
    }

    //    试一下双指针的方法
    ListNode *reverseList2(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *tmp = nullptr;

        while (cur != nullptr)
        {
            tmp = cur->next; // 先记录下来后面的信息避免找不到

            cur->next = pre;

            pre = cur; // 向前一步
            cur = tmp;
        }
        return pre;
    }

    //   试一下递归的方法
    ListNode *reverseList3(ListNode *head)
    {

        // if (head == nullptr) // 基础情况
        // {
        //     return nullptr;
        // }
    }
    void printLinkedList(ListNode *head)
    {
        ListNode *cur = head;
        while (cur != nullptr)
        {
            printf("%d ", cur->val);
            cur = cur->next;
        }
        printf("\n");
    }
};

int main()
{
    // 创建一个新的链表
    ListNode *head = new ListNode(1);
    for (int i = 2; i < 6; i++)
    {
        ListNode *node = new ListNode(i);
        node->next = head->next;
        head->next = node;
    }

    // 打印链表
    Solution().printLinkedList(head);

    // 反转链表
    ListNode *newHead = Solution().reverseList2(head);
    if(newHead == nullptr)
    {
        printf("newHead is nullptr \n");
    }

    // 打印反转后的链表
    Solution().printLinkedList(newHead);
}
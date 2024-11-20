

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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head;                // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode *cur = dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }

    ListNode *removeElements2(ListNode *head, int val)
    {
        // 删除头结点
        while (head != NULL && head->val == val)
        { // 注意这里不是if
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        // 收缩情况了

        // 删除非头结点
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
    ListNode *removeElements3(ListNode *head, int val)
    {
        // 基础情况：空链表
        if (head == nullptr)
        {
            return nullptr;
        }

        // 递归处理
        if (head->val == val)
        {
            ListNode *newHead = removeElements3(head->next, val); // 递归处理下一个节点
            delete head;
            return newHead; // 返回下一个节点
        }
        else
        {
            head->next = removeElements3(head->next, val); // 递归处理下一个节点
            return head; // 返回当前节点
        }
    }
};

ListNode *createLinkedList(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;

    // 创建链表的头节点
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    // 循环创建并链接剩余节点
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

std::vector<int> values = {1};
ListNode *head = createLinkedList(values);

int main()
{
    int target = 6;
    Solution s;
    ListNode *res = s.removeElements3(head, target); //把head 返回回去了
    // 输出链表
    while (res != NULL)
    {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}
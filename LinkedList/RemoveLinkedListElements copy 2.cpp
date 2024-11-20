

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
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
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
        // 删除头结点
        while (head != NULL && head->val == val)
        { // 注意这里不是if
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        // 收缩情况了

        if (head == NULL)
        {
            return head;
        }

        // 删除非头结点
        ListNode *cur = head;
        while ( cur->next != NULL)
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

std::vector<int> values = {1, 2, 6, 3, 4, 5, 6};
ListNode *head = createLinkedList(values);

int main()
{

    int target = 6;
    Solution s;
    ListNode *res = s.removeElements(head, target);
    // 输出链表
    while (res != NULL)
    {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}
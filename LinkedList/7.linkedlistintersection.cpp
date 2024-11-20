#include <iostream>
#include <vector>

// 定义链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 创建链表并返回头节点
ListNode *createLinkedList(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// 打印链表
void printLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 创建相交链表
std::pair<ListNode *, ListNode *> createIntersectedLinkedLists(const std::vector<int> &listA, const std::vector<int> &listB, int skipA, int skipB)
{
    ListNode *headA = createLinkedList(listA);
    ListNode *headB = createLinkedList(listB);

    ListNode *currentA = headA;
    ListNode *currentB = headB;

    // 移动到指定的skipA位置
    for (int i = 0; i < skipA; ++i)
    {
        currentA = currentA->next;
    }

    // 移动到指定的skipB位置
    for (int i = 0; i < skipB; ++i)
    {
        currentB = currentB->next;
    }

    // 使链表B的skipB位置与链表A的skipA位置相交
    currentB->next = currentA;

    return {headA, headB};
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL)
        { // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL)
        { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度 合并后面操作 比较好
        if (lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--)
        {
            curA = curA->next;
        }
        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL)
        {
            if (curA == curB)
            {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};

int main()
{
    std::vector<int> listA = {4, 1, 8, 4, 5};
    std::vector<int> listB = {5, 0, 1, 8, 4, 5};
    int skipA = 2;
    int skipB = 3;

    auto [headA, headB] = createIntersectedLinkedLists(listA, listB, skipA, skipB);

    std::cout << "List A: ";
    printLinkedList(headA);
    std::cout << "List B: ";
    printLinkedList(headB);

    ListNode *Intersect = Solution().getIntersectionNode(headB, headA);

    printLinkedList(Intersect);

    return 0;
}
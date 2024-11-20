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
        // 先一起长
        int lenthA = 0;
        int lenathB = 0;
        ListNode *headtempA = headA;
        ListNode *headtempB = headB;

        while (headtempA != nullptr)
        {
            lenthA++;
            headtempA = headtempA->next;
        }

        while (headtempB != nullptr)
        {
            lenathB++;
            headtempB = headtempB->next;
        }

        headtempA = headA;
        headtempB = headB;

        int size = lenthA - lenathB;

        if (size >= 0)
        {
            while (size--)
            {
                headtempA = headtempA->next;
            }

            while (headtempA != headtempB)
            {
                headtempA = headtempA->next;
                headtempB = headtempB->next;

                if (headtempA == nullptr)
                {
                    return nullptr;
                }
            }

            return headtempA;
        }
        else
        {
            size = abs(size);

            while (size--)
            {
                headtempB = headtempB->next;
            }

            while (headtempA != headtempB)
            {
                headtempA = headtempA->next;
                headtempB = headtempB->next;

                if (headtempA == nullptr)
                {
                    return nullptr;
                }
            }

            return headtempA;
        }
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
    {
        // 长度
        int lenthA = 0;
        int lenathB = 0;

        // 来回走
        ListNode *headtempA = headA;
        ListNode *headtempB = headB;
        // 来回走
        ListNode *walkA = headA;
        ListNode *walkB = headB;

        while (headtempA != nullptr)
        {
            lenthA++;
            headtempA = headtempA->next;
        }

        while (headtempB != nullptr)
        {
            lenathB++;
            headtempB = headtempB->next;
        }

        headtempA = headA;
        headtempB = headB;

        int size = lenathB + lenthA;

        while (size--)
        {
            if (headtempA == headtempB)
            {
                return headtempA;
            }
            // 后面就是更新节点    感觉有点奇奇怪怪的感觉
            if (headtempA == nullptr)
            {
                headtempA = headB;
            }
            else
            {
                headtempA = headtempA->next;
                if (headtempA == nullptr)
                {
                    headtempA = headB;
                }
            }

            if (headtempB == nullptr)
            {
                headtempB = headA;
            }
            else
            {
                headtempB = headtempB->next;
                if (headtempB == nullptr)
                {
                    headtempB = headA;
                }
            }
        }

        return nullptr;
    }

    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB)
    {
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

    ListNode *Intersect = Solution().getIntersectionNode2(headB, headA);

    printLinkedList(Intersect);

    return 0;
}
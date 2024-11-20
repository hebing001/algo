#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
// 定义链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 定义ListNode排序大小
bool operator<(const ListNode &a, const ListNode &b)
{
    return a.val < b.val;
}

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // 检测环
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // 找到环的起始节点
                ListNode *ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }

        return nullptr; // 无环
    }

    ListNode *detectCycle2(ListNode *head)
    {
        // 创建一个 unordered_map，键为字符串，值为整数
        std::unordered_map<ListNode *, int> hashMap;
        ListNode *temp = head;
        int value = 0;
        while (temp != nullptr)
        {
            auto it = hashMap.find(temp);
            if (it == hashMap.end())
            {
                // 键不存在，插入键值对
                hashMap[temp] = value++;
            }
            else
            {
                // 键存在，弹出该值并返回
                ListNode *existingValue = it->first;

                return existingValue;
            }
            temp = temp->next;
        }

        return nullptr;
    }

    ListNode *detectCycle3(ListNode *head) {
        set<ListNode*> visited;  // 使用set记录访问过的节点

        ListNode* current = head;
        while (current != nullptr) {
            // 如果当前节点已经在set中，说明找到环的入口节点
            if (visited.count(current)) {
                return current;
            }

            // 否则将当前节点加入set    
            visited.insert(current);

            // 移动到下一个节点
            current = current->next;
        }

        // 如果遍历完链表没有发现环，返回nullptr
        return nullptr;
    }
};

// 辅助函数：创建链表并返回头节点
ListNode *createLinkedList(const std::vector<int> &values, int pos)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    ListNode *cycleNode = nullptr;

    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (i == pos)
        {
            cycleNode = current;
        }
    }

    if (pos != -1)
    {
        current->next = cycleNode;
    }

    return head;
}

int main()
{
    std::vector<int> values = {3, 2, 0, -4};
    int pos = 1; // 环的起始位置

    ListNode *head = createLinkedList(values, pos);

    Solution solution;
    ListNode *cycleStart = solution.detectCycle3(head);

    if (cycleStart)
    {
        std::cout << "Cycle starts at node with value: " << cycleStart->val << std::endl;
    }
    else
    {
        std::cout << "No cycle detected" << std::endl;
    }

    return 0;
}
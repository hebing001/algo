

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

    // 我就是TM的想不到递归的方法，这个递归的方法真的是太妙了
    // 递归的方法，其实就是从后往前，每次都是把当前节点的next指向前一个节点

    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;  // 递归的终止条件 基准条件
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);  // 这里的cur就是pre，temp就是cur
    }
    ListNode* reverseList2(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head); // 这里的NULL就是pre    
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

    // 打印反转后的链表
    Solution().printLinkedList(newHead);
}
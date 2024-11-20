

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
        // 处理头节点
        // 如果用if的话肯定不行
        do
        {
            if (head == NULL)
            {
                return NULL;
            }
            else if (head->val == val)
            {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
                continue;
            }

            // head 不为空而且值 不与 要找的数相等就到这里了  是不是头就确定了
            // 改进

        while(head == NULL || head->val == val  )
        {
            if(head == NULL)
            {
                return NULL;
            }

            else
            {
                head = head->next;
            }
            
        }



            // 头为空 还有头为相等的都被删除了
            break;

        } while (1);

        // 接着处理接下来的数据
        ListNode *tmp =head;
        while (tmp->next != NULL) //结束到尾巴了
        {
            if(tmp->next->val !=val)
            {
                tmp=tmp->next;
            }
            else 
            {
                ListNode *tmp2 =tmp->next;
                tmp->next = tmp->next->next;
                delete tmp2;


            }
           
        }

        return head;
    
        
    }
    // 解法2
    // 就是设置一个虚拟节点多好
        ListNode *removeElements2(ListNode *head, int val)
        {
            ListNode * fakenode = new ListNode();
            fakenode->next = head;

            ListNode *tmp = fakenode;

            while (tmp->next != NULL)
            {
                if (tmp->next->val != val)
                {
                    tmp = tmp->next;
                }
                else
                {
                        ListNode *tmp2 = tmp->next;
                        tmp->next = tmp->next->next;
                        delete tmp2;
                }
                
            }
            return fakenode->next;

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
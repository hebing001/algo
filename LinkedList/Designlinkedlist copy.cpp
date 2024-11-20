#include <stdio.h>

class MyLinkedList
{
public:
    typedef struct nodelist
    {
        int data;
        nodelist *next;

        // 构造函数
        nodelist(int val) : data(val), next(nullptr) {}
        nodelist(int val, nodelist *next) : data(val), next(next) {}

    } nodelist;
    
    MyLinkedList()
    {
        _size = 0;
        _dumyhead = new nodelist(0);
    }

    int get(int index)
    {
        int tmp = index;
        // 范围 （0 ，szie -1）
        if (index > _size - 1 || index < 0)
        {
            printf("取的位置有问题 \n");
            return -1;
        };

        nodelist *cur = _dumyhead->next;

        while (index--)
        {
            cur = cur->next;
        };

        printf("%d 当前取的数是 %d \n", tmp, cur->data);

        return 0;
    }

    void addAtHead(int val)
    {
        nodelist *newnode = new nodelist(val);
        newnode->next = _dumyhead->next;
        _dumyhead->next = newnode;
        _size++;
    }

    void addAtTail(int val)
    {
        nodelist *newnode = new nodelist(val);
        nodelist *tail = _dumyhead;

        while (tail->next != nullptr) // 寻找到尾部
        {
            tail = tail->next;
        };

        tail->next = newnode;

        _size++;
    }

    void addAtIndex(int index, int val)
    {
        // 范围 （-无穷 ，size）
        if (index > _size)
        {
            printf("插入超出范围了 \n");
            return;
        };

        if (index < 0)
        {
            index = 0; // 加到开头
        }

        nodelist *newnode = new nodelist(val);
        nodelist *preindex = _dumyhead;
        // 找到index的位置
        while (index--)
        {
            preindex = preindex->next;
        }

        // 接起来就行了
        newnode->next = preindex->next;
        preindex->next = newnode;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        // 范围 （0 ，size-1）
        if (index >= _size || index < 0)
        {
            printf("删除超出范围了 \n");
            return;
        };

        nodelist *preindex = _dumyhead;
        // 找到index的位置
        while (index--)
        {
            preindex = preindex->next;
        }

        preindex->next = preindex->next->next;
        _size--;
    }
    void printNodeList()
    {
        nodelist *cur = _dumyhead->next;
        printf("size = %d \n", this->_size);
        while (cur != nullptr)
        {
            printf(" node.data  %d \n   \n", cur->data);
            cur = cur->next;
        }
    }

private:
    int _size;
    nodelist *_dumyhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(void)
{
    MyLinkedList *mylinkedlist = new MyLinkedList();

    mylinkedlist->addAtTail(20);
    mylinkedlist->addAtHead(1);
    mylinkedlist->addAtHead(3);
    mylinkedlist->addAtIndex(0, 21);

    mylinkedlist->addAtTail(20);
    mylinkedlist->printNodeList();

    mylinkedlist->addAtIndex(5, 1000);
    mylinkedlist->printNodeList();
    mylinkedlist->deleteAtIndex(2);
    mylinkedlist->printNodeList();
}
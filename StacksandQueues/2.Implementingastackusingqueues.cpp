

#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        queue1.push(x);
    }

    int pop()
    {
        int size = queue1.size();

        for (int i = 0; i < size - 1; i++)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int temp = queue1.front();

        queue1.pop();

        while (!queue2.empty())
        {
            queue1.push(queue2.front());
            queue2.pop();
        }

        return temp;
    }

    int top()
    {
        int size = queue1.size();
        for (int i = 0; i < size - 1; i++)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int temp = queue1.front();
        queue2.push(queue1.front());

        queue1.pop();

        while (!queue2.empty())
        {
            queue1.push(queue2.front());
            queue2.pop();
        }

        return temp;
    }

    bool empty()
    {
        return queue1.empty();
    }

private:
    queue<int> queue1;
    queue<int> queue2;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    printf("%d\n", param_3);
    printf("%d\n", param_4);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stack1.push(x);
    }

    int pop()
    {

        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int temp =  stack2.top();
        stack2.pop();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        

        return temp;
    }

    int peek()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int temp =  stack2.top();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return temp;
    }

    bool empty()
    {
        return stack1.empty();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    printf("%d\n", param_2);
    printf("%d\n", param_3);
    printf("%d\n", param_4);

    return 0;
}
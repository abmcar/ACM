#include <stdio.h>
#include <stdlib.h>

#define DataType int
#define MaxSize 100
struct SeqStack
{
    int MaxNum;
    int tail;
    int top;
    DataType *s;
};
typedef struct SeqStack Stack;

Stack createEmptyStack()
{
    printf("Create Empty Stack\n");
    Stack nowStack;
    nowStack.s = (DataType *)malloc(sizeof(int) * MaxSize);
    nowStack.MaxNum = MaxSize;
    nowStack.top = 0;
    nowStack.tail = MaxSize - 1;
    return nowStack;
}

int isEmptyStack(Stack s)
{
    printf("Check Empty Stack:\n");
    if (s.top == 0)
        return 1;
    return 0;
}

int isEmptyStack_end(Stack s)
{
    printf("Check Empty Stack:\n");
    if (s.tail == s.MaxNum - 1)
        return 1;
    return 0;
}

void push(Stack *s, DataType val)
{
    printf("Push %d\n", val);
    s->s[s->top++] = val;
}

void pop(Stack *s)
{
    printf("Pop\n");
    s->top--;
}

DataType top(Stack s)
{
    printf("Top\n");
    return s.s[s.top-1];
}

void push_end(Stack *s, DataType val)
{
    printf("Push Back %d\n",val);
    s->s[s->tail--] = val;
}

void pop_end(Stack *s)
{
    printf("Pop Back\n");
    s->tail++;
}

DataType tail(Stack s)
{
    printf("Tail\n");
    return s.s[s.tail+1];
}

int main()
{
    Stack nowStack = createEmptyStack();
    push(&nowStack,1);
    printf("%d\n",top(nowStack));
    push(&nowStack,2);
    printf("%d\n",top(nowStack));
    pop(&nowStack);
    printf("%d\n",top(nowStack));

    push_end(&nowStack,123);
    printf("%d\n",tail(nowStack));
    push_end(&nowStack,1234);
    printf("%d\n",tail(nowStack));
    pop_end(&nowStack);
    printf("%d\n",tail(nowStack));
    return 0; 
}
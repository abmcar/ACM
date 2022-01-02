#include <stdio.h>
#include <stdlib.h>
#define DataType int
#define MaxSize 100

typedef struct
{
    int MaxNum;
    int tail;
    int top;
    DataType *num;
} Stack;

Stack initStack()
{
    printf("Init Stack\n");
    Stack nowStack;
    nowStack.num = (DataType *)malloc(sizeof(int) * MaxSize);
    nowStack.MaxNum = MaxSize;
    nowStack.top = 0;
    nowStack.tail = MaxSize - 1;
    return nowStack;
}

int checkEmptyStack(Stack s)
{
    printf("Check stack empty:\n");
    if (s.top == 0)
        return 1;
    return 0;
}

int checkEmptyStack_back(Stack s)
{
    printf("Check back stack stack:\n");
    if (s.tail == s.MaxNum - 1)
        return 1;
    return 0;
}

void push(Stack *s, DataType element)
{
    printf("Push %d\n", element);
    if (s->top + 1 == s->tail)
    {
        printf("Push fail,stack full\n");
        return;
    }
    s->num[s->top++] = element;
}

void pop(Stack *s)
{
    printf("Pop\n");
    if (s->top == 0)
    {
        printf("Pop fail,stack empty\n");
        return;
    }
    s->top--;
}

DataType top(Stack s)
{
    printf("Get top\n");
    if (s.top == 0)
    {
        printf("Get top fail, stack empty\n");
        return;
    }
    return s.num[s.top - 1];
}

void push_back(Stack *s, DataType element)
{
    printf("Push Back %d\n", element);
    if (s->tail - 1 == s->top)
    {
        printf("Push back fail, stack full\n");
        return;
    }
    s->num[s->tail--] = element;
}

void pop_back(Stack *s)
{
    printf("Pop Back\n");
    if (s->tail == s->MaxNum - 1)
    {
        printf("Pop back fail, stack empty\n");
        return;
    }
    s->tail++;
}

DataType tail(Stack s)
{
    printf("Get tail\n");
    if (s.tail == s.MaxNum - 1)
    {
        printf("Get tail fail, stack empty\n");
        return;
    }
    return s.num[s.tail + 1];
}

int main()
{
    Stack nowStack = initStack();
    printf("%d\n",checkEmptyStack(nowStack));
    push(&nowStack,100);

    printf("%d\n",checkEmptyStack_back(nowStack));
    push_back(&nowStack,100);

    printf("%d\n",checkEmptyStack(nowStack));
    pop(&nowStack);

    printf("%d\n",checkEmptyStack_back(nowStack));
    pop_back(&nowStack);

    printf("%d\n",checkEmptyStack(nowStack));
    printf("%d\n",checkEmptyStack_back(nowStack));

    return 0;
}
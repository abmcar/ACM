
#include <stdio.h>
#include <stdlib.h>
#define DataType int
#define MaxSize 4
typedef struct
{
    int MaxNum;
    int front, end;
    DataType *num;
} Queue;

Queue initQueue()
{
    printf("Init Queue\n");
    Queue nowQueue;
    nowQueue.num = (DataType *)malloc(sizeof(int) * MaxSize);
    nowQueue.MaxNum = MaxSize;
    nowQueue.front = 0;
    nowQueue.end = 0;
    return nowQueue;
}

int checkEmptyQueue(Queue q)
{
    printf("Check queue empty:\n");
    if (q.front == q.end)
        return 1;
    return 0;
}

void push(Queue *q, DataType element)
{
    printf("Push %d\n", element);
    if (((q->end + 1) % q->MaxNum) == q->front)
    {
        printf("Push fail,queue full\n");
        return;
    }
    q->num[q->end++] = element;
    q->end = q->end % q->MaxNum;
}

void pop(Queue *q)
{
    printf("Pop\n");
    if (q->front == q->end)
    {
        printf("Pop fail,queue empty\n");
        return;
    }
    q->front++;
    q->front = q->front % q->MaxNum;
}

DataType front(Queue q)
{
    printf("Get front:\n");
    if (q.front == q.end)
    {
        printf("Get front fail,queue empty\n");
        return;
    }
    return q.num[q.front];
}

int main()
{
    Queue nowQueue = initQueue();
    push(&nowQueue,1);
    push(&nowQueue,2);
    push(&nowQueue,3);
    push(&nowQueue,4);
    push(&nowQueue,5);
    pop(&nowQueue);
    printf("%d\n",front(nowQueue));
    pop(&nowQueue);
    printf("%d\n",front(nowQueue));
    pop(&nowQueue);
    printf("%d\n",front(nowQueue));
    pop(&nowQueue);
    printf("%d\n",front(nowQueue));
    pop(&nowQueue);
    printf("%d\n",front(nowQueue));
    return 0;
}
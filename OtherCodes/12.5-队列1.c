#include <stdio.h>
#include <stdlib.h>

#define DataType int
#define MaxSize 5
struct SeqQueue
{
    int MaxNum;
    int front, end;
    DataType *num;
};
typedef struct SeqQueue Queue;

Queue createEmptyQueue()
{
    printf("Create Empty Queue\n");
    Queue nowQueue;
    nowQueue.num = (DataType *)malloc(sizeof(int) * MaxSize);
    nowQueue.MaxNum = MaxSize;
    nowQueue.front = 0;
    nowQueue.end = 0;
    return nowQueue;
}

int isEmptyQueue(Queue q)
{
    printf("Check Empty Queue:\n");
    if (q.front == q.end)
        return 1;
    return 0;
}

void push(Queue *q, DataType val)
{
    printf("Push %d\n", val);
    if (((q->end+1)%q->MaxNum) == q->front)
    {
        printf("Push fail, queue full\n");
        return;
    }
    q->num[q->end++] = val;
    q->end = q->end % q->MaxNum;
}

void pop(Queue *q)
{
    printf("Pop\n");
    if (q->front == q->end)
    {
        printf("Pop fail, queue empty\n");
        return;
    }
    q->front++;
    q->front = q->front % q->MaxNum;
}

DataType front(Queue q)
{
    printf("Front:\n");
    if (q.front == q.end)
    {
        printf("Get front fail, queue empty\n");
        return;
    }
    return q.num[q.front];
}

int main()
{
    Queue nowQueue = createEmptyQueue();
    push(&nowQueue,1);
    push(&nowQueue,2);
    push(&nowQueue,3);
    push(&nowQueue,4);
    push(&nowQueue,5);
    push(&nowQueue,6);
    push(&nowQueue,7);
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
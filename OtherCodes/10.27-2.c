#include <stdio.h>

struct Node
{
    struct Node *next;
    int val;
} * strNode;
int array[100], arrSize;

void insert(int num, struct Node *strNode)
{
    struct Node *nowNode = strNode;
    struct Node *nextNode = strNode->next;
    while (nextNode != NULL)
    {
        nowNode = nextNode;
        nextNode = nowNode->next;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = num;
    nowNode->next = newNode;
    newNode->next = NULL;
}

void ins(int num, struct Node *strNode)
{
    arrSize++;
    printf("insert %d\n",num);
    struct Node *nowNode = strNode;
    struct Node *nextNode = strNode->next;
    while (nextNode != NULL)
    {
        nowNode = nextNode;
        nextNode = nowNode->next;
        if (num >= nowNode->val)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->val = num;
            nowNode->next = newNode;
            newNode->next = nextNode;
            return;
        }
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = num;
    nowNode->next = newNode;
    newNode->next = NULL;
}

void traveral(struct Node *strNode)
{
    struct Node *nowNode = strNode;
    printf("%d", nowNode->val);
    while (nowNode->next != NULL)
    {
        printf("-->%d", nowNode->next->val);
        nowNode = nowNode->next;
    }
    printf("\n");
}

int find(int num, struct Node *strNode)
{
    struct Node *nowNode = strNode;
    if (nowNode->val == num)
        return 1;
    while (nowNode->next != NULL)
    {
        if (nowNode->next->val == num)
            return 1;
        nowNode = nowNode->next;
    }
    return -1;
}

int getNum(int pos, struct Node *strNode)
{
    struct Node *nowNode = strNode;
    for (int i = 1; i < pos; i++)
        nowNode = nowNode->next;
    return nowNode->val;
}

void opt1()
{
    printf("reverse list\n");
    for (int i = 1; i <= arrSize; i++)
        insert(getNum(arrSize - i + 1, strNode), strNode);
    arrSize *= 2;
}

int get(int arr[])
{
    int cnt = 0;
    int temp;
    while (scanf("%d", &temp))
    {
        if (temp == -1)
            break;
        arr[cnt++] = temp;
    }
    return cnt;
}

int check(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        if (arr[i] < arr[i - 1])
            return -1;
    return 1;
}

int main()
{
    printf("输入一个递增序列,用空格隔开,输入-1结束输入\n");
    strNode = (struct Node *)malloc(sizeof(struct Node));
    strNode->next = NULL;
    arrSize = get(array);
    if (check(array, arrSize) == -1)
    {
        printf("Error input");
        return 0;
    }
    strNode->val = array[0];
    for (int i = 1; i < arrSize; i++)
        insert(array[i], strNode);
    ins(3,strNode);
    traveral(strNode);
    opt1();
    traveral(strNode);
    printf("find %d ans: %d\n", 123, find(123, strNode));
    printf("find %d ans: %d\n", 1, find(1, strNode));
}
#include <stdio.h>
#include <stdlib.h>
#define DataType int
const int MaxSize = 100;
typedef struct List
{
    int maxSize;
    int nowSize;
    DataType *element;
} SeqList;
SeqList *list;

SeqList *initList()
{
    SeqList *nowList = (SeqList *)malloc(sizeof(SeqList));
    nowList->nowSize = 0;
    nowList->maxSize = MaxSize;
    nowList->element = (DataType *)malloc(sizeof(DataType) * MaxSize);
    if (nowList->element)
    {
        printf("List created!\n");
        return nowList;
    }
    else
    {
        printf("List create fail!\n");
        free(nowList);
        return NULL;
    }
}

int checkEmpty(SeqList *nowList)
{
    if (nowList->nowSize == 0)
        return 1;
    return 0;
}

void appendNum(int num, SeqList *nowList)
{
    if (nowList->nowSize == nowList->maxSize)
    {
        printf("List full!\n");
        return;
    }
    printf("append num %d\n", num);
    nowList->element[nowList->nowSize] = num;
    nowList->nowSize++;
}

void insertNum(int num, int pos, SeqList *nowList)
{
    if (pos - 1 > nowList->nowSize)
    {
        printf("List length not enough!\n");
        return;
    }
    if (nowList->nowSize == nowList->maxSize)
    {
        printf("List full!\n");
        return;
    }
    printf("insert num %d\n", num);
    for (int i = nowList->nowSize - 1; i >= pos - 1; i--)
        nowList->element[i + 1] = nowList->element[i];
    nowList->nowSize++;
    nowList->element[pos - 1] = num;
}

void traveralList(SeqList *nowList)
{
    for (int i = 0; i < nowList->nowSize; i++)
        printf("%d ", nowList->element[i]);
    printf("\n");
}

int findNum(int num, SeqList *nowList)
{
    for (int i = 0; i < nowList->nowSize; i++)
    {
        if (nowList->element[i] == num)
            return i + 1;
    }
    return -1;
}

void deleteNum(int targetNum, SeqList *nowList)
{
    printf("delete num %d\n", targetNum);
    for (int i = 0; i < nowList->nowSize; i++)
    {
        if (nowList->element[i] == targetNum)
        {
            for (int j = i + 1; j < nowList->nowSize; j++)
                nowList->element[j - 1] = nowList->element[j];
            nowList->nowSize--;
        }
    }
}

int main()
{
    list = initList();
    printf("check empty result:%d\n", checkEmpty(list));
    insertNum(1, 1, list);
    traveralList(list);
    insertNum(1, 2, list);
    traveralList(list);
    insertNum(4, 3, list);
    traveralList(list);
    insertNum(5, 4, list);
    traveralList(list);
    insertNum(1, 5, list);
    traveralList(list);
    insertNum(4, 6, list);
    traveralList(list);
    printf("check empty result:%d\n", checkEmpty(list));
    printf("find %d result %d\n", 1, findNum(1, list));
    printf("find %d result %d\n", 2, findNum(2, list));
    printf("find %d result %d\n", 3, findNum(3, list));
    printf("find %d result %d\n", 4, findNum(4, list));
    printf("find %d result %d\n", 5, findNum(5, list));
    deleteNum(3, list);
    traveralList(list);
    deleteNum(1, list);
    traveralList(list);
    deleteNum(5, list);
    traveralList(list);
    printf("find %d result %d\n", 1, findNum(1, list));
    printf("find %d result %d\n", 2, findNum(2, list));
    printf("find %d result %d\n", 3, findNum(3, list));
    printf("find %d result %d\n", 4, findNum(4, list));
    printf("find %d result %d\n", 5, findNum(5, list));
    deleteNum(2, list);
    deleteNum(4, list);
    printf("check empty result:%d\n", checkEmpty(list));
    return 0;
}
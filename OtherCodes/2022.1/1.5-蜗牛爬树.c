#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DataType int
#define MaxSize 100
#define Maxn 1000

typedef struct
{
    int MaxNum;
    int tail;
    int top;
    DataType *num;
} Stack;

//��ʼ��ջ
Stack initStack()
{
    Stack nowStack;
    nowStack.num = (DataType *)malloc(sizeof(int) * MaxSize);
    nowStack.MaxNum = MaxSize;
    nowStack.top = 0;
    nowStack.tail = MaxSize - 1;
    return nowStack;
}

// ��Ԫ��ѹ��ջ
void push(Stack *s, DataType element)
{
    if (s->top + 1 == s->tail)
        return;
    s->num[s->top++] = element;
}

// ջ����Ԫ��
void pop(Stack *s)
{
    if (s->top == 0)
        return;
    s->top--;
}

// ���ߺ���ţ����
int h, k;
// ÿֻ��ţ������
int v[Maxn], n[Maxn], m[Maxn];
// ��ǰ�߶�,�������߶�,��Сʱ�����ţ���
int cnt, totU, minPos;
// ��ǰ��ţ���м�¼,������ţ���м�¼
int ans[Maxn], totAns[Maxn];
// ��С����ʱ��
double minCost;

int main()
{
    // ����
    scanf("%d %d", &k, &h);
    for (int i = 1; i <= k; i++)
        scanf("%d %d %d", &v[i], &n[i], &m[i]);
    // ��ʼ����Сʱ��
    minCost = 1e9;
    // ��ÿֻ��ţ���
    for (int i = 1; i <= k; i++)
    {
        memset(ans, 0, sizeof ans);
        int nowV = v[i];
        int nowU = n[i];
        int nowD = m[i];
        Stack nowS = initStack();
        cnt = totU = 0;
        int temp = 0;
        // ģ�����й���
        ans[cnt]++;
        totAns[cnt]++;
        while (cnt <= h)
        {
            push(&nowS, cnt + 1);
            temp++;
            totU++;
            cnt++;
            ans[cnt]++;
            totAns[cnt]++;
            if (cnt == h)
                break;
            if (totU % nowU == 0)
            {
                for (int j = 1; j <= nowD; j++)
                {
                    pop(&nowS);
                    cnt--;
                    ans[cnt]++;
                    totAns[cnt]++;
                }
            }
        }
        // �ж��Ƿ���Сʱ��
        if (totU * 1.0 / nowV < minCost)
        {
            minCost = totU * 1.0 / nowV;
            minPos = i;
        }
        // ���
        printf("����ʱ��:%lf\n", totU * 1.0 / nowV);
        printf("��������:");
        for (int j = 0; j <= h; j++)
            printf("%d ", ans[j]);
        printf("\n");
    }

    printf("�ܾ�������:");
    for (int i = 0; i <= h; i++)
        printf("%d ", totAns[i]);
    printf("\n");
    printf("���ı��:%d\n", minPos);
    return 0;
}

/*

3 10
1 2 1
2 2 1
3 3 2
 */
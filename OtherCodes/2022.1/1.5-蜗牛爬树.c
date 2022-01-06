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

//初始化栈
Stack initStack()
{
    Stack nowStack;
    nowStack.num = (DataType *)malloc(sizeof(int) * MaxSize);
    nowStack.MaxNum = MaxSize;
    nowStack.top = 0;
    nowStack.tail = MaxSize - 1;
    return nowStack;
}

// 把元素压入栈
void push(Stack *s, DataType element)
{
    if (s->top + 1 == s->tail)
        return;
    s->num[s->top++] = element;
}

// 栈弹出元素
void pop(Stack *s)
{
    if (s->top == 0)
        return;
    s->top--;
}

// 树高和蜗牛数量
int h, k;
// 每只蜗牛的属性
int v[Maxn], n[Maxn], m[Maxn];
// 当前高度,总上升高度,最小时间的蜗牛编号
int cnt, totU, minPos;
// 当前蜗牛爬行记录,所有蜗牛爬行记录
int ans[Maxn], totAns[Maxn];
// 最小花费时间
double minCost;

int main()
{
    // 输入
    scanf("%d %d", &k, &h);
    for (int i = 1; i <= k; i++)
        scanf("%d %d %d", &v[i], &n[i], &m[i]);
    // 初始化最小时间
    minCost = 1e9;
    // 对每只蜗牛求解
    for (int i = 1; i <= k; i++)
    {
        memset(ans, 0, sizeof ans);
        int nowV = v[i];
        int nowU = n[i];
        int nowD = m[i];
        Stack nowS = initStack();
        cnt = totU = 0;
        int temp = 0;
        // 模拟爬行过程
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
        // 判断是否最小时间
        if (totU * 1.0 / nowV < minCost)
        {
            minCost = totU * 1.0 / nowV;
            minPos = i;
        }
        // 输出
        printf("消耗时间:%lf\n", totU * 1.0 / nowV);
        printf("经过次数:");
        for (int j = 0; j <= h; j++)
            printf("%d ", ans[j]);
        printf("\n");
    }

    printf("总经过次数:");
    for (int i = 0; i <= h; i++)
        printf("%d ", totAns[i]);
    printf("\n");
    printf("最快的编号:%d\n", minPos);
    return 0;
}

/*

3 10
1 2 1
2 2 1
3 3 2
 */
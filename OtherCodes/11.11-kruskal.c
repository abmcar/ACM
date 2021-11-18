#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重
}Edge;

int cmp(Edge a, Edge b)
{
    if (a.weight < b.weight)
        return -1;
    return 1;
}

void kruskal()
{
    int father[100005];
    int ans = 0;
    for (int i = 1; i <= numV; i++)
        father[i] = i;
    for (int i = 1; i <= numE; i++)
    {
        int f1 = find(edge[i].str);
        int f2 = find(edge[i].str);
        if (f1 == f2)
            continue;
        edge[i].use = true;
        ans += edge[i].weight;
        father[f1] = f2;
    }
}

int main()
{
    Edge edges[123];
   edges[1].weight = 123;
   edges[2].weight = 2;
    qsort(edges,2,sizeof(Edge), cmp);
    printf("%d",edges[1].weight);
    
}
#include <stdio.h>
#include <stdlib.h>

struct GLNode
{
    int tag;
    union
    {
        char data;
        struct GLNode *sublist;
    } val;
    struct GLNode *link;
};

void CreateGL(struct GLNode **g)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        *g = NULL;
    else if (ch == '(')
    {
        *g = (struct GLNode *)malloc(sizeof(struct GLNode));
        (*g)->tag = 1;
        CreateGL(&((*g)->val.sublist));
    }
    else
    {
        *g = (struct GLNode *)malloc(sizeof(struct GLNode));
        (*g)->tag = 0;
        (*g)->val.data = ch;
    }
    scanf("%c", &ch);
    if (*g == NULL)
        ;
    else if (ch == ',')
        CreateGL(&((*g)->link));
    else if ((ch == ')') || (ch == '\n'))
        (*g)->link = NULL;
}

GLNode *SearchGL(GLNode *&g, char a)
{
    while (g != NULL)
    {
        if (g->tag == 1)
        {
            if (SearchGL(g->val.sublist, a))
                return (g->val.sublist);
        }
        else
        {
            if (g->val.data == a)
                return g;
        }
        g = g->link;
    }
    return NULL;
}

int main()
{
    char a;
    struct GLNode *g;
    CreateGL(&g);
    char temp = SearchGL(g, a)->val.data;
    return 0;
}
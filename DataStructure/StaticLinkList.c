#define MAXSIZE 100

//静态链表的数据结构，以游标代替指针,游标为下一元素的下标
typedef struct
{
    int data;
    int cur; //cursor
} Component, staticlinklist[MAXSIZE];

//初始化
int InitList(staticlinklist space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
    return 0;
}

//插入
int Malloc_SLL(staticlinklist space)
{
    int i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[i].cur;
    }
    return i;
}
int ListInsert(staticlinklist L, int i, int e)
{
    int j, k, l;
    ;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L) + 1)
    {
        return -1;
    }

    j = Malloc_SLL(L);
    if (j)
    {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++)
        {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return 0;
    }
    return -1;
}

//删除
int ListDelete(staticlinklist L, int i)
{
    int j, k;

    if (i < 1 || i > ListLength(L))
    {
        return -1;
    }

    k = MAXSIZE - 1;

    for (j = 1; j <= i - 1; j++)
    {
        k = L[k].cur;
    }

    j = L[k].cur;

    L[k].cur = L[j].cur;

    free_SLL(L, j);
    return 0;
}
  void free_SLL(staticlinklist space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}
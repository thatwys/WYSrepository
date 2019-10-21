typedef struct Node
{
    int data;
    struct Node *next;
} Node, *Linklist; //链表数据结构

//链表生成（头部插入）
void CreateList(Linklist *L, int n)
{
    Linklist p;
    int i;

    srand(time(0));

    *L = (Linklist)malloc(sizeof(Node));
    (*L)->next = NULL;

    for (i = 0; i < n; i++)
    {
        p = (Linklist)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

//链表生成（尾部插入）
void CreateList(Linklist *L, int n)
{
    Linklist p, r;
    int i;

    srand(time(0));
    *L = (Linklist)malloc(sizeof(Node));
    r = *L;

    for (i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }

    r->next = NULL;
}

//链表插入
int ListInsert(Linklist *L, int i, int e)
{
    int j;
    Linklist p, a;

    p = *L;
    j = 1;

    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p || j > i)
    {
        return -1;
    }

    a = (Linklist)malloc(sizeof(Node));
    a->data = e;
    a->next = p->next;
    p->next = a;

    return 0;
}

//链表删除
int ListDelete(Linklist *L, int i, int *e)
{
    int j;
    Linklist p, q;

    p = *L;
    j = 1;

    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }

    if (!(p->next) || j > i)
    {
        return -1;
    }

    q = p->next;
    p->next = q->next;

    *e = q->data;
    free(q);
    return 0;
}

//整表删除
int ClearList(Linklist *L)
{
    Linklist p, q;

    p = (*L)->next;

    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    (*L)->next = NULL;

    return 0;
}
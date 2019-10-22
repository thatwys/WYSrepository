//循环单向链表数据结构
typedef struct node
{
    int data;
    struct node *next;
} node;

//创建单单向循环链表
node *create(int n)
{
    node *p = NULL, *head;
    head = (node *)malloc(sizeof(node));
    p = head;
    node *s;
    int i = 1;

    if (0 != n)
    {
        while (i <= n)
        {
            s = (node *)malloc(sizeof(node));
            s->data = i++;
            p->next = s;
            p = s;
        }
        s->next = head->next;
    }
    free(head);
    return s->next;
}

//循环双向链表数据结构
typedef struct DNode
{
    int data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *BCLinkList;

//插入(懒得写完了，就写最关键四句)
void ListInsert(BCLinkList s, BCLinkList p)
{
    s->next = p;
    s->prior = p->prior;
    p->prior->next = s;
    p->prior = s;
}

//删除(懒得写完了，就写最关键三句)
void ListDelete(BCLinkList p)
{
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
}
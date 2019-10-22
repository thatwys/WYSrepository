//顺序栈（Sequence Stack）的数据结构
typedef struct
{
    int *base;
    int *top;
    int stacksize;
} SqStack;

//创建栈
#define STACK_INIT_SIZE 100
void InitStack(SqStack *s)
{
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

//插入
void Push(SqStack *s, int e)
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (int *)malloc(s->base, (s->stacksize + STACK_INIT_SIZE) * sizeof(int));
        if (!s->base)
        {
            exit(0);
        }
        s->top = s->base + s->stacksize;
        s->stacksize += STACK_INIT_SIZE;
    }
    *(s->top) = e;
    s->top++;
}

//删除
void Pop(SqStack *s, int *e)
{
    if (s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);
}

//清空
void ClearStack(SqStack *s)
{
    s->top = s->base;
}

//销毁（和清空做区分）
void DestroyStack(SqStack *s)
{
    int i, len;
    len = s->stacksize;
    for (i = 0; i < len; i++)
    {
        free(s->base);
        s->base++;
    }
    s->base = s->top = NULL;
    s->stacksize = 0;
}

//链式栈数据结构
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;
typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

//插入
int Push(LinkStack *s, int e)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    return 0;
}

//删除
int Pop(LinkStack *s, int *e)
{
    LinkStackPtr p;
    if (StackEmpty(*s))
    {
        return -1;
    }
    *e = s->top->data;
    p = s->top;
    s->top = s->top->next;
    free(p);
    s->count--;
    return 0;
}

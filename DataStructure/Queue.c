//队列链式数据结构实现
typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
} LinkQueue;

//入队
void InsertQueue(LinkQueue *q, int e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (p == NULL)
    {
        exit(0);
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

//出队
void DeleteQueue(LinkQueue *q, int e)
{
    QueuePtr p;
    if (q->front == q->rear)
    {
        return;
    }
    p = q->front->next;
    e = p->data;
    q->front->next = p->next;
    if (q->rear == p)
    {
        q->rear = q->front;
    }
    free(p);
}

//循环队列数据结构
#define MAXSIZE 100
typedef struct
{
    int *base;
    int front;
    int rear;
} CycleQueue;

//初始化
void InitQueue(CycleQueue *q)
{
    q->base = (int *)malloc(MAXSIZE * sizeof(int));
    if (!q->base)
    {
        exit(0);
    }
    q->front = q->rear = 0;
}

//插入
void InsertQueue(CycleQueue *q, int e)
{
    if ((q->rear + 1) % MAXSIZE == q->front)
    {
        return;
    }
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
}

//删除
void DeleteQueue(CycleQueue *q, int *e)
{
    if (q->front == q->rear)
    {
        return;
    }
    *e = q->base[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}
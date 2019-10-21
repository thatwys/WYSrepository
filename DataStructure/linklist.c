typedef struct Node
{
    int data;
    struct Node *next;
}Node,*Linklist;                 //链表数据结构


//链表插入
int ListInsert(Linklist *L,int i, int e){
    int j;
    Linklist p, a;

    p = *L;
    j = 1;

    while(p&& j<i){
        p=p->next;
        j++;
    }

    if(!p||j>i){
        return -1;
    }

    a = (Linklist)malloc(sizeof(Node));
    a->data = e;
    a->next = p->next;
    p->next = a;

    return 0;
}

 
//链表删除
int ListDelete(Linklist *L, int i, int *e){
    int j;
    Linklist p,q;

    p = *L;
    j = 1;

    while(p->next&&j<i){
        p = p->next;
        j++;
    }

    if( !(p->next)||j>i){
        return -1;
    }

    q = p->next;
    p->next = q->next;

    *e = q->data;
    free(q);
    return 0;
}
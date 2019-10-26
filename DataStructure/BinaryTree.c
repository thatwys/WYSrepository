//二叉树的链式存储结构
typedef struct BTNode
{
    int data;
    struct BTNode *rchild;
    struct BTNode *lchild;
} BTNode, *BTree;

//建立二叉树
void CreateBiTree(BTree *T)
{
    int a;
    if (a)
    {
        *T = (BTNode *)malloc(sizeof(BTNode));
        (*T)->data = a;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    else
    {
        *T = NULL;
    }
}

//遍历二叉树
/*
前序、中序、后序
下述为递归实现
*/

//前序遍历
void PreOrderTraverse(BTree T)
{
    if (T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//中序遍历
void InOrderTraverse(BTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        visit(T->data);
        InOrderTraverse(T->rchild);
    }
}

//后序遍历
void PostOrderTraverse(BTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T->data);
    }
}

/*下述为非递归实现*/
//前序遍历
void PreOrderTraverse(BTree BT)
{
    BTree T = BT;
    Stack s = CreateStack(MAX_SIZE);
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            visit(T->data);
            Push(S, T);
            T = T->lchild;
        }
        if (!IsEmpty(S))
        {
            T = Pop(S);
            T->rchild;
        }
    }
}

//中序遍历
void InOrderTraversal(BTree BT)
{
    BTree T = BT;
    Stack S = CreateStack(MAX_SIZE);
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S, T);
            T = T->lchild;
        }
        if (!IsEmpty(S))
        {
            T = Pop(S);
            visit(T->data);
            T = T->rchild;
        }
    }
}

//后序遍历
void PostOrderTraverse(BTree T)
{
    Stack S1 = CreateStack(MAX_SIZE);
    Stack S2 = CreateStack(MAX_SIZE);

    while (T || !IsEmpty(S1))
    {
        while (T)
        {
            Push(S2, T);
            Push(S1, T);
            T = T->rchild;
        }
        if (!IsEmpty(S1))
        {
            T = Pop(S1);
            T->lchild;
        }
    }
    while (!IsEmpty(S2))
    {
        T = Pop(S2);
        visit(T->data);
    }
}

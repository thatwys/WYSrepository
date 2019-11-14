//二叉平衡树

#define LH 1
#define EH 0
#define RH -1

typedef struct BiTNode
{
    int data;
    int bf;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int InsertAVL(BiTree *T, int e, int *taller)
{
    if (!*T)
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    {
        if (e == (*T)->data)
        {
            *taller = FALSE;
            return -1;
        }
        if (e < (*T)->data)
        {
            if (!InsertAVL(&(*T)->lchild, e, taller))
            {
                return FALSE;
            }
            if (*taller)
            {
                switch ((*T)->bf)
                {
                case LH:
                    //左平衡
                    *taller = FALSE;
                    break;
                case EH:
                    (*T)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH:
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                }
            }
        }
        else
        {
            if (!InsertAVL(&(*T)->rchild, e, taller))
            {
                return FALSE;
            }
            if (*taller)
            {
                switch ((*T)->bf)
                {
                case LH:
                    (*T)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH:
                    (*T)->bf = RH;
                    *taller = TRUE;
                    break;

                case RH:
                    //右平衡
                    *taller = FALSE;
                    break;
                }
            }
        }
    }
}
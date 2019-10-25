//树的存储结构（双亲表示法）
#define MAX_TREE_SIZE 100
typedef struct TNode
{
    int data;
    int parent;
} TNode;

typedef struct
{
    TNode nodes[MAX_TREE_SIZE];
    int r; //根位置
    int n; //结点数
} Tree;

//树的存储结构（孩子表示法）
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} CTNode, *ChildPtr;

//头结构
typedef struct
{
    int data;
    int parent;
    ChildPtr firstchild;
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r;
    int n;
} Tree;
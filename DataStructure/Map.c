//图的存储结构

//邻接矩阵
//一维数组存储顶点信息，二维数组存储边弧信息
#define MAX_VERTEX_NUM 10000
typedef struct
{
    VRType adj;     //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
    InfoType *info; //弧或边额外含有的信息指针
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM]; //存储图中顶点数据
    AdjMatrix arcs;                  //二维数组，记录顶点之间的关系
    int vexnum, arcnum;              //记录图的顶点数和弧（边）数
    GraphKind kind;                  //记录图的种类
} MGraph;

//邻接表
//把数组与链表结合在一起存储，顶点用一维数组存储，每个顶点的邻接点构成一个线性表
typedef struct ENode
{
    int adjvex;
    struct ENode *next;
} EdgeNode;

typedef struct VNode
{
    int vertex;
    struct VNode *next;
} VertexNode;

typedef VertexNode AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList adjlist;
    int n, e;
} AdjMatrix;

//十字链表
//展现各点的连接关系，包含tailvex、headvex、headlink、taillink等
//十字链表是邻接表和逆邻接表的结合
typedef struct ArcBox
{
    int tailvex, headvex;        //弧尾、弧头对应顶点在数组中的位置下标
    struct ArcBox *hlik, *tlink; //分别指向弧头相同和弧尾相同的下一个弧
    InfoType *info;              //存储弧相关信息的指针
} ArcBox;

typedef struct VexNode
{
    VertexType data;            //顶点的数据域
    ArcBox *firstin, *firstout; //指向以该顶点为弧头和弧尾的链表首个结点
} VexNode;

typedef struct
{
    VexNode xlist[MAX_VERTEX_NUM]; //存储顶点的一维数组
    int vexnum, arcnum;            //记录图的顶点数和弧数
} OLGraph;

//马踏棋盘问题
//在国际象棋棋盘中，把马放在任意方格要求每个方格只走一次，最终让马走遍64个方格
#define X 8
#define Y 8
int chess[X][Y];

//找寻基于(x,y)的下一个位置
int nextxy(int *x, int *y, int count)
{
    switch (count)
    {
    case 0:
        if (*x + 2 <= X - 1 && *y - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
        {
            *x += 2;
            *y -= 1;
            return 1;
        }
        break;
    case 1:
        if (*x + 2 <= X - 1 && *y + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
        {
            *x += 2;
            *y += 1;
            return 1;
        }
        break;
    case 2:
        if (*x + 1 <= X - 1 && *y + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0)
        {
            *x += 1;
            *y += 2;
            return 1;
        }
        break;
    case 3:
        if (*x - 2 >= 0 && *y - 1 >= 0 && chess[*x - 2][*y - 1] == 0)
        {
            *x -= 2;
            *y -= 1;
            return 1;
        }
        break;
    case 4:
        if (*x - 2 >= 0 && *y + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0)
        {
            *x -= 2;
            *y += 1;
            return 1;
        }
        break;
    case 5:
        if (*x + 1 <= X - 1 && *y - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
        {
            *x += 1;
            *y -= 2;
            return 1;
        }
        break;
    case 6:
        if (*x - 1 >= 0 && *y + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0)
        {
            *x += 2;
            *y += 1;
            return 1;
        }
        break;
    case 7:
        if (*x - 1 >= 0 && *y - 2 >= 0 && chess[*x - 1][*y - 2] == 0)
        {
            *x += 2;
            *y += 1;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

//xy起始坐标，tag是标记变量，每走一步tag+1
int TravelChessBoard(int x, int y, int tag)
{
    int x1 = x, y1 = y, flag = 0, count = 0;
    chess[x][y] = tag;
    if (X * Y == tag)
    {
        //打印棋盘
        return 1;
    }

    flag = nextxy(&x1, &y1, count);
    while (0 == flag && count < 7)
    {
        count++;
        flag = nextxy(&x1, &y1, count);
    }

    while (flag)
    {
        if (TravelChessBoard(x1, y1, tag + 1))
        {
            return 1;
        }
        x1 = x;
        y1 = y;
        count++;

        flag = nextxy(&x1, &y1, count);
        while (0 == flag && count < 7)
        {
            count++;
            flag = nextxy(&x1, &y1, count);
        }
    }
    if (flag == 0)
    {
        chess[x][y] = 0;
    }
}

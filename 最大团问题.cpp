//# include <iostream>
//# include <string>
//# include <queue>
//using namespace std;
//struct bbnode //定义一棵子集数，LChild代表当前的层是在昨孩子还是右孩子
//{ //左孩子代表要这个点，右孩子代表不要。parent代表父亲节点
//	bbnode* parent;
//	bool LChild;
//};
//struct CliqueNode //定义优先队列类型为CliqueNode
//{
//	int cn, un, level; //分别是当前团顶点数，最大顶点上界，和所在的层次
//	bbnode* ptr; //记录该点的情况是左孩子还是右孩子，父母是谁
//	bool operator<(const CliqueNode& a) const //<号重载建立大根堆
//	{
//		if (a.un > un) return true;
//		if (a.un == un && a.cn > cn) return true;
//		else return false;
//	}
//};
//int G[101][101]; //定义图
//bool bestx[101]; //记录最大团的情况
//void init(int n) //输入
//{
//	int i, j;
//	memset(G, 1, sizeof(G));
//	memset(bestx, false, sizeof(bestx));
//	for (i = 1; i <= n; i++)
//		for (j = 1; j <= n; j++)
//			scanf("%d", &G[i][j]);
//}
//int work(int n)
//{
//	bbnode* E = new(bbnode); //定义E代表记录的队列情况
//	int i = 1, j, cn = 0, bestn = 0; //cn代表当前解，bestn代表最优解
//	bool OK; //哨兵，判断新加入的点是否满足最大团
//	priority_queue<CliqueNode> Q; //定义优先队列Q
//	E->LChild = false; //初始化
//	E->parent = NULL;
//	while (i != n + 1)
//	{
//		OK = true;
//		bbnode* B = E; //把当前点的数据给B，B为中间变量
//		for (j = i - 1; j > 0; B = B->parent, j--)
//			if (B->LChild && G[i][j] == 0) //如果不满足就停止
//			{
//				OK = false;
//				break;
//			}
//		if (OK) //满足条件
//		{
//			CliqueNode* C = new(CliqueNode); //定义一个节点C
//			C->ptr = new(bbnode);
//			if (cn + 1 > bestn) bestn = cn + 1; //如果当前解+1大于最优解
//			C->cn = cn + 1; //输入数据
//			C->level = i + 1;
//			C->ptr->LChild = true;
//			C->ptr->parent = E;
//			C->un = cn + 1 + n - i;
//			Q.push(*C); //进队列
//		}
//		if (cn + n - i >= bestn) //不满足条件但是还是可能有最优解
//		{
//			CliqueNode* C = new(CliqueNode); //定义一个节点C
//			C->ptr = new(bbnode);
//			C->cn = cn; //输入数据
//			C->level = i + 1;
//			C->ptr->LChild = false;
//			C->ptr->parent = E;
//			C->un = cn + n - i;
//			Q.push(*C); //进队列
//		}
//		CliqueNode N;
//		N = Q.top(); //取队顶元素，最大堆
//		Q.pop(); //删除队顶元素
//		E = N.ptr; //记录当前团的信息
//		cn = N.cn; //记录当前团的顶点数
//		i = N.level; //所在的层次
//	}
//	for (j = n; j > 0; j--) //保存最优解
//	{
//		bestx[j] = E->LChild;
//		E = E->parent;
//	}
//	return bestn;
//}
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		init(n);
//		int ans = work(n);
//		printf("%d\n", ans);
//		for (int i = n; i > 0; i--)
//			if (bestx[i] == true)
//				printf("%d ", i);
//		putchar(10);
//	}
//	return 0;
//}
///*
//5
//0 1 0 1 1
//1 0 1 0 1
//0 1 0 0 1
//1 0 0 0 1
//1 1 1 1 0
//*/
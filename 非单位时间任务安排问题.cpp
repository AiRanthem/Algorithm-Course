//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
///*
//首先将任务按其截止时间非减序排序
//p(i, d)表示对任务1,2..i，截止时间为d的最小误时惩罚
//p(i, d) = min{ p(i-1, d)+wi,  p(i-1, min{d, di}-ti) }
//p(1, d) = 0  t1<=d
//p(1, d) = w1  t1>d
//*/
//const int INF = 100000;
//const int MAX = 50;
//int p[MAX][200];
//
//struct Task
//{
//	int t; //完成任务需要的时间
//	int d; //截止时间
//	int w; //误时惩罚
//
//	bool operator < (const Task& ta) const
//	{
//		return d < ta.d;
//	}
//};
//
//Task task[MAX];
//
////
//int greedy(int n)
//{
//	sort(task, task + n);  //按截止时间排序
//	int d = task[n - 1].d; //最大截止时间
//	int i, j;
//	//for(i=0; i<n; i++)
//		//for(j=0; j<=d; j++)
//			//p[i][j] = INF;
//
//	for (i = 0; i <= d; i++)
//		if (i > task[0].t)
//			p[0][i] = 0;
//		else
//			p[0][i] = task[0].w;
//
//	for (i = 1; i < n; i++)
//		for (j = 0; j <= d; j++)
//		{
//			p[i][j] = p[i - 1][j] + task[i].w;
//			int jj = task[i].d > j ? j : task[i].d;
//			if (jj >= task[i].t && p[i][j] > p[i - 1][jj - task[i].t])
//				p[i][j] = p[i - 1][jj - task[i].t];
//		}
//
//	return p[n - 1][d];
//}
//
//int main()
//{
//	cout << "输入任务数：";
//	int n;
//	cin >> n;
//	cout << "\n输入完成任务需要的时间，截止时间，误时惩罚：\n";
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		cin >> task[i].t >> task[i].d >> task[i].w;
//	}
//
//	cout << "最小误时惩罚为：" << greedy(n);
//	cout << endl;
//	return 0;
//}

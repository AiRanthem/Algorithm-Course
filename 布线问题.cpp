////假设要将一组元件安装在一块线路板上，为此需要设计一个线路板布线方案。
////各元件的连线数由连线矩阵 conn 给出。
////元件 i 和元件 j 之间的连线数为 conn(i, j)。
////如果将元件 i 安装在线路板上位置 r 处，而将元件 j 安装在线路板上位置 s 处，
////则元件 i 和元件 j 之间的距离为 dist(r, s)。
////确定了所给的 n 个元件的安装位置，就确定了一个布线方案。与此布线方案相应的布线成本为：
////sum(1<=i<j<=n) {conn(i,j) * dist(r,s)}
////试设计一个算法找出所给 n 个元件的布线成本最小的布线方案 。
////设计一个算法，对于给定的 n 个元件，计算最佳布线方案，使布线费用达到最小。
//
//#include <iostream>
//using namespace std;
//
//int cost(int pos, int conn[][20], int PCB[]) 
//{
//	int curCost = 0, dist;
//	for (register int i = 0; i < pos; i++) {
//		for (register int j = i + 1; j <= pos; j++) {
//			dist = PCB[i] > PCB[j] ? PCB[i] - PCB[j] : PCB[j] - PCB[i];
//			curCost += dist * conn[i][j];
//		}
//	}
//	return curCost;
//}
//
//void dfs(int pos,int preCost,int *minCost, int PCB[], int n, int conn[][20], int finalPCB[])
//{
//	int curCost;
//	if (pos == n - 1)
//	{   // save and exit
//		curCost = cost(pos, conn, PCB);
//		if (curCost < *minCost)
//		{
//			*minCost = curCost;
//			for (int i = 0; i < n; ++i)
//				finalPCB[i] = PCB[i];
//		}
//		return;
//	}
//
//	for (int i = pos; i < n; ++i)
//	{
//		swap(PCB[pos], PCB[i]);
//		curCost = cost(pos, conn, PCB);
//		if (curCost < *minCost)
//			dfs(pos + 1, curCost, minCost, PCB, n, conn, finalPCB);
//		swap(PCB[pos], PCB[i]);
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int conn[20][20] = { 0 };
//	bool notused[20] = { true };
//	int PCB[20];
//	int finalPCB[20];
//	int minCost = 10000000;
//
//	// input and init
//	for (int i = 0; i <= n - 1; ++i)
//	{
//		for (int j = i + 1; j <= n - 1; ++j)
//		{
//			cin >> conn[i][j];
//			conn[j][i] = conn[i][j];
//		}
//		PCB[i] = i;
//		conn[i][i] = 0;
//	}
//
//	dfs(0, 0, &minCost, PCB, n, conn, finalPCB);
//	cout << minCost << endl;
//	cout << finalPCB[0] + 1;
//	for (int i = 1; i < n; ++i)
//		cout << ' ' << finalPCB[i] + 1;
//	cout << endl;
//	return 0;
//}

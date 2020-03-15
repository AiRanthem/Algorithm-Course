////设有 n 件工作分配给 n 个人。将工作 i 分配给第 j 个人所需的费用为cij 。试设计一个算
////法，为每一个人都分配 1 件不同的工作，并使总费用达到最小。
////
////设计一个算法，对于给定的工作费用，计算最佳工作分配方案，使总费用达到最小。
////#include <iostream>
////using namespace std;
////
////void dfs(int worker, int cur, int *min, int n, bool toArrange[], int cost[][20])
////{
////	int t = 0;
////	for (int i = 0; i < n; ++i)
////	{
////		if (toArrange[i])
////		{
////			toArrange[i] = false;
////			t = cur + cost[i][worker];
////			if (t > * min)
////			{
////				toArrange[i] = true;
////				return;
////			}
////			if (worker == n - 1)
////			{ // exit
////				if (t < *min)
////					*min = t;
////				toArrange[i] = true;
////				return;
////			}
////			else
////			{
////				dfs(worker + 1, t, min, n, toArrange, cost);
////				toArrange[i] = true;
////			}
////		}
////	}
////}
////
////int main()
////{
////	int n;
////	cin >> n;
////	int cost[20][20] = { 0 };
////	bool toArrange[20] = { false };
////	for (int i = 0; i < n; ++i)
////	{
////		for (int j = 0; j < n; ++j)
////		{
////			cin >> cost[i][j];
////		}
////		toArrange[i] = true;
////	}
////
////	int min = 10000000;
////	dfs(0, 0, &min, n, toArrange, cost);
////
////	cout << min << endl;
////	return 0;
////}

//#include <iostream>
//using namespace std;
//int a[10];
//int n;
//int c[10][10];
//int minCost = 1000;
//
//int cost(int t)
//{
//	int sum = 0;
//	for (int i = 1; i <= t; ++i)
//		sum += c[i][a[i]];
//	return sum;
//}
//
//void dfs(int t)
//{
//	int curCost;
//	if (t == n)
//	{
//		curCost = cost(t);
//		if (curCost < minCost)
//			minCost = curCost;
//		return;
//	}
//
//	for (int i = t; i <= n; ++i)
//	{
//		swap(a[i], a[t]);
//		curCost = cost(t);
//		if (curCost < minCost)
//			dfs(t + 1);
//		swap(a[i], a[t]);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//			cin >> c[i][j];
//		a[i] = i;
//	}
//
//	dfs(1);
//	cout << minCost;
//	return 0;
//}
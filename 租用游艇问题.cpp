////问题描述：长江游艇俱乐部在长江上设置了n个游艇出租站1，2，....，n。游客可在这些游艇出租站租用游艇，并在下游的任何一个游艇出租站归还游艇。游艇出租站i到游艇出租站j之间的租金为r(i, j)，1 <= i <= j <= n。试设计一个算法，计算法出游艇出租站1到游艇出租站n的最少租金。
////
////算法设计：对于给定的游艇出租站i到游艇出租站j之间的租金为r(i, j)，1 <= i <= j <= n，计算出从游艇出租站1到游艇出租站n的最少租金
//#include <iostream>
//#include <climits>
//
//using namespace std;
//
//// 子结构：
//// 更新r即可。
//// r[i][j] = min( r[i][k] + r[k][j])
//
//int main()
//{
//	int r[201][201] = { 0 }; // direct cost
//	int n;
//
//	// inputs
//	cin >> n;
//	for (int i = 1; i <= n - 1; ++i)
//	{
//		for (int j = i + 1; j <= n; ++j)
//		{
//			cin >> r[i][j];
//		}
//	}
//
//	// r[i][j] = min( r[i][k] + r[k][j])
//	for (int step = 2; step <= n - 1; ++step)
//	{
//		for (int i = 1; i + step <= n; ++i)
//		{
//			int j = i + step; // 对角线遍历填表
//			int minVal = INT_MAX;
//			for (int k = i; k <= j; ++k) // 寻找k
//			{
//				if (r[i][k] + r[k][j] < minVal)
//					minVal = r[i][k] + r[k][j];
//			}
//			r[i][j] = minVal;
//		}
//	}
//
//	cout << r[1][n] << endl;
//	
//	return 0;
//}
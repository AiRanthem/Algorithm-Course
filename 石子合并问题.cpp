////在一个圆形操场的四周摆放着n 堆石子。现要将石子有次序地合并成一堆。规定每次只能选相邻的2 堆石子合并成新的一堆，并将新的一堆石子数记为该次合并的得分。试设计一个算法，计算出将n堆石子合并成一堆的最小得分和最大得分。
//
//#include <iostream>
//#include <climits>
//using namespace std;
//
//// 子结构
//// 使用a[n]存每一堆石子的个数
//// 使用M[i][j]存第i号以及后j堆产生的最大得分
//// 使用m[i][j]存第i号以及后j堆产生的最小得分
//// M[i][j] = max( M[i][k] + M[(i+k+1)%n][j-k-1] + sum(a[i:j])
//// m[i][j] = min( m[i][k] + m[(i+k+1)%n][j-k-1] + sum(a[i:i+j] )
//int sum(int a[], int i, int j, int n);
//
//int main()
//{
//	int a[100];
//	int M[100][100];
//	int m[100][100];
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//		M[i][0] = m[i][0] = 0;
//	}
//
//	// M[i][j] = max( M[i][k] + M[(i+k+1)%n][j-k-1] + sum(a[i:i+j] )
//	// m[i][j] = min( m[i][k] + m[(i+k+1)%n][j-k-1] + sum(a[i:i+j] )
//	for (int j = 1; j <= n - 1; ++j)
//	{
//		for (int i = 0; i <= n - 1; ++i)
//		{
//			int max = 0;
//			int min = INT_MAX;
//			for (int k = 0; k <= j - 1; ++k)
//			{
//				int big = M[i][k] + M[(i + k + 1) % n][j - k - 1] + sum(a, i, j, n);
//				int small = m[i][k] + m[(i + k + 1) % n][j - k - 1] + sum(a, i, j, n);
//				if (big > max)
//					max = big;
//				if (small < min)
//					min = small;
//			}
//			M[i][j] = max;
//			m[i][j] = min;
//		}
//	}
//
//	int Max = 0;
//	int Min = INT_MAX;
//	for (int i = 0; i <= n - 1; ++i) 
//	{
//		if (M[i][n - 1] > Max)	Max = M[i][n - 1];
//		if (m[i][n - 1] < Min)	Min = m[i][n - 1];
//	}
//
//	cout << Min << endl << Max << endl;
//
//	return 0;
//}
//
//
//int sum(int a[], int i, int j, int n)
//{
//	int retVal = 0;
//	for (int t = 0; t <= j; ++t)
//	{
//		retVal += a[(i+t)%n];
//	}
//	return retVal;
//}
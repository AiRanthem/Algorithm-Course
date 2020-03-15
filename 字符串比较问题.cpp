//#include <iostream>
//#include <string>
//#define MAX 30
//
//using namespace std;
//
///*
//	dp[i][j] = a串前i个，b串前j个最小
//
//	dp[i][j] = dp[i][j-1]
//		a a
//		bbb|b
//	dp[i][j] = dp[i-1][j]
//		a a|a
//		bbb
//	dp[i][j] = dp[i-1][j-1] + d(a,b)
//		aaa|a
//		bbb|b
//*/
//
//inline int d(char a, char b)
//{
//	return abs(a - b);
//}
//
//int minT(int a, int b, int c)
//{
//	if (a > b)
//		a = b;
//	if (a > c)
//		a = c;
//	return a;
//}
//
//int cmp(string a, string b, int k)
//{
//	int la = a.length(), lb = b.length();
//
//	int dp[MAX][MAX] = { 0 };
//
//	dp[0][0] = 0;
//
//	for (int i = 1; i <= la; ++i)
//		dp[i][0] = k * i;
//
//	for (int i = 1; i <= lb; ++i)
//		dp[0][i] = k * i;
//
//	for (int i = 1; i <= la; ++i)
//	{
//		for (int j = 1; j <= lb; ++j)
//		{
//			dp[i][j] = minT(
//				dp[i - 1][j] + k,
//				dp[i][j - 1] + k,
//				dp[i - 1][j - 1] + d(a[i - 1], b[j - 1])
//			);
//		}
//	}
//
//	return dp[la][lb];
//}
//
//int main()
//{
//	string a, b;
//	int k;
//	cin >> a >> b;
//	cin >> k;
//	
//	cout << cmp(a, b, k) << endl;
//
//	return 0;
//}
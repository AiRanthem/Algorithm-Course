////定义于字母表Σ = { a,b,c }的乘法表如下，
////
////           a        b       c
////       |_____________________
////  a    |   b        b       a
////       |
////  b    |   c        b       a
////       |
////  c    |   a        c       c
////
////依此乘法表，对任一定义域该乘法表上的字符串，适当加括号后得到一个表达式。例如，对于字符串x = bbbba，它加一个括号表达式为
////
////(b(bb)(ba))。依乘法表，该表达式的值为a。试设计一个动态规划算法，对任一定义于乘法表上的字符串x = x1....xn，计算有多少种不同的
////
////加括号方式，使得由x导出的加括号表达式的值为a。
////
////算法设计：对于给定的字符串x = x1....xn，计算有多少种不同的加括号方式，使由x导出的加括号表达式值为a。
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int map(int ch)
//{
//	switch (ch)
//	{
//	case 'a':return 0;
//	case 'b':return 1;
//	case 'c':return 2;
//	}
//}
//
//int main()
//{
//	int mul[3][3] = { {1,1,0},{2,1,0},{0,2,2} };
//	int str[255];
//	int ways[255][255][3];
//	int a = 0, b = 1, c = 2;
//	/*
//	 ways[i][j][a] = way of str[i:j] as 'a'.
//
//	 ways[i][j][a] = sum( ways[i][k][a] * ways[k+1][j][c]
//	                    + ways[i][k][b] * ways[k+1][j][c]
//	                    + ways[i][k][c] * ways[k+1][j][a] )
//	 
//   ways[i][j][b] = sum( ways[i][k][a] * ways[k+1][j][a]
//	                    + ways[i][k][a] * ways[k+1][j][b]
//	                    + ways[i][k][b] * ways[k+1][j][b] )
//
//	 ways[i][j][c] = sum( ways[i][k][b] * ways[k+1][j][a]
//	                    + ways[i][k][c] * ways[k+1][j][b]
//	                    + ways[i][k][c] * ways[k+1][j][c] )
//	*/
//
//	string input;
//	cin >> input;
//	int n = input.length();
//
//	for (int i = 1; i <= n; ++i)
//	{
//		str[i] = map(input[i-1]);
//		ways[i][i][a] = str[i] == a;
//		ways[i][i][b] = str[i] == b;
//		ways[i][i][c] = str[i] == c;
//	}
//
//	for (int step = 1; step <= n - 1; ++step)
//	{
//		for (int i = 1; i + step <= n; ++i)
//		{
//			int j = i + step;
//			int maxa = 0, maxb=0, maxc=0;
//			for (int k = i; k < j; ++k)
//			{
//			   /*ways[i][j][a] = sum( ways[i][k][a] * ways[k+1][j][c]
//									+ ways[i][k][b] * ways[k+1][j][c]
//									+ ways[i][k][c] * ways[k+1][j][a] )*/
//				int cura = ways[i][k][a] * ways[k + 1][j][c]
//					     + ways[i][k][b] * ways[k + 1][j][c]
//					     + ways[i][k][c] * ways[k + 1][j][a];
//
//			   /*ways[i][j][b] = sum(ways[i][k][a] * ways[k + 1][j][a]
//								   + ways[i][k][a] * ways[k + 1][j][b]
//			   					   + ways[i][k][b] * ways[k + 1][j][b] )*/
//				int curb = ways[i][k][a] * ways[k + 1][j][a]
//					     + ways[i][k][a] * ways[k + 1][j][b]
//					     + ways[i][k][b] * ways[k + 1][j][b];
//
//			   /*ways[i][j][c] = sum( ways[i][k][b] * ways[k+1][j][a]
//									+ ways[i][k][c] * ways[k+1][j][b]
//									+ ways[i][k][c] * ways[k+1][j][c] )*/
//				int curc = ways[i][k][b] * ways[k + 1][j][a]
//					     + ways[i][k][c] * ways[k + 1][j][b]
//					     + ways[i][k][c] * ways[k + 1][j][c];
//				maxa += cura;
//
//				maxb += curb;
//
//				maxc += curc;
//			}
//			ways[i][j][a] = maxa;
//			ways[i][j][b] = maxb;
//			ways[i][j][c] = maxc;
//		}
//	}
//
//	cout << ways[1][n][a] << endl;
//	return 0;
//}
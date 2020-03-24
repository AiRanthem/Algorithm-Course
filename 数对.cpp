////x和y均不大于n, 并且x除以y的余数大于等于k。
//
////输入描述:
////输入包括两个正整数n, k(1 <= n <= 10 ^ 5, 0 <= k <= n - 1)。
////输出描述 :
////对于每个测试用例, 输出一个正整数表示可能的数对数量。
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	// x, y <= n
//	// x % y >= k
//
//	unsigned long long cnt = 0;
//
//	if (k == 0)
//	{
//		cnt = n * n;
//	}
//	else
//	{
//		int base, offset;
//
//		for (int y = k + 1; y <= n; ++y)
//		{
//			base = (n / y) * (y - k);
//			offset = (n % y >= k) ? (n % y - k + 1) : 0;
//			cnt += base + offset;
//		}
//	}
//	cout << cnt;
//}
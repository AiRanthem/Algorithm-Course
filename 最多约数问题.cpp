//«问题描述：
//正整数 x 的约数是能整除 x 的正整数。正整数 x 的约数个数记为 div(x)。例如，1，2，5，10 都是正整数10 的约数，且 div(10) = 4。设 a 和 b 是 2 个正整数，a≤b，找出 a 和 b之间约数个数最多的数 x。
//«编程任务：
//对于给定的 2 个正整数 a≤b，编程计算 a 和 b 之间约数个数最多的数。

//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//int const MAX = 100005;
//int isPrime[MAX];
//int ma, cnt=-1, l, r;
//
//void get_primes()
//{
//	bool get[MAX];
//	memset(get, true, sizeof(get));
//	get[0] = get[1] = false;
//	for (int i = 2; i <= sqrt(MAX); i++)
//		if (get[i])
//			for (int j = i * i; j < MAX; j += i)
//				get[j] = false;
//	for (int i = 2; i <= MAX; i++)
//		if (get[i])
//			isPrime[++cnt] = i;
//}
//
//
//void search(int from, int tot, int num, int left, int right)
//{
//	ma = tot > ma ? tot : ma;
//	if ((left == right) && (left > num))
//		search(from, tot * 2, num * left, 1, 1);
//	for (int i = from; i <= cnt; i++)
//	{
//		if (isPrime[i] > right)
//			return;
//		else
//		{
//			int j = isPrime[i], x = left - 1, y = right, n = num, t = tot, m = 1;
//			while (true)
//			{
//				m++;
//				t += tot;
//				x /= j;
//				y /= j;
//				if (x == y)
//					break;
//				n *= j;
//				search(i + 1, t, n, x + 1, y);
//			}
//			if (tot < (ma / (1 << m)))
//				return;
//		}
//	}
//}
//
////int main()
////{
////	cnt = 0;
////	get_primes();
////	while (scanf("%d %d", &l, &r) != EOF)
////	{
////		if ((l == 1) && (r == 1))
////			ma = 1;
////		else
////		{
////			ma = 2;
////			search(1, 1, 1, l, r);
////		}
////		printf("%d\n", ma);
////	}
////}
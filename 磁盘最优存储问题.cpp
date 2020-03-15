////题目描述：
////设有n 个程序{ 1,2,…, n }要存放在长度为L的磁带上。
////程序i存放在磁带上的长度是Li， 1 <= i <= n。
////这n 个程序的读取概率分别是p1, p2, ..., pn, 且pi + p2 + ... + pn = 1。
////如果将这n 个程序按 i1, i2, ...., in 的次序存放，
////则读取程序ir 所需的时间
////tr = c * (Pi1 * Li1 + Pi2 * Li2 + ... + Pir * Lir)。
////这n 个程序的平均读取 时间为t1 + t2 + ... + tn。 
////磁带最优存储问题要求确定这n 个程序在磁带上的一个存储次序，使平均读取时间达到 最小。
////试设计一个解此问题的算法, 并分析算法的正确性和计算复杂性。
////编程任务：
////对于给定的n个程序存放在磁带上的长度和读取概率，编程计算n个程序的最优存储方 案。
////输入：
////第一行是正整数n，表示文件个数。接下来的n行中， 每行有2 个正整数a 和b，分别表示程序存放在磁带上的长度和读取概率。实际上第k个程 序的读取概率ak / (a1 + a2 + ... + an)。对所有输入均假定c = 1。
////输出：
////输出一个实数，保留1位小数，表示计算出的最小平均读取时间。
//
////算法：就是短进程优先。排个序就行了。
//#include <iostream>
//using namespace std;
//void normalize(int n, double p[]);
//void sort(double t[], int low, int high);
//
//int main()
//{
//	int n;
//	cin >> n;
//	double p[10005], l[10005];
//	for (int i = 0; i < n; ++i)
//		cin >> l[i] >> p[i];
//	normalize(n, p);
//
//	// 用p表示t, 看不懂可以
//	for (int i = 0; i < n; ++i)
//		p[i] = p[i] * l[i];
//	
//	sort(p, 0, n - 1);
//
//	double time = 0;
//	for (int i = 0; i < n; ++i)
//		time += p[i] * (n - i);
//
//	printf("%.1f\n", time);
//	return 0;
//}
//
//void normalize(int n, double p[])
//{
//	double sum = 0;
//	for (int i = 0; i < n; ++i)
//		sum += p[i];
//	for (int i = 0; i < n; ++i)
//		p[i] = p[i] / sum;
//}
//
//void sort(double t[], int low, int high)
//{
//	if (low >= high)
//		return;
//	
//	double s = t[low];
//	int i = low, j = high;
//	
//	while (i < j)
//	{
//		while (i < j && t[j] >= s) --j;
//		t[i] = t[j];
//		while (i < j && t[i] <= s) ++i;
//		t[j] = t[i];
//	}
//	t[i] = s;
//	
//	sort(t, low, i - 1);
//	sort(t, i + 1, high);
//}
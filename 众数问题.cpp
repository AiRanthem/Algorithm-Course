////所谓众数，就是对于给定的含有N个元素的多重集合，每个元素在S中出现次数最多的成为该元素的重数， 多重集合S重的重数最大的元素成为众数。例如：S = { 1,2,2,2,3,5 }，则多重集S的众数是2，其重数为3。 现在你的任务是：对于给定的由m个自然数组成的多重集S，计算出S的众数及其重数。
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int ii = 0; ii < n; ++ii)
//	{
//		int time[100005] = { 0 }, m, curNum;
//		int maxTime = 0, max = -1;
//		cin >> m;
//		for (int i = 0; i < m; ++i)
//		{
//			cin >> curNum;
//			++time[curNum];
//			if (time[curNum] > maxTime)
//			{
//				maxTime = time[curNum];
//				max = curNum;
//			}
//		}
//		cout << max << ' ' << maxTime << endl;
//	}
//	
//	return 0;
//}

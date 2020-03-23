////小Q正在给一条长度为n的道路设计路灯安置方案。
////
////为了让问题更简单, 小Q把道路视为n个方格, 需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。
////
////小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
////
////小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//// ...XX....XX
//
//int main()
//{
//	int t; // num of test cases, [1,1000]
//	cin >> t;
//
//	int n;        // length of current road
//	char c[1000]; // '.' or 'x'
//	int idx;      // current position to analysis
//	int count;    // count of lights
//	for (int ii = 0; ii < t; ++ii)
//	{
//		cin >> n;
//		for (int i = 0; i < n; ++i)
//			cin >> c[i];
//		// init
//		idx = 0;
//		count = 0;
//
//		while (idx < n)
//		{
//			if (c[idx] == 'X')
//				++idx;
//			else // c[idx] == '.'
//			{
//				if (idx >= n-1)
//				{
//					idx += 2;
//					++count;
//				}
//				else
//				{
//					idx += 3;
//					++count;
//				}
//			}
//		}
//		cout << count << endl;
//	}
//}
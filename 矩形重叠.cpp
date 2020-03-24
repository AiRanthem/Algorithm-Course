////想要知道某个重合区域在多少个矩形内，可以转化为计算这个重合区域的左下角在多少个矩形内。
////外面两层循环遍历了所有重合区域可能的左下角，最里层循环计算这个左下角在多少个矩形内。这
////个算法可以保证一定能算出正确结果，但也算了很多额外的情况，有点像充分条件的意思。
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n, x1[50], x2[50], y1[50], y2[50];
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//		cin >> x1[i];
//	for (int i = 0; i < n; ++i)
//		cin >> y1[i];
//	for (int i = 0; i < n; ++i)
//		cin >> x2[i];
//	for (int i = 0; i < n; ++i)
//		cin >> y2[i];
//
//	int cnt = 0, ans = 0;
//	for (int x : x1)
//		for (int y : y1)
//		{
//			cnt = 0;
//			for (int i = 0; i < n; ++i)
//			{
//				if (x >= x1[i] && x < x2[i] && y >= y1[i] && y < y2[i])
//					++cnt;
//			}
//			if (cnt > ans)
//				ans = cnt;
//		}
//	cout << ans;
//	return 0;
//}

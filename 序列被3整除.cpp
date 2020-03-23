////小Q得到一个神奇的数列: 1, 12, 123, ...12345678910, 1234567891011...。
////并且小Q对于能否被3整除这个性质很感兴趣。
////小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	long l, r;
//	cin >> l >> r;
//
//	int offset = 0;
//	switch (l % 3)
//	{
//	case 1:l += 2; offset = 2; break;
//	case 2:l += 1; offset = 2; break;
//	default:offset = 1; break;
//	}
//	r -= l;
//	long full = r / 3 * 2;
//	switch (r % 3)
//	{
//	case 1:case 2:full += r % 3 - 1;
//	default:break;
//	}
//	cout << full + offset;
//}
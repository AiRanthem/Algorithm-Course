////输入描述:
////每个输入包含一个测试用例。
////每个测试用例的第一行包含一个正整数，表示转方向的次数N(N <= 1000)。
////接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。
////输出描述 :
////输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	char turn;
//	int offset = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> turn;
//		if (turn == 'L')
//			--offset;
//		else
//			++offset;
//	}
//	offset %= 4;
//	if (offset < 0)
//		offset += 4;
//	switch (offset)
//	{
//	case 1:cout << 'E'; break;
//	case 2:cout << 'S'; break;
//	case 3:cout << 'W'; break;
//	default:cout << 'N';
//	}
//}
////在数据加密和数据压缩中常需要对特殊的字符串进行编码。给定的字母表 A 由 26 个小写英文字母组成
////A = { a,b,…,z }。
////该字母表产生的升序字符串是指字符串中字母按照从左到右出现的次序与字母在字母表中出现的次序相同，且每个字符最多出现 1 次。
////例如，a, b, ab, bc, xyz 等字符串都是升序字符串。现在对字母表 A 产生的所有长度不超过 6 的升序字符串按照字典序排列并编码如下。
////1	2	…	26	27	28	…
////a	b	…	z	ab	ac	…
////对于任意长度不超过 6 的升序字符串，迅速计算出它在上述字典中的编码。
////
////«编程任务：
////对于给定的长度不超过 6 的升序字符串，编程计算出它在上述字典中的编码。
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
///*******问题分析*******/
//// 假设字符串有n位
//// 1、计算位数小于n位的所有情况。需要函数：长度为l的所有递增字符串的个数
//int numWithLength(int l);
//// 2、设最高位为x，求所有小于x开头的长度为n的字符串个数。需要函数：以a开头的长度为l的字符串个数
//int numStartWith(int a, int l);
//// 3、依次对每一位计算步骤2，直到结束。需要函数：计算从a到b(不包括b)开头的长为l的字符串个数
//int numStartBetween(int a, int b, int l);
//
///*******程序逻辑*******/
//
//int main()
//{
//	int n;
//	cin >> n;
//	string str;
//
//	for (int t = 0; t < n; t++)
//	{
//		cin >> str;
//		int len = str.length();
//		int output = 0;
//
//		// step 1
//		for (int l = 1; l < len; ++l)
//			output += numWithLength(l);
//
//		// step 2
//		output += numStartBetween('a', str[0], len);
//
//		// step 3
//		for (int i = 1; i < len; ++i)
//		{
//			output += numStartBetween(str[i - 1] + 1, str[i], len - i);
//		}
//
//		// output
//		cout << output + 1 << endl;
//	}
//
//	return 0;
//}
//
///*******函数实现*******/
//
//int numWithLength(int l)
//{
//	int num = 0;
//	for (int i = 'a'; i <= 'z'; ++i)
//		num += numStartWith(i, l);
//
//	return num;
//}
//
//int numStartWith(int a, int l)
//{
//	if (l == 1) return 1;
//	int num = 0;
//	for (int i = a + 1; i <= 'z'; ++i)
//		num += numStartWith(i, l - 1);
//
//	return num;
//}
//
//int numStartBetween(int a, int b, int l)
//{
//	int num = 0;
//	for (int i = a; i < b; ++i)
//	{
//		num += numStartWith(i, l);
//	}
//
//	return num;
//}

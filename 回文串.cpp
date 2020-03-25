////输入描述:
////输入一个字符串S 例如“aabcb”(1 <= |S| <= 50), | S | 表示字符串S的长度。
////输出描述 :
////符合条件的字符串有"a", "a", "aa", "b", "c", "b", "bcb"
////
////所以答案 : 7
//
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//bool isLoop(string subS) {
//	int l = subS.length();
//	for (int i = 0; i < l; ++i) {
//		if (subS[i] != subS[l - 1 - i])
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	int cnt = 0;
//	int l = s.length();
//	for (int offset = 0; offset < l; ++offset) {
//		for (int size = 1; size <= l - offset; ++size) {
//			string subS = s.substr(offset, size);
//			if (isLoop(subS))
//				++cnt;
//		}
//	}
//	cout << cnt;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	char c[100000];
//	cin >> c;
//	int n = 0, i = -1;
//	vector<int> opn; // ²Ù×÷Êý
//	vector<int> ops; // ²Ù×÷·û
//
//	while (c[++i] != '\0')
//	{
//		switch (c[i]) {
//		case '+':
//		case '-':
//			ops.push_back(c[i]);
//			opn.push_back(n);
//			n = 0;
//			break;
//		default:
//			n = n * 10 + c[i] - '0';
//			break;
//		}
//	}
//	opn.push_back(n);
//	int len = ops.size();
//	for (i = 0; i < len; ++i)
//	{
//		switch (ops[i]) {
//		case '+':opn[i + 1] += opn[i]; break;
//		case '-':opn[i + 1] = opn[i] - opn[i + 1]; break;
//		default:break;
//		}
//	}
//
//	cout << opn[len];
//}
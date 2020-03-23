//// 在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作
//// 每个输入包含一个测试用例。
//// 每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N <= 100000)和小伙伴的数量M(M <= 100000)。
//// 接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di <= 1000000000)和报酬Pi(Pi <= 1000000000)。
//// 接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai <= 1000000000)。
//// 保证不存在两项工作的报酬相同。
//
//// 对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Job {
//private:
//	int d, p; // difficulity, pay
//public:
//	void setD(int d) { this->d = d; }
//	void setP(int p) { this->p = p; }
//	int getP() { return p; }
//	int getD() { return d; }
//	Job(int d, int p) :d(d), p(p) {}
//	Job() :d(0), p(0) {}
//	bool operator<(Job& other)
//	{
//		return p > other.p;
//	}
//};
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//
//	int d, p;
//	vector<Job> jobs;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> d >> p;
//		jobs.push_back(Job(d, p));
//	}
//	sort(jobs.begin(), jobs.end());
//
//	int a;
//	vector<int> abilities;
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> a;
//		for (auto iter = jobs.begin(); iter != jobs.end(); ++iter)
//		{
//			if (iter->getD() <= a)
//			{
//				cout << iter->getP() << endl;
//				break;
//			}
//		}
//	}
//}
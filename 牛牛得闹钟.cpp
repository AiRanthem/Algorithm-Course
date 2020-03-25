////每个输入包含一个测试用例。
////每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N <= 100)。
////接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0 <= A < 24)时Mi(0 <= B < 60)分。
////接下来的一行包含一个整数，表示从起床算起他需要X(0 <= X <= 100)分钟到达教室。
////接下来的一行包含两个整数，表示上课时间为A(0 <= A < 24)时B(0 <= B < 60)分。
////数据保证至少有一个闹钟可以让牛牛及时到达教室。
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Clock
//{
//public:
//	Clock(int h, int m) {
//		this->h = h;
//		this->m = m;
//		timestap = h * 60 + m;
//	}
//
//	bool operator<(Clock& other) {
//		return timestap > other.timestap;
//	}
//
//	int getTimeStap() {
//		return timestap;
//	}
//
//	int geth() { return h; }
//	int getm() { return m; }
//
//private:
//	int h;
//	int m;
//	int timestap;
//};
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<Clock> alarms;
//	int h, m;
//
//	for (int i = 0; i < N; ++i) {
//		cin >> h >> m;
//		alarms.push_back(Clock(h, m));
//	}
//	sort(alarms.begin(), alarms.end());
//
//	int road_time;
//	cin >> road_time;
//
//	int class_time;
//	cin >> h >> m;
//	class_time = h * 60 + m;
//
//	for (auto iter = alarms.begin(); iter != alarms.end(); ++iter) {
//		if (iter->getTimeStap() + road_time <= class_time)
//		{
//			cout << iter->geth() << ' ' << iter->getm();
//			break;
//		}
//	}
//	return 0;
//}
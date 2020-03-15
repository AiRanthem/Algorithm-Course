//假设有n个任务由k个可并行工作的机器完成。完成任务i需要的时间为ti。试设计一个算法找出完成这n个任务的最佳调度，使得完成全部任务的时间最早。
//对任意给定的整数n和k，以及完成任务i需要的时间为ti，i = 1~n。编程计算完成这n个任务的最佳调度。
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int cmp(int a, int b)
//{
//	return a > b;
//}
//
//void smart_search(int no_work, int timeUsed, int timeUsedByMachine[], int *minTime, int timeCost[], int k, int n)
//{
//	if (timeUsed >= * minTime) return; // 重点：大于等于不是大于！如果已经用的时间等于最小时间，安排该工作后一定大于最小时间，要剪枝！
//	if (no_work >= n)
//	{   // exit
//		if (timeUsed < *minTime)
//			*minTime = timeUsed;
//		return;
//	}
//
//	for (int i = 0; i < k; ++i)
//	{
//		 把当前工作安排给 安排该工作后总工作时间依然不大于最小时间的 机器
//		int m = timeUsedByMachine[i] + timeCost[no_work];
//		if (m <= *minTime)
//		{
//			timeUsedByMachine[i] = m;
//			smart_search(no_work + 1, max(timeUsed, timeUsedByMachine[i]), timeUsedByMachine, minTime, timeCost, k, n);
//			 max的解释：如果timeUsed大，代表机器已经完成了之前的任务在等这个任务，机器空转一段时间；反之为任务等机器。
//			timeUsedByMachine[i] -= timeCost[no_work];
//		}
//	}
//}
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	int timeCost[100];
//	for (int i = 0; i < n; ++i)
//		cin >> timeCost[i];
//	sort(timeCost, timeCost + n, cmp);
//
//	int machineTime[100];
//	for (int i = 0; i < k; ++i)
//	{
//		machineTime[i] = 0;
//	}
//	int minTime = 100000;
//
//	smart_search(0, 0, machineTime, &minTime, timeCost, k, n);
//	cout << minTime << endl;
//	return 0;
//}

//
//#include <iostream>
//#include <cstdlib>
//#include <iomanip>
//#include <queue>
//using namespace std;
//
///*
//	优先级定义：
//	第一优先级：可以走的位置少的
//	第二优先级：距离边缘近的
//
//	算法：无论如何从中心点(M/2,N/2)开始，寻找一条哈密顿回路，然后将开始点作为起点。
//	证明：一个连通图存在哈密顿回路，则将任何一个点作为起点，经由哈密顿回路必定可以遍历所有点并回到起点。
//*/
//
//typedef struct {
//	int x;
//	int y;
//} Go;
//
//Go go[8] = { {-2, -1}, {-1, -2}, { 1, -2}, { 2, -1}, { 2, 1}, { 1, 2}, {-1, 2}, {-2, 1} };
//
//struct NextPos {
//	int nextPosSteps;        //表示下一位置有多少种走法；走法少的优先考虑
//	int nextPosDirection;    //下一位置相对于当前位置的方位
//	int nextPosToMidLength;  //表示当前位置距中间点距离；距离中间点远的优先考虑
//	bool operator < (const NextPos& a) const {
//		return nextPosSteps > a.nextPosSteps && nextPosToMidLength < a.nextPosToMidLength;
//	}
//
//};
//
//int board[100][100];
//int M, N; //棋盘大小
//
///*检测格子可行*/
//bool check(int x, int y) {
//	if (x >= 0 && x < M && y >= 0 && y < N && board[x][y] == 0)
//		return true;
//	return false;
//}
//
///*计算下一位置走法数*/
//int nextPosHasSteps(int x, int y) {
//	int steps = 0;
//	for (int i = 0; i < 8; ++i) {
//		if (check(x + go[i].x, y + go[i].y))
//			steps++;
//	}
//	return steps;
//}
//
///*判断是否回到起点*/
//bool returnStart(int x, int y) {
//	//校验下一步是否可以回到起点，也就是棋盘的中间位置
//	int midx = M / 2 - 1 , midy = N / 2 - 1;
//	//midx = M / 2 - 1;
//	//midy = N / 2 - 1;
//	for (int i = 0; i < 8; ++i)
//		if (x + go[i].x == midx && y + go[i].y == midy)
//			return true;
//	return false;
//}
//
///*距离棋盘中心*/
//int posToMidLength(int x, int y) {
//	int midx = M / 2 - 1;
//	int midy = N / 2 - 1;
//	return (abs(x - midx) + abs(y - midy));
//}
//
///*输出*/
//void outputResult(int xstart, int ystart) {
//	int total = M * N;
//	int k = total - board[xstart][ystart];
//	for (int i = 0; i < M; ++i) {
//		cout << endl << endl;
//		for (int j = 0; j < N; ++j) {
//			board[i][j] = (board[i][j] + k) % total + 1;
//			cout << setw(5) << board[i][j];
//		}
//	}
//	cout << endl << endl;
//}
//
///*进行遍历*/
//void BackTrace(int step, int x, int y, int xstart, int ystart) {
//	if (step == M * N && returnStart(x, y)) {
//		//巡游完毕
//		outputResult(xstart, ystart);
//		exit(0);
//	}
//	else {
//		priority_queue<NextPos> q;
//
//		// 从(x.y)开始的第一步：
//		for (int i = 0; i < 8; ++i) {
//			// 遍历八个方向
//			if (check(x + go[i].x, y + go[i].y)) {
//				// 如果可行则加入优先队列
//				NextPos aNextPos;
//				aNextPos.nextPosSteps = nextPosHasSteps(x + go[i].x, y + go[i].y);
//				aNextPos.nextPosDirection = i;
//				aNextPos.nextPosToMidLength = posToMidLength(x + go[i].x, y + go[i].y);
//				q.push(aNextPos);
//			}
//		}
//
//		/*回溯法*/
//		while (q.size()) {
//			// 1. 行走最优的一步
//			int d = q.top().nextPosDirection;
//			q.pop();
//			x += go[d].x;
//			y += go[d].y;
//			board[x][y] = step + 1; // 将对应格子标为第step步走到
//
//			// 2. 进行下一步
//			BackTrace(step + 1, x, y, xstart, ystart);
//
//			// 3. 如果回到了这里，说明没有找到最好的路径，则这一步回滚
//			board[x][y] = 0;
//			x -= go[d].x;
//			y -= go[d].y;
//		}
//	}
//}
//
//void riderKick(int xstart, int ystart) {
//	//初始化棋盘
//	for (int i = 0; i < M; i++)
//		for (int j = 0; j < N; j++)
//			board[i][j] = 0;
//	int midx = M / 2 - 1;
//	int midy = N / 2 - 1;
//	board[midx][midy] = 1; //从棋盘的中间的位置开始马周游
//	BackTrace(1, midx, midy, xstart, ystart);
//}
//
//int main() {
//	// 起始位置
//	int x, y;
//	srand(time(NULL));
//	x = rand() % 8;
//	y = rand() % 8;
//
//	// 棋盘大小，M * N
//	M = N = 8;
//	
//	// 从(x,y)开始
//	riderKick(x, y);
//
//	return 0;
//}
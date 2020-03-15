//#include <iostream>
//#include <cstring>
//
//#define N 50
//#define MAX 2147483647
//
//using namespace std;
//
//int m, n;
//int G[N][N];
//
//
//template<class T>
//class PriorityQueue
//{
//public:
//	int size;
//	T* data;
//
//public:
//	PriorityQueue();
//	~PriorityQueue();
//
//	int Size();
//	bool empty();
//	void push(T key);
//	void pop();
//	void clear();
//	T top();
//};
//
//template<class T>
//PriorityQueue<T>::PriorityQueue()
//{
//	data = (T*)malloc((100000) * sizeof(T));
//	size = 0;
//}
//
//template<class T>
//PriorityQueue<T>::~PriorityQueue()
//{
//	while (!empty())
//	{
//		pop();
//	}
//}
//
//template<class T>
//bool PriorityQueue<T>::empty()
//{
//	if (size > 0)
//		return false;
//	return true;
//}
//
//template<class T>
//void PriorityQueue<T>::push(T key)
//{
//	if (empty())
//	{
//		data[++size] = key;
//		return;
//	}
//
//	int i;
//
//	for (i = ++size; data[i / 2] > key; i /= 2)
//	{
//		data[i] = data[i / 2];
//	}
//	data[i] = key;
//}
//
//template<class T>
//T PriorityQueue<T>::top()
//{
//	return data[1];
//}
//
//template<class T>
//void PriorityQueue<T>::pop()
//{
//	int i, child;
//
//	T last = data[size--];
//
//	for (i = 1; i * 2 <= size; i = child)
//	{
//		child = i * 2;
//		if (child != size && data[child + 1] < data[child])
//			child++;
//		if (last > data[child])
//			data[i] = data[child];
//		else
//			break;
//	}
//	data[i] = last;
//}
//
//class HeapNode {
//public:
//	int i;     // 点号
//	int cut;   // 当前割边数
//	int edges; // 活边数
//	int x[N];  // 
//
//	HeapNode(int i, int cut, int edges) {
//		this->i = i;
//		this->cut = cut;
//		this->edges = edges;
//		memset(x, 0, sizeof(int) * N);
//	}
//
//	HeapNode(const HeapNode& heapNode) {
//		this->i = heapNode.i;
//		this->cut = heapNode.cut;
//		this->edges = heapNode.edges;
//		memcpy(x, heapNode.x, sizeof(int) * N);
//	}
//
//	bool operator > (const HeapNode& a) const {
//		return cut < a.cut;
//	}
//
//	bool operator < (const HeapNode& a) const {
//		return cut > a.cut;
//	}
//
//};
//
//HeapNode bestCut() {
//	PriorityQueue<HeapNode> Q;
//	HeapNode I(0, MAX, 0);
//	Q.data[0] = I;
//	HeapNode E(1, 0, m);
//	HeapNode best = E;
//	Q.push(E);
//
//	while (!Q.empty()) {
//		E = Q.top(); Q.pop();
//
//		if (E.i > n) {
//			if (E.cut > best.cut)
//				best = E;
//			continue;
//		}
//
//		HeapNode F = E;
//		// F：加入割集的情况
//		// E：不加入割集的情况
//		int i = F.i;
//		for (int j = 1; j <= n; j++) {
//			if (G[i][j]) {
//				if (F.x[j])
//					F.cut--; // 和集内点相连，割边减少
//				else {
//					F.cut++; // 和集外点相连，一条活边变为割边
//					F.edges--;
//				}
//			}
//		}
//		F.x[i] = 1; F.i++;
//		// 已有割边和活边之和为理论割边上限
//		if (F.cut + F.edges > best.cut)
//			Q.push(F);
//		if (E.cut + E.edges > best.cut) {
//			E.i++;
//			Q.push(E);
//		}
//	}
//	return best;
//}
//
//int main(int argc, char* argv[]) {
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++) {
//		int s, e;
//		cin >> s >> e;
//		G[s][e] = G[e][s] = 1;
//	}
//
//	HeapNode best = bestCut();
//	printf("%d\n", best.cut);
//	for (int i = 1; i < n; i++) {
//		printf("%d ", best.x[i]);
//	}
//	printf("%d", best.x[n]);
//}
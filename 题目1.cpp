#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[3][100000] = { 0 };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}
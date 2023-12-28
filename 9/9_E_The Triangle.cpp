#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110;
int N;
int triArr[MAXN][MAXN];
int stDp[MAXN][MAXN];
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> triArr[i][j];   
		}
	}
	for (int k = 0; k < N; ++k) {
		stDp[N - 1][k] = triArr[N - 1][k]; 
	}
	for (int i = N - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			stDp[i][j] = max(stDp[i + 1][j], stDp[i + 1][j + 1]) + triArr[i][j];
		}
	}
	cout << stDp[0][0] << endl;
	system("PAUSE");
	return 0;
}
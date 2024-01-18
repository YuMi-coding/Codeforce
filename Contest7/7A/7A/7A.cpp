#define _CRT_SECURE_NO_WARNINGS
#define USE_ONLINE_JUDGE
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 10;
const int N = 8;
vector<vector<char>> board;

int main() {
#ifndef USE_ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	board.resize(N);
	for (int i = 0; i < N; ++i) {
		board[i].resize(N);
		for (int j = 0; j < N; ++j) {
			scanf("%c", &board[i][j]);
		}
		getchar();
	}

	vector<int> row(N, 0);
	vector<int> col(N, 0);

	int ansCol = 0;
	for (int i = 0; i < N; ++i) {
		bool flag = false;
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == 'W') {
				flag = true;
				break;
			}
		}
		if (!flag) {
			++ansCol;
			row[i] = 1;
		}
	}

	int ansRow = 0;
	for (int j = 0; j < N; ++j) {
		bool flag = false;
		for (int i = 0; i < N; ++i) {
			if (board[i][j] == 'W') {
				flag = true;
				break;
			}
		}
		if (!flag) {
			++ansRow;
			col[j] = 1;
		}
	}

	if (ansRow == N) {
		printf("%d\n", ansRow);
	}else if(ansCol == N){
		printf("%d\n", ansCol);
	}
	else {
		printf("%d\n", ansCol + ansRow);
	}

	return 0;

}

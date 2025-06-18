using namespace std;
#include <iostream>
#include <vector>
#include <queue>
int row, col, len, tempy, tempx;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
struct dataset
{
	int z, y, x;
	bool operator < (const dataset& other) const {
		return z < other.z;
	}
};
dataset cur;

void solve() {
	cin >> row >> col;
	vector<vector<int>> height(row, vector<int>(col, 0));
	vector<vector<int>> arr(row, vector<int>(col, 0));
	priority_queue<dataset> que;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> height[i][j];
			que.push({ height[i][j], i, j });
		}
	}
	arr[0][0] = 1;
	len = que.size();
	for (int i = 0; i < len; i++) {
		cur = que.top(); que.pop();
		for (int j = 0; j < 4; j++) {
			tempy = cur.y + dy[j]; tempx = cur.x + dx[j];
			if (tempy >= 0 && tempy < row && tempx >= 0 && tempx < col && height[tempy][tempx] < height[cur.y][cur.x]) {
				arr[tempy][tempx] += arr[cur.y][cur.x];
			}
		}
	}
	cout << arr[row - 1][col - 1] << '\n';
}



int main() {
	solve();
	return 0;
}
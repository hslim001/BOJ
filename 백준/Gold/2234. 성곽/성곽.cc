using namespace std;
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
struct yx
{
	int y, x;
};
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int row, col, max_extent = 0, removed_max = 0, num = 0;
int arr[50][50];
bool visited[50][50];
int num_arr[50][50] = { 0 };
int cnts[2501] = { 0 };
void bfs(int y, int x) {
	int cnt = 1, ny, nx;
	++num;
	deque<yx> que;
	yx cur;
	que.push_back({ y, x });
	visited[y][x] = 1;
	num_arr[y][x] = num;
	while (!que.empty())
	{
		cur = que.front(); que.pop_front();
		for (int i = 0; i < 4; ++i) {
			if ((arr[cur.y][cur.x] & (1 << i)) != 0) continue;
			ny = cur.y + dy[i]; nx = cur.x + dx[i];
			if (ny < 0 || ny >= row || nx < 0 || nx >= col || visited[ny][nx] == 1) continue;
			++cnt;
			que.push_back({ ny, nx });
			visited[ny][nx] = 1;
			num_arr[ny][nx] = num;
		}
	}

	max_extent = max(max_extent, cnt);
	cnts[num] = cnt;
}



void find() {
	int ny, nx;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (arr[i][j] & (1 << i) == 0) continue;
				ny = i + dy[k]; nx = j + dx[k];
				if (ny < 0 || ny >= row || nx < 0 || nx >= col || num_arr[ny][nx] == num_arr[i][j]) continue;
				removed_max = max(cnts[num_arr[i][j]] + cnts[num_arr[ny][nx]], removed_max);
			}
		}
	}
}

int main()
{	
	cin >> col >> row;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> arr[i][j];
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (visited[i][j] == 1) continue;
			bfs(i, j);
		}
	}
	find();
	cout << num << '\n' << max_extent << '\n' << removed_max << '\n';
	return 0;
}
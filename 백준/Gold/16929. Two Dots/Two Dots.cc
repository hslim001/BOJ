using namespace std;
#include <iostream>
#include <vector>
#include <deque>
struct yx
{
	int y, x, num, cnt;
};
int row, col;
char arr[50][50];

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };


bool bfs(int y, int x) {
	deque<yx> que;
	yx visited[50][50] = { 0 };
	visited[y][x].cnt = 1;
	yx cur;
	int ny, nx;
	char gijun = arr[y][x];
	for (int i = 0; i < 4; ++i) {
		ny = y + dy[i]; nx = x + dx[i];
		if (ny < 0 || ny >= row || nx < 0 || nx >= col || arr[ny][nx] != gijun) continue;
		visited[ny][nx].cnt = 2;
		visited[ny][nx].num = i;
		que.push_back({ ny, nx, i, 2 });
	}


	while (!que.empty())
	{
		cur = que.front(); que.pop_front();

		for (int i = 0; i < 4; ++i) {
			ny = cur.y + dy[i]; nx = cur.x + dx[i];
			if (ny < 0 || ny >= row || nx < 0 || nx >= col || arr[ny][nx] != gijun) continue;
			if (visited[ny][nx].cnt != 0 ) {
				if (visited[ny][nx].num != cur.num && cur.cnt + visited[cur.y][cur.x].cnt - 2 >= 4 ) {
					return 1;
				}
			}
			else {
				visited[ny][nx].cnt = cur.cnt + 1;
				visited[ny][nx].num = cur.num;
				que.push_back({ ny, nx, cur.num, cur.cnt + 1});
			}
		}
	}
	return 0;
}
bool solve() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {

			bool ret = bfs(i, j);
			if (ret == 1) {
				return 1;
			}
		}
	}
	return 0;
}

int main()
{	
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> arr[i][j];
		}
	}

	if (solve() == 1) {
		cout << "Yes" << '\n';
	}
	else {
		cout << "No" << '\n';
	}

	return 0;
}
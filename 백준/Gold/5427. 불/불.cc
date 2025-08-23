using namespace std;
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
struct yx
{
	int y, x;
};
int row, col;
char arr[1000][1000];
bool visited[1000][1000];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
yx start;
deque<yx> que;
deque<yx> fire_que;
void solve() {
	fire_que.clear();
	que.clear();
	memset(visited, 0, sizeof(visited));
	cin >> col >> row;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') fire_que.push_back({ i, j });
			if (arr[i][j] == '@') {
				que.push_back({ i, j }); 
				visited[i][j] = 1;
			}
		}
	}
	yx cur;
	int ny, nx, cnt = 0;
	while (!que.empty())
	{	
		++cnt;
		int size = fire_que.size();
		for (int i = 0; i < size; ++i) {
			cur = fire_que.front(); fire_que.pop_front();
			for (int j = 0; j < 4; ++j) {
				ny = cur.y + dy[j]; nx = cur.x + dx[j];
				if (ny < 0 || ny >= row || nx < 0 || nx >= col || arr[ny][nx] != '.') continue;
				fire_que.push_back({ ny, nx });
				arr[ny][nx] = '*';
			}
		}
		size = que.size();
		for (int i = 0; i < size; ++i) {
			cur = que.front(); que.pop_front();
			if (cur.y == 0 || cur.y == row - 1 || cur.x == 0 || cur.x == col - 1) {
				cout << cnt << '\n';
				return;
			}
			for (int j = 0; j < 4; ++j) {
				ny = cur.y + dy[j]; nx = cur.x + dx[j];
				if (ny < 0 || ny >= row || nx < 0 || nx >= col || arr[ny][nx] != '.') continue;
				que.push_back({ ny, nx });
				arr[ny][nx] = '*';
			}
		}
		
	}
	cout << "IMPOSSIBLE" << '\n';
	return;
}
int main()
{
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		solve();
	}
	return 0;
}
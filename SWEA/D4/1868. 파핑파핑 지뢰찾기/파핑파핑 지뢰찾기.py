using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
vector<string> arr;
bool visited[300][300];
int map[300][300];
int dy[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int length;
int cnt;
void dfs(int y, int x) {
	cnt--;
	if (map[y][x] > 0) return;
	int tempy, tempx;
	
	
	for (int k = 0; k < 8; ++k) {
		tempy = y + dy[k]; tempx = x + dx[k];
		if (tempy < 0 || tempy >= length || tempx < 0 || tempx >= length || visited[tempy][tempx]) continue;
		if (arr[tempy][tempx] == '*') continue;
		visited[tempy][tempx] = 1;
		dfs(tempy, tempx);
	}
}
int solve() {
	arr.clear();
	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
	cnt = 0;
	cin >> length;
	string input;
	for (int i = 0; i < length; ++i) {
		cin >> input;
		arr.push_back(input);
	}

	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (arr[i][j] == '*') {
				map[i][j] = 1000;
				int tempy, tempx;
				for (int k = 0; k < 8; ++k) {
					tempy = i + dy[k]; tempx = j + dx[k];
					if (tempy < 0 || tempy >= length || tempx < 0 || tempx >= length) continue;
					if (arr[tempy][tempx] == '*') continue;
					map[tempy][tempx] += 1;
				}
			}
			else
			{
				cnt++;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (arr[i][j] == '*' || map[i][j] > 0) continue;

			visited[i][j] = 1;
			dfs(i, j);
			result++;
		}
	}
	return result + cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cout << '#' << tc << ' ' << solve() << '\n';
	}
	return 0;
}
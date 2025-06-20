using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
int length, num;
int arr[200][200];
int sec, targety, targetx;
map<int, vector<pair<int, int>>> dict;

int time, tempy, tempx;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
bool visited[200][200];
pair<int, int> cur;
vector<pair<int, int>> memo;
void delta(int val) {
	memo.clear();
	for (int i = 0; i < dict[val].size(); i++) {
		cur = dict[val][i];
		for (int j = 0; j < 4; j++) {
			tempy = cur.first + dy[j]; tempx = cur.second + dx[j];
			if (tempy >= 0 && tempy < length && tempx >= 0 && tempx < length && arr[tempy][tempx] == 0) {
				memo.push_back(make_pair(tempy, tempx));
				arr[tempy][tempx] = val;
			}
		}
	}

	dict[val] = memo;

	
}
void solve() {
	cin >> length >> num;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				dict[arr[i][j]].push_back(make_pair(i, j));
			}
		}
	}
	cin >> sec >> targety >> targetx;
	while (time < sec)
	{
		time++;
		for (int i = 1; i <= num; i++) {
			delta(i);
		}
	}
	
	//for (int i = 0; i < length; i++) {
	//	for (int j = 0; j < length; j++) {
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	cout << arr[targety - 1][targetx - 1] << '\n';
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int num, result = 1e9;
vector<vector<int>> arr;
vector<int> startTeam, linkTeam;

void calculate() {
    int start = 0, link = 0;
    
    // startTeam 능력치 계산
    for (int i = 0; i < startTeam.size(); i++) {
        for (int j = i + 1; j < startTeam.size(); j++) {
            int a = startTeam[i], b = startTeam[j];
            start += arr[a][b] + arr[b][a];
        }
    }
    
    // linkTeam 능력치 계산
    for (int i = 0; i < linkTeam.size(); i++) {
        for (int j = i + 1; j < linkTeam.size(); j++) {
            int a = linkTeam[i], b = linkTeam[j];
            link += arr[a][b] + arr[b][a];
        }
    }
    
    result = min(result, abs(start - link));
}

void dfs(int idx, int cnt) {
    if (cnt == num/2) {
        linkTeam.clear();
        for (int i = 0; i < num; i++) {
            if (find(startTeam.begin(), startTeam.end(), i) == startTeam.end()) {
                linkTeam.push_back(i);
            }
        }
        calculate();
        return;
    }
    
    for (int i = idx; i < num; i++) {
        startTeam.push_back(i);
        dfs(i + 1, cnt + 1); // 다음 인덱스부터 탐색
        startTeam.pop_back();
    }
}

int main() {
    cin >> num;
    arr.resize(num, vector<int>(num));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
        }
    }
    
    // 0번 선수 고정 (대칭성 최적화)
    startTeam.push_back(0);
    dfs(1, 1); // 1번 인덱스부터 탐색
    cout << result;
    
    return 0;
}

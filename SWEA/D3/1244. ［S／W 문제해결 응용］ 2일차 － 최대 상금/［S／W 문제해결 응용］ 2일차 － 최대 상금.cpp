#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
int max_val = 0;
unordered_set<string> visited[10];
void dfs(string num, int cnt, int limit){
    if (cnt == limit){
        max_val = max(max_val, stoi(num));
        return;
    }
    if (visited[cnt].count(num)){
        return;
    }else{
        visited[cnt].insert(num);
    }
    char temp;
    for (int i = 0; i < num.length(); i++){
        for (int j = i + 1; j < num.length(); j++){
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
            dfs(num, cnt+1, limit);
            temp = num[j];
            num[j] = num[i];
            num[i] = temp;
        }
    }
    return;
}

void solve(){
    string num;
    max_val = 0;
    int change; cin >> num >> change;
    for (int i = 0; i < 10; i++){
        visited[i].clear();
    }
    dfs(num, 0, change);
    cout << max_val;
}

int main() {   
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << " ";
        solve();
        cout << "\n";

    }
    return 0;
}
#include <iostream>
using namespace std;


int dfs(int n, int m,int cnt, int val){
    if (cnt == m){
        return val;
    }
    return dfs(n, m, cnt + 1, val * n);
}
void solve(){
    int tc; cin >> tc;
    int n, m; cin >> n >> m;
    int result = dfs(n, m, 0, 1);
    cout << result;
}

int main() {   
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 10; //cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << " ";
        solve();
        cout << "\n";

    }
    return 0;
}
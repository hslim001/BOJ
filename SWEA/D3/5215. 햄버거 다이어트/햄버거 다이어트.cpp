#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


void solve(){
    int num, limit; cin >> num >> limit;
    vector<int> dp(limit + 1, 0);
    for (int j = 0; j < num; j++){
        int score, kcal; cin >> score >> kcal;
        for (int i = limit; i >= kcal; i--){
            dp[i] = max(dp[i - kcal] + score, dp[i]);
        }
    }
    cout << dp[limit];
}

int main() {   
    //freopen("input.txt", "r", stdin);
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
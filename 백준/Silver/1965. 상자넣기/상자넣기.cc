#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


void solve(){
    int length; cin >> length;
    vector<int> arr(length, 0);
    vector<int> dp(length, 0);
    for(int i=0; i < length; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i< length; i++){
        for(int j=0; j < i; j++){
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) + 1 << "\n";
}

int main() {   
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
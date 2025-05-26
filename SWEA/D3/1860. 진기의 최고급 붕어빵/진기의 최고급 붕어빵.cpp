#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


void solve(){
    int num, time, operate; cin >> num >> time >> operate;
    vector<int> arr(num, 0);
    for (int i = 0; i < num; i++) cin >> arr[i];
    sort(arr.begin(), arr.end()); 
    int cur_time = 0, cur_oper = 0, sold = 0;
    for (int arrive : arr){
        sold++;
        cur_oper = (arrive / time) * operate - sold;
        if (cur_oper < 0){
            cout << "Impossible" << "\n";
            return;
        }
        
    }
    cout << "Possible" << "\n";
    
}

int main() {   
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << '#' << tc << ' ';
        solve();
    }
}
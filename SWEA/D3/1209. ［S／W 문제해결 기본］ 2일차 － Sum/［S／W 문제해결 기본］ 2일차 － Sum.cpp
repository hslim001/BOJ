#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


void solve(){
    int tc; cin >> tc;
    int arr[100][100] = {0};
    int max_val = 0, sum_val = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 100; i++){
        sum_val = 0;
        for (int j = 0; j < 100; j++){
            sum_val += arr[i][j];
        }
        max_val = max(max_val, sum_val);
    }

    for (int i = 0; i < 100; i++){
        sum_val = 0;
        for (int j = 0; j < 100; j++){
            sum_val += arr[j][i];
        }
        max_val = max(max_val, sum_val);
    }
    sum_val = 0;
    for (int i = 0; i < 100; i++){
        sum_val += arr[i][i];
    }
    max_val = max(max_val, sum_val);
    sum_val = 0;
    for (int i = 0; i < 100; i++){
        sum_val += arr[i][99 - i];
    }
    max_val = max(max_val, sum_val);

    cout << max_val;

}

int main() {   
    //freopen("input.txt", "r", stdin);
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
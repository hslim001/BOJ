#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

void solve(){
    int length; cin >> length;
    vector<vector<int>> arr(length, vector<int>(length, 0));
    for (int i = 0; i < length; i++){
        string temp; cin >> temp;
        for (int j = length - 1; j >= 0; j--){
            arr[i][j] = temp[j] - '0';
        }
    }
    int sum_val = 0;
    int mid = length / 2;
    for (int i = 0; i < mid; i++){
        for (int j = mid - i; j < length - mid + i; j++){
            sum_val += arr[i][j];
        }
    }
    for (int i = 0; i <= mid; i++){
        for (int j = i; j < length - i; j++){
            sum_val += arr[mid + i][j];
        }
    }
    cout << sum_val;
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
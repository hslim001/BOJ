#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


void solve(){
    int length; cin >> length;
    int limit = length / 2;
    vector<vector<char>> arr(8, vector<char>(8));
    string temp;
    for(int i=0; i < 8; i++){
        cin >> temp;
        for(int j = 0; j < 8; j++){
            arr[i][j] = temp[j];
        }
    }
    int cnt = 0, flag = 0;
    for(int i=0; i < 8; i++){
        for(int j = 0; j <= 8 - length; j++){
            flag = 0;
            for(int k = 0; k < limit; k++){
                if (arr[i][j + k] != arr[i][j + length - k - 1]){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) cnt++;
            
        }
    }
    for(int i=0; i < 8; i++){
        for(int j = 0; j <= 8 - length; j++){
            flag = 0;
            for(int k = 0; k < limit; k++){
                if (arr[j  + k][i] != arr[j + length - k - 1][i]){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) cnt++;
            
        }
    }
    cout << cnt;
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
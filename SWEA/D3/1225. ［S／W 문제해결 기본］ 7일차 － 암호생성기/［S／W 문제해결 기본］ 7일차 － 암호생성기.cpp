#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
void solve(){
    int tc; cin >> tc;
    int temp = 0;
    queue<int> arr; 
    for(int i = 0; i < 8; i ++) {
        cin >> temp;
        arr.push(temp);
    }
    int val = 0;
    while (1)
    {
        val++;
        if (val == 6) val = 1;

        temp = arr.front(); arr.pop();
        temp -= val;
        if (temp <= 0){
            temp = 0;
            arr.push(temp);
            break;
        }
        arr.push(temp);
        
    }
    for(int i = 0; i < 8; i ++) {
        temp = arr.front(); arr.pop();
        cout << temp << " ";
    }
    
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
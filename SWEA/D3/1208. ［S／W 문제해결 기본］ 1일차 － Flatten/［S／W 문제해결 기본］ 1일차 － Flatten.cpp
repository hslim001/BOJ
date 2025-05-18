#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

void solve(){
    int dump; cin >> dump;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    int temp;
    for (int i = 0; i < 100; i++){
        cin >> temp;
        maxh.push(temp);minh.push(temp);
    }
    int top, bottom;
    for (int i = 0; i < dump; i++){
        top = maxh.top(); maxh.pop();
        bottom = minh.top(); minh.pop();
        if (top - bottom <= 1){
            maxh.push(top); minh.push(bottom);
            break;
        }
        top--; bottom++;
        maxh.push(top); minh.push(bottom);
    }
    top = maxh.top();
    bottom = minh.top();
    cout << top - bottom;
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
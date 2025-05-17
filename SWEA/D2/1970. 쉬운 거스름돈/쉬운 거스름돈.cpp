#include <iostream>
using namespace std;
#include <vector>

void find(){
    int coin[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
    int cnt[8] = {0};
    int money; cin >> money;
    for (int i = 0; i < 8; i++){
        cnt[i] = money / coin[i];
        money = money % coin[i];
        cout << cnt[i] << " ";
    }

    cout << "\n";
}


int main() {
    
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 0; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << "\n";
        find();

    }
    return 0;
}
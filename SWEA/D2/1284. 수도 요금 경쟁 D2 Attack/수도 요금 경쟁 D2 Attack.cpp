#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



void find(){
    int liter, gibon, gijun, chogwa, use;
    int a_cost, b_cost;
    cin >> liter >> gibon >> gijun >> chogwa >> use;
    a_cost = liter * use;
    b_cost = gibon;
    b_cost += use <= gijun ?  0 : (use - gijun) * chogwa;
    cout << (a_cost < b_cost ? a_cost : b_cost);
}

int main() {   
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T = 0; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << " ";
        find();
        cout << "\n";

    }
    return 0;
}
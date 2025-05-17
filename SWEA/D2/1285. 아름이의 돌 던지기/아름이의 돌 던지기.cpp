#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



void find(){
    int num; cin >> num;
    int val = 0, min_val = 99999999, cnt = 0;
    for (int i=0; i < num; i++){
        cin >> val;
        if (abs(val) < min_val){
            min_val = abs(val); cnt = 1;
        }else if(abs(val) == min_val){
            cnt += 1;
        }
    }
    cout << min_val << " "<< cnt;
}

int main() {   
   // freopen("input.txt", "r", stdin);
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
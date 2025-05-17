#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void find(){
    int cnt = 0;
    int num; cin >> num;
    for (int i = 0; i < num; i++){
        char alpha; int length; cin >> alpha >> length;
        for (int j = 0; j < length; j++){
            cnt ++;
            cout << alpha;
            if (cnt % 10 == 0){
                cout << "\n";
            }
        }
    }
    if (cnt % 10 != 0){
        cout << "\n";
    }
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
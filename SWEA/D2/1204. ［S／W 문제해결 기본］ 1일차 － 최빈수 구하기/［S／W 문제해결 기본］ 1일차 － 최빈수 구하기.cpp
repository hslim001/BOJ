#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



void find(){
    int arr[101] = {0};
    int TC; cin >> TC;
    int score;
    for (int i=0; i < 1000; i++){
        cin >> score;
        arr[score] += 1;
    }
    int max = -1, idx = 0;
    for (int i=0; i <= 100; i++){
        if (arr[i] >= max){
            max = arr[i];
            idx = i;
        }
    }
    cout << idx;
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
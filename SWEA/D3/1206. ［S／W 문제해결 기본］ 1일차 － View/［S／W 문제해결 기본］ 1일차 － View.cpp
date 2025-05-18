#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



void find(){
    int num; cin >> num;
    vector<int> arr(num, 0);
    for (int i=0; i < num; i++){
        cin >> arr[i];
    }
    int val = 0;
    int result = 0;
    for (int i=2; i < num - 2; i++){
        val = max({arr[i-2], arr[i-1], arr[i + 1], arr[i + 2]});
        if (arr[i] > val){
            result += arr[i] - val;
        }
    }
    cout << result;
}

int main() {   
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T = 10; //cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << " ";
        find();
        cout << "\n";

    }
    return 0;
}
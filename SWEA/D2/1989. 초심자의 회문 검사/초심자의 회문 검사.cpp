#include <iostream>
using namespace std;
#include <vector>
#include <stack>


int main() {
    //freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        string arr; cin >> arr;
        int flag = 1;
        for (int i = 0; i < arr.length() / 2; i++){
            if (arr[i] != arr[arr.length() - 1 - i]){
                flag = 0;
            }
        }
        cout << "#" << tc << " ";
        if (flag){
            cout << 1;}
        else{
            cout << 0;}
        cout << "\n";
    }

    return 0;
}
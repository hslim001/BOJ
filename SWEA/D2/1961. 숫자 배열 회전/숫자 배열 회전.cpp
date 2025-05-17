#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void find(){
    int length; cin >> length;
    vector<vector<int>> arr(length, vector<int>(length, 0));
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < length; i++){
        for (int j=0; j < length; j++){
            cout << arr[length - j - 1][i];
        }
        cout << " ";
        for (int j=0; j < length; j++){
            cout << arr[length - i - 1][length - 1 - j];
        }
        cout << " ";
        for (int j=0; j < length; j++){
            cout << arr[j][length - i - 1];
        }
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
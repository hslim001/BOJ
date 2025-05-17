#include <iostream>
using namespace std;
#include <vector>

int find(){
    int length = 9;
    int arr[length][length];
    for (int i = 0; i < length; i++){
        for (int j=0; j < length; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < length; i++){
        int cnt_arr[10] = {0};
        for (int j = 0; j < length; j++){
            if (cnt_arr[arr[i][j]]){
                return 0;
            }else{
                cnt_arr[arr[i][j]] = 1;
            }
        }
    }
    for (int i = 0; i < length; i++){
        int cnt_arr[10] = {0};
        for (int j = 0; j < length; j++){
            if (cnt_arr[arr[j][i]]){
                return 0;
            }else{
                cnt_arr[arr[j][i]] = 1;
            }
        }
    }

    for (int y = 0; y < length; y+=3){
        for (int x=0; x < length; x+=3){
            int cnt_arr[10] = {0};
            for (int i = y; i < y + 3; i++){
                for (int j = x; j < x + 3; j++){
                    if (cnt_arr[arr[i][j]]){
                        return 0;
                    }else{
                        cnt_arr[arr[i][j]] = 1;
                    }
                }
            }
        }
    }

    return 1;
}


int main() {
    
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 0; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        int result = find();
        cout << "#" << tc << " " << result << "\n";
    }
    return 0;
}
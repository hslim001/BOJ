#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void find(){
    int num; cin >> num;
    int cnt[5] = {0};
    int numbers[5] = {2, 3, 5, 7, 11};
    for (int i = 0; i < 5; i++){
        while (1)
        {
            if (num % numbers[i] == 0){
                cnt[i]++;
                num /= numbers[i];
            }else{
                break;
            }
        }
    }
    for(int i=0; i < 5; i++){
        cout << " " << cnt[i];
    }
}


int main() {   
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 0; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << "";
        find();
        cout << "\n";

    }
    return 0;
}
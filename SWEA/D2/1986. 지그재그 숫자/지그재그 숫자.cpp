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
        int num; cin >> num;
        int sum = 0;
        for (int i = 1; i <= num; i++){
            if (i % 2 == 0){
                sum -= i;
            }else{
                sum += i;
            }
        }
        cout << "#" << tc << " " << sum << "\n";
    }

    return 0;
}
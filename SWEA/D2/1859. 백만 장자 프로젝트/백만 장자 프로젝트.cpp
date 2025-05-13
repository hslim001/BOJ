#include <iostream>
using namespace std;
#include <vector>

long long find(int num, int arr[1000000]){
    long long sum_val = 0;
    int sell_day = num - 1;
    for (int i = num - 1; i >=0; i--){
        if (arr[sell_day] > arr[i]){
            sum_val += arr[sell_day] - arr[i];
        }else{
            sell_day = i;
        }
    }
    return sum_val;
}


int arr[1000000] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int T; cin >> T;

    int num;

    long long result = 0;
    for (int tc = 1; tc <= T; tc++){
        cin >> num;
        for (int i = 0; i < num; i++){
            cin >> arr[i];
        }
        result = find(num, arr);
        cout << "#" << tc << " " << result << endl;
        
    }

    return 0;
}
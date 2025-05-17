#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <bitset>


void find(){
    long long num; cin >> num;
    int arr[10] = {0}, cnt = 0;
    long long current = 0;
    int sum = 0;
    while (1)
    {   
        cnt ++;
        current = cnt * num;
        while (current)
        {
            arr[current % 10] = 1;
            current = current / 10;
        }
        sum = 0;
        for (int i = 0; i < 10; i++){
            sum += arr[i];
        }
        if (sum == 10){
            break;
        }

    }
    cout <<  cnt * num;
}

int main() {   
  //  freopen("input.txt", "r", stdin);
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
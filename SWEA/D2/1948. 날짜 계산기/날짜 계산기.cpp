#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void find(){
    int start_month, start_date, end_month, end_date;
    cin >> start_month >> start_date >> end_month >> end_date;
    vector<int> arr = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 1;
    for (int i = start_month; i <= end_month; i++){
        if (i == start_month){
            day += arr[i] - start_date;
        }else if (i == end_month){
            day += end_date;
        }else{
            day += arr[i];
        }
    }
    cout << day;
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
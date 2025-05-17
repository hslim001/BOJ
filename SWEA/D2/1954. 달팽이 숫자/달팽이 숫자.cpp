#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void find(){
    int num; cin >> num;
    vector<vector<int>> arr(num, vector<int>(num, 0));
    int direc = 0; int cnt = 0;
    int limit = num * num;

    int y = 0, x = 0;
    while (cnt < limit)
    {   
        cnt++;

        switch (direc)
        {
        case 0:
            arr[y][x] = cnt; 
            
            if (0 <= y && y <num && 0 <= x + 1 && x + 1 <num && arr[y][x + 1] == 0){
                x++;
            }else{
                direc = (direc + 1) % 4;
                y++;
            }
            break;
        case 1:
            arr[y][x] = cnt;
            if (0 <= y + 1 && y + 1 < num && 0 <= x && x < num && arr[y + 1][x] == 0){
                y++;
            }else{
                direc = (direc + 1) % 4;
                x--;
            }
            break;
        case 2:
            arr[y][x] = cnt;
            if (0 <= y && y <num && 0 <= x - 1 && x - 1 <num && arr[y][x - 1] == 0){
                x--;
            }else{
                direc = (direc + 1) % 4;
                y--;
            }
            break;
        case 3:
            arr[y][x] = cnt;
            if (0 <= y - 1 && y - 1 <num && 0 <= x && x <num && arr[y - 1][x] == 0){
                y--;
            }else{
                direc = (direc + 1) % 4;
                x++;
            }
            break;
        }
        
    }
    for (int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}


int main() {   
 //   freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 0; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << "\n";
        find();


    }
    return 0;
}
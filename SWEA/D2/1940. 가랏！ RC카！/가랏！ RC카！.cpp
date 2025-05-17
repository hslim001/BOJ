#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void find(){
    int time; cin >> time;
    int speed = 0, move = 0;
    int command, acel;
    for (int i=0; i < time; i++){
        cin >> command;
        if (command == 0){
            move += speed;
        }else if (command == 1){
            cin >> acel;
            speed += acel;
            move += speed;
        }else{
            cin >> acel;
            speed -= acel;
            if (speed < 0) speed = 0;
            move += speed;
        }
    }
    cout << move;
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
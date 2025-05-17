#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <bitset>


void find(unordered_map<char, int> dict){
    string total = "";
    string input; cin >> input;
    
    int pointer = 0; int current = 0;
    for (int i=0; i < input.length(); i++){
        current = dict[input[i]];
        total += bitset<6>(current).to_string();
    }
    string tounicode;
    for (int i=0; i < total.length(); i += 8){
        tounicode = total.substr(i, 8);
        cout << char(stoi(tounicode, nullptr ,2));
    }
}

int main() {   
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string decoding = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    unordered_map<char, int> dict;
    for (int i=0; i < decoding.length(); i++){
        dict[decoding[i]] = i;
    }
    int T = 0; cin >> T;
    for (int tc = 1; tc <= T; tc++){
        cout << "#" << tc << " ";
        find(dict);
        cout << "\n";

    }
    return 0;
}
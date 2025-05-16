#include <cstdio>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

int main() {
    //freopen("input.txt", "r", stdin);

    
    int T = 0; scanf("%d", &T);

    vector<string> score = {"D0", "C-", "C0", "C+", "B-", "B0", "B+", "A-", "A0", "A+"};
    for (int tc = 1; tc <= T; tc++){
        int num, select; scanf("%d %d", &num, &select);
        int arr[num] = {0};
        int mid, end, assignment;
        int targetscore = 0;
        for (int i = 0; i < num; i++){
            scanf("%d %d %d", &mid, &end, &assignment);
            arr[i] = mid * 35 + end * 45 + assignment * 20;
            if (i == select - 1){
                targetscore = arr[i];
            }
        }
        sort(arr, arr + num);
        int idx = 0;
        for (int i = 0; i < num; i++){
            if (arr[i] == targetscore){
                idx = i / (num / 10);
            }
        }
        printf("#%d %s\n", tc, score[idx].c_str());
    }
    return 0;
}
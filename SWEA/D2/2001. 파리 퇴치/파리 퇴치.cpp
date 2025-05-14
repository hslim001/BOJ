#include <cstdio>
using namespace std;
#include <vector>



int main() {
   // freopen("input.txt", "r", stdin);

    int T; scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++){
        int sum_val = 0, max_val = 0;
        int length, flychae; scanf("%d %d", &length, &flychae);
        int arr[length][length] = {0};
        for (int i = 0; i < length; i++){
            for (int j = 0; j < length; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 0; i <= length - flychae; i++){
            for (int j = 0; j <= length - flychae; j++){
                sum_val = 0;
                for (int y = i; y < i + flychae; y++){
                    for (int x = j; x < j + flychae; x++){
                        sum_val += arr[y][x];
                    }
                }
                if (sum_val > max_val)
                    max_val = sum_val;
            }
        }
        printf("#%d %d\n", tc, max_val);
    }

    return 0;
}
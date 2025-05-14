#include <cstdio>
using namespace std;
#include <vector>



int main() {
   // freopen("input.txt", "r", stdin);
    

    int T; scanf("%d", &T);
    
    int arr[10][10] = {0};
    arr[0][0] = 1;
    for (int i = 1; i < 10; i++){
        for (int j = 0; j <= i; j++){
            if (j - 1 >= 0)
                arr[i][j] += arr[i-1][j-1];
            arr[i][j] += arr[i - 1][j];
        }
    }
    for (int tc = 1; tc <= T; tc++){
        int num; scanf("%d", &num);
        printf("#%d\n", tc);
        for (int i = 0; i < num; i++){
            for (int j = 0; j <= i; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }


    return 0;
}
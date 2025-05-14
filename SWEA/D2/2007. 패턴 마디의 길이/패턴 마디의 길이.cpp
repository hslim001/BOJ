#include <cstdio>
using namespace std;
#include <vector>



int main() {
    //freopen("input.txt", "r", stdin);
    
    int T; scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++){
        char str[30];
        scanf("%s", str);
        int idx = 0; int flag = 1; int result = 0;
        for (int i = 1; i <= 10; i++){
            idx = 0; flag = 1;
            for (int j = 0; j < 30; j++){
                if (str[idx] != str[j]){
                    flag = 0;
                    break;
                }
                idx = (idx + 1) % i;
            }
            if (flag){
                result = i;
                break;
            }
        }
        printf("#%d %d\n", tc, result);




    }
    return 0;
}
#include <cstdio>
using namespace std;
#include <vector>



int main() {
    //freopen("input.txt", "r", stdin);
    
    int num; scanf("%d", &num);
    int temp = 0;
    int cnt = 0;
    int temp2 = 0;
    for (int i=1; i <= num; i++){
        temp = i;
        cnt = 0;
        while (temp != 0)
        {   temp2 = temp % 10;
            if (temp2 != 0 && temp2% 3 == 0){
                cnt += 1;
            }
            temp /= 10;
        }
        if (cnt == 0){
            printf("%d ", i);
        }
        else{
            for (int j = 0; j < cnt; j++){
                printf("%s", "-");
                
            }
            printf("%s", " ");
        
        }
    }

    return 0;
}
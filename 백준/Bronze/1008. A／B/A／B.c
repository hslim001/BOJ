#include<stdio.h>

int main(){
    
    double a, b;
    
    scanf("%lf %lf", &a, &b);
    a = a/b;
    printf("%.20lf", a);
    return 0;
}
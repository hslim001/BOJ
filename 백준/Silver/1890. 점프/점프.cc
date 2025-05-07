#include <iostream>
#include <fstream>
using namespace std;


long long find(int num, int arr[100][100]){
  long long dp[100][100] = {0};
  dp[0][0] = 1;
  for (int i = 0; i < num; i++){
    for (int j = 0; j < num; j ++){
      if (i == num - 1 & j == num - 1){
        break;
      }
      if (i + arr[i][j] < num){
        dp[i + arr[i][j]][j] += dp[i][j];
      }
      if (j + arr[i][j] < num){
        dp[i][j + arr[i][j]] += dp[i][j];
      }
    }
  }
  return dp[num - 1][num - 1];
}




int main(){
  
  //ifstream cin("C:/Users/SSAFY/Desktop/algo/input.txt");

  int num;
  cin >> num;
  int arr[100][100] = {0};
  for (int i = 0; i < num; i++){
    for (int j=0; j < num; j ++){
      cin >> arr[i][j];
    }
  }
  long long result = find(num, arr);
  cout << result;
  return 0;
}
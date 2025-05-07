#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
struct Load
{
  int city;
  int length;
};

int main() {
  //ifstream cin("input.txt");
  int city_num, load_num, interview_num;
  cin >> city_num >> load_num >> interview_num;
  vector<vector<Load>> graph(city_num + 1);
  for (int i=0; i < load_num; i++){
    int u, v, len;
    cin >> u >> v >> len;
    graph[v].push_back({u, len});
  }
  vector<unsigned long long> visited(city_num + 1, ULLONG_MAX);
  deque<int> que;
  for (int i=0; i < interview_num; i++){
    int interview_place;
    cin >> interview_place;
    visited[interview_place] = 0;
    que.push_back(interview_place);
  }
  
  int current = 0;
  while (!que.empty()){
    current = que.front(); que.pop_front();
    for (int i = 0; i < graph[current].size(); i ++){
      unsigned long long temp = graph[current][i].length + visited[current];
      if (temp < visited[graph[current][i].city]){
        visited[graph[current][i].city] = temp;
        que.push_back(graph[current][i].city);
      }
    }
  }
  unsigned long long min_len = 1;
  for (int i = 1; i < city_num + 1; i++){
    if (visited[i] != ULLONG_MAX && visited[i] > visited[min_len]){
      min_len = i;
    }
  }
  cout << min_len << endl << visited[min_len] << endl;
  // for (int i = 1; i < city_num + 1; i++){
  //   cout << visited[i] << " ";
  // }

  return 0;
}
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
struct Load
{
  int city;
  unsigned long long length;
  bool operator<(const Load& other) const {
    return length > other.length;
  }
};

int main() {
  //ifstream cin("input.txt");
  ios::sync_with_stdio(false); cin.tie(0);
  int city_num, load_num, interview_num;
  cin >> city_num >> load_num >> interview_num;
  vector<vector<Load>> graph(city_num + 1);
  for (int i=0; i < load_num; i++){
    int u, v;
    unsigned long long len;
    cin >> u >> v >> len;
    graph[v].push_back({u, len});
  }
  vector<unsigned long long> visited(city_num + 1, ULLONG_MAX);
  priority_queue<Load> que;
  for (int i=0; i < interview_num; i++){
    int interview_place;
    cin >> interview_place;
    visited[interview_place] = 0;
    que.push({interview_place, 0});
  }
  
  int current = 0;
  unsigned long long cur_len = 0;
  while (!que.empty()){
    current = que.top().city;
    cur_len = que.top().length; que.pop();
    if (cur_len > visited[current]) continue;
    for (int i = 0; i < graph[current].size(); i ++){
      unsigned long long temp = graph[current][i].length + visited[current];
      if (temp < visited[graph[current][i].city]){
        visited[graph[current][i].city] = temp;
        que.push({graph[current][i].city, temp});
      }
    }
  }
  unsigned long long min_len = 1;
  for (int i = 1; i < city_num + 1; i++){
    if (visited[i] != ULLONG_MAX && visited[i] > visited[min_len]){
      min_len = i;
    }
  }
  cout << min_len << endl << visited[min_len];
  // for (int i = 1; i < city_num + 1; i++){
  //   cout << visited[i] << " ";
  // }

  return 0;
}
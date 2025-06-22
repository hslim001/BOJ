#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, a[21][21], min_diff = 1e9;
int selected[10];
bool start_team[21] = {false};

void back(int depth, int idx, int current_sum) {
    if (depth == n/2) {
        int link_team[10], link_count = 0;
        for (int i = 0; i < n; i++) {
            if (!start_team[i]) {
                link_team[link_count++] = i;
            }
        }
        int link_sum = 0;
        for (int i = 0; i < link_count; i++) {
            for (int j = i+1; j < link_count; j++) {
                link_sum += a[link_team[i]][link_team[j]] + a[link_team[j]][link_team[i]];
            }
        }
        min_diff = min(min_diff, abs(current_sum - link_sum));
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!start_team[i]) {
            start_team[i] = true;
            selected[depth] = i;
            
            int new_sum = current_sum;
            for (int j = 0; j < depth; j++) {
                new_sum += a[i][selected[j]] + a[selected[j]][i];
            }
            
            back(depth+1, i+1, new_sum);
            start_team[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    start_team[0] = true;
    selected[0] = 0;
    back(1, 1, 0);
    cout << min_diff;
    return 0;
}

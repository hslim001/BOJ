using namespace std;
#include <iostream>
#include <vector>
int length;
int nums[1000000];
int main()
{
	
	vector<int> ans;
	cin >> length;
	for (int i = 0; i < length; ++i) {
		cin >> nums[i];
	}
	ans.push_back(0);
	for (int i = 0; i < length; ++i) {
		if (ans.back() < nums[i]) {
			ans.push_back(nums[i]);
		}
		else {
			int left = 0, right = ans.size(), mid;
			while (left < right)
			{
				mid = (left + right) / 2;
				if (nums[i] > ans[mid]) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}
			ans[left] = nums[i];
		}
	}
	cout << ans.size() - 1 << endl;
	return 0;
}
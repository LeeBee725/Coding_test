#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int sum = 0;
  vector<int> shorts(9);
  for (int i = 0; i < 9; ++i) {
    cin >> shorts[i];
    sum += shorts[i];
  }

  sort(shorts.begin(), shorts.end());

  int p1 = 0, p2 = 8;
  while (sum - shorts[p1] - shorts[p2] != 100) {
    if (sum - shorts[p1] - shorts[p2] < 100)
      --p2;
    else
      ++p1;
  }

  for (int i = 0; i < 9; ++i) {
    if (i != p1 && i != p2) cout << shorts[i] << "\n";
  }
  return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<int> diff(n + 1, 0);
  for (int i = 1; i <= k; i++)
    {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      diff[a] += 1;
      if (b + 1 < n)
        diff[b+1] -= 1;
    }

  vector<int> heights (n, 0);
  heights[0] = diff[0];

  for (int i = 1; i < n; i++)
    {
      heights[i] = heights[i-1] + diff[i];
    }

  sort(heights.begin(), heights.end());
  cout << heights[n / 2] << endl;
  
  return 0;
}
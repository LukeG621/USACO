#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> prefixSum(n+1);

  for (int i = 1;  i <= n; i++)
    {
      long long x;
      cin >> x;
      prefixSum[i] = prefixSum[i-1] + x;
    }

  long long maxArrSum = prefixSum[1];
  long long minArrSum = prefixSum[0];

  for (int i = 1; i <= n; i++) {
    maxArrSum = max(maxArrSum, prefixSum[i] - minArrSum);
    minArrSum = min(minArrSum, prefixSum[i]);
  }

  cout << maxArrSum << endl;

  return 0;
}
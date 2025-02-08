#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<pair<int, int>> times;

  int n;
  cin >> n;

  vector<pair<int, int>> events;
  events.reserve(2 * n);

  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    events.push_back({start, 1});
    events.push_back({end, -1});
  }

  sort(events.begin(), events.end());
  int currentCustomers = 0, maxCustomers = 0;

  for (const auto &event : events) {
    currentCustomers += event.second;
    maxCustomers = max(maxCustomers, currentCustomers);
  }

  cout << maxCustomers << endl;
  
  return 0;
}
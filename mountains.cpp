#include<vector>
#include<algorithm>
#include<fstream>
#include<iostream>

using namespace std;

struct interval {
  long long start;
  long long end;
};

bool compare(const interval &a, const interval &b) {
  if (a.start == b.start) return a.end > b.end;

  return a.start < b.start;
}

int main() {

  ifstream fin("mountains.in");
  ofstream fout("mountains.out");
  
  int n;
  fin >> n;

  vector<interval> mountains;
  mountains.reserve(n);
  
  for (int i = 0; i < n; i++) {
    int x, y;
    fin >> x >> y;

    mountains.push_back({x - y, x + y});

  }
    
  sort(mountains.begin(), mountains.end(), compare);

  int visibleCount = 0;
  long long currentMaxRight = -1e18;

  for (const auto &mountain : mountains) {
    if (mountain.end <= currentMaxRight) {
      continue;
    }

    visibleCount++;
    currentMaxRight = mountain.end;
  }
  
  fout << visibleCount << endl;
  return 0;

  fin.close();
  fout.close();
}
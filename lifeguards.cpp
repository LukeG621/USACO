#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<fstream>

using namespace std;

struct Event {
  int time;
  int type;
  int id;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream fin("lifeguards.in");
  ofstream fout("lifeguards.out");
  
  int n;
  fin >> n;

  vector<pair<int, int>> intervals(n);
  vector<Event> events;

  
  for (int i = 0; i < n; i++) {
    int start, end;
    fin >> start >> end;
    intervals[i] = make_pair(start, end);
    events.push_back({start, 1, i});
    events.push_back({end, -1, i});
  }

  sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
    return a.time < b.time;
  });

  int totalCoverage = 0;
  vector<int> alone(n, 0);
  int currentGuards = 0;
  int prevTime = events[0].time;
  set<int> active;

  
  for (const auto &e : events) {
    int currentTime = e.time;
    int differenceInTime = currentTime - prevTime;
    
    if (currentGuards > 0)
      totalCoverage += differenceInTime;

    if (currentGuards == 1)
        alone[*active.begin()] += differenceInTime;

    if (e.type == 1) {
      active.insert(e.id);
      currentGuards++;
    }

    else {
      active.erase(e.id);
      currentGuards--;
    }

    prevTime = currentTime;
  }

  int sol = 0;
  for (int i = 0; i < n; i++) 
    sol = max(sol, totalCoverage - alone[i]);

  fout << sol << endl;

  fin.close();
  fout.close();
  
  return 0;
}
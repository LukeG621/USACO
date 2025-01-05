#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<tuple>
#include <fstream>


using namespace std;

int main()
{

  ifstream fin("speeding.in");  // Open input file
  ofstream fout("speeding.out"); // Open output file

  int m,n;
  fin >> n >> m;

  // Goal is to make a 3-tuple with the point (distance traveled so far), the speed limit, and the current speed. From there, we will maximize te current speed - speed limit by iterating through the entire tuple

  vector<tuple<int, int, int>> info;
  int nTemp1, nTemp2;
  int sum = 0;
  for (int i = 0; i < n; i++)
    {
      fin >> nTemp1 >> nTemp2;
      for (int j = sum; j < sum + nTemp1; j++)
        {
          // Sets the last element to 0 for the time being
          info.push_back(make_tuple(j, nTemp2, 0));
        }
      sum += nTemp1;

    }

  sum = 0;

  int mTemp1, mTemp2;
  
  for (int i = 0; i < m; i++)
    {
      fin >> mTemp1 >> mTemp2;
      for (int j = sum; j < sum + mTemp1; j++)
        {
          get<2>(info[j]) = mTemp2;
        }
      sum += mTemp1;
    }

  int maxSpeedOver = 0;
  int limit, currentSpeed;
  for (size_t i = 0; i < info.size(); i++)
    {
      limit = get<1>(info[i]);
      currentSpeed = get<2>(info[i]);
      maxSpeedOver = max(maxSpeedOver, currentSpeed - limit);
    }

  fout << maxSpeedOver << endl;
  
  fin.close(); // Close files
  fout.close();
  
  return 0;
}
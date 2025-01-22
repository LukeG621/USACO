#include<iostream>
#include<vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> alongZ(n, vector<int> (n)), alongY(n, vector<int> (n)), alongX(n, vector<int> (n));

  int numberOfConfigs = 0;

  while (q--)
    {
      int x,y,z;
      cin >> x >> y >> z;
      alongX[y][z]++;
      if (alongX[y][z] == n)
        numberOfConfigs++;

      alongY[x][z]++;
      if (alongY[x][z] == n)
        numberOfConfigs++;

      alongZ[x][y]++;
      if (alongZ[x][y] == n)
        numberOfConfigs++;


      cout << numberOfConfigs << endl;
    }

  return 0;
}
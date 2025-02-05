#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;



int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int n, q;
  cin >> n >> q;

  vector<vector<int>> forest(n+1, vector<int>(n+1));

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        {
          char val;
          cin >> val;
          if (val == '*')
            forest[i+1][j+1] = 1;
          else
            forest[i+1][j+1] = 0;
        }
    }

  vector<vector<int>> prefixForest(n+1, vector<int>(n+1));

  for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <=n; j++)
        {
          prefixForest[i][j] = forest[i][j] + prefixForest[i - 1][j] + prefixForest[i][j - 1] - prefixForest[i-1][j-1];
        }
    }

  for (int i = 0; i < q; i++)
  {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int sum = prefixForest[x2][y2] 
              - prefixForest[x1 - 1][y2] 
              - prefixForest[x2][y1 - 1] 
              + prefixForest[x1 - 1][y1 - 1];
      cout << sum << endl;
  }


  return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<tuple>
#include <fstream>


using namespace std;

int main()
{

  ifstream fin("lostcow.in");  // Open input file
  ofstream fout("lostcow.out"); // Open output file

  int x,y;
  fin >> x >> y;
    
  int step = 1;
  int desiredPos = x + step;

  bool found = false;

  int currentPos = x;
  int distance = 0;
  while (found == false)
    {
      // For each element until the desired position, check if currentPosition = y
      if (desiredPos > currentPos)
      {
        for (int i = currentPos + 1; i <= desiredPos; i++)
          {
            distance++;
            if (i == y)
            {
              found = true;
              break;
            }
          }
      }
      else
      {
        for (int i = currentPos - 1; i >= desiredPos; i--)
          {
            distance++;
            if (i == y)
            {
              found = true;
              break;
            }
          }
      }

        // Update desired position

      if (found == false)
      {
        currentPos = desiredPos;
        step *= -2;
        desiredPos = x + step;
      }
    }

  fout << distance << endl;
  
  fin.close(); // Close files
  fout.close();
  
  return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <fstream>


using namespace std;

string duplicateLine(string line, int k)
{
  string result;
  for (char ch : line)
    result.append(k, ch);

  return result;
}

int main()
{

  ifstream fin("cowsignal.in");  // Open input file
  ofstream fout("cowsignal.out"); // Open output file
  int m, n, k;
  fin >> m >> n >> k;

  vector<string> lines;
  string currentLine;
  
  for (int i = 0; i < m; i++)
  {
     fin >> currentLine;
     lines.push_back(currentLine); 
  }

  vector<string> modifiedLines;
  string modifiedLine;

  for (const string &line : lines)
    {
      string modifiedLine = duplicateLine(line, k);
      for (int i = 0; i < k; i++)
        fout << modifiedLine << endl;
    }


  fin.close(); // Close files
  fout.close();
  
  return 0;
}
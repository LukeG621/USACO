#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	ifstream fin("hps.in");
	ofstream fout("hps.out");


	int N;
	fin >> N;
	int temp = N;
	char gesture;

	vector<char> gestures;

	while (temp--)
	{
		fin >> gesture;
		gestures.push_back(gesture);
	}

	vector<int> prefixHoofs(N, 0), prefixPaper(N, 0), prefixScissors(N, 0);

	prefixHoofs[0] = (gestures[0] == 'S' ? 1 : 0);
	prefixPaper[0] = (gestures[0] == 'H' ? 1 : 0);
	prefixScissors[0] = (gestures[0] == 'P' ? 1 : 0);

	for (int i = 1; i < N; i++) 
	{
		prefixHoofs[i] = prefixHoofs[i - 1] + (gestures[i] == 'S' ? 1 : 0);
		prefixPaper[i] = prefixPaper[i - 1] + (gestures[i] == 'H' ? 1 : 0);
		prefixScissors[i] = prefixScissors[i - 1] + (gestures[i] == 'P' ? 1 : 0);
	}


	vector<int> suffixHoofs(N+ 1, 0), suffixPaper(N + 1, 0), suffixScissors(N + 1, 0);
	suffixHoofs[N] = suffixPaper[N] = suffixScissors[N] = 0;

	for (int i = N - 1; i >= 0; i--) 
	{
		suffixHoofs[i] = suffixHoofs[i + 1] + (gestures[i] == 'S' ? 1 : 0);
		suffixPaper[i] = suffixPaper[i + 1] + (gestures[i] == 'H' ? 1 : 0);
		suffixScissors[i] = suffixScissors[i + 1] + (gestures[i] == 'P' ? 1 : 0);
	}


	int maxWins = 0;
	for (int i = 0; i < N; i++)
	{
		int firstWins = max({ prefixHoofs[i], prefixPaper[i], prefixScissors[i] });
		int secondWins = max({suffixHoofs[i + 1], suffixPaper[i + 1], suffixScissors[i + 1] });
		int totalWins = firstWins + secondWins;

		maxWins = max(maxWins, totalWins);

	}

	fout << maxWins << endl;
	
	fin.close();
	fout.close();

	return 0;
}
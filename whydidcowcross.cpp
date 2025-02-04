#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
  
    int n, k, b;
    fin >> n >> k >> b;

    vector<int> signals(n, 0);

    for (int i = 0; i < b; i++) {
        int id;
        fin >> id;
        signals[id - 1] = 1;
    }

    vector<int> prefixBroken(n, 0);
    prefixBroken[0] = signals[0];
  
    for (int i = 1; i < n; i++) {
        prefixBroken[i] = prefixBroken[i - 1] + signals[i];
    }

    int minimum = n;
    minimum = min(minimum, prefixBroken[k - 1]);

    for (int i = k; i < n; i++) {
        int numberBroken = prefixBroken[i] - prefixBroken[i - k];
        minimum = min(minimum, numberBroken);
    }

    fout << minimum << "\n";

    fin.close();
    fout.close();
    return 0;
}

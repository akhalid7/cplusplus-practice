#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int factorial(int n) {
    if (n==0) return 1;
    else return n*factorial(n-1);
}

int fibonacciR(int n) { return (n<=1) ? 1 : fibonacciR(n-1)+fibonacciR(n-2); }
void fibonacci(int n) {
    for (int i=0; i<n; ++i)
        cout << fibonacciR(i) << ' ';

    cout << endl;
}

void subsequenceR(string str, string s, int i, vector<string>& subsequences) {
    if (i == str.size()) return;

    s.push_back(str[i]);

    if (find(subsequences.begin(), subsequences.end(), s) == subsequences.end()) {
        subsequences.push_back(s);
    }

    for (int j=i+1; j<str.size(); ++j) {
        subsequenceR(str, s, j, subsequences);
    }
}
vector<string> subsequence(string str) {
    vector<string> subsequences;

    for (int i=0; i<str.size(); ++i) {
        subsequenceR(str, string(), i, subsequences);
    }

    return subsequences;
}
vector<string> subsequenceI(string str) {
    vector<string> subsequences;

    for (int i=1; i<(1<<str.size()); ++i) {
        string subsequence;

        for (int j=0; j<str.size(); ++j) {
            if (i & (1<<j)) {
                subsequence.push_back(str[j]);
            }
        }

        if (find(subsequences.begin(), subsequences.end(), subsequence) == subsequences.end()) {
            subsequences.push_back(subsequence);
        }
    }

    return subsequences;
}

vector<vector<int>> LCSGrid(string s, string v) {
    vector<vector<int>> lcsGrid;

    for (int i=0; i<=s.size(); ++i) {
        lcsGrid.push_back(vector<int>(s.size()+1, 0));
    }

    for (int i=1; i<=s.size(); ++i) {
        for (int j=1; j<=v.size(); ++j) {
            if (v[j-1] == s[i-1]) {
                lcsGrid[i][j] = lcsGrid[i-1][j-1] + 1;
            } else {
                lcsGrid[i][j] = lcsGrid[i-1][j] >= lcsGrid[i][j-1] ? lcsGrid[i-1][j] : lcsGrid[i][j-1];
            }
        }
    }

    return lcsGrid;
}
int LCS(string s, string v) {
    return LCSGrid(s, v)[s.size()][v.size()];
}

int main() {
    string s = "grain", v = "gain";

    cout << LCS(s, v) << endl;

    return 0;
}


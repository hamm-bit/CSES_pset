// Trading at IMC II
// https://www.hackerrank.com/contests/imc-x-csesoc-x-cpmsoc-coding-competition-division-b/challenges/imc21-b12
#include "bits-stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    string Q_temp;
    getline(cin, Q_temp);

    int Q = stoi(ltrim(rtrim(Q_temp)));
    const int THRESHOLD = 70;
    vector<int> precomp[THRESHOLD + 5];
    for (int Y = 1; Y <= THRESHOLD; Y++) {
        precomp[Y].resize(N);
        for (int i = N - 1; i >= 0; i--) {
            if (i + Y < N) {
                precomp[Y][i] = max(precomp[Y][i + Y], A[i + Y]);
            }
            else {
                precomp[Y][i] = INT_MIN;
            }
        }
    }
    
    for (int Q_itr = 0; Q_itr < Q; Q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int X = stoi(first_multiple_input[0]);
        X--;
        int Y = stoi(first_multiple_input[1]);

        // Answer questions here
        if (Y <= THRESHOLD) {
            cout << (precomp[Y][X] > A[X] ? "YES" : "NO") << "\n";
        }
        else {
            bool hasLarger = false;
            for (int i = X + Y; i < N; i += Y) {
                if (A[i] > A[X]) {
                    hasLarger = true;
                    break;
                }
            }

            cout << (hasLarger ? "YES" : "NO") << "\n";
        }
    }

    // Do post-processing here

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

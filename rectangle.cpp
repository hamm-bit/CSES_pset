#include "bits-stdc++.h"

using namespace std;
#define ll long long

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER_ARRAY x
 *  3. INTEGER_ARRAY y
 */

int solve(int N, vector<int> x, vector<int> y) {
    int k[1000], last = 0;
    vector<int> x_out;
    vector<int> y_out;
    iota(k, k + N, 0);
    for (int i = 0; i < N; i++) {
        next_permutation(k, k + N);
        if (k[])

        last = k[N]
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    /*
     * *********************************************************************
     * *                                                                   *
     * *   Everything from here handles input/output, and may be ignored.  *
     * *                                                                   *
     * *********************************************************************
     */

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split(rtrim(x_temp_temp));

    vector<int> x(N);

    for (int i = 0; i < N; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    string y_temp_temp;
    getline(cin, y_temp_temp);

    vector<string> y_temp = split(rtrim(y_temp_temp));

    vector<int> y(N);

    for (int i = 0; i < N; i++) {
        int y_item = stoi(y_temp[i]);

        y[i] = y_item;
    }

    int result = solve(N, x, y);

    fout << result << "\n";

    fout.close();

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


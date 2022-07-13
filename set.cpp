#include "bits-stdc++.h"

using namespace std;
#define ll long long

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. STRING_ARRAY allowed_words
 *  3. INTEGER K
 *  4. STRING_ARRAY guesses
 *  5. STRING_ARRAY responses
 */

vector<string> solve(int N, vector<string> allowed_words, int K, vector<string> guesses, vector<string> responses) {
    vector<string> poten;
    char sug[5] = {'#', '#', '#', '#', '#'}, ans[5] = {0, 0, 0, 0, 0};
    for (int k = 0; k < K; k++) {
        if (responses[k] == "GGGGG") {
            poten.push_back(guesses[k]);
            return poten;
        }
        for (int i = 0; i < 5; i++) {
            if (responses[k][i] == 'G') {
                ans[i] = guesses[k][i];
            }
            else if (responses[k][i] == 'Y') {
                sug[i] = guesses[k][i];
            }
        }
    }

    for (int n = 0; n < N; n++) {
        for (int k = 0; k < K; k++) {
            if (allowed_words[n] == guesses[k]) {
                allowed_words.erase(allowed_words.begin() + n);
                N--;
            }
        }
    }
    
    // verify existing answer:
    for (int j = 0 ; j < 5; j++) {
        if (ans[j] != 0) {
            for (int k = 0; k < N; k++) {
                if (allowed_words[k][j] != ans[j]) {
                    allowed_words.erase(allowed_words.begin() + k);
                    N--; k--;
                }
            }
        }
    }
    

    for (int n = 0; n < N; n++) {
        for (int k = 0; k < 5; k++) {
            cout << k << ", " << sug[k] << endl;
            if (sug[k] != '#') {
                int set_in = 0;
                for (int l = 0; l < 5; l++) {
                    set_in += (sug[k] == allowed_words[n][l]);
                }
                if (set_in == 0) {
                    allowed_words.erase(allowed_words.begin() + n);
                    N--; n--;
                }
            }
        }
        
    } 
    return allowed_words;
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
    cin.sync_with_stdio(false);
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    vector<string> allowed_words(N);

    for (int i = 0; i < N; i++) {
        string allowed_words_item;
        getline(cin, allowed_words_item);

        allowed_words[i] = allowed_words_item;
    }

    string K_temp;
    getline(cin, K_temp);

    int K = stoi(ltrim(rtrim(K_temp)));

    vector<string> guesses(K);

    for (int i = 0; i < K; i++) {
        string guesses_item;
        getline(cin, guesses_item);

        guesses[i] = guesses_item;
    }

    vector<string> responses(K);

    for (int i = 0; i < K; i++) {
        string responses_item;
        getline(cin, responses_item);

        responses[i] = responses_item;
    }

    vector<string> result = solve(N, allowed_words, K, guesses, responses);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    fout << "\n";

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

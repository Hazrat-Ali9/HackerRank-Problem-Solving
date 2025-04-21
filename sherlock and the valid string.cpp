#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    short int alpha[26] = {0};
    for (char& c : s)
        alpha[c-97]++;
    int frequency = 0, invalid = 0;
    for (int i = 0; i < 26; i++) {

        if (alpha[i] > 0) {

            if (frequency == 0) frequency = alpha[i];

            else if (frequency > 0 && frequency != alpha[i]) invalid++;

            if (invalid > 1) return "NO";
        }
    }

    return "YES";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

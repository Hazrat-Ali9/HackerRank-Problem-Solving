#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */


string timeInWords(int h, int m) {
    map<int, string> words = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "quarter"}, // Not fifteen
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {21, "twenty one"},
        {22, "twenty two"},
        {23, "twenty three"},
        {24, "twenty four"},
        {25, "twenty five"},
        {26, "twenty six"},
        {27, "twenty seven"},
        {28, "twenty eight"},
        {29, "twenty nine"},
        {30, "half"} // Not "thirty"
    };

    // Specific cases
    string minute_word;
    bool show_minutes = true;
    if (m == 0) return words[h] + " o' clock";
    else if (m == 1) minute_word = "one minute";
    else if (m == 15 || 60 - m == 15 || m == 30) {
        minute_word = words[m];
        show_minutes = false;
    }
    else minute_word = words[m] + " minutes";

    // General rule of formatting
    if (m > 30) {
        if (show_minutes)
            return words[60 - m] + " minutes to " + words[h + 1];
        return words[60 - m] + " to " + words[h + 1];
    }
    return minute_word + " past " + words[h]; // Else
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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

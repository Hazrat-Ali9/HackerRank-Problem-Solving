#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int& n, int& m, vector<vector<int>>& edges, int& s) {
    map<int, list<int>> adj; 
    bool valid_test = false;
    for (int i = 0; i < edges.size(); i++) {
    
        if (edges[i][0] == s || edges[i][1] == s)
            valid_test = true;
       
        adj[edges[i][0]].emplace_back(edges[i][1]);
        adj[edges[i][1]].emplace_back(edges[i][0]);
    }

    vector<bool> visited(n + 1, false); 
    vector<bool> calculated(n + 1, false);
    vector<int> distance(n + 1, 0); 
    vector<int> ans(n + 1, 0);

    if (valid_test) {
        
        queue<int> q; 
        q.emplace(s); 
        while (!q.empty()) {
            int current = q.front();
            visited[current] = true;
            q.pop();
            
            for (list<int>::iterator itr = adj[current].begin(); itr != adj[current].end(); ++itr) {
                int child = *itr;
                if (visited[child] == false && calculated[child] == false) {
                    distance[child] = distance[current] + 6;
                    ans[child] = distance[child];
                    
                    calculated[child] = true;
                    q.emplace(child);
                }
            }
        }
    }

    vector<int>::iterator ans_itr = ans.begin();
    ans.erase(ans_itr); 
    for (int i = 0; i < ans.size(); i++) {
        
        if (i == s - 1) ans.erase(ans_itr + s - 1);
        if (ans[i] == 0) ans[i] = -1;
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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


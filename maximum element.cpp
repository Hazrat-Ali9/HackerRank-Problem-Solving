
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main() {

    int n, query_type, query_value, maximum;
    string query_line;
    stack<int> s, max_tracker;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, query_line);
        istringstream ss(query_line);
        ss >> query_type >> query_value;
        switch (query_type) {
        case 1:
            s.push(query_value);
            if (max_tracker.empty() || max_tracker.top() <= query_value)
                max_tracker.push(query_value);
            break;
        case 2:
            if (s.top() == max_tracker.top())
                max_tracker.pop();
            s.pop();
            break;
        default:
            cout << max_tracker.top() << endl;
        }
    }
    return 0;
}

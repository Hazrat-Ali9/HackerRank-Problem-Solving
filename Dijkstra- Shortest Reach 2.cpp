#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int id;
    unsigned int distance;
    vector<pair<Node *, int>> adjacent;
    
    Node(int id)
        : id(id), distance(-1)
    { }
};

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        Node** nodes = new Node*[n + 1];
        
        for (int j = 1; j <= n; j++) {
            nodes[j] = new Node(j);
        }
        
        for (int j = 0; j < m; j++) {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            Node *u = nodes[x];
            Node *v = nodes[y];
            u->adjacent.emplace_back(v, r);
            v->adjacent.emplace_back(u, r);
        }
        
        int s;
        scanf("%d", &s);
        priority_queue<pair<int, Node*>> pq;
        
        nodes[s]->distance = 0;
        pq.push(make_pair(0, nodes[s]));
        
        while (!pq.empty()) {
            const auto d = pq.top().first;
            const auto u = pq.top().second;
            pq.pop();
            
            if (d > u->distance) {
                continue;
            }
            
            for (const auto &pair : u->adjacent) {
                const auto v = pair.first;
                const auto e = pair.second;
                if (v->distance > d + e) {
                    v->distance = d + e;
                    pq.push(make_pair(d + e, v));
                }
            }
        }

        bool first = true;
        
        for (int j = 1; j <= n; j++) {
            if (j == s) {
                continue;
            }
            
            cout << (first ? "" : " ") << (int)nodes[j]->distance;
            first = false;
        }
        
        cout << endl;
    }
    
    return 0;
}

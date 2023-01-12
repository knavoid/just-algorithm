#include <iostream>
#include <deque>
#include <algorithm>
 
using namespace std;
 
int T, V, E, v1, v2, p, c;
int vertexNumber, subTreeSize;
deque<int> parent;
deque<deque<int>> childs;
 
int getSubTreeSize(int v) {
    int size = 1;
    for (int cv : childs[v])
        size += getSubTreeSize(cv);
 
    return size;
}
 
int main() {
 
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // input
        cin >> V >> E >> v1 >> v2;
        parent.assign(V + 1, 0);
        childs.assign(V + 1, deque<int>());
        for (int i = 0; i < E; i++) {
            cin >> p >> c;
            parent[c] = p;
            childs[p].push_back(c);
        }
 
        // solution
        deque<int> p1, p2;
        while (v1 != 0) {
            p1.push_front(v1);
            v1 = parent[v1];
        }
        while (v2 != 0) {
            p2.push_front(v2);
            v2 = parent[v2];
        }
        for (int i = 1; i < min(p1.size(), p2.size()); i++) {
            if (p1[i] != p2[i]) {
                vertexNumber = p1[i - 1];
                break;
            }
        }
        subTreeSize = getSubTreeSize(vertexNumber);
 
        // output
        cout << '#' << tc << ' ' << vertexNumber << ' ' << subTreeSize << '\n';
    }
 
    return 0;
}
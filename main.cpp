#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int depth, int D, long long balls, vector<int>& leafStates, int leafStart) {
    if (depth == D) {
        leafStates[node - leafStart] = balls % 2;
        return;
    }
    long long left = (balls + 1) / 2;
    long long right = balls / 2;
    dfs(node * 2, depth + 1, D, left, leafStates, leafStart);
    dfs(node * 2 + 1, depth + 1, D, right, leafStates, leafStart);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int D; long long n;
    if (!(cin >> D >> n)) return 0;
    int leafStart = 1 << (D - 1);
    int leafCount = 1 << (D - 1);
    vector<int> leafStates(leafCount, 0);
    dfs(1, 1, D, n, leafStates, leafStart);
    // compute last ball position
    long long k = n;
    int node = 1;
    for (int i = 0; i < D - 1; ++i) {
        if (k % 2 == 1) {
            node = node * 2;
            k = (k + 1) / 2;
        } else {
            node = node * 2 + 1;
            k = k / 2;
        }
    }
    cout << node << "\n";
    for (int i = 0; i < leafCount; ++i) {
        if (i) cout << ' ';
        cout << leafStates[i];
    }
    cout << "\n";
    return 0;
}

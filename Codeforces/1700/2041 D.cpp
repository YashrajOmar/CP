ps link : https://codeforces.com/problemset/problem/2041/D

#include <bits/stdc++.h>
using namespace std;

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

struct State {
    int x, y, dir, cnt, steps;
};

int bfs(vector<string>& maze, int n, int m, pair<int,int> S, pair<int,int> T) {
    queue<State> q;
    set<tuple<int, int, int, int>> visited;

    for (int d = 0; d < 4; d++) {
        int nx = S.first + dx[d];
        int ny = S.second + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (maze[nx][ny] == '#') continue;

        visited.insert({nx, ny, d, 1});
        q.push({nx, ny, d, 1, 1});
    }

    while (!q.empty()) {
        auto [x, y, dir, cnt, steps] = q.front(); q.pop();
        if (x == T.first && y == T.second) {
            return steps;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maze[nx][ny] == '#') continue;

            int new_cnt = (d == dir) ? cnt + 1 : 1;
            if (new_cnt > 3) continue;

            auto state = make_tuple(nx, ny, d, new_cnt);
            if (visited.count(state)) continue;
            visited.insert(state);
            q.push({nx, ny, d, new_cnt, steps + 1});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    pair<int, int> S, T;

    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') S = {i, j};
            if (maze[i][j] == 'T') T = {i, j};
        }
    }

    cout << bfs(maze, n, m, S, T) << '\n';
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

int n, m;

long long encode(int x, int y, int dir, int cnt) {
    return (((1LL * x * m + y) << 4) | (dir << 2) | cnt);   ///	<< 4	reserve 4 bits for dir+cnt   << 2	reserve 2 bits for cnt   no shift	stored in lowest 2 bits
}

int bfs(vector<string>& maze, pair<int,int> S, pair<int,int> T) {
    queue<tuple<int, int, int, int, int>> q;  // x, y, dir, cnt, steps
    unordered_set<long long> visited;

    for (int d = 0; d < 4; d++) {
        int nx = S.first + dx[d];
        int ny = S.second + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (maze[nx][ny] == '#') continue;

        q.emplace(nx, ny, d, 1, 1);
        visited.insert(encode(nx, ny, d, 1));
    }

    while (!q.empty()) {
        auto [x, y, dir, cnt, steps] = q.front(); q.pop();
        if (x == T.first && y == T.second) {
            return steps;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maze[nx][ny] == '#') continue;

            int new_cnt = (d == dir) ? cnt + 1 : 1;
            if (new_cnt > 3) continue;

            long long key = encode(nx, ny, d, new_cnt);
            if (!visited.count(key)) {
                visited.insert(key);
                q.emplace(nx, ny, d, new_cnt, steps + 1);
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<string> maze(n);
    pair<int, int> S, T;

    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') S = {i, j};
            if (maze[i][j] == 'T') T = {i, j};
        }
    }

    cout << bfs(maze, S, T) << '\n';
    return 0;
}

Time Complexity	O(n × m × 4 × 3) = O(nm)
Space Complexity	O(nm)

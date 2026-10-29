class Solution {
public:
    int LOG, n, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;
    vector<int> cur, rootMask;

    void dfs(int u, int p) {
        tin[u] = timer++;

        up[0][u] = p;

        for (int k = 1; k < LOG; k++) {
            up[k][u] = up[k - 1][up[k - 1][u]];
        }

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            rootMask[v] = rootMask[u] ^ cur[v];

            dfs(v, u);
        }

        tout[u] = timer - 1;
    }

    void add(int i, int val) {
        for (i++; i <= n; i += i & -i) {
            bit[i] ^= val;
        }
    }

    void rangeXor(int l, int r, int val) {
        add(l, val);

        if (r + 1 < n) {
            add(r + 1, val);
        }
    }

    int pointQuery(int i) {
        int res = 0;

        for (i++; i > 0; i -= i & -i) {
            res ^= bit[i];
        }

        return res;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k)) {
                u = up[k][u];
            }
        }

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 1, 0);
        cur.resize(n);
        rootMask.assign(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            cur[i] = 1 << (s[i] - 'a');
        }

        rootMask[0] = cur[0];
        dfs(0, 0);

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = cur[u] ^ newMask;

                rangeXor(tin[u], tout[u], delta);
                cur[u] = newMask;
            } else {
                ss >> v;

                int w = lca(u, v);

                int xu = rootMask[u] ^ pointQuery(tin[u]);
                int xv = rootMask[v] ^ pointQuery(tin[v]);

                int mask = xu ^ xv ^ cur[w];

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
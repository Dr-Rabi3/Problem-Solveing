/// https://www.spoj.com/problems/TRSTAGE/

/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/
#include                             <bits/stdc++.h>
#define     ll                       long long
#define     ld                       long double
#define     ed                       '\n'
#define     sz(x)                    x.size()
#define     all(x)                   x.begin(), x.end()
#define     rall(x)                  x.rbegin(), x.rend()
#define     fixed(x)                 fixed<<setprecision(x)
#define     memo(dp,x)               memset(dp,x,sizeof(dp))
#define     sumOf(a)                 (ll)((-1 + sqrt(8 * a + 1)) / 2)
#define     Good_Bay                 return

constexpr int mod = 1e9 + 7, oo = 0x3f3f3f3f, N = 1e6 + 5;
const double pi = acos(-1), EPS = 1e-7;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;

using namespace std;

template < typename T > istream& operator >> (istream& in, vector < T >& v) {
    for (auto& x : v) in >> x;
    return in;
}

template < typename T > ostream& operator << (ostream& out, const vector < T >& v) {
    for (const T& x : v) out << x << ' ';
    return out;
}

void Accept() { // for VS code
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
int dy[] = { 1 , 0 , -1 ,  0 , 1 , -1 ,  1 , -1 };
int dx[] = { 0 , 1 ,  0 , -1 , 1 , -1 , -1 ,  1 };
int n, m, p, src, dist;
vector<int>v;
double DP(int node, int mask, vector<vector<pair<int, int>>>& adj, vector<vector<double>>& dp, vector<int>& vis) {
    if (node == dist)return 0;
    if (mask == (1 << n) - 1)return oo;
    if (dp[node][mask] != -1)return dp[node][mask];
    double ret = oo;
    for (auto i : adj[node]) {
        int x = i.first;
        double d = i.second;
        for (int j = 0;j < n;j++) {
            if ((mask >> j) & 1)continue;
            ret = min(ret, DP(x, mask | (1 << j), adj, dp, vis) + d / v[j]);
        }
    }
    return dp[node][mask] = ret;
}
void doWork(int tt) {
    while (cin >> n >> m >> p >> src >> dist) {
        if (!n && !m && !p && !src && !dist)break;
        v = vector<int>(n);
        cin >> v;
        vector<vector<pair<int, int>>>adj(m + 1);
        vector<int>vis(m + 1);
        vector<vector<double>>dp(m + 1, vector<double>(1 << n, -1));
        for (int i = 0;i < p;i++) {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({ v,c });
            adj[v].push_back({ u,c });
        }
        auto ans = DP(src, 0, adj, dp, vis);
        cout << fixed(3) << (ans >= oo ? "Impossible" : to_string(ans)) << ed;
    }
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        cout << ed;
        // if (i < t)cout << ed;
    }
    Good_Bay 0;
}

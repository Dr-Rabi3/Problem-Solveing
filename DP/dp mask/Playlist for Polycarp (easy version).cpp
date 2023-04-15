///  https://codeforces.com/problemset/problem/1185/G1


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
int n, t;
vector<pair<int, int>>v;
int dp[1 << 16][20];
int DP(int mask, int last, int sum) {
    // cout << sum << ed;
    if (sum >= t)return sum == t;
    if (~dp[mask][last])return dp[mask][last];
    int op = 0;
    for (int i = 0;i < n;i++) {
        if (v[i].second == last || (mask >> i) & 1)continue;
        op += DP(mask | (1 << i), v[i].second, sum + v[i].first);
        op %= mod;
    }
    return dp[mask][last] = op;
}
void doWork(int tt) {
    memo(dp, -1);
    cin >> n >> t;
    v = vector<pair<int, int>>(n);
    for (auto& i : v)cin >> i.first >> i.second;
    cout << DP(0, 0, 0);
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

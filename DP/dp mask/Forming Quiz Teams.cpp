/// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1852


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
int n;
vector<pair<double, double>>v;
double dp[1 << 16];
double Sqrt(int i, int j) {
    return sqrt(pow(v[j].first - v[i].first, 2) + pow(v[j].second - v[i].second, 2));
}
double DP(int mask) {
    if (mask == (1 << n) - 1) return 0;
    if (!dp[mask])return dp[mask];
    double ret = oo;
    for (int i = 0;i < n;i++) {
        if ((mask >> i) & 1)continue;
        for (int j = i + 1;j < n;j++) {
            if ((mask >> j) & 1)continue;
            ret = min(ret, Sqrt(j, i) + DP(mask | (1 << i) | (1 << j)));
        }
        break;
    }
    return dp[mask] = ret;
}
void doWork(int tt) {
    memo(dp, -1);
    while (cin >> n, n) {
        n *= 2;
        v = vector<pair<double, double>>(n);
        for (int i = 0;i < n;i++) {
            string s;
            cin >> s >> v[i].first >> v[i].second;
        }
        cout << "Case " << tt++ << ": " << fixed(2) << DP(0) << ed;
    }
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        // cout << ed;
        // if (i < t)cout << ed;
    }
    Good_Bay 0;
}

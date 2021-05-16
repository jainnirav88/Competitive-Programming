#include<bits/stdc++.h> // 56 70 "baklol☺, take it easy"
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;

using ll = long long int;
using ld = long double;
using ull = unsigned long long int;

#define rep(x, k, n)        for(int x = (k); x <= (n); ++x)
#define rept(x, k, n)       for(int x = (k); x < (n); ++x)
#define repr(x, k, n)       for(int x = (k); x >= (n); --x)
#define pb                  push_back
#define F                   first
#define S                   second
#define siz(x)              ((int)(x).size())
#define o2(x)               ((x) * (x))
#define all(x)              (x).begin(), (x).end()
#define clr(x, k)           memset(x, k, sizeof(x)) // 0, -1
#define printv(v, k, n)     rep(i, k, n) cout << v[i] << " \n"[i==n];
#define print2dv(V,k,m,n)   rep(j, k, m) printv(V[j], k, n);
#define report(x)           cout << ((x) ? "Yes" : "No") << '\n'
#define getunique(x, y)     unique(x, y) - (x); // array should be shorted
#define setbits(x)          __builtin_popcountll(x)
#define int                 long long // "be careful"

typedef vector<int>         vi;
typedef pair<int, int>      pii;

template<typename T1, typename T2> ostream& operator<<(ostream &ostream, const pair<T1, T2> &p){
    ostream << p.first << " " << p.second; return ostream;
}
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &v){
    for(auto &it : v) ostream << it << " "; return ostream;
}

#ifdef LOCAL
#include<E:\Programming\CP\A-Main\debug\debug_code.h> // errors : debug_code.h
#else
#define deb(...)
#define debv(v, k, n)
#define deb2dv(V, k, n, m)
#define line
#endif

constexpr int mod = 1e9 + 7; // 998244353;
constexpr long double eps = 1e-9;
constexpr long double pi = 3.141592653589793238;
constexpr long long inf = 2e9, ninf = -2e9;
constexpr int N = 3e5 + 5, M = 2e5 + 5;

/*/------------------------------ CODE BEGINS ------------------------------/*/

int n, m;

struct DSU {
    vector<int> arr, sz; // size of roots.
    int components;

    DSU(int n){ // n = size
        components = n;
        for(int i = 0; i <= n; i++){
            arr.push_back(i);
            sz.push_back(1); // Initially all are root -> size = 1.
        }
    }

    int root(int v){
        while(v != arr[v]) v = arr[v];
        return v;
    }

    bool find(int v, int u){
        return root(v) == root(u);
    }

    bool Union(int v, int u){
        int root_v = root(v);
        int root_u = root(u);
        if(root_v == root_u) return false;

        if(sz[root_v] < sz[root_u]) swap(root_v, root_u);
        
        arr[root_u] = root_v;
        sz[root_v] += sz[root_u];
        sz[root_u] = 0;
        components--;
        
        return true;
    }

    void printARR(){
        // to print the array.
        for(int i = 1; i <= n; i++){
            cout << arr[i] << " \n"[i==n];
        }
    }

    void printSIZE(){
        // to print the size, size = 0 -> it's connected in some set, size != 0 -> it's root.
        for(int i = 1; i <= n; i++){
            cout << sz[i] << " \n"[i==n];
        }
    }
    // copy : DSU dsu(n);
};

// TC: O(logn)
int mpow(int base, int exp){
    base %= mod;
    int result = 1;
    while(exp > 0){
        if(exp & 1) result = ((long long)result * base) % mod;
        base = ((long long)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void DONT_ASSUME_BLINDLY() {

    cin >> n >> m;
    DSU dsu(m);
    vector<int> res;
    rep(i, 1, n){
        int k, u, v = 0;
        cin >> k >> u;
        if(k != 1) cin >> v;
        if(dsu.Union(u, v)){
            res.pb(i);
        }
    }
    cout << mpow(2, siz(res)) << ' ' << siz(res) << '\n';
    cout << res << '\n';
}

/*/------------------------------- CODE ENDS -------------------------------/*/

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // cout << setprecision(12) << fixed;
    int tc = 1;
    // cin >> tc;
    for(int i = 1; i <= tc; i++) {
        DONT_ASSUME_BLINDLY();
#ifdef LOCAL
        auto brute_force = [&]()->void{

        };
        // brute_force();
        // break;
#endif
    }

    cerr << "[time:" << 1.0*clock()/CLOCKS_PER_SEC << "s] ";
    return 0;
}

/*
-> Please, don't get stuck at one approach only.
-> Understood the problem?, misread?
-> edge cases, n = 1 ?
-> binary search ?
-> brute_force ?
-> time complexity - 1 sec : 4e8 will work but risky.
-> space complexity - 256 mb : 6e7(int), 3e7(ll), 2e8(bool, char), will work.
-> entire input - multiple testcases.
-> mod : sort ?, mint, remove #define int.
-> Iterative > Recursive.
-> clear - global variables.
-> builtin function - add ll.
-> Move on - if completely_stuck > 30 minute.
-> Submit - right file.
*/

/*
-> Don't assume blindly.
-> Focus on problem.
-> Recovery from the failure.
-> Do consider worst case time complexity.
-> If solution is barely passing then do submit again after doing optimization.
-> Be careful in nested loop. Iterating variable name should be different for both loop.
-> Think simple first.
-> Don't be stupid.
-> Be comfortable and in your control.
*/
#include <bits/stdc++.h> // 203
using namespace std;

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
#define print2dv(V,k,n,m)   rep(j, k, n) printv(V[j], k, m);
#define report(x)           cout << ((x) ? "Yes" : "No") << '\n'
#define getunique(x, y)     unique(x, y) - (x); // array should be shorted
#define setbits(x)          __builtin_popcountll(x)
#define int                 long long // "be carefull"

// min, max-value in the test case
constexpr long long mn_val = 0, mx_val = 1e18;
// min, max-length of the array, string etc.
constexpr int mn_len = 1, mx_len = 100000;

// call rnd(min_val, max_val);
// Note: it doesn't guarantee distinct values.
static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r){
  return uniform_int_distribution<long long>(l, r)(rng);
}

namespace generator{

    long long get_num(long long a = mn_val, long long b = mx_val){
        return rnd(a, b);
    }

    string get_binary_string(int len = -1){

        if(len == -1){
            len = rnd(mn_len, mx_len);
        }

        string str(len, '0');

        for(auto &ch : str){
            if(rng() & 1) ch ^= 1;
        }

        return str;
    }

    string get_string(int len = -1, bool lowercase_only = true){
        int min_char = 'a' - 'a', max_char = 'z' - 'a';

        if(len == -1){
            len = rnd(mn_len, mx_len);
        }

        string str(len, '0');

        for(int i = 0; i < len; i++){
            str[i] = (rnd(min_char, max_char) + 'a');
        }

        if(lowercase_only) return str;

        for(auto &ch : str){
            if(rng() & 1) ch ^= 32; // swap case (make c to C)
        }

        return str;
    }

    template<typename T>
    vector<T> get_array(int len = -1, T a = mn_val, T b = mx_val){

        if(len == -1) len = rnd(mn_len, mx_len);

        vector<T> v(len);

        for(int i = 0; i < len; i++){
            v[i] = rnd(a, b);
        }

        return v;
    }

    vector<pair<int, int>> get_tree(int n = -1){

        if(n == -1) n = rnd(mn_len, mx_len);

        vector<pair<int, int>> res(n-1);

        for(int i = 2; i <= n; i++){
            int u = i, v = rnd(1, i-1);

            if(rng() & 1) swap(u, v);

            res[i-2] = {u, v};
        }

        shuffle(res.begin(), res.end(), rng);

        return res;
    }

    vector<pair<int, int>> get_simple_graph(int n, int m, bool connected = true){

        vector<pair<int, int>> res;
        set<pair<int , int>> edge_set;

        // maximum condition for edge
        assert(2 * m <= 1ll * n * (n-1));

        if(connected){
            // minimum edges of connected graph
            assert(m >= n-1);

            res = get_tree(n);

            for(auto edge : res) edge_set.insert(edge);
            res.clear();

            for(int i = n; i <= m; i++){
                while(true){
                    // not tested, refer the commented one if doesn't work correctly

                    int u = rnd(1, n);
                    int v = rnd(1, n);

                    if(u == v || edge_set.count({u, v}) || edge_set.count({v, u})) continue;

                    edge_set.insert({u,v});
                    break;
                }

                // label:
                // int u = rnd(1, n);
                // int v = rnd(1, n);

                // if(u == v || edge_set.count({u, v}) || edge_set.count({v, u}))
                //     goto label;
                // else edge_set.insert({u,v});

            }
        }
        else{
            for(int i = 1; i <= m; ++i){
                while(true){
                    // not tested, refer the commented one if doesn't work correctly

                    int u = rnd(1, n);
                    int v = rnd(1, n);

                    if(u == v || edge_set.count({u, v}) || edge_set.count({v, u})) continue;
                    edge_set.insert({u,v});
                    break;
                }


                // label2:
                // int u = rnd(1, n);
                // int v = rnd(1, n);

                // if(u == v || edge_set.count({u, v}) || edge_set.count({v, u})) goto label2;
                // else edge_set.insert({u,v});

            }
        }

        for(auto edge : edge_set){
            res.push_back(edge);
        }

        shuffle(res.begin(), res.end(), rng);

        return res;
    }
};
using namespace generator;

/*/-------------------------------------------------------------------------/*/
/*/------------------------- Modify Below function -------------------------/*/
/*/-------------------------------------------------------------------------/*/

// comment/uncomment the next line in if you have multi_test.
// #define MULTI_TEST

constexpr int min_tests = 1, max_tests = 1;
constexpr int min_val = 1, max_val = 1e18;
constexpr int min_len = 1, max_len = 10;

// complete this function for each test case.
// namespace examples at last
void make_test(){

    int n = get_num(min_len, max_len);
    int m = get_num(min_len, max(1ll, ((n * (n - 1)) / 2) - 3));

    cout << n << " " << m << '\n';
    
    vector<pair<int, int>> edges = get_simple_graph(n, m, false);

    for(auto [u, v] : edges) {
        cout << u << " " << v << "\n";
    }

    // int n = get_num(min_len, max_len);
    // string s = get_string(n);
    // cout << n << ' ' << 26 << "\n";
    // cout << s << "\n";
}

int32_t main(){

    // demo* d = new demo;

    int t = 1;

    #ifdef MULTI_TEST
        t = get_num(min_tests, max_tests);
        assert(t >= min_tests && t <= max_tests);
        cout << t << '\n';
    #endif

    for(int i = 1; i <= t; i++){

        make_test();

        // make_test_example(); // at last
    }

    return 0;
}

/*/-------------------------------------------------------------------------/*/
/*/----------------------------- Explanations ------------------------------/*/
/*/-------------------------------------------------------------------------/*/

/*
-> get_num(a, b);
// gives a random number between [a, b] - if a, b given.
// otherwise get_num() gives a random_number between 0 and 10**18;

-> get_string(l, bool lowercase_only = true);
// gives a string of length l.
// (by default lowercase you can change that by calling get_string(l, false);

-> get_array(len, min_num_of_array, max_num_of_array)
    // note that this returns a vector;

-> get_tree(n) gives a tree of n nodes(list of edges)

-> get_simple_graph(nodes, edges, bool connected = 1)
// you can change connected/disconnected option too. (list of edges)
*/

struct demo{
    demo(){

        cout << get_num() << endl;
        cout << get_num(10, 20) << "\n";

        vector<int> v = get_array(12ll, 1ll, 1000ll);
        // size, min_element, max_element.
        // you can call g.get_array() or g.get_array(10) too
        // see definition for details.

        cout << "the array generated is {";
        for(auto it : v)
            cout << it << ", ";
        cout << " }" << endl;

        vector<pair<int, int>> tree = get_tree(5);
        cout << "the tree generated has edgelist { ";
        for(auto [u, v]: tree)
            cout << "(" << u << ", " << v << ") , ";
        cout << " }" << endl;

        // similary for graph
        // connected_graph
        get_simple_graph(10, 12);

        // can be disconnected_graph
        get_simple_graph(10, 12, 0);
        // both graph will have 10 nodes and 12 edges.
    }
};

/*

=> for a question having sample tests like this

T
N
S (string)
An array of size N.(a1 , a2 , a3 , a4 , .... an)

*/

namespace examples{
    void make_test_array(){
        int N = get_num(min_len, max_len);
        cout << N << '\n';
        vector<int> v = get_array(N, min_val, max_val);
        assert(siz(v) == N);
        for(auto it : v){
            assert(it >= min_val && it <= max_val);
            cout << it << ' ';
        }
        cout << '\n';
    }

    void make_test_string(){
        int N = get_num(min_len, max_len);
        cout << N << '\n'; // comment/uncomment
        string s = get_string(N);
        assert(siz(s) == N);
        cout << s << '\n';
    }

    void make_test_example(){
        int N = get_num(1, 10);
        string s = get_string(N);
        vector<int> v = get_array(N, 0ll, 20ll);

        // you have to output them too.
        cout << N << endl;
        cout << s << endl;

        for(auto i: v) cout << i << " "; cout << endl;

        // int n = get_num(15, 20);
        // assert(n >= 15 && n <= 20);
        // vector<int> v = get_array(n, min_val, max_val);
        // assert((int)v.size() == n);
        // cout << n << '\n';
        // for(auto it : v){
        //     assert(it >= min_val && it <= max_val);
        //     cout << it << ' ';
        // }
        // cout << '\n';

        // string s = get_string();
        // int num = get_num(5000, 10000);
        // cout << (int)s.size() << ' ' << num << '\n';
        // cout << s << '\n';
    }
};
using namespace examples;
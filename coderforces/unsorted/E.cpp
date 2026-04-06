#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
#define RAYA cout<<"=============="<<"\n"
#define sz(x) ((int)x.size())
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define pp pop_back
#define mp make_pair
#define fst first
#define snd second
#define str string
#define pri(x) cout << (x) << "\n"
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using ll = long long;
using pii = pair<int,int>;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

template<class A, class B>
ostream& operator<<(ostream& o, const pair<A,B>& p){
    return o << "(" << p.first << "," << p.second << ")";
}

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<ll> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
string YES = "YES\n"; 
string NO = "NO\n";
ll maxn = 300000 + 10;

// sieve
vector<int> spf; // spf[x] = menor factor primo de x

void build_spf(int maxn) {
    spf.assign(maxn + 1, 0);

    for (int i = 2; i <= maxn; i++) {
        if (spf[i] == 0) {
            spf[i] = i; // i es primo

            if (1LL * i * i <= maxn) {
                for (long long j = 1LL * i * i; j <= maxn; j += i) {
                    if (spf[j] == 0)
                        spf[j] = i;
                }
            }
        }
    }
}

vector<pair<int,int>> factorize(int x) {
    vector<pair<int,int>> fac;

    while (x > 1) {
        int p = spf[x], e = 0;

        while (x % p == 0) {
            x /= p;
            e++;
        }

        fac.push_back({p, e});
    }

    return fac;
}

void solve(){
    ll n; cin>>n;
    vi a(n);
    vi b(n+1, 0);
    fore(i, 0, n)cin>>a[i];
    sort(all(a));
    fore(i, 0, n){
        b[a[i]] = 1;
    }
    // cout<<b<<endl;
    vi res;
    fore(i, 1, n+1){
        //ll numact = a[i];
        // db(i);
        if(b[i]){
            // cout<<"entro: "<<i<<endl;
            res.pb(1); 
            // cout<<"res actual ";
            // cout<<res<<endl;
            continue;
        }
        // cout<<"no entre: "<<i<<endl;
        if(i==1){
            res.pb(-1);
            continue;
        }
        vector<pair<int,int>> f = factorize(i); 
        bool flag = true;
        for(pair<int, int> pairs: f){
            if(b[pairs.fst] == 0){
                res.pb(-1); 
                flag = false;
                break;
            }
        }
        if(flag){
            ll tam = 0;
            for(pair<int, int> pairs: f){
                // cout<<"par actual"<<endl;
                // cout<<pairs<<endl;
                tam += pairs.snd;
            }
            // db(tam);
            res.pb(tam);
        }
            //         cout<<"res actual ";
            // cout<<res<<endl;
    }
    fore(i, 0, sz(res)){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    FIN; 
    //int t = 1;
    build_spf(maxn);
    int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0;
}
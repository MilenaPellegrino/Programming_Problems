#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(ll i=(a);i<(b);i++)
#define rof(i, a, b) for(ll i=(b);i>(a);i--)
#define forn(e,c) for(const auto &e : (c))
#define db(x) cout<<#x<< " = "<<(x)<<endl
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

template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}


void solve(){
    ll n; cin>>n;
    vi a(n); fore(i, 0, n)cin>>a[i];
    map<ll, ll> freq; 
    fore(i, 0, n){
        freq[a[i]]++;
    }
    ll dist = sz(freq);
    ll r = n-1;
    ll max_seg = 0;
    while(r>=0){
        map<ll, ll> freq_temp; 
        ll dist = 0;
        for(ll l = r; l>= 0; l--){
            freq_temp[a[l]]++;
            if (freq_temp[a[l]] == 1) dist++;

            if (dist == sz(freq)){
                max_seg++;

                for(ll i=l; i<=r; i++){
                    freq[a[i]]--;
                    if (freq[a[i]] == 0){
                        freq.erase(a[i]);
                    }
                }
                r = l-1;
                break;
            }
            if (l == 0) {
                // No pudimos formar mas segm validos
                r = -1;
            }
        }
    }

    cout<<max_seg<<"\n";
    
}

int main(){
    FIN; 
    //int t = 1;
    int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0;
}
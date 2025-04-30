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
    ll p; cin>>p;
    ll k; cin>>k;

    // CASOS ESPECIALES: 
    if(n==2){
        cout<<(p%2)+1<<endl;
        return;
    }

    //queue<ll> q; // GENERAL
    vi q;

    fore(i, 1, n+1){
        if(i!= p){
            q.pb(i);
        }
    }

    // queue<ll> qsinp; 

    
    // for(ll i = p-1; i>=1; i--){
    //     qsinp.push(i);
    // }
    
    // ll tamq = qsinp.size();
    // // while(!qsinp.empty()){
    // //     cout<<qsinp.front()<<" ";
    // //     qsinp.pop();
    // // }

    // vi a;
    // while(!qsinp.empty()){
    //     a.pb(qsinp.front());
    //     qsinp.pop();
    // }

    // reverse(all(q));
    // fore(i, 0, sz(q) - tamq ){
    //     if(i==p)continue;
    //     a.pb(q[i]);
    // }

    ll start = 0;
    fore(i, 0, sz(q)){
        if(q[i]>p){
            start = i;
            break;
        }
    }
    ll pos = start;
    fore(i, 0, k){
        pos++;
        if(pos>= sz(q))pos=0;
    }

    ll res = q[pos];
    // fore(i, 0, k){
    //     res = a[i];
    //     a.pb(a[i]);
    // }  

    //db(res);
    //cout<<q<<endl;
    cout<<res<<"\n";
}

int main(){
    FIN; 
    int t = 1;
    //int t; cin>>t; 
    while(t--){
        solve();
    }
    return 0;
}
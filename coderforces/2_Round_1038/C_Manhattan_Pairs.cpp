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

set<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set<ll> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// (a, b, index)
multiset<tuple<ll, ll, ll>> ms;

pair<ll, ll> buscar(){
    pair<ll, ll> res;

    //  (maxs/min, index, a, b)
    tuple<ll, ll, ll, ll> maxsab = {-2e9, -1, -1, -1};
tuple<ll, ll, ll, ll> minab = {2e9, -1, -1, -1};
    tuple<ll, ll, ll, ll> maxsba = {-2e9, -1, -1, -1};;
    tuple<ll, ll, ll, ll> minba = {2e9, -1, -1, -1};;

    for (auto pars : ms){
        ll posa = get<0>(pars);
        ll posb = get<1>(pars);
        ll indx = get<2>(pars);

        ll ab = posa + posb;
        ll ba = posa - posb;

        if ( ab >= get<0>(maxsab)){
            get<0>(maxsab) = ab;
            get<1>(maxsab) = indx;
            get<2>(maxsab) = posa;
            get<3>(maxsab) = posb;
        }
        if (ab <= get<0>(minab)){
            get<0>(minab) = ab;
            get<1>(minab) = indx;
            get<2>(minab) = posa;
            get<3>(minab) = posb;
        }

        if (ba >= get<0>(maxsba)){
            get<0>(maxsba) = ba;
            get<1>(maxsba) = indx;
            get<2>(maxsba) = posa;
            get<3>(maxsba) = posb;
        }

        if (ba <= get<0>(minba)){
            get<0>(minba) = ba;
            get<1>(minba) = indx;
            get<2>(minba) = posa;
            get<3>(minba) = posb;
        }
    }

    ll difs1 = get<0>(maxsab) - get<0>(minab);
    ll difs2 = get<0>(maxsba) - get<0>(minba);

    tuple<ll, ll, ll> res1;
    tuple<ll, ll, ll> res2;
    if(difs1 >= difs2){
        get<0>(res1) = get<2>(maxsab);
        get<1>(res1) = get<3>(maxsab);
        get<2>(res1) = get<1>(maxsab);

        get<0>(res2) = get<2>(minab);
        get<1>(res2) = get<3>(minab);
        get<2>(res2) = get<1>(minab);
    }else{
        get<0>(res1) = get<2>(maxsba);
        get<1>(res1) = get<3>(maxsba);
        get<2>(res1) = get<1>(maxsba);

        get<0>(res2) = get<2>(minba);
        get<1>(res2) = get<3>(minba);
        get<2>(res2) = get<1>(minba);
    }

    auto it = ms.find(res1);
    if (it!= ms.end()){
        ms.erase(it);
    }

    auto it2 = ms.find(res2);
    if (it2!= ms.end()){
        ms.erase(it2);
    }
    pair<ll, ll> resu; 
    resu.fst = get<2>(res1); 
    resu.snd = get<2>(res2);
    return resu;
}

void solve(){
    ll n; cin>>n;
    
    fore(i, 0, n){
        ll ai, bi; cin>>ai>>bi; 
        ms.insert({ai, bi, i+1});
    }
    ll its = n/2;
    vector<pair<ll, ll>> res;
    while(its--){
        pair<ll, ll> cures = buscar();
        res.pb(cures);
    }
    fore(i, 0, sz(res)){
        cout<<res[i].fst<<" "<<res[i].snd<<"\n";
    }
}

int main(){
    FIN; 
    //int t = 1;
    int t; cin>>t; 
    while(t--){
        ms.clear();
        solve();
    }
    return 0;
}

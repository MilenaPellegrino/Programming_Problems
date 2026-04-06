#include<bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

using ll = long long;
typedef vector<ll> vi; 

bool func1(vector<ll> &a, vector<ll> &b){
    return a[0] <= b[0];
}

bool func2(vector<ll> &a, vector<ll> &b){
    return a[1] <= b[1];
}

bool func3(vector<ll> &a, vector<ll> &b){
    return a[2] <= b[2];
}

struct CustomCompare {
    bool operator()(const vector<ll>& a, const vector<ll>& b) const {
        return sz(a) > sz(b); // Example: Sort in descending order
    }
};

int main(){FIN; 

    ll t; cin>>t; 
    while(t--){
        ll n; cin>>n; 
        vector<vector<ll>> a(n, vector<ll>(3, 0));
        vector<vector<ll>> gv;
        set<vector<ll>, CustomCompare> g;
        fore(i, 0, n){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        sort(all(a), func1);
        fore(i, 0, n){
            fore(j, i, n){
                if(a[j][0] != a[i][0])break;
                g[i].pb(j);
                g[j].pb(i);
            }
        }
        sort(all(a), func1);
        fore(i, 0, n){
            fore(j, i, n){
                if(a[j][0] != a[i][0])break;
                g[i].pb(j);
                g[j].pb(i);
            }
        }

    }

    return 0; 
}

#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i =(a); i<(b); i++)
#define all (x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())
using ll = long long; 
typedef vector<ll> vi; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

vector<ll> mt;
vector<bool> used;

bool try_kuhn(ll v, vector<vector<ll>> g) {
    if (used[v])
        return false;
    used[v] = true;
    for (ll to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to], g)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}


int main(){FIN;

    ll n; cin>>n;
    vector<vector<ll>> g(n, vi(n, 0));
    vector<string> s1(n);
    vector<string> s2(n);
    fore(i,0,n){
        cin >> s1[i];
    }
    fore(i,0,n){
        cin >> s2[i];
    }

    fore(i,0,n){
        fore(j,0,n){
            ll count = 0;
            while(count<s1.size() || count<s2.size()){
                if(s1[i][count]!=s2[j][count]){
                    break;
                }
                count++;
            }
            g[i][j]=count;
            g[j][i]=count;
        }
    }

    mt.assign(n, -1);
    for (ll v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v, g);
    }

    ll c = 0;

    for (ll i = 0; i < n; ++i)
        if (mt[i] != -1)
            c += mt[i] + 1;

    cout << c << "\n";

    for (ll i = 0; i < n; ++i)
        cout << mt[i] + 1 << " " << i + 1 << "\n";

    return 0;
}


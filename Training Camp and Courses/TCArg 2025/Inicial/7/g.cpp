#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a); i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second
#define sz(x) ((int)x.size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

using ll = long long; 
typedef vector<ll> vi; 
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

ll idx_m1 = 0, idx_m0 = 0, idx_p1; 
bool poss(vi& a, ll n){
    bool ans = true;
    ll prev = gcd(a[0], a[1]); 
    //cout<<prev<<" ";
    fore(i, 1, n-1){
        ll cur = gcd(a[i], a[i+1]); 
        if(prev>cur){
            ans = false; 
            idx_m1 = i-1; 
            idx_m0 = i; 
            idx_p1 = i+1;
            break;
        }
        prev = cur;
        //cout<<cur<<" ";
    }
    //cout<<endl;
    return ans;
}
int main(){
    FIN;
    ll t; cin>>t; 
    while(t--){
        ll idx1 = 0, idx2 = 0;
        ll n; cin>>n; 
        vi a(n); 
        fore(i, 0,n)cin>>a[i];
        
        
        // CASE 1 -> it's possible 
        bool possible = poss(a, n);

        if(possible){
            cout<<"YES\n";
            continue;
        }
        // CASE 2 -> It's not possible
        // Case 2.1 remove i-1 (idx_m1)
        vi b; 
        fore(i, 0, n){
            if(i==idx_m1){
                continue;
            }
            b.pb(a[i]);
        }
        // Case 2.2 remove i (idx_m0)
        vi c; 
        fore(i, 0, n){
            if(i==idx_m0){
                continue;
            }
            c.pb(a[i]);
        } 
        // Case 2.3 remove i+1 (idx_p1)
        vi d; 
        fore(i, 0, n){
            if(i==idx_p1){
                continue;
            }
            d.pb(a[i]);
        } 
        possible = poss(b, n-1) || poss(c, n-1) || poss(d, n-1);
        if(possible){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}
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

int main(){
    FIN;

    ll t; cin>>t;
    while(t--){

        ll n; cin>>n;
        vi v(n);
        vi sum(n+1);
        sum[0]=0;
        fore(i,0,n){
            cin>>v[i];
            sum[i+1] = sum[i] + v[i];
        }
        string s; cin>>s;
        vi vs(n);
        fore(i,0,n){
            if(s[i]=='L') vs[i]=0;
            else vs[i]=1;
        }
        ll l=0,r=n-1;
        ll res=0;
        while(l<r){
            if(vs[l]==1){
                l++; continue;
            }
            if(vs[r]==0){
                r--; continue;
            }
            res+=sum[r+1]-sum[l];
            l++; r--;
        }
        cout<<res<<"\n";

    }

    return 0;
}
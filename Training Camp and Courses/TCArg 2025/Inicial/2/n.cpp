#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define vi vector<ll>
#define fore(i, a, b) for (ll i= a; i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main(){
    FIN;
    ll t;cin>>t;
    fore(j,0,t){
        string s,al;
        map<char,ll> m;
        cin>>al;
        cin>>s;
        fore(i,0,26){
            m.insert({al[i],i+1});
        }
        ll r=0;
        fore(i,1,s.size()){
            r+=abs(m[s[i]]-m[s[i-1]]);
        }
        cout<<r<<"\n";
    }

    return 0;
}
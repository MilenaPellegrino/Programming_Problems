#include<bits/stdc++.h> 
using namespace std; 

#define fore(i, a, b) for(ll i=(a);i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first 
#define snd second 
#define sz(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long; 
typedef vector<ll> vi;
 
int main(){FIN;
   ll n;cin>>n;
   ll a=n*2;
   ll r1=(-1+sqrt(1+4*a))/2;
   ll res=n-(r1*(r1+1))/2;
   if(res==0){
    cout<<r1<<"\n";
   }else{
   cout<<res<<"\n";
   }
   return 0;
}
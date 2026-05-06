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
 int main(){
    FIN;

   ll t; cin >>t;

   while(t--){

      ll a,b,c,d; cin >>a>>b>>c>>d;
      ll count=0;
      if(b>a) count++;
      if(c>a) count++;
      if(d>a) count++;
      cout << count<<"\n";

   }

    return 0;
 }
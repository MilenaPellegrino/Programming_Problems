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

   ll a,b,c; cin>>a>>b>>c;
   cout << 100 << "\n";
   fore (i,0,50){
      cout << a << " ";
   }
   fore (i,50,95){
      cout << b << " ";
   }
   fore (i,95,99){
      cout << c << " ";
   }
   cout << c+1 << "\n";
   
   return 0;
}
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
    vector<char> a = {'a', 'b' , 'b', 'a'};
    sort(all(a));
    do {
        for(char x : a)cout<<x<<endl;
        cout<<endl; 
    } while (next_permutation(all(a)));
   return 0;
}
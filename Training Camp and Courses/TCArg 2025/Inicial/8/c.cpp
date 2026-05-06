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

char func(char a, char b){
    if((a=='W'&&b=='N') || (a=='N'&&b=='E') || (a=='E'&&b=='S') || (a=='S'&&b=='W')){
        return 'R';
    }
    return 'L';
}

int main(){
    FIN; 

    ll t; cin>>t;
    while(t--){

        ll n; cin>>n;
        char c; cin>>c;
        ll l; cin>>l;
        char dir = c;
        cout << n*2-1<<" "<< c<<"\n";
        n--;
        cout << "Z "<<l<<"\n";
        while(n--){
            char c; cin>>c;
            ll l; cin>>l;
            cout << func(dir, c) << "\n";
            dir = c;
            cout << "Z "<<l<<"\n";
        }

    }

    return 0; 
}



/*

int main(){
    FIN; 

    ll t; cin>>t;
    while(t--){

        ll n; cin>>n;
        char c; cin>>c;
        ll l; cin>>l;
        char dir = c;
        cout << n*2-1<<" "<< c<<"\n";
        n-=2;
        cout << "Z "<<l<<"\n";
        while(n--){
            char c; cin>>c;
            ll l; cin>>l;
            char a = 'L';
            if((dir=='W'&&c=='N') || (dir=='N'&&c=='E') || (dir=='E'&&c=='S') || (dir=='S'&&c=='W')){
                a= 'R';
            }
            cout << a << "\n";
            dir = c;
            cout << "Z "<<l<<"\n";
        }

    }

    return 0; 
}
*/
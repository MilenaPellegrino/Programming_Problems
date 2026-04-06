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

int main(){FIN; 

    int n, R; cin >> n >> R;
    double pi = 3.141592653589793;
    double p = 1 - cos(2*pi/n);
    // cout << p << "\n";

    double k = sqrt( pow((R*p),2)*4 + 8*p*pow(R,2) - 4*pow(p*R,2) );
    // cout << k << "\n";
    double r1 = (-2*R*p + k)/(4-2*p);
    double r2 = (-2*R*p - k)/(4-2*p);

    // cout << r1 << "\n";
    // cout << r2 << "\n";

    cout<<fixed<<setprecision(10)<<-r2<<"\n";


    return 0;
}
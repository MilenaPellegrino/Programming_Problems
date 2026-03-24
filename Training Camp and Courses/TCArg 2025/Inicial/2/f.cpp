#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define vi vector<ll>
#define fore(i, a, b) for (ll i= a; i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back 
#define fst first
#define snd second 
#define sz(x) ((int)x.size())

ll kadane_max ( const vector < long long >& arr ) {
    if(sz(arr)==0){
        return 0;
    }
    ll cur = arr [0] , best = arr [0];
    for ( int i = 1; i < (int) arr.size(); ++ i ) {
        cur = max ( arr [i] , cur + arr [i]);
        best = max ( best , cur );
    }
    return best;
}

ll kadane_min ( const vector < long long >& arr ) {
    if(sz(arr)==0){
        return 0;
    }
    ll cur = arr[0], best = arr [0];
    for ( int i = 1; i < (int)arr.size(); ++ i ) {
        cur = min ( arr [i] , cur + arr [i]);
        best = min ( best , cur );
    }
    return best;
}

ll kadane_con_k_max(vector<long long>& a, int k) {
    int n = a.size();
    vector<long long> left(n), right(n);

    left[0] = a[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(a[i], left[i-1] + a[i]);
    }

    right[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        right[i] = max(a[i], right[i+1] + a[i]);
    }

    return left[k] + right[k] - a[k];
}

ll kadane_con_k_min(vector<long long>& a, int k) {
    int n = a.size();
    vector<long long> left(n), right(n);

    left[0] = a[0];
    for (int i = 1; i < n; i++) {
        left[i] = min(a[i], left[i-1] + a[i]);
    }

    right[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        right[i] = min(a[i], right[i+1] + a[i]);
    }

    return left[k] + right[k] - a[k];
}


#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main(){
    FIN;
    ll t; cin>>t; 
    while(t--){
        ll n; cin>>n; 
        vi a(n);
        fore(i, 0, n)cin>>a[i];
        vi b; 
        vi c; 
        ll idxstrange = -1; 
        fore(i, 0, n){
            if(a[i] != 1 && a[i] != -1){
                idxstrange = i;
                break;
            }
        }
        // cout<<"0=============================="<<endl;
        // cout<<idxstrange<<endl;
        if(idxstrange != -1){
            fore(i, 0, idxstrange){
                b.pb(a[i]);
            }
            fore(i, idxstrange + 1, n){
                c.pb(a[i]);
            }
        }
        // cout<<"1=============================="<<endl;
        ll maxsin1 = 0, minsin1 = 0; 
        ll maxsin2 = 0, minsin2 = 0; 
        ll maxcon = 0, mincon = 0; 

        // maxsin1 = kadane_max(b); 
        // minsin1 = kadane_min(b); 

        // maxsin2 = kadane_max(c); 
        // minsin2 = kadane_min(c); 
        
        set<ll> ans; 
        ans.insert(0);

        if(idxstrange != -1){
            ans.insert(a[idxstrange]);
            maxcon = kadane_con_k_max(a, idxstrange); 
            mincon = kadane_con_k_min(a, idxstrange);

            maxsin1 = kadane_max(b); 
            minsin1 = kadane_min(b); 

            maxsin2 = kadane_max(c); 
            minsin2 = kadane_min(c); 
        } else{
            maxsin1 = kadane_max(a);
            minsin1 = kadane_min(a);
            fore(i, minsin1, maxsin1 + 1){
                ans.insert(i);
            }
            cout<<sz(ans)<<"\n";
            for(ll elem : ans){
                cout<<elem<<" ";
            }
            cout<<"\n";
            continue; 
        }
        // cout<<"2=============================="<<endl;
        // cout<<maxsin1<<" "<<minsin1<<endl; 
        // cout<<maxsin2<<" "<<minsin2<<endl; 
        // cout<<maxcon<<" "<<mincon<<endl;      

        // if(idxstrange != -1){
        //     mincon += a[idxstrange]; 
        // }
        

        //set<ll> ans; 
        fore(i, minsin1, maxsin1 + 1){
            ans.insert(i);
        }

        fore(i, minsin2, maxsin2 + 1){
            ans.insert(i); 
        }

        if(idxstrange != -1){
            fore(i, mincon, maxcon + 1){
                ans.insert(i);
            }
        }

        // cout<<"3=============================="<<endl;
        cout<<sz(ans)<<"\n";
        for(ll elem : ans){
            cout<<elem<<" ";
        }
        cout<<"\n";
        // fore(i, 0, n){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // fore(i, 0, sz(b)){
        //     cout<<b[i]<<" ";
        // }
        // cout<<endl;
        // fore(i, 0, sz(c)){
        //     cout<<c[i]<<" ";
        // }
        // cout<<endl;
    }


    return 0;
}
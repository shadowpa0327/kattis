#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
#define PB push_back
#define eb emplace_back
#define MK make_pair
#define F first
#define S second
#define setpre(a) cout.precision(a),cout<<fixed;
#define ALL(a) a.begin(),a.end()
#define MEM(a,b) memset(a,b,sizeof a)
#define TIE ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#ifdef DEBUG
    ofstream outfile("output.txt");
#endif

bool solve(set<long double>s,long double fifth_value,long double targer){
    s.insert(fifth_value);
    double ans = 0;
    for(auto it = ++s.begin(); it!=(--s.end());it++){
        ans+=(*it);
    }
   // cout<<ans<<endl;
    return ans <= targer*3;
}


int main(){TIE
    
    vector<int>v(4);
    int target;
    for(int i=0;i<4;i++){
        double tmp;
        cin>>tmp;
        v[i] = tmp*100+1e-6;
    }
    sort(ALL(v));
    double tmp;
    cin>>tmp;
    target = tmp*100+1e-6;
    target*=3;
    if(v[1]+v[2]+v[3]<=target){
        cout<<"infinite"<<endl;
    }
    else if(v[0]+v[1]+v[2]>target){
        cout<<"impossible"<<endl;
    }
    else{
        setpre(2);
        cout<<(target- v[1]-v[2])/100.0<<endl;
    }
}

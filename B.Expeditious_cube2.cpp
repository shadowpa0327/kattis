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

bool solve(multiset<long double>s,long double fifth_value,long double targer){
    s.insert(fifth_value);
    double ans = 0;
    for(auto it = ++s.begin(); it!=(--s.end());it++){
        ans+=(*it);
    }
   // cout<<ans<<endl;
    return ans <= targer*3;
}


int main(){TIE
    setpre(2);
    multiset<long double>s;
    long double target;
    for(int i=0;i<4;i++){
        double tmp;
        cin>>tmp;
        s.insert(tmp);
    }
    cin>>target;
    long double l = *(s.begin())-1,r = *(--s.end())+1;
  //  cout<<l<<' '<<r<<endl;
    for(int i=0;i<30;i++){
        long double mid = (l+r)/2;
        if(solve(s,mid,target)){
            l = mid ;
        }
        else{
            r = mid ;
        }
    }
    if(l > *(--s.end())) cout<<"infinite"<<endl;
    else if(r<*(s.begin())) cout<<"impossible"<<endl;
    else cout<< l <<endl;
    return 0;
}
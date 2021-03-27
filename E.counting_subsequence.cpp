#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#include <unordered_map>
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


int main(){TIE
    int testcase,seq_len;
    cin>>testcase;
    while(testcase--){
        string tmp;
        getline(cin,tmp);
        cin>>seq_len;
        ll ans = 0;
        unordered_map<ll,ll>m;
        m.clear();
        m[0] = 1;
        ll buf = 0;
        for(int i=0,tmp;i<seq_len;i++){
            cin>>tmp;
            buf+=tmp;
            auto it = m.find(buf-47);
            if(it!=m.end()){
                ans+=(*it).S;
            }
            m[buf]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


//本題關鍵 ： 要記得設初始條件 
// 此題即為變相的two sum

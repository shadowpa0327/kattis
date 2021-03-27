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

class graph{
    public:
    vector<list<pii> >adjlist;
    int vertex;
    graph(int n):vertex(n){
        adjlist.resize(n);
    }
    void addedge(int from,int to,int weight);
};


int main(){TIE
    int n,e,t;
    cin>>n>>e>>t;
    graph g(n);
    for(int i=0,a,b,c;i<e;i++){
        cin>>a>>b>>c;
        g.addedge(a,b,c);
    }
    priority_queue<pll,vll,greater<pll> >pq_spider;
    vll spider_dis(n,0);
    return 0;
}

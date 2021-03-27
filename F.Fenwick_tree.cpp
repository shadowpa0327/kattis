#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
#define PB push_back
#define eb emplace_back
#define MK make_pair
#define endl '\n'
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


class BIT{
    public:
    int seq_size;
    vll data_arr;
    vll Binary_index_tree;
    BIT(int n):seq_size(n){
        data_arr.resize(n,0);
        Binary_index_tree.resize(n+1,0);
    }
    void parse_input(){
        for(int i=0;i<seq_size;i++){
            cin>>data_arr[i];
            update_bit(i,data_arr[i]);
        }
        //for(auto it:Binary_index_tree)cout<<it<<" ";
        //cout<<endl;
    }
    void update_bit(int loc,int value);
    ll query(int l,int r);
};

void BIT::update_bit(int loc,int value)
{   
    int cur = loc + 1;
    while(cur<seq_size+1){
        //cout<<cur<<" ";
        Binary_index_tree[cur] +=value;
        cur += (cur&(-cur));
        
    }
   // cout<<endl;
}

ll BIT::query(int l,int r){
    ll prefix_r=0,prefix_l=0;
    int cur1=l,cur2=r+1;
    while(cur2){
        prefix_r+=Binary_index_tree[cur2];
        cur2-=(cur2&(-cur2));
    }
    while(cur1){
        prefix_l+=Binary_index_tree[cur1];
        cur1-=(cur1&(-cur1));
    }
    return (prefix_r-prefix_l);
}



int main(){TIE
    int r,q;
    cin>>r>>q;
    BIT b(r);
    for(int i=0;i<q;i++){
        char mode;
        cin>>mode;
        if(mode=='+'){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            b.update_bit(tmp1,tmp2);
        }
        else{
            int tmp;
            cin>>tmp;
            if(tmp)
                cout<<b.query(0,tmp-1)<<endl;
            else cout<<0<<endl;
        }
    }
    //b.parse_input();
    //cout<<b.query(0,3)<<endl;;
    return 0;
}

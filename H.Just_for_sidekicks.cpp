#include<bits/stdc++.h>
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
using namespace std;

class BIT{
    public:
    int seq_size;
    vll data_arr;
    vll Binary_index_tree;
    BIT(int n):seq_size(n){
        data_arr.resize(n,0);
        Binary_index_tree.resize(n+1,0);
    }
    BIT(){};
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
        Binary_index_tree[cur] +=value;
        cur += (cur&(-cur)); 
    }
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


int value[6];




int main(){
    int q,r;
    cin>>q>>r;
    for(int i=0;i<6;i++){
        cin>>value[i];
    }
    vector<BIT>B(6,BIT(q));
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        B[s[i]-'1'].update_bit(i,1);
    }
    for(int i=0,mode,idx1,idx2;i<r;i++){
        cin>>mode>>idx1>>idx2;
        if(mode==1){
            B[s[idx1-1]-'1'].update_bit(idx1-1,-1);
            B[idx2-1].update_bit(idx1-1,1);
            s[idx1-1] = idx2+'0';
        }
        else if(mode==2){
            value[idx1-1]=idx2;
        }
        else{
            ll ans = 0;
            for(int i=0;i<6;i++){
                ans+=B[i].query(idx1-1,idx2-1)*value[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
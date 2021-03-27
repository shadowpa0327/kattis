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

class segment_tree
{
    public:
    int data_number;
    vector<int>origin_data;
    vector<int>tree_data;
    segment_tree(int n):data_number(n){
        tree_data.resize(4*n+1,0x7fffffff);
    }
    void read_data(){
        for(int i=0;i<data_number;i++){
            int tmp;cin>>tmp;
            origin_data.PB(tmp);
        }
    }
    void build_tree(int low,int high,int index){
        if(low==high){
            tree_data[index]=origin_data[low];
        }
        else{
            int mid = (low+high) >> 1;
            build_tree(low,mid,2*index);
            build_tree(mid+1,high,2*index+1);
            tree_data[index] = min(tree_data[2*index],tree_data[2*index+1]);
        }
    }

    ll rangeQuery(int ql,int qr,int l,int r,int index){
        if(ql<=l&&qr>=r)
            return tree_data[index];
        ll mid = (l + r) >> 1 , re = 0x7fffffff;
        if(ql<=mid){
            re = min(re,rangeQuery(ql,qr,l,mid,2*index));
        }
        if(qr>=mid+1){
            re = min(re,rangeQuery(ql,qr,mid+1,r,2*index+1));
        }
        return re;
    }

    void set_value(int loc,int l,int r,int index,int v){
        if(l==r){
            tree_data[index] = v;
            return;
        }
        int mid = (l+r)>>1;
        if(loc<=mid){
            set_value(loc,l,mid,index*2,v);
        }
        else if(loc>=mid+1){
            set_value(loc,mid+1,r,index*2+1,v);
        }
        tree_data[index] = min(tree_data[index*2],tree_data[index*2+1]);
    }

};

bool BST(int targer,vll &arr){
    int l = 0 ,r = arr.size()-1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(arr[mid]==targer)return true;
        else if(arr[mid]>targer)r = mid-1;
        else l = mid+1;
    }
    return false;
}





int main(){TIE
    ll n,m,a,c,x0;
    cin>>n>>m>>a>>c>>x0;
    vll arr(n);
    vll v;
    for(int i=0;i<n;i++){
        arr[i] = (a*x0+c)%m;
        v.PB(arr[i]);
        x0=arr[i];
    }
    int ans = 0;
    for(auto it:v){
        if(BST(it,arr))ans++;
    }
    cout<<ans<<endl;
    return 0;
}

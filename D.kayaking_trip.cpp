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

int strength[3];
int b,n,e,sb,sn,se;
vector<pair<ll,string> >combine;
vi kayaking;

bool can_arrange(int bb,int nn,int ee,string s){
    for(auto it:s){
        if(it=='b')bb--;
        if(it=='n')nn--;
        if(it=='e')ee--;
    }
    return (bb>=0&&nn>=0&&ee>=0);
}

bool check(int bound){
    int bb = b,nn=n,ee=e;
    bool can = true;
    for(int i:kayaking){
        bool if_this_can =false;
        for(auto it : combine){
            if(i*it.first>=bound&&can_arrange(bb,nn,ee,it.S)){
                for(auto itt:it.S){
                   // if(bound==1668)cout<<itt<<" ";
                    if(itt=='b')bb--;
                    if(itt=='n')nn--;
                    if(itt=='e')ee--;
                    
                }
                if_this_can= true;
                break;
            }
        }
        if(!if_this_can){
            can = false;
            break;
        }
    }
    return can;
}




int main(){TIE
    
    cin>>b>>n>>e>>sb>>sn>>se;
    combine.PB(MK(sb+sb,"bb"));
    combine.PB(MK(sb+sn,"bn"));
    combine.PB(MK(sb+se,"be"));
    combine.PB(MK(sn+sn,"nn"));
    combine.PB(MK(sn+se,"ne"));
    combine.PB(MK(se+se,"ee"));
   //sort(ALL(combine));
    //處理船的組合
    int kayaki = (b+n+e)/2;
    kayaking.resize(kayaki);
    for(int i=0;i<kayaki;i++){
        cin>>kayaking[i];
    }
    sort(ALL(kayaking)); // 讓c 比較小的船優先找乘客
    //reverse(ALL(kayaking));

    int l = 0 , r = 1e9;
    while(r>(l+1)){
        int mid = (l+r)>>1;
        if(check(mid))
            l = mid;
        else
            r = mid;
    } 
    cout<<l<<endl;

    return 0;
}

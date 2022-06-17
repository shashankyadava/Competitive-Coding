#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sky LONG_LONG_MAX
#define ajen LONG_LONG_MIN
#define mod 1000000007
#define modulo 998244353

vector<pair<ll,ll>>index1 = {
    {1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1}
};
const int N = 100000;
vector<int>adj[N];
int visi[N];
void dfs(int v){
    int parent = v;
    visi[parent] = 1;
    for(int child: adj[parent]){
        if(visi[child])continue;

        dfs(child);
    }
}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int>ans;
    int vis[100001] = {0};
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        ans.push_back(parent);
        for(int child: adj[parent]){
            if(vis[child])continue;
            q.push(child);
            vis[child] = 1;
        }
    }
    return ans;
}
bool cycleindirectedgraph(int parent,vector<bool>&visited,vector<bool>&dfsvisited){
    visited[parent] = true;
    dfsvisited[parent] = true;
    for(auto child: adj[parent]){
        if(!visited[child]){
            if(cycleindirectedgraph(child,visited,dfsvisited)){
                return true;
            }
        }
        if(visited[child]&&dfsvisited[child]){
            return true;
        }
    }
    dfsvisited[parent] = false;
    return false;
}
ll binaryexponentiation(ll a,ll b){
    if(b==0)return 1;
    ll res = binaryexponentiation(a,b/2);
    if(b%2) return res*res*a;
    else return res*res;
}

void SieveOfEratosthenes(int n){
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++){
        if (prime[p]){
            cout<<p<<" ";
        }
    }        
}
void add_edge(int n){
    for(int i = 0; i<n; i++){
        ll x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void setIO(string name="") {  // name is nonempty for USACO file I/O
	if (!name.empty()) {
		freopen((name+".in").c_str(), "r", stdin);  // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}
class dsu{

    vector<int>parent;
    vector<pair<ll,ll>>ans;
    vector<ll>r;
    dsu(int n){
        parent.resize(n+1,-1);
        ans.resize(n+1);
        r.resize(n+1,0);
    }
    int f(ll a){
        if(parent[a]<0)return a;
        return parent[a] = f(parent[a]);
    }
    void u(ll a,ll b){
        ll x = f(a);
        ll y = f(b);
        if(x==y){
            ans.push_back({a,b});
            return;
        }
        else{
            if(r[b]>r[a]){
                swap(a,b);
            }
            if(r[a]==r[b]){
                r[a]++;
            }
            parent[x] = y; 
        }
    }
};
class mst{
    struct edges{
        ll a,b,w;
    };
    edges ar[100005];
    vector<ll>parent;
    vector<ll>r;
    mst(int n){
        parent.resize(n+1,-1);
        r.resize(n+1,0);
    }
    int sum;
    bool comp(edges a,edges b){
        if(a.w<b.w)return true;
        else return false;
    }
    int f(ll a){// find with path compression
        if(parent[a]<0)return a;
        return parent[a] = f(parent[a]);
    }
    void u(ll a,ll b){//union by rank
        
        if(r[b]>r[a]){
            swap(a,b);
        }
        parent[b] = a;
        if(r[a]==r[b]){
            r[a]++;
        } 
    }
};
class segtree{
    vector<int>seg;
    segtree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low,int high,int arr[]){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)>>2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind,int low,int high,int l,int r){
        // no overlap
        if(high<l||low>r)return INT_MAX;
        // complete overlap
        if(low>=l&&high<=r)return seg[ind];
        // partial overlap
        int mid = (low+high)>>2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = (low+high)>>2;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val);
        }
        else update(2*ind+2,mid+1,high,i,val);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
};
int main(){
    //setIO("filename");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin>>t;
    while(t--){

    }  
    return 0;
}

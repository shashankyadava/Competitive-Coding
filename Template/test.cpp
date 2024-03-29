#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds ;
#define ll long long
#define sky LONG_LONG_MAX
#define ajen LONG_LONG_MIN
#define mod 1000000007
#define modulo 998244353
#define nline '\n'
#define need_mod 2147483647
const int N = 100000;
template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename PB> using ordered_set = tree<PB,null_type,less_equal<PB>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero i.e. it is zero indexed based).
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool isvalid(int x,int y){
    if(x<0||y<0||x>=1000||y>=1000)return false;
    return true;
}
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
            if(r[y]>r[x]){
                swap(x,y);
            }
            if(r[x]==r[y]){
                r[x]++;
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
        int mid = (low+high)/2;
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
class dijkstra{
    void solve(){
        vector<pair<int,int>>graph[1000];// in graph first contains the node and second 
                                        // contain the weight
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>dist(1000,1e9);
        q.push({0,1});
        dist[1] = 0;
        while(!q.empty()){
            int parent = q.top().second;
            int distance = q.top().first;
            q.pop();
            if(distance!=dist[parent])continue;
            for(pair<int,int> child: graph[parent]){
                if(distance+child.second<dist[child.first]){
                    dist[child.first] = distance+child.second;
                    q.push({dist[child.first],child.first});
                }
            }
        }
        for(int i = 0; i<=100; i++){
            // printing the distances 
            cout<<dist[i]<<" ";
        }
        cout<<endl;
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

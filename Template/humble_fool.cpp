#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sky LONG_LONG_MAX
#define ajen LONG_LONG_MIN
#define mod 1000000007
#define modulo 998244353

vector<pair<ll,ll>>index = {
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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin>>t;
    while(t--){
        
    }
    return 0;
}

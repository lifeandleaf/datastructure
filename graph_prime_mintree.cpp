#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123;
const int inf=1234567;
int graph[maxn][maxn],graph_tree[maxn][maxn];

void prime_mintree(int begin,int n)
{
    int all_val=0;
    vector<int>node_use;
    node_use.push_back(begin);
    vector<int>node_unuse;
    for(int i=1;i<=n;i++){
        if(i==begin) continue;
        node_unuse.push_back(i);
    }
    while(!node_unuse.empty()){
        int min=inf,ed=-1,bg=-1;
        for(int i=0;i<int(node_use.size());i++){
            for(int j=0;j<int(node_unuse.size());j++){
                if(graph[node_use[i]][node_unuse[j]]&&graph[node_use[i]][node_unuse[j]]<min){
                    min=graph[node_use[i]][node_unuse[j]];
                    ed=j;
                    bg=i;
                }
            }
        }
        if(min==inf) break;
        printf("node: from%3d   to%3d   value:%4d\n",node_use[bg],node_unuse[ed],min);
        all_val+=min;
        graph[node_use[bg]][node_unuse[ed]]=0;
        graph[node_unuse[ed]][node_use[bg]]=0;
        graph_tree[node_use[bg]][node_unuse[ed]]=min;
        graph_tree[node_unuse[ed]][node_use[bg]]=min;
        node_use.push_back(node_unuse[ed]);
        node_unuse.erase(node_unuse.begin()+ed);
    }
    printf("the sum of value is :%4d\n",all_val);
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    prime_mintree(1,n);
    return 0;
}
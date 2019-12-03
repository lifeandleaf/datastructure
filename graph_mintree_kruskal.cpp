#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123;

int parent[maxn],graph[maxn][maxn];

struct edge{
    int begin,end,val;
    bool operator < (const edge &x)const{
        return this->val<x.val;
    }
};

vector<edge>box_edge;

int find(int s)
{
    while(parent[s]>0){
        s=parent[s];
    }
    return s;
}

void graph_mintree(int n)
{
    for(int i=0;i<=n;i++){
        parent[i]=0;
    }
    int bg,ed,len=int(box_edge.size());
    for(int i=0;i<len;i++){
        bg=find(box_edge[i].begin);
        ed=find(box_edge[i].end);
        if(bg!=ed){
            parent[bg]=ed;
            printf("edge: from %3d to %3d ; value %4d\n",box_edge[i].begin,box_edge[i].end,box_edge[i].val);
        }
    }
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
            if(i<j&&graph[i][j]){
                box_edge.push_back(edge{i,j,graph[i][j]});
            }
        }
    }
    sort(box_edge.begin(),box_edge.end());
    graph_mintree(n);
    return 0;
}
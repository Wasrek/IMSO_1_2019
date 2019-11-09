/*
    TASK:Milk_Scheduling
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int t[10100],in[10100],out[10100];
vector< int > g[10010];
long long dfs(int i,long long now){
    now+=t[i];
    long long maa=now;
    // printf("%lld\n",now);
    for(auto x: g[i]){
        maa=max(maa,dfs(x,now));
        // printf("to %d\n",x);
    }
    return maa;
}
int main()
{
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        in[b]++;
        out[a]++;
        g[a].push_back(b);
    }
    long long ans=0,ma;
    for(int i=1;i<=n;i++){
        if(in[i]==0)ans=max(ans,(long long)t[i]);
        if(out[i]){
            ma=dfs(i,0);
            // printf("%lld\n",ma);
            ans=max(ma,ans);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

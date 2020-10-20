#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m;
vector<int> candy[6000],ans;
int dist[6000];
int jarak (int start, int target){
    if(start<=target){return target-start;}
    else{
        return n - (start-target);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(b>a)candy[a].push_back(b);
        else{candy[a].push_back(n+b);}
    }
    for(int i=1;i<=n;i++){
        sort(candy[i].begin(),candy[i].end());
        if(candy[i].empty()){dist[i]=0;}
        else{
            int sd=jarak(i,candy[i][0]);
            int jlh;
            jlh = candy[i].size()-1;
            dist[i] = sd+n*jlh;
        }
    }

    for(int i=1;i<=n;i++){
        int temp = 0;
        for(int j=1;j<=n;j++){
            if(candy[j].size()>0)temp = max (temp , dist[j] + jarak(i,j));
        }
        ans.push_back(temp);
    }
    for(int i=0;i<ans.size();i++){
        if(i>0)printf(" %d",ans[i]);
        else{printf("%d",ans[i]);}
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll sum[400000],righ[350000],lef[350000],best[350000];
int n,x,a[400000];
priority_queue < pair<ll,int> > q;
int main(){
    scanf("%d %d",&n,&x);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    for(int i=n;i>=1;i--){
        sum[i]=sum[i+1]+a[i];
        q.push(make_pair(sum[i],i));
    }
    for(int i=n;i>=1;i--){
        ll temp=0;
        while(!q.empty()){
            ll s = q.top().first;
            int idx = q.top().second;
            if(idx<=i){temp=max(temp,s-sum[i+1]);break;}
            else{q.pop();}
        }
        lef[i]=temp;
    }

    while(!q.empty())q.pop();
        for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        q.push(make_pair(sum[i],i));
    }
    for(int i=1;i<=n;i++){
        ll temp = 0;
        while(!q.empty()){
            ll s = q.top().first;
            int idx = q.top().second;
            if(idx>=i){temp=max(temp,s-sum[i-1]);break;}
            else{q.pop();}
        }
        righ[i]=temp;
    }

    ll mx=0;
    for(int i=0;i<=n;i++){mx = max (lef[i]+righ[i+1],mx);}

    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++){
        ll res = lef[i-1] - x*sum[i-1];
        if(res<0)res=0;
        q.push(make_pair(res,i));
    }

    for(int i=n;i>=1;i--){
        ll res = righ[i+1] + x * sum[i];
        ll add = 0;
        while(!q.empty()){
            ll s = q.top().first;
            int idx = q.top().second;
            if(idx<=i){add=max(add,s);break;}
            else{q.pop();}
        }
        best[i] = res + add;
        if(best[i]<0)best[i]=0;
    }
    for(int i=1;i<=n;i++){
        mx = max(mx,best[i]);
    }
    printf("%lld\n",mx);

}




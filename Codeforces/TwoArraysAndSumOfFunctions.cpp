#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,a[300000],b[300000],pre[300000];
ll md=998244353;
priority_queue < pair<int,int> > q;
ll m[300000];
ll sum = 0;
ll calc (){
        ll oc = n;
        pre[0]=0;
        for(int i=1;i<=n/2;i++){
            pre[i]=pre[i-1];
            pre[i]-= (i-1)*oc;
            pre[i]+= i*oc;
            ll temp = ((pre[i]%md)*(m[i]%md))%md;
            sum = ((sum % md) + (temp % md))%md;

            //cout<<pre[i]<<endl;
            oc-=2;
        }
        pre[n+1]=0;
        oc = n;
        int idx = 1;
        for(int i=n;i>n/2;i--){
            pre[i]=pre[i+1];
            pre[i]-=(idx-1)*oc;
            pre[i]+=idx*oc;
            ll temp = ((pre[i]%md)*(m[i]%md))%md;
            sum = ((sum % md) + (temp % md))%md;

            //cout<<pre[i]<<endl;
            oc-=2;
            idx++;
        }

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(make_pair(a[i],i));
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        int temp = q.top().first;
        int idx = q.top().second;
        m[idx] = ((temp % md)* (b[i]%md))%md;
        q.pop();
    }
    calc();
    cout<<sum<<endl;


}


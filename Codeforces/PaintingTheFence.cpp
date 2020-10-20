#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int l[6000],r[6000],n,q;
int pd[6000],paint[6000];
int s1[6000],s2[6000],s3[6000];
int mp(int one,int two){
    pair<int,int> p1,p2;
    p1 = make_pair(l[one],r[one]);
    p2 = make_pair(l[two],r[two]);
    if(p1>p2)swap(p1,p2);

    if(p1.second >= p2.first){
        int a=p1.first;
        int b=p2.first;
        int c=min(p1.second,p2.second);
        int d=max(p2.second,p1.second);
        int painted = s1[n]+s2[n]+s3[n];
        int cancel=0;
        cancel += s1[b]-s1[a-1];
        cancel += s1[c]-s1[b-1];
        cancel += s2[c]-s2[b-1];
        cancel += s1[d]-s1[c-1];
        return painted-cancel;
    }
    else{
        int painted = s1[n]+s2[n]+s3[n];
        int cancel = 0;
        int a,b,c,d;
        a=p1.first;
        b=p1.second;
        c=p2.first;
        d=p2.second;
        cancel += s1[b]-s1[a-1];
        cancel += s1[d]-s1[c-1];
        return painted-cancel;
    }
}

int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l[i],&r[i]);
        pd[l[i]]++;
        pd[r[i]+1]--;
    }
    for(int i=1;i<=n;i++)paint[i]=paint[i-1]+pd[i];
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1];
        s2[i]=s2[i-1];
        s3[i]=s3[i-1];
        if(paint[i]==1){s1[i]++;}
        if(paint[i]==2){s2[i]++;}
        if(paint[i]>2){s3[i]++;}
    }
    int mx=0;
    for(int i=1;i<q;i++){
        for(int j=i+1;j<=q;j++){
            mx=max (mx,mp(i,j));
        }
    }
    printf("%d\n",mx);

}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int segtree[4 * 100010],lazy[4*100010],a[100010],n;
void build(int stree[], int arr[], int node, int l, int r){
    if(l==r){
        stree[node] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(stree,arr,node*2,l,mid);
    build(stree,arr,node*2+1,mid+1,r);
    stree[node] = min (stree[node*2] , stree[node*2+1]);
}
void update(int stree[], int node, int l, int r, int ql, int qr, int val){
    if(ql > r || qr < l) return;
    int sel = 1;
    if(lazy[node] != 0){
        stree[node] += sel * lazy[node];
        if(l!=r){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(ql <= l && r <= qr){
        stree[node] += sel * val;
        if(l!=r){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (l+r)/2;;
    update(stree,node*2,l,mid,ql,qr,val);
    update(stree,node*2+1,mid+1,r,ql,qr,val);
    stree[node] = min(stree[node*2] , stree[node*2+1]);
}
int query(int stree[], int node, int l, int r, int ql, int qr){
    if(lazy[node] != 0){
        int sel = 1;
        stree[node] += lazy[node] * sel;
        if(l!=r){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(ql > r || qr < l) return INT_MAX;
    if(ql <= l && r <= qr) return stree[node];
    int mid = (l+r)/2;
    return min(query(stree,node*2,l,mid,ql,qr) , query(stree,node*2+1,mid+1,r,ql,qr));
}
int main(){
    cin>>n; for(int i=1;i<=n;++i) cin>>a[i];
    build(segtree, a, 1, 1, n);
    update(segtree, 1, 1, n, 1, n, -10);
    cout<<query(segtree, 1, 1, n, 1, 4)<<endl;
}

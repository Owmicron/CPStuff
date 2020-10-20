#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pob pop_back

ll cross_product(pll o, pll a, pll b){
    return  (a.fi - o.fi) *  (b.se - o.se) -  (a.se - o.se) * (b.fi - o.fi);
}
vpii convex_hull(vpii A){
    int n = A.size();
    if(n <= 3) return A;

    vpii ans;
    sort(all(A));
    for(int i=0;i<n;++i){
        while(ans.size()>=2 && cross_product(ans[ans.size()-2],ans[ans.size()-1],A[i]) <= 0)++f, ans.pob();
        ans.pb(A[i]);
    }
    int lim = ans.size()+1;
    for(int i=n-2;i>=0;--i){
        while(ans.size() >= lim && cross_product(ans[ans.size() - 2], ans[ans.size() - 1], A[i]) <= 0 ) ans.pob();
        ans.pb(A[i]);
    }
    ans.pob();
    return ans;
}
int main(){

    vpii points;

    points.push_back({ 0, 3 });
    points.push_back({ 2, 2 });
    points.push_back({ 1, 1 });
    points.push_back({ 2, 1 });
    points.push_back({ 3, 0 });
    points.push_back({ 0, 0 });
    points.push_back({ 3, 3 });
    points.push_back({ 0, 2 });

    vpii c = convex_hull(points);
    for(auto i : c) cout<<i.fi<<","<<i.se<<endl;

	return 0;
}

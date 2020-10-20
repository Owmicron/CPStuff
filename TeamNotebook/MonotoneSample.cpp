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

//struct Point{
//	long double x, y;
//	bool operator (Point p) return x < p.x || (x == p.x && y < p.y);
//};
//const long double EPS = 0.0000001;
//long double cross_product(Point o, Point a, Point b){
//	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
//}
//vector<Point> convex_hull(vector<Point> A){
//	int n = A.size(), k = 0;
//	if(n <= 3) return A;
//	vector<Point> ans(2*n);
//	sort(A.begin(), A.end());
//	for(int i = 0; i < n; i++){
//		while(k >= 2 && cross_product(ans[k-2], ans[k-1], A[i]) <= EPS) k--;
//		ans[k++] = A[i];
//	}
//	for(int i = n-1, t = k+1; i > 0; i--){
//		while(k >= t && cross_product(ans[k-2], ans[k-1], A[i-1]) <= EPS) k--;
//		ans[k++] = A[i-1];
//	}
//	ans.resize(k-1);
//	return ans;
//}

ll cross_product(pll o, pll a, pll b){
    return  (a.fi - o.fi) *  (b.se - o.se) -  (a.se - o.se) * (b.fi - o.fi);
}
vpii convex_hull(vpii A){
int n = A.size(), k = 0;

    if (n <= 3)
        return A;

    vector<pii> ans(2 * n);

    // Sort points lexicographically
    sort(A.begin(), A.end());

    // Build lower hull
    for (int i = 0; i < n; ++i) {

        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        int f = 0;
        while (k >= 2 && cross_product(ans[k - 2],
                          ans[k - 1], A[i]) <= 0)
            ++f, k--;
        ans[k++] = A[i];
        //for(auto it : ans) cout<<it.fi<<" "<<it.se<<endl;
    }
    for(auto i : ans) cout<<i.fi<<" "<<i.se<<endl;

    // Build upper hull
    for (size_t i = n - 1, t = k + 1; i > 0; --i) {

        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        while (k >= t && cross_product(ans[k - 2],
                           ans[k - 1], A[i - 1]) <= 0)
            k--;
        ans[k++] = A[i - 1];
    }

    // Resize the array to desired size
    ans.resize(k - 1);

    return ans;
}
int main(){
//	int n, sz;
//	long double x, y;
//	vector<Point> points;
//	cin >> n;
//	for(int i = 0; i < n; i++){
//		cin >> x >> y;
//		points.push_back({x, y});
//	}
//	vector<Point> ans = convex_hull(points);
//	sz = ans.size();
//	for(int i = 0; i < sz; i++){
//		cout << ans[i].x << ' ' << ans[i].y << endl;
//	}

    vpii points;

    points.push_back({ 0, 3 });
    points.push_back({ 2, 2 });
    points.push_back({ 1, 1 });
    points.push_back({ 2, 1 });
    points.push_back({ 3, 0 });
    points.push_back({ 0, 0 });
    points.push_back({ 3, 3 });

    vpii c = convex_hull(points);
    //for(auto i : c) cout<<i.fi<<","<<i.se<<endl;

	return 0;
}

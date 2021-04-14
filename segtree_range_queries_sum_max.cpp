#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define rep(i,s) for(ll i=0; i<s ; i++)
#define f(i,a,b) for(ll i(a); i<b ; i++)
const ll INF = 1000000000;
const ll N = 300005;
const ll MOD = 1000000007;
const ll cons = 200005;
const ll MOD2= 1000000006;
const ll MAXN = 1000005;
using namespace std;

ll treesum[4*N];
ll treemax[4*N];

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        treesum[v] = a[tl];
        treemax[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        treesum[v] = treesum[v*2] + treesum[v*2+1];
        treemax[v] = max(treemax[v*2],treemax[v*2+1]);
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return treesum[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
ll maxi(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r){
        return 0;
    }
    if (l == tl && r == tr) {
    	return treemax[v];
    }
    ll tm = (tl + tr) / 2;
    return max(maxi(v*2, tl, tm, l, min(r, tm)),maxi(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll change) {
    if (tl == tr) {
        treemax[v] = change;
        treesum[v] = change;
    } else {
        ll tm = (tl + tr) / 2;
        if (l <= tm){
            update(v*2, tl, tm, l , r , change);
        }
        if(r >= tm+1){
            update(v*2+1, tm + 1, tr,l , r , change);
        }
        treesum[v] = treesum[v*2] + treesum[v*2 + 1];
        treemax[v] = max(treemax[v*2],treemax[v*2 + 1]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll n,m;
	cin >> n >> m;
	ll arr[n+1];
	f(i,1,n+1){
		cin >> arr[i];
	}
	build(arr,1,1,n);
	rep(i,m){
		ll k,l,r;
		cin >> k >> l >> r;
		if(k == 2){
			ll val = sum(1,1,n,l,r);
			cout << val << endl;
		}
		else{
			ll val = maxi(1,1,n,l,r);
			if(val > 2){
				update(1,1,n,l,r);
			}
		}
	}
}

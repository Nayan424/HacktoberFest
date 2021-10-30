#define ff first
#define ss second
#define sz(x) (ll)x.size()
#define all(x) x.begin(),x.end()
#define pl pair<ll,ll>
#define vi vector<ll>
#define vii vector<pl>
#define val(x) cout<<#x<<" is "<<x<<endl
bool flag=true;
const ll N=2e5+10;
const ll inf = 998244353;
ll modpow(ll x,ll y,ll p=mod)
{  
    ll res = 1;    
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {  
        if (y & 1)  
          res = (res%p*x%p) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 
ll modinv(ll n , ll p=mod)
{
    return modpow(n,p-2,p);
}
void facto()
{
	vi fact(5);
	fact[0]=1;
	inv[0]=1;
	for (ll i = 1; i < 5; i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=modinv(fact[i])%mod;
	}
}
//prime factorization
ll spf[N+1];
vector<ll> pr;
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<N; i++) 
        spf[i] = i; 
    for (int i=4; i<N; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<N; i++) 
    { 
        if (spf[i] == i) //prime nos
        { 
            for (int j=i*i; j<N; j+=i) 
  
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
void primefactorization(ll x)
{
	vii v;
	while(x!=1)
	{
		ll m=spf[x];
		//cout<<x<<"--->"<<spf[x]<<endl;
		ll cnt=0;
		while(x%m==0)
		{
			x/=m;
			cnt++;
		}
		
		//val(m);
		v.pb({m,cnt});
	}
}
//------------------------------------------
//How to write adjacent grid bfs
int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
auto curr = q.front(); 
q.pop();

er = curr.first;
ec = curr.second;
for(auto& dir: dirs)
	int nr = er + dir[0], nc = ec + dir[1];

//-------------------------------------------------

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ll t;
	cin >> t;
 
	for(ll tc = 1; tc <= t; tc++) {
		ll x, y;
		cin >> x >> y;
		cout << "Case #" << tc << ": ";	
 
		string steps = "";
 
		while(x != 0 || y != 0) 
		{
		    if(abs(x) % 2 == 1 && abs(y) % 2 == 1) {
    		    cout << "IMPOSSIBLE" << endl;
    		    steps = "";
    		    break;
    		}
    		if(abs(x) % 2 == 0 && abs(y) % 2 == 0) {
    		    cout << "IMPOSSIBLE" << endl;
    		    steps = "";
    		    break;
    		}
 
		    if(abs(x) % 2 == 1) {
		    	if((x-1)/2==0&&y==0) {
		    		steps += "E";
    		        x -= 1;
		    	} else if((x+1)/2==0&&y==0) {
		    		steps += "W";
    		        x += 1;
		    	} else if(((x-1)/2 + y/2) % 2 == 0) {
		            steps += "W";
    		        x += 1;
		        } else {
		            steps += "E";
    		        x -= 1;
		        }
    		}
    		if(abs(y) % 2 == 1) {
    			if((y-1)/2 == 0 && x/2 == 0) {
    				steps += "N";
    		        y -= 1;
    			} else if((y+1)/2==0 && x/2 ==0) {
    				steps += "S";
    				y +=1;
    			} else if(((y-1)/2 + x/2) % 2 == 0) {
		            steps += "S";
    		        y += 1;
		        } else {
		            steps += "N";
    		        y -= 1;
		        }
    		}
    		x = x/2;
    		y = y/2;
		}
 
		if(steps != "") 
		cout << steps << endl;
	}
 
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const double E = 1e-9, pi = 2 * acos(0);
struct Point {
    int x, y, id;
};
Point operator - (Point a, Point b){
    return (Point){a.x - b.x, a.y - b.y, -1};
}
long long cross(Point a, Point b){
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}
long long cross(Point a, Point b, Point c){
    return cross(b - a, c - a);
}
vector<Point> convex_hull(vector<Point> points)
{
    sort(points.begin(), points.end(), [&](Point a, Point b){
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });
    vector<Point> upper, lower;
    for(int i = 0; i < (int)points.size(); i++){
        while(upper.size() >= 2 && cross(upper.end()[-2], upper.end()[-1], points[i]) > 0)
            upper.pop_back();
        upper.push_back(points[i]);
    }
    for(int i = (int)points.size() - 1; i >= 0; i--){
        while(lower.size() >= 2 && cross(lower.end()[-2], lower.end()[-1], points[i]) > 0)
            lower.pop_back();
        lower.push_back(points[i]);
    }
    if(lower.size() > 2) upper.insert(upper.end(), lower.begin() + 1, lower.end() - 1);
    return upper;
}
// 1 => Strictly inside; -1 => Border; 0 => Outside
int point_in_poly(const vector<Point> & poly, Point p){
    int many = 0;
    for(int i = 0; i < (int)poly.size(); i++)
    {
        Point a = poly[i], b = poly[i + 1 < (int) poly.size() ? i + 1 : 0];
        if(a.x > b.x) swap(a, b);
        if(a.x <= p.x && p.x <= b.x)
        {
            if(abs(a.x - b.x) == 0)
            {
                if(min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) return -1;
            } 
            else 
            {
                double y = a.y + 1. * (b.y - a.y) / (b.x - a.x) * (p.x - a.x);
                if(abs(y - p.y) <= E) return -1;
                if(y >= p.y && p.x < b.x) many++;
            }
        }
    }
    return many % 2;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<Point> poly(n);
        vector<int> not_used(n, 1);
        for(int i = 0; i < n; i++){
            cin >> poly[i].x >> poly[i].y;
            poly[i].id = i;
        }
        vector<vector<Point>> rings;
        while(accumulate(not_used.begin(), not_used.end(), 0) >= 3){
            vector<Point> can;
            for(int i = 0; i < n; i++){
                if(not_used[i]){
                    can.push_back(poly[i]);
                }
            }
            vector<Point> hull = convex_hull(can);
            for(auto & p : hull)
                not_used[p.id] = 0;
            rings.push_back(hull);
        }
        for(int i = 0; i < q; i++){
            Point p;
            cin >> p.x >> p.y;
            int ans = 0;
            for(auto & ring : rings){
                if(point_in_poly(ring, p) == 1)
                    ans += 1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}

#include <stdio.h>     
#include <stdlib.h>    
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
#define ld long double
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<iii,int>
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define vv vector
#define endl '\n'
 
using namespace std;
 
const int MAXN = 100*1000 + 5;
 
struct DSU{
	int parent[MAXN];
	vv<ii> extraEdge[MAXN];
	DSU(){
		FOR(i,MAXN)parent[i] = i;
	}
	int find(int a){
		if(parent[a] != a)parent[a] = find(parent[a]);
		return parent[a];
	}
	bool isSame(int a,int b){
		return find(a) == find(b);
	}
	void merge(int a,int b){
		if(isSame(a,b)){
			int pa = find(a);
			extraEdge[pa].pb({a,b});
		}else{
			int pa = find(a);
			int pb = find(b);
			if(extraEdge[pa].size() > extraEdge[pb].size()){
				parent[pb] = pa;
				for(auto e: extraEdge[pb])extraEdge[pa].pb(e);	
			}else{
				parent[pa] = pb;
				for(auto e: extraEdge[pa])extraEdge[pb].pb(e);
			}
		}
	}
};	
 
multiset<int> g[MAXN];
void solve(){
	DSU dsu;
	int n,m;
	cin >> n >> m;
	FOR(i,n)g[i].clear();
	FOR(i,m){
		int a,b;
		cin >> a >> b;
		a--;b--;
		dsu.merge(a,b);
		g[a].insert(b);
		g[b].insert(a);
	}
	vi allRootsNotTree;
	vi allRootsTree;
	FOR(i,n){
		if(dsu.find(i) == i){
			if(dsu.extraEdge[i].empty())allRootsTree.pb(i);
			else allRootsNotTree.pb(i);
		}
	}
 
 	vv<ii> allExtraEdges;
	vv<ii> newEdges;
	int s = allRootsNotTree.size();
	if(s > 1){
		FOR(i,s){
			ii ed = dsu.extraEdge[allRootsNotTree[i]].back();
			ii edn = dsu.extraEdge[allRootsNotTree[(i+1)%s]].back();
			//cout << ed.ff << " " << ed.ss << endl;
			//cout << ed.ff << " " << ed.ss << endl;
			g[ed.ff].erase(g[ed.ff].find(ed.ss));
			g[ed.ss].erase(g[ed.ss].find(ed.ff));
			g[ed.ss].insert(edn.ff);
			g[edn.ff].insert(ed.ss);
			if(i == 0)allExtraEdges.pb({edn.ff,ed.ss});
		}
	}
	
 	if(s > 1){
 		FOR(i,s)dsu.extraEdge[allRootsNotTree[i]].pop_back(); // since all these were already used. 	
 	}
	
	
	FOR(i,s){
		for(auto e : dsu.extraEdge[allRootsNotTree[i]]){
			allExtraEdges.pb(e);
		}
	}
	int x = 0;	
	vi listOf1Nodes;
	while(!allExtraEdges.empty()){
		auto e = allExtraEdges.back();
		if(allRootsTree.empty())break;
		int item = allRootsTree.back();allRootsTree.pop_back();
		if(g[item].empty())listOf1Nodes.pb(item);
		else{
			int nitem = *(g[item].begin());
			g[item].erase(g[item].find(nitem));
			g[e.ff].erase(g[e.ff].find(e.ss));
			g[e.ss].erase(g[e.ss].find(e.ff));
			g[nitem].erase(g[nitem].find(item));
			g[item].insert(e.ff);
			g[e.ff].insert(item);
			g[nitem].insert(e.ss);
			g[e.ss].insert(nitem);
 
			allExtraEdges.pop_back();
		}
	}
	for(auto e : listOf1Nodes)allRootsTree.pb(e);
	for(auto e : allExtraEdges){
		if(allRootsTree.size() == 0){
			break;
		}
		if(allRootsTree.size() == 1){
			g[e.ff].erase(g[e.ff].find(e.ss));
			g[e.ss].erase(g[e.ss].find(e.ff));
			int root1 = allRootsTree.back();allRootsTree.pop_back();
			g[e.ff].insert(root1);
			g[e.ss].insert(root1);
			g[root1].insert(e.ff);
			g[root1].insert(e.ss);
			x+=2;
			break;
		}
 
		g[e.ff].erase(g[e.ff].find(e.ss));
		g[e.ss].erase(g[e.ss].find(e.ff));
		int root1 = allRootsTree.back();allRootsTree.pop_back();
		int root2 = allRootsTree.back();allRootsTree.pop_back();
		g[e.ff].insert(root1);
		g[e.ss].insert(root2);
		g[root1].insert(e.ff);
		g[root2].insert(e.ss);
		x+=2;
	}
 
	//cout << "SSGDFg" << endl;
	
	int root1;
	if(allRootsNotTree.empty())root1 = allRootsTree[0];
	else root1 = allRootsNotTree[0];
	for(auto e : allRootsTree){
		if(allRootsNotTree.empty() and e == allRootsTree[0])continue;
		x += 2;	
		g[e].insert(root1);
		g[root1].insert(e);
	}
 
 
 
	vv<ii> allEdges;
	FOR(i,n){
		for(auto e: g[i]){
			if(i < e){
				allEdges.pb({i,e});
			}
		}
	}
	cout << x << " " << allEdges.size() << endl;
	for(auto e: allEdges){
		cout << e.ff+1 << " " << e.ss+1 << endl;
	}
}
 
#include<bits/stdc++.h>
using namespace std;
#define ll int
map<pair<ll,ll>,list<pair<ll,ll>>> adj;
ll func(ll turn,ll ra,ll pa,ll rb,ll pb,map<pair<ll,ll>,ll>& mp,ll ctra,ll ctrb)
{
	bool cont=true;
	for(auto x :adj[{ra,pa}])
	{
		if(!mp[x])
		cont=false;
	}
	for(auto x:adj[{rb,pb}])
	{
		if(!mp[x])
		cont=false;
	}
	if(cont)
	{
		return ctra-ctrb;
	}
	if(turn==0)
	{
		ll mx=INT_MIN;
		bool f=false;
		for(auto x:adj[{ra,pa}])
		{
			if(mp[x]) continue;
			f=true;
			mp[x]++;
			mx=max(mx,func(1,x.first,x.second,rb,pb,mp,ctra+1,ctrb));
			mp[x]--;
		}
		if(!f)
		mx=func(1,ra,pa,rb,pb,mp,ctra,ctrb);
		return mx;
	}
	else
	{
		ll mx=INT_MAX;
		bool f=false;
		for(auto x:adj[{rb,pb}])
		{
			if(mp[x]) continue;
			f=true;
			mp[x]++;
			mx=min(mx,func(0,ra,pa,x.first,x.second,mp,ctra,ctrb+1));
			mp[x]--;
		}
		if(!f)
		mx=func(0,ra,pa,rb,pb,mp,ctra,ctrb);
		return mx;
	}
}



#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

void solve(int test){
	cout << "Case #" << test << ": ";
	int r,c;
	cin >> r;
	c = r;
	vector<vector<int>> a(r,vector<int>(c));
	vector<vector<int>> b(r,vector<int>(c));
	vector<int> p(r),q(c);
	
	int R = r + 10;
	
	vector<vector<pii>> v(R + c + 20);
	vector<int> vis(R+c+20);
	
	rep(i,0,r){
		rep(j,0,c){
			cin >> a[i][j];
		}
	}
	
	int tot = 0;
	set<pii> s;
	
	rep(i,0,r){
		rep(j,0,c){
			cin >> b[i][j];
			if(a[i][j] == -1){
				v[i].pb({j+R,b[i][j]});
				v[j+R].pb({i,b[i][j]});
				tot += b[i][j];
				s.insert({0,i});
			}
		}
	}
	
	rep(i,0,r){
		cin >> p[i];
	}
	
	rep(j,0,c){
		cin >> q[j];
	}
	
	int ans = 0;
	
	while(!s.empty()){
		auto cur = *s.begin();
		s.erase(cur);
		int dis = -cur.fr;
		// cout << dis << "\n";
		int ver = cur.sc;
		if(vis[ver]){
			continue;
		}
		ans += dis;
		vis[ver] = 1;
		for(pii x:v[ver]){
			if(vis[x.fr]){
				continue;
			}
			s.insert({-x.sc,x.fr});
		}
	}
	
	ans = tot - ans;
	cout << ans;
	cout << "\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	cin>>t;
	rep(i,1,t+1) solve(i);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int INF=1e18;
const int N=1e5+5;


const int32_t maxn=N;
struct node{
	int v=0;
	node(){}
	node(int val){
		v=1<<(val-'a');
	}
	void merge(node &l,node &r)
	{
		v=l.v|r.v;
	}
}zero;
struct update{
	int v=0;
	update(){}
	update(int val){
		v=val;
	}
	void combine(update &other){
		
	}
	void apply(node &x){
		x=v;
	}
}noop;
struct segtree{
	node t[4*maxn];
	bool lazy[4*maxn];
	update upds[4*maxn];
	void pushdown(int32_t v,int32_t tl,int32_t tr)
	{
		int32_t tm=(tl+tr)/2;
		if(lazy[v]){
			apply(v*2,tl,tm,upds[v]);
			apply(v*2+1,tm+1,tr,upds[v]);
			lazy[v]=0;
			upds[v]=noop;
		}
	}
	void apply(int32_t v,int32_t tl,int32_t tr,update &val)
	{
		if(tl!=tr){
			lazy[v]=1;
			upds[v].combine(val);
		}
		val.apply(t[v]);
	}
	template<typename T>
	void build(T a[], int32_t v, int32_t tl, int32_t tr) {
		if (tl == tr) {
			t[v]=a[tl];
			return;
		} else {
			int32_t tm = (tl + tr) / 2;
			build(a, v*2, tl, tm);
			build(a, v*2+1, tm+1, tr);
			t[v].merge(t[v*2],t[v*2+1]);
		}
	}
	node query(int32_t v, int32_t tl, int32_t tr, int l, int r) {
		if (l > tr || r < tl)
			return zero;
		if (l <= tl && tr <= r) {
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) / 2;
		node a,b,ans;
		a=query(v*2, tl, tm, l, r);
		b=query(v*2+1, tm+1, tr, l, r);
		ans.merge(a,b);
		return ans;
	}
	void rupd(int32_t v, int32_t tl, int32_t tr, int l, int r, update &val)
	{
		if(l > tr || r < tl)
			return;
		if(l <= tl && tr <= r)
		{
			apply(v,tl,tr,val);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr)/2;
		rupd(v*2,tl,tm,l,r,val);
		rupd(v*2+1,tm+1,tr,l,r,val);
		t[v].merge(t[v*2],t[v*2+1]);
	}
public:
	int len=maxn;
	void clear(){
		rep(i,0,4*len){
			t[i]=zero;
			lazy[i]=0;
			upds[i]=noop;
		}
	}
	template<typename T>
	void build(T a[]){
		build(a,1,0,len-1);
	}
	node query(int l,int r){
		return query(1,0,len-1,l,r);
	}
	void rupd(int l,int r,update val){
		rupd(1,0,len-1,l,r,val);
	}
}t;

char c[N];
void solve(){
	int q;
	cin>>c>>q;
	t.build(c);
	rep(i,0,q){
		int k;
		cin>>k;
		if(k==1){
			int pos;char ch;
			cin>>pos>>ch;
			pos--;
			t.rupd(pos,pos,ch);
		}
		else{
			int l,r;
			cin>>l>>r;
			l--;r--;
			cout<<ppc(t.query(l,r).v)<<"\n";
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}


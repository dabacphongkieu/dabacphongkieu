#include<bits/stdc++.h>
#include<conio.h>

#define INF 1000000000000
#define pb push_back
#define ff first
#define ss second
#define vt vector
#define ll long long
#define vl vt<ll>
#define vll vt<pair<ll, ll> >
#define for1(i, a, b) for(ll i = a; i <= b; ++i)
#define for2(i, a, b) for(ll i = a; i >= b; --i)

using namespace std;
ll m, n, u, v, w, t, d[1005][105];
vl a(1005);
vll son_in_law[1005];
tuple<ll, ll, ll> m1;
priority_queue<tuple<ll, ll, ll>, vt<tuple<ll, ll, ll> >, greater<tuple<ll, ll, ll> > > pq;

void dijkstra(){
	
	for1(i,0,1004){
		for1(j,0,104){
			d[i][j] = INF;
		}
	}
	
	d[u][0] = 0;
	pq.push(make_tuple(d[u][0], u, 0));
	while(pq.size()){
		m1 = pq.top();
		pq.pop();
		if(get<1>(m1) == v){
			cout << get<0>(m1) <<"\n";
			while(pq.size()) pq.pop();
			break;
		}
		if(d[get<1>(m1)][get<2>(m1)] != get<0>(m1)) continue;
		 
		// Tai moi thoi diem : Hoac cong them 1 lit (Dung yen)
		w = get<0>(m1) + a[get<1>(m1)];
		if(get<2>(m1)+1 <= n && w < d[get<1>(m1)][get<2>(m1) + 1]){
			d[get<1>(m1)][get<2>(m1) + 1] = w;
			pq.push(make_tuple(w, get<1>(m1), get<2>(m1) + 1));
		}
		
		// Hoac nhay sang mot node lien ke
		for(auto i : son_in_law[get<1>(m1)]){
			w = get<2>(m1) - i.ss;
			if(w >= 0 && d[i.ff][w] > get<0>(m1)){
				d[i.ff][w] = get<0>(m1);
				pq.push(make_tuple(get<0>(m1), i.ff, w));
			}
		} 
	}
	if(d[v][0] == INF) cout <<"impossible\n";
}

int main() {
//	freopen("PERFECT1.inp", "r", stdin);
//	freopen("PERFECT1.out", "w", stdout);	
	cin >> m >> n;
	for1(i,0,m-1) cin >> a[i];
	
	for1(i,1,n){
		cin >> u >> v >> w;
		son_in_law[u].pb({v, w});
		son_in_law[v].pb({u, w});
	}
	
	cin >> t;
	while(t--){
		cin >> n >> u >> v;
		dijkstra();	
	}
}

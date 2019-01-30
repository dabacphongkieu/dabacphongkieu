#include<bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define X real()
#define Y imag()
#define vt vector
#define ll long long
#define vl vt<ll>
#define vll vt<pair<ll, ll> >
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define for1(i, a, b) for(ll i = a; i <= b; ++i)
#define for2(i, a, b) for(ll i = a; i >= b; --i)

using namespace std;
const ll INF = 1000000007;
typedef complex<double> P;
map<pair<double,double>, ll> mp;
map<pair<double,double>,P>up;
map<pair<double,double>,bool>check;
vt<P>arr;
stack<P> stk;
stack<P> stk1;

bool cmp(const P &a, const P &b){
	if(a.X < b.X) return true;
	if(a.X == b.X && a.Y < b.Y) return true;
	return false;
}

void build_upper_bound(const P &a){ 	// Can't go to the left( > 0)
	
	P b, c;
	b = stk.top();stk.pop();c = stk.top();
	
	while(1){
		if((conj(b-c)*(a-b)).Y >= 0){
			if(stk.size() > 1){
				b = c;
				stk.pop();
				c = stk.top();	
			}else break;
		}else{stk.push(b);break;} 
	}
	
	stk.push(a);
	
	return;
}

void build_lower_bound(const P &a){ 	// Can't go to the right( < 0)
	
	P b, c;
	b = stk1.top();stk1.pop();c = stk1.top();
	
	while(1){
		if((conj(b-c)*(a-b)).Y <= 0){
			if(stk1.size() > 1){
				b = c;
				stk1.pop();
				c = stk1.top();	
			}else break;
		}else{stk1.push(b);break;} 
	}
	
	stk1.push(a);
	
	return;
}

int main() {
//	freopen("PERFECT1.inp", "r", stdin);
//	freopen("PERFECT1.out", "w", stdout);
	ll t,n,u,v,cnt = 0;
	P a, b;
	cin >> t;
	while(t--){
		if(++cnt != 1) cout <<"\n\n";
		mp.clear();
		up.clear();
		arr.clear();
		check.clear();
		P exact(INF,INF);
		cin >> n;
		for1(i,1,n){
			cin >> u >> v;
			a = P(u,v);
			
			if(exact.Y > a.Y || (exact.Y == a.Y && exact.X > a.X)) exact = a;
			if(!mp[{a.X,a.Y}]){mp[{a.X,a.Y}] = i;arr.pb(a);}
		}
		
		sort(arr.begin(), arr.end(), cmp);
		
		for(auto i : arr){
			if(stk.size()<2){stk.push(i);continue;}
			build_upper_bound(i);
		}
		
		for(auto i : arr){
			if(stk1.size()<2){stk1.push(i);continue;}
			build_lower_bound(i);
		}
		
		double sum = 0;
/*
		while(stk1.size()){cout<<stk1.top()<<" ";stk1.pop();}
		cout<<":Bao duoi\nBao tren:";
		while(stk.size()){cout<<stk.top()<<" ";stk.pop();}
*/
		while(stk1.size()!=1){b=stk1.top();stk1.pop();up[{stk1.top().X,stk1.top().Y}]=b;sum+=abs(b-stk1.top());}
		while(stk.size()!=1){b=stk.top();stk.pop();up[{b.X,b.Y}]=stk.top();sum+=abs(b-stk.top());}
		stk.pop();stk1.pop();
		printf("%.2lf\n",sum);
		while(check[{exact.X,exact.Y}]==0){
			cout << mp[{exact.X,exact.Y}] <<" ";
			check[{exact.X,exact.Y}] = 1;
			exact = up[{exact.X,exact.Y}];
		}
	}
}
/*
1
8
1 2
1 9
2 0
3 0
4 9
6 4
10 4
7 9
*/



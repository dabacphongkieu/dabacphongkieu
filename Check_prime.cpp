#include<bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
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
ll xyz[] = {2,3,5,7,11,13,17,19,23,29,31,37};

ll val(ll x, ll y, ll modd){
	if(y == 1) return x%modd;
	ll u = val(x,y/2,modd);
	return y%2?(u+u+x)%modd:(u+u)%modd;
}

ll power(ll m, ll n, ll modd){
	if(n == 0) return 1%modd;
	if(n == 1) return m%modd;
	ll au = power(m,n/2,modd);
	return n%2?(val(val(au,au,modd),m,modd))%modd:(val(au,au,modd))%modd;
}

pll anal(ll a){
	ll cnt = 0;
	while(a%2==0){
		cnt++;
		a/=2;
	}
	return {cnt, a};
}

bool check_prime(ll a){
	ll s, d;
	tie(s,d) = anal(a-1);
	bool wa;
	for1(aa,0,11){
		wa = true;
		for1(r,0,s-1){
			if(xyz[aa]!=a && power(xyz[aa],d,a) != 1 && (power(xyz[aa],(ll)(pow(2,r)*d),a)+1)%a!=0){
			}else wa = false;
		}
		if(wa == true) return 0;
	}
	return 1;
}

bool check(ll a){
	if(a%2==0){cout << 0;return 0;} 
	cout << check_prime(a);	
}
int main() {
	
}



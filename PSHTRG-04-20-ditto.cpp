#include <bits/stdc++.h>
using namespace std;
typedef long long int in;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define lp(i,a,b) for(i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i<b;i++)
#define iter vector<in>::iterator
#define MOD 1000000007
struct node{
	int se, ss;
	vector<ll>v;
};
int n;
ll* ar;
node *st;
void build(int i, int s, int e){
	if(s==e){
		st[i].se = st[i].ss = s;
		st[i].v.pb(ar[s]);
		//cout<<"\n\n"<<st[i].v.size()<<endl;
		//cout<<ar[s];
		return;
	}
	else{
		build(2*i+1, s, (s+e)/2);
		build(2*i+2, (s+e)/2+1, e);
		st[i].se = e; st[i].ss = s;
		int l1 = st[2*i+1].v.size();
		int l2 = st[2*i+2].v.size();
		//cout<<"Len: "<<s<<"  "<<e<<"  "<<l1+l2<<endl;
		vector<ll> tmp;
		int p=0,q=0;
		while(p<l1 || q <l2){
			if(p==l1){tmp.pb(st[2*i+2].v[q++]);}
			else if(q==l2){tmp.pb(st[2*i+1].v[p++]);}
			else{
				ll a=st[2*i+1].v[p];
				ll b=st[2*i+2].v[q];
				if(a<=b){tmp.pb(a); p++;}
				else {tmp.pb(b); q++;}
			}
		}
		//fr(j,0,tmp.size())cout<<tmp[j]<<" ";
		//cout<<tmp.size()<<endl; 
		p = l1+l2-3;
		while(p>=0){
			ll a=tmp[p], b=tmp[p+1], c=tmp[p+2];
			if(a+b>c && b+c>a && c+a>b)break;
			if(p==0)break;
			p--;
		}
		if(p<0)p=0;
		while(p < l1+l2)st[i].v.pb(tmp[p++]);
		
	}
}
void update(int i, int s, int e, int pos, ll val){
	if(pos < s || pos > e)return;
	if(s==e && pos == s){
		st[i].v[0]=val;
		return;
	}
	else{
		update(2*i+1, s, (s+e)/2, pos , val);
		update(2*i+2, (s+e)/2+1, e, pos , val);
		int l1 = st[2*i+1].v.size();
		int l2 = st[2*i+2].v.size();
		//cout<<"Len: "<<s<<"  "<<e<<"  "<<l1+l2<<endl;
		vector<ll> tmp;
		int p=0,q=0;
		st[i].v.clear();
		while(p<l1 || q <l2){
			if(p==l1){tmp.pb(st[2*i+2].v[q++]);}
			else if(q==l2){tmp.pb(st[2*i+1].v[p++]);}
			else{
				ll a=st[2*i+1].v[p];
				ll b=st[2*i+2].v[q];
				if(a<=b){tmp.pb(a); p++;}
				else {tmp.pb(b); q++;}
			}
		}
		//fr(j,0,tmp.size())cout<<tmp[j]<<" ";
		//cout<<tmp.size()<<endl; 
		p = l1+l2-3;
		while(p>=0){
			ll a=tmp[p], b=tmp[p+1], c=tmp[p+2];
			if(a+b>c && b+c>a && c+a>b)break;
			if(p==0)break;
			p--;
		}
		if(p<0)p=0;
		while(p < l1+l2)st[i].v.pb(tmp[p++]);
		
	}
}
vector<ll> fn(int i, int s, int e, int l, int r){
	if(l > e || r < s){vector<ll> vv; return vv;}
	if(l <= s && e <= r){ //cout<<"X";
		return st[i].v;
	}
	else{
		vector<ll> a = fn(2*i+1, s, (s+e)/2,l,r);
		vector<ll> b = fn(2*i+2, (s+e)/2+1,e,l,r); 
		if(b.size()==0)return a;
		if(a.size()==0)return b;
		int l1 =a.size(); 
		int l2 = b.size();
		vector<ll> tmp;
		int p=0,q=0;
		while(p<l1 || q <l2){
			if(p==l1){tmp.pb(b[q++]);}
			else if(q==l2){tmp.pb(a[p++]);}
			else{
				ll a1=a[p];
				ll b1=b[q];
				if(a1<=b1){tmp.pb(a1); p++;}
				else {tmp.pb(b1); q++;}
			}
		}
		p = l1+l2-3; 
		while(p>=0){
			ll a1=tmp[p], b1=tmp[p+1], c1=tmp[p+2];
			if(a1+b1>c1 && b1+c1>a1 && c1+a1>b1)break;
			if(p==0)break;
			p--;
		}
		
		if(p<0)p=0;
		vector<ll> ret;
		while(p < l1+l2)ret.pb(tmp[p++]);
		return ret;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w+", stdout);
	#endif
	int q;
	cin>>n>>q;
	ar = (ll*)(malloc(n*sizeof(ll)));
	st = (node*)(malloc(4*n*sizeof(node)));
	fr(i,0,n)cin>>ar[i];
	build(0,0,n-1); // index, ss, se
	//return 0;
	fr(i,0,q){
		int ty;
		cin>>ty;
		if(ty==1){
			int x;
			ll y;
			cin>>x>>y;
			x--;
			update(0,0,n-1,x,y); //return 0;
		}
		else{
			int l,r;
			cin>>l>>r;
			l--; r--;
			vector<ll> tmp = fn(0,0,n-1,l,r);
			ll ans = 0;
			int p = tmp.size()-3; //cout<<st[0].v.size();
			//fr(q,0,5)cout<<st[0].v[q]<<" ";
			while(p >= 0){
				ll a1=tmp[p], b1=tmp[p+1], c1=tmp[p+2];
				if(a1+b1>c1 && b1+c1>a1 && c1+a1>b1){
					ans = a1+b1+c1;
					break;
				}
				p--;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define rre(i,r,l) for(int i=(r);i>=(l);i--)
#define re(i,l,r) for(int i=(l);i<=(r);i++)
#define Clear(a,b) memset(a,b,sizeof(a))
#define inout(x) printf("%d",(x))
#define douin(x) scanf("%lf",&x)
#define strin(x) scanf("%s",(x))
#define op operator
typedef unsigned long long ULL;
typedef const int cint;
typedef long long LL;
using namespace std;
template<typename Q>
inline char inin(Q &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x=f?-x:x;
	return ch;
}
int main()
{
	int a;
	cin>>a;
	cout<<a+1;
	return 0;
}



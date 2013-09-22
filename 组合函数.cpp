#include <iostream>
using namespace std;
int fac(int n)
{
	int t;
	if(n==1)
		t=1;
	else
		t=n*fac(n-1);
	return t;
}
int main()
{
	const int max_n=12;
	int n,m;
	cout<<"Input number m n:";
	cin>>m>>n;
	if(m>=1&&m<=max_n)
	{
		if(n<=m&&n<=max_n)
			cout<<"Combination("<<m<<","<<n<<")is;"<<fac(m)/(fac(n)*fac(m-n))<<endl;
		else
			cout<<"erro"<<endl;
	}
	system("pause");
	return 0;
}





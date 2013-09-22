#include <iostream>
using namespace std;
int power(int x,int y)
{
	int z,i;
	if(x==0&&y==0||y==0)
		z=1;
	else
		for(i=0;i<y;i++)
		{
			z=x*power(x,y-1);
		}
	return z;
}
int main()
{
	int n,m;
	cout<<"please input number n m:";
	cin>>n>>m;
	cout<<"the power of"<<n<<"^"<<m<<"is:"<<power(n,m)<<endl;
	system("pause");
	return 0;
}

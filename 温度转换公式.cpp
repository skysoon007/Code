# include<iostream>
using namespace std;
int transform(int f){
	int c;
    c=(f-32)*5/9;
    return c;
}
int main()
{
	int a;
	cout<<"please input the degree:";
	cin>>a;
	cout<<transform(a);
	system("pause");
	return 0;
}



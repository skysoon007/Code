#include<iostream>
using namespace std;
class sqstack
{
private:
 int *elem;
public:
	int top;
	int maxsize;
	    ~sqstack();
 sqstack(int size)
 {
	 maxsize=size;
     elem=new int[maxsize];
	 top=0;
 }
     int sqlength();
     void sqpush(int e);
     void sqpop(int &e);
     void display();
	 bool sqisEmpty();
	 bool sqisFull();
};
int sqstack::sqlength()
 {
    return top;
 }
void sqstack::sqpush(int e)
 { 
	 elem[top++]=e;  
 }
void sqstack::sqpop(int &e)   
{ 
	if (!sqisEmpty())
    {
		e=elem[--top];
    }
}
void sqstack::display()
{
 for(int i=top-1;i>=0;i-- )
 {
  cout<<elem[i] <<"  ";
 }
  cout<<endl;
}
bool sqstack::sqisEmpty()
{
	return top==0;
	
}
bool sqstack::sqisFull()
{
	if(top==maxsize)
	{
		return true;
	}
	if(top<maxsize)
	{
		return false;
	}
}
sqstack::~sqstack(){
   delete [] elem;
}
int main()
{
	void length(sqstack **);
	void push(sqstack**);
    void pop(sqstack **);
	sqstack **a,*p=new sqstack(10);
	a=&p;
	int action;
	do{
		cout<<"-----------�˵�-----------"<<endl;
		cout<<"1)���峤��"<<endl;
		cout<<"2)��ջ"<<endl;
		cout<<"3)��ջ"<<endl;
		cout<<"4)�˳�"<<endl;
		cout<<(*a)->maxsize;
		cin>>action;
		switch(action){
		case 1:
			length(a);
			break;
		case 2:
			push(a);
			break;
		case 3:
			pop(a);
			break;
		case 4:
			return 0;
		default:
			cout<<"�������˴���Ĳ˵��������ѡ��";
		}
	}while(1);
}

void length(sqstack **a){
    int x;
	sqstack* p;
    cout<<"����Ҫ����ջ�ĳ��ȣ�"<<endl;
    cin>>x;
	p=new sqstack(x);
	*a=p;
	
}
void push(sqstack** a){
	int i,e;
	sqstack b=**a;
	sqstack* addSpace(sqstack);
	if((*a)->sqisFull()){*a=addSpace(b);}
	for(i=1;i<=(*a)->maxsize;i++)
    {
	 cout<<"������Ҫ��ջ������:"<<endl;
     cin>>e;
     (*a)->sqpush (e);
	}
	 cout<<"��ʾ��ջ�е�Ԫ��Ϊ��"<<endl;
     (*a)->display ();
 
}
void pop(sqstack** a){
	int i,e,x;
	cout<<"��ʾ��ջ�е�Ԫ��Ϊ��"<<endl;
     (*a)->display ();
     cout<<"�����ջԪ�ظ���:";
     cin>>x;
     cout<<"��ջԪ��Ϊ��";
     for(i=1;i<=x;i++)
     {   
	 (*a)->sqpop (e);
     cout<<e<<"  ";
     }
     cout<<endl;
     cout<<"��ʾջ�е�ʣ��Ԫ��Ϊ��"<<endl;
     (*a)->display ();
}

sqstack* addSpace(sqstack a){
	int t,&te=t;
	
		sqstack b(a.maxsize*2);
		sqstack c(a.maxsize);
		for(int i = 0; i < a.maxsize ;i++){
		a.sqpop(te);
		c.sqpush(te);
		}
		for(int i = 0; i < a.maxsize ;i++){
		c.sqpop(te);
		b.sqpush(te);
		}
		//b.maxsize=2*a->maxsize;
		delete &c;
		cout<<"���Զ�����"<<endl;
		return &b;
	}

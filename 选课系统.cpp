#include <iostream>
using namespace std;

struct Student{
	char name[20];
	int IDnumber;
	int score;
}students[100];

unsigned int ID_Count = 0;//定义计数器，类似于指针，指向最后一个数组

void list();
void curricul_avariable();
void out();
void addscore();
void input(struct Student &student);
int find(char* name);

int main()
{
	int action;
	do{
		cout<<"-----------菜单-----------"<<endl;
		cout<<"1)查看学生名单"<<endl;
		cout<<"2)选课"<<endl;
		cout<<"3)退选"<<endl;
		cout<<"4)录入成绩"<<endl;
		cout<<"5)退出程序"<<endl;

		cin>>action;
		switch(action){
		case 1:
			list();
			break;
		case 2:
			curricul_avariable();
			break;
		case 3:
			out();
			break;
		case 4:
			addscore();
			break;
		case 5:
			return 0;
		default:
			cout<<"您输入了错误的菜单项，请重新选择！";
		}
	}while(1);
}

void list(){
	cout<<"-------学生姓名-------"<<endl;
	cout<<"姓名\t"<<"学号\t"<<"成绩"<<endl;
	for(int i=0;i<ID_Count;i++){
		cout<<students[i].name<<"\t"<<students[i].IDnumber<<"\t"<<students[i].score<<endl;
	}
	cout<<"-------学生-------"<<endl;
}

void curricul_avariable(){
	struct Student student;
	input(student);

	int i = find(student.name);
	if(i == ID_Count){
		strcpy(students[i].name,student.name);
		students[i].IDnumber=student.IDnumber;
		ID_Count++;
	}
}//定义选课函数

void out(){
	struct Student student;
	input(student);

	int j,k=0,i = find(student.name);
	if(i == ID_Count){
		cout<<"输入错误！"<<endl;
	}else{
		for(int j=i;j<ID_Count-1;j++)
		{
			while((students[j].name[k++]=students[j+1].name[k++])!='\0');//将数组name由后向前出入，并将后数组'\0'一并传入前数组
			students[j].IDnumber=students[j+1].IDnumber;
			students[j].score=students[j+1].score;
		}
		ID_Count--;
   

	}
}//定义退选函数

void addscore(){
	struct Student student;
	input(student);
	int i = find(student.name);
	if(i == ID_Count){
		cout<<"输入错误！"<<endl;
	}else{
		cout<<"成绩：";
		cin>>student.score;
		students[i].score = student.score;
	}

}//定义录入成绩函数

void input(struct Student &student){
	cout<<"姓名：";
	cin>>student.name;

	cout<<"学号：";
	cin>>student.IDnumber;
	
}//创建输入姓名、学号函数

int find(char*name){
	int i;
	for(i=0;i<ID_Count;i++){
		if(strcmp(students[i].name,name) == 0)//调用字符比较函数，查找是否姓名相符
		{
			break;
		}
	}
	return i;
}//创建查找（比对）姓名函数

#include <iostream>
using namespace std;

struct Student{
	char name[20];
	int IDnumber;
	int score;
}students[100];

unsigned int ID_Count = 0;//�����������������ָ�룬ָ�����һ������

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
		cout<<"-----------�˵�-----------"<<endl;
		cout<<"1)�鿴ѧ������"<<endl;
		cout<<"2)ѡ��"<<endl;
		cout<<"3)��ѡ"<<endl;
		cout<<"4)¼��ɼ�"<<endl;
		cout<<"5)�˳�����"<<endl;

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
			cout<<"�������˴���Ĳ˵��������ѡ��";
		}
	}while(1);
}

void list(){
	cout<<"-------ѧ������-------"<<endl;
	cout<<"����\t"<<"ѧ��\t"<<"�ɼ�"<<endl;
	for(int i=0;i<ID_Count;i++){
		cout<<students[i].name<<"\t"<<students[i].IDnumber<<"\t"<<students[i].score<<endl;
	}
	cout<<"-------ѧ��-------"<<endl;
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
}//����ѡ�κ���

void out(){
	struct Student student;
	input(student);

	int j,k=0,i = find(student.name);
	if(i == ID_Count){
		cout<<"�������"<<endl;
	}else{
		for(int j=i;j<ID_Count-1;j++)
		{
			while((students[j].name[k++]=students[j+1].name[k++])!='\0');//������name�ɺ���ǰ���룬����������'\0'һ������ǰ����
			students[j].IDnumber=students[j+1].IDnumber;
			students[j].score=students[j+1].score;
		}
		ID_Count--;
   

	}
}//������ѡ����

void addscore(){
	struct Student student;
	input(student);
	int i = find(student.name);
	if(i == ID_Count){
		cout<<"�������"<<endl;
	}else{
		cout<<"�ɼ���";
		cin>>student.score;
		students[i].score = student.score;
	}

}//����¼��ɼ�����

void input(struct Student &student){
	cout<<"������";
	cin>>student.name;

	cout<<"ѧ�ţ�";
	cin>>student.IDnumber;
	
}//��������������ѧ�ź���

int find(char*name){
	int i;
	for(i=0;i<ID_Count;i++){
		if(strcmp(students[i].name,name) == 0)//�����ַ��ȽϺ����������Ƿ��������
		{
			break;
		}
	}
	return i;
}//�������ң��ȶԣ���������

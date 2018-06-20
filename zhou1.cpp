
//查询、修改、添加、删除、保存、显示、输入数据
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int read(void);
int write(void);

struct worker{


char workerid[10];//取职工工号
char name[10];//取职工姓名
float gslary();//取岗位工资
float xslary();//取薪级工资
float zslary();//取职务工资
float jslary();//取绩效工资
float sum();//取应发工资
float personaltax();//取个人所得税
float realslary();//取实发工资
}worker1,*p,*q;

int write()
{	FILE*fp;
	int i;
	p=worker1;
	char a[10],b[10];
	float gs,xs,zs,js,s,pt,rs;
	if(fp=fopen("2.dat","rt"))==NULL{

	if(fp=open("2.dat","wb+"))==NULL{
	cout<<"Cannot open file strike  any  key exit!";
	getcha();
	exit(-1);
}
for(i=0;i++;p++)
cout<<"\ninput data\n";
cin>>p->workerid;
cin>>p->name;
cin>>p->gslary;
cin>>p->xslary;
cin>>p->zslary;
cin>>p->jslary;
cin>>p->sum;
cin>>p->personaltax;
cin>>p->realslary;
}

{ifstream fin("2.dat",ios::in);
if(!fin)
{cout<<"cannot open input file.\n";
}
fin.close();
return 0;
}

	int read()
{ 
		p=worker1;
fread(q,sizeof(struct worker),1,fp);
{

	cout<<"职工工号:"<<id<<endl;
	cout<<"职工姓名:"<<name<<endl;
    cout<<"岗位工资:"<<gs<<endl;
    cout<<"薪级工资:"<<xs<<endl;
    cout<<"职务工资:"<<zs<<endl;
    cout<<"绩效工资:"<<js<<endl;
    cout<<"应发工资:"<<endl;
    cout<<"个人所得税:"<<endl;
    cout<<"实发工资:"<<endl;
		/*scanf("%s",p->name);
		scanf("%f",p->gslary);
		scanf("%f",p->xslary);
		scanf("%f",p->zslary);
		scanf("%f",p->jslary);
		scanf("%f",p->sum);
		scanf("%f",p->personaltax);
		scanf("%f",p->realslary);*/



cout<<"\n\nid\name\tgs\txs\tzs\tjs\ts\tpt\trs\n";
cout<<q->workerid<<"  "<<q->name<<"   "<<q->gslary<<"   "<<q->xsllary
<<"  "<<q->zslary<<"   "<<q->jslary<<"  "<<q->sum<<"  "<<q->personaltax
<<"   "<<q->realslary<<endl;
fclose();
return 0;
}

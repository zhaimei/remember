
//��ѯ���޸ġ���ӡ�ɾ�������桢��ʾ����������
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int read(void);
int write(void);

struct worker{


char workerid[10];//ȡְ������
char name[10];//ȡְ������
float gslary();//ȡ��λ����
float xslary();//ȡн������
float zslary();//ȡְ����
float jslary();//ȡ��Ч����
float sum();//ȡӦ������
float personaltax();//ȡ��������˰
float realslary();//ȡʵ������
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

	cout<<"ְ������:"<<id<<endl;
	cout<<"ְ������:"<<name<<endl;
    cout<<"��λ����:"<<gs<<endl;
    cout<<"н������:"<<xs<<endl;
    cout<<"ְ����:"<<zs<<endl;
    cout<<"��Ч����:"<<js<<endl;
    cout<<"Ӧ������:"<<endl;
    cout<<"��������˰:"<<endl;
    cout<<"ʵ������:"<<endl;
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

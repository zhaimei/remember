



//ְ�����ʼ�¼��ְ�����š�ְ����������λ���ʡ�н�����ʡ�ְ���������Ч���ʡ�Ӧ�����ʡ���������˰��ʵ������9����Ŀ����
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
 struct worker{
	char workerID[10];//ְ������
	char name[10];//����
	float gsalary;//��λ����
	float xsalary;//н������
	float zsalary;//ְ�����
	float jsalary;//��Ч����
	float sumsalary;//Ӧ������
	float personaltax;//��������˰
	float realsalary;//ʵ������
}zggz[],worker1[2],worker2[2],*p,*q;

     void read(struct worker wor[]);//��ȡְ����������
	 void write(struct worker wor[]);//����ְ����������
	 void find(struct worker wor[]);//��ѯְ����������
	 void list(struct worker wor[]);//���ְ����������
	 void modify(struct worker wor[]);//�޸�ְ����������
	 void del(struct worker wor[]);//ɾ��ְ����������
     void add(struct worker wor[]);//���ְ����������
	 void grsds(struct worker wor[]);//�����������˰
	 void main()//������
	 {

	 }

void read()
{
	FILE *fp;
	int i=1;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","rt"))==NULL){      //�ļ���ʧ��
		cout<<"Cannot open file strike any key exit!\n";
	    exit(-1);
	}
	fseek(fp,i*sizeof(struct worker),0);//�ƶ��ļ�λ��ָ��
	fread(p,sizeof(struct worker),1,fp);
		cout<<"\n\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\n";
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;//������һ�����˵���Ϣ
		cout<<p->workerID<<"\t"<<p->name<<"\t\t"<<p->gsalary<<
		         "\t\t"<<p->xsalary<<"\t\t"<<p->zsalary<<"\t\t"<<p->jsalary<<endl;//�����ڶ������˵���Ϣ
	fclose(fp);

}
void write()
{
	FILE *fp;
	//float gs,xs,zs,js;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","wt+"))==NULL){        //�ļ���ʧ��
		cout<<"Cannot open file strike any key exit!\n";
		exit(-1);
	}
	for(int i=0;i<2;i++,p++,n++){                       //�ļ��򿪳ɹ�
		cout<<"������������Ϣ�����ţ������ȵȣ���"<<i+1<<"\n";
		cin>>p->workerID; //���빤��
		cin>>p->name;    // ��������
		cin>>p->gsalary; //�����λ����
		cin>>p->xsalary;//����н������
		cin>>p->zsalary;//����ְ�����
		cin>>p->jsalary;//���뼨Ч����
	}
	p=worker1;
	fwrite(p,sizeof(struct worker),2,fp);//д��2�Σ�ÿ�γ�����worker�ֽ���
	rewind(fp);
	fread(q,sizeof(struct worker),2,fp);
/*	cout<<"\n\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\n";
	for(i=0;i<2;i++,q++)
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;*/
	fclose(fp);
}
void find(struct worker wor[]) //��ѯְ����������
{
	int i=0,num;
	int x=0;
	char str[15];
	printf("������Ҫ�ҵı�Ż�����:");
	scanf('%s',&id);
	for(i=0;i<2;i++)
	{
		if(wor[i].id=num)
	//if(!strcmp(str,a[i].id)||!strcmp(str,a[i].name))
	{
			wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
			printf("\nְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
system("pause");
	}
	}
}
	

int del(zddz*a)//ɾ��ְ����������
{ 
int i=0;
int x=0;
char str[15];
printf("������Ҫɾ���ı�Ż�����:");
scanf('%s',str);
printf(" ɾ���ɹ� ");
for(i=0;i<2;i++)
if(!strcmp(str,a[i].id)||!strcmp(str,a[i].name))
{
	while(i<2)
	{
		strcpy(a[i].id,a[i+1].id);
		strcpy(a[i].name,a[i+1].name);
		a[i].gslary=a[i+1].gslary;
		a[i].xslary=a[i+1].xslary;
		a[i].zslary=a[i+1].zslary;
		a[i].jslary=a[i+1].jslary;
		a[i].sumslary=a[i+1].sumslary;
		a[i].personaltax=a[i+1].personaltax;
		a[i].realslary=a[i+1].realslary;
		i++;

	}
	x++;
}
if(x==0)
{
	printf("����ı�Ż����������ڣ�����������:");
}
return 2-x;
}

void modify()//�޸�ְ����������
{
	int i;
	int x=0;
	char str[15];
	printf("����Ҫ�޸ĵĹ���:");
	scanf('%s',str);
	for(i=0;i<2;i++)
 	if(!strcmp(worker,a[i].id)||!strcmp(worker,a[i].name))
	{
		printf("�����޸ĺ�ְ��������:");
		scanf('%s',a[i].name);
		printf("�����޸ĺ�ְ���ĸ�λ����:");
		scanf('%f',a[i].gslary);
		printf("�����޸ĺ�ְ����н������:");
		scanf('%s',a[i].xslary);
		printf("�����޸ĺ�ְ����ְ�����:");
		scanf('%s',a[i].zslary);
		printf("�����޸ĺ�ְ���ļ�Ч����:");
		scanf('%s',a[i].jslary);
        printf("�����޸ĺ�ְ���ļ�Ч����:");
		scanf('%s',a[i].jslary);
		printf("�����޸ĺ�ְ����Ӧ������:");
		scanf('%s',a[i].sumslary);
		printf("�����޸ĺ�ְ���ĸ�������˰:");
		scanf('%s',a[i].personaltax);
		printf("�����޸ĺ�ְ����ʵ������:");
		scanf('%s',a[i].realslary);
		printf("   �޸ĳɹ�    ");
		a[i].sumslary=a[i].gslary+a[i].xslary+a[i].zslary+a[i].jslary;
		x++;
	}
	if(x==0)
	{
		printf("δ�ҵ�Ҫ�޸ĵı��");
	}
}

int add()//����ְ����������
{
	int i;
	int x=0;
	char str[15];
	printf("����Ҫ���ӵĹ���:");
	scanf('%s',str);
	printf("����һ���µļ�¼��Ϣ:");
	for(i=0;i<2;i++)
	if(strcmp(str,a[i].id)==0)
	{
		x=i;
		for(i=2;i<x+1;i--)
		strcpy(a[i].id,a[i-1].id);
		strcpy(a[i].name,a[i-1].name);
		a[i].gslary=a[i-1].gslary;
		a[i].xslary=a[i-1].xslary;
		a[i].zslary=a[i-1].zslary;
		a[i].jslary=a[i-1].jslary;
		a[i].sumslary=a[i-1].sumslary;
	}
}
x++;
        printf("����ְ������:");
		scanf('%s',a[i].id);
        printf("����ְ��������:");
		scanf('%s',a[i].name);
		printf("����ְ���ĸ�λ����:");
		scanf('%f',a[i].gslary);
		printf("����ְ����н������:");
		scanf('%s',a[i].xslary);
		printf("����ְ����ְ�����:");
		scanf('%s',a[i].zslary);
		printf("����ְ���ļ�Ч����:");
		scanf('%s',a[i].jslary);
        printf("����ְ���ļ�Ч����:");
		scanf('%s',a[i].jslary);
		printf("����ְ����Ӧ������:");
		scanf('%s',a[i].sumslary);
		printf("����ְ���ĸ�������˰:");
		scanf('%s',a[i].personaltax);
		printf("����ְ����ʵ������:");
		scanf('%s',a[i].realslary);
		a[i].sumslary=a[i].gslary+a[i].xslary+a[i].zslary+a[i].jslary;
		return x;
		}

int grsds()
{
	float ftax;//ȫ��Ӧ��˰���ö�
	float mtax;//ȫ��Ӧ��˰
	if(ftax<=500)
		mtax=ftax*5%;
	else if(ftax>500&&ftax<=2000);
	mtax=ftax*10%;
	else(ftax>2000&&ftax<5000);
	mtax=ftax*15%;
	else(ftax>5000&&ftax<20000);
	mtax=ftax*20%;
	else(ftax>20000&&ftax<40000);
	mtax=ftax*25%;
	else(ftax>40000&&ftax<60000);
	mtax=ftax*30%;
	else(ftax>60000&&ftax<80000);
	mtax=ftax*35%;
	else(ftax>80000&&ftax<100000);
	mtax=ftax*40%;
	else(ftax>100000);
	mtax=ftax*45%;
return 0;
}

int main()
{
	write();
	read();
	find();
	del();
	grsds();
	add();
	modify();
	return 0;
}

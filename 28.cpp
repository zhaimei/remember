
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
}*pp;
 //zggz[],worker1[2],worker2[2],*p,*q;

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
	if((fp=fopen("gx.dat","rt"))==NULL){      //�ļ���ʧ��
		cout<<"Cannot open file strike any key exit!\n";
	    exit(-1);
	}
	fseek(fp,i*sizeof(struct worker),0);//�ƶ��ļ�λ��ָ��
	fread(pp,sizeof(struct worker),1,fp);
		cout<<"\n\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\n";
		cout<<pp->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;//������һ�����˵���Ϣ
		cout<<pp->workerID<<"\t"<<p->name<<"\t\t"<<p->gsalary<<
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
printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,
	   wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
system("pause");
	}
	}
}
	

int del(struct worker wor[])//ɾ��ְ����������
{ 
	pp=wor;
	struct worker temp;
	int delid;
	char ask;
	int i,j;
//int i=0;
//int x=0;
//char str[15];
    if((fp=fopen("deldata.sys","wb+"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(1);
	}

	fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
system("cls");

printf(" ������Ҫɾ����Ա������:");
fflush(stdin);
scanf("%d",&delid);
printf("\n\t�Ƿ�ȷ��ɾ��ְ��%d����Ϣ(y/n)",delid);
fflush(stdin);
ask = getchar();
if(ask != 'n')
{
	for(i=0;i<2;i++)
	{
		if(wor[i].id==delid)
			break;
}
	if(i>2)
printf("\n\tû����Ҫɾ����ְ��!\n");
else
{
for(j=i;j<2;j++)
{
temp = wor[j];
wor[j] = wor[j+1];
wor[j+1] = temp;
}
2--; //ɾ��һ��ְ����Ϣ��ְ��������Ӧ-1
system("cls");
printf("\n\nɾ���ɹ�!\n");
}
wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,
		wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
getch();
}
}

void modify()//�޸�ְ����������
{
	pp=wor;
	int num,i=0;//numΪ�����û������ְ�����
    if((fp=fopen("modify.sys","wb+"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
        getch();
		exit(1);
	}
	fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
    printf(" ������Ҫ�޸ĵ�Ա������:");
    scanf("%d",&num);
   Sleep(500);
   printf("\n\t�����������.");
for(i=0;i<2;i++)
{
Sleep(250);
printf(".");
}
for(i=0;i<2;i++)
{
if(wor[i].id==num)
	{
	    printf("�����޸ĺ�ְ���Ĺ���:");
		fflush(stdin);
		scanf('%s',&wor[i].id);
		printf("�����޸ĺ�ְ��������:");
		fflush(stdin);
		scanf('%s',&wor[i].name);
		printf("�����޸ĺ�ְ���ĸ�λ����:");
		fflush(stdin);
		scanf('%f',&wor[i].gslary);
		printf("�����޸ĺ�ְ����н������:");
		fflush(stdin);
		scanf('%s',&wor[i].xslary);
		printf("�����޸ĺ�ְ����ְ�����:");
		fflush(stdin);
		scanf('%s',&wor[i].zslary);
		printf("�����޸ĺ�ְ���ļ�Ч����:");
		fflush(stdin);
		scanf('%s',&wor[i].jslary);
        printf("�����޸ĺ�ְ���ļ�Ч����:");
		fflush(stdin);
		scanf('%s',&wor[i].jslary);
		printf("�����޸ĺ�ְ����Ӧ������:");
		fflush(stdin);
		scanf('%s',&wor[i].sumslary);
		printf("�����޸ĺ�ְ���ĸ�������˰:");
		fflush(stdin);
		scanf('%s',&wor[i].personaltax);
		printf("�����޸ĺ�ְ����ʵ������:");
		fflush(stdin);
		scanf('%s',&wor[i].realslary);
		printf("   �޸ĳɹ�    ");
		wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,wor[i].xslary,
		wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
}
}
	}

void add()//����ְ����������
{
	int flag=1;
	pp=wor;
	int i,num;
	if((fp=fopen("insertdata.sys","wb+"))==NULL)
{
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
	fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
    printf(" ������Ҫ��ӵ�Ա������:");
    scanf("%d",&num);
	for(i=0;i<2;i++)
	{
		if(wor[i].id==num) //�ж�ְ�������Ϣ�����?
{
printf("ְ��������Ϣ�Ѿ�����!\n");
flag=0;
getch();
break;
}
}
if (flag!=0)
{
	2++;
	printf("�����޸ĺ�ְ���Ĺ���:");
	fflush(stdin);
	scanf('%s',&wor[2-1].id);
	printf("�����޸ĺ�ְ��������:");
	fflush(stdin);
	scanf('%s',&wor[2-1].name);
	printf("�����޸ĺ�ְ���ĸ�λ����:");
	fflush(stdin);
	scanf('%f',&wor[2-1].gslary);
	printf("�����޸ĺ�ְ����н������:");
	fflush(stdin);
	scanf('%s',&wor[2-1].xslary);
	printf("�����޸ĺ�ְ����ְ�����:");
	fflush(stdin);
	scanf('%s',&wor[2-1].zslary);
	printf("�����޸ĺ�ְ���ļ�Ч����:");
	fflush(stdin);
	scanf('%s',&wor[2-1].jslary);
    printf("�����޸ĺ�ְ���ļ�Ч����:");
	fflush(stdin);
	scanf('%s',&wor[2-1].jslary);
	printf("�����޸ĺ�ְ����Ӧ������:");
	fflush(stdin);
	scanf('%s',&wor[2-1].sumslary);
	printf("�����޸ĺ�ְ���ĸ�������˰:");
	fflush(stdin);
	scanf('%s',&wor[2-1].personaltax);
	printf("�����޸ĺ�ְ����ʵ������:");
	fflush(stdin);
	scanf('%s',&wor[2-1].realslary);
	wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,
		wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
printf("   ���ӳɹ�    ");
getch();
}
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
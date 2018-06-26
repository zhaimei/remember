



//职工工资记录由职工工号、职工姓名、岗位工资、薪级工资、职务津贴、绩效工资、应发工资、个人所得税和实发工资9个项目构成
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
 struct worker{
	char workerID[10];//职工工号
	char name[10];//姓名
	float gsalary;//岗位工资
	float xsalary;//薪级工资
	float zsalary;//职务津贴
	float jsalary;//绩效工资
	float sumsalary;//应发工资
	float personaltax;//个人所得税
	float realsalary;//实发工资
}zggz[],worker1[2],worker2[2],*p,*q;

     void read(struct worker wor[]);//读取职工工资数据
	 void write(struct worker wor[]);//保存职工工资数据
	 void find(struct worker wor[]);//查询职工工资数据
	 void list(struct worker wor[]);//浏览职工工资数据
	 void modify(struct worker wor[]);//修改职工工资数据
	 void del(struct worker wor[]);//删除职工工资数据
     void add(struct worker wor[]);//添加职工工资数据
	 void grsds(struct worker wor[]);//计算个人所得税
	 void main()//主函数
	 {

	 }

void read()
{
	FILE *fp;
	int i=1;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","rt"))==NULL){      //文件打开失败
		cout<<"Cannot open file strike any key exit!\n";
	    exit(-1);
	}
	fseek(fp,i*sizeof(struct worker),0);//移动文件位置指针
	fread(p,sizeof(struct worker),1,fp);
		cout<<"\n\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\n";
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;//读出第一个工人的信息
		cout<<p->workerID<<"\t"<<p->name<<"\t\t"<<p->gsalary<<
		         "\t\t"<<p->xsalary<<"\t\t"<<p->zsalary<<"\t\t"<<p->jsalary<<endl;//读出第二个工人的信息
	fclose(fp);

}
void write()
{
	FILE *fp;
	//float gs,xs,zs,js;
	p=worker1;
	q=worker2;
	if((fp=fopen("gx.dat","wt+"))==NULL){        //文件打开失败
		cout<<"Cannot open file strike any key exit!\n";
		exit(-1);
	}
	for(int i=0;i<2;i++,p++,n++){                       //文件打开成功
		cout<<"输入两个人信息（工号，姓名等等）："<<i+1<<"\n";
		cin>>p->workerID; //输入工号
		cin>>p->name;    // 输入姓名
		cin>>p->gsalary; //输入岗位工资
		cin>>p->xsalary;//输入薪级工资
		cin>>p->zsalary;//输入职务津贴
		cin>>p->jsalary;//输入绩效工资
	}
	p=worker1;
	fwrite(p,sizeof(struct worker),2,fp);//写入2次，每次长度是worker字节数
	rewind(fp);
	fread(q,sizeof(struct worker),2,fp);
/*	cout<<"\n\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\n";
	for(i=0;i<2;i++,q++)
		cout<<q->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;*/
	fclose(fp);
}
void find(struct worker wor[]) //查询职工工资数据
{
	int i=0,num;
	int x=0;
	char str[15];
	printf("输入你要找的编号或姓名:");
	scanf('%s',&id);
	for(i=0;i<2;i++)
	{
		if(wor[i].id=num)
	//if(!strcmp(str,a[i].id)||!strcmp(str,a[i].name))
	{
			wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
			printf("\n职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
system("pause");
	}
	}
}
	

int del(zddz*a)//删除职工工资数据
{ 
int i=0;
int x=0;
char str[15];
printf("输入想要删除的编号或姓名:");
scanf('%s',str);
printf(" 删除成功 ");
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
	printf("输入的编号或姓名不存在，请重新输入:");
}
return 2-x;
}

void modify()//修改职工工资数据
{
	int i;
	int x=0;
	char str[15];
	printf("输入要修改的工号:");
	scanf('%s',str);
	for(i=0;i<2;i++)
 	if(!strcmp(worker,a[i].id)||!strcmp(worker,a[i].name))
	{
		printf("输入修改后职工的姓名:");
		scanf('%s',a[i].name);
		printf("输入修改后职工的岗位工资:");
		scanf('%f',a[i].gslary);
		printf("输入修改后职工的薪级工资:");
		scanf('%s',a[i].xslary);
		printf("输入修改后职工的职务津贴:");
		scanf('%s',a[i].zslary);
		printf("输入修改后职工的绩效工资:");
		scanf('%s',a[i].jslary);
        printf("输入修改后职工的绩效工资:");
		scanf('%s',a[i].jslary);
		printf("输入修改后职工的应发工资:");
		scanf('%s',a[i].sumslary);
		printf("输入修改后职工的个人所得税:");
		scanf('%s',a[i].personaltax);
		printf("输入修改后职工的实发工资:");
		scanf('%s',a[i].realslary);
		printf("   修改成功    ");
		a[i].sumslary=a[i].gslary+a[i].xslary+a[i].zslary+a[i].jslary;
		x++;
	}
	if(x==0)
	{
		printf("未找到要修改的编号");
	}
}

int add()//增加职工工资数据
{
	int i;
	int x=0;
	char str[15];
	printf("输入要增加的工号:");
	scanf('%s',str);
	printf("输入一条新的记录信息:");
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
        printf("输入职工工号:");
		scanf('%s',a[i].id);
        printf("输入职工的姓名:");
		scanf('%s',a[i].name);
		printf("输入职工的岗位工资:");
		scanf('%f',a[i].gslary);
		printf("输入职工的薪级工资:");
		scanf('%s',a[i].xslary);
		printf("输入职工的职务津贴:");
		scanf('%s',a[i].zslary);
		printf("输入职工的绩效工资:");
		scanf('%s',a[i].jslary);
        printf("输入职工的绩效工资:");
		scanf('%s',a[i].jslary);
		printf("输入职工的应发工资:");
		scanf('%s',a[i].sumslary);
		printf("输入职工的个人所得税:");
		scanf('%s',a[i].personaltax);
		printf("输入职工的实发工资:");
		scanf('%s',a[i].realslary);
		a[i].sumslary=a[i].gslary+a[i].xslary+a[i].zslary+a[i].jslary;
		return x;
		}

int grsds()
{
	float ftax;//全月应纳税所得额
	float mtax;//全月应纳税
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

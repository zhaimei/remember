
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
}*pp;
 //zggz[],worker1[2],worker2[2],*p,*q;

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
	if((fp=fopen("gx.dat","rt"))==NULL){      //文件打开失败
		cout<<"Cannot open file strike any key exit!\n";
	    exit(-1);
	}
	fseek(fp,i*sizeof(struct worker),0);//移动文件位置指针
	fread(pp,sizeof(struct worker),1,fp);
		cout<<"\n\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\n";
		cout<<pp->workerID<<"\t"<<q->name<<"\t\t"<<q->gsalary<<
		         "\t\t"<<q->xsalary<<"\t\t"<<q->zsalary<<"\t\t"<<q->jsalary<<endl;//读出第一个工人的信息
		cout<<pp->workerID<<"\t"<<p->name<<"\t\t"<<p->gsalary<<
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
printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,
	   wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
system("pause");
	}
	}
}
	

int del(struct worker wor[])//删除职工工资数据
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

	fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
system("cls");

printf(" 输入想要删除的员工工号:");
fflush(stdin);
scanf("%d",&delid);
printf("\n\t是否确认删除职工%d的信息(y/n)",delid);
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
printf("\n\t没有你要删除的职工!\n");
else
{
for(j=i;j<2;j++)
{
temp = wor[j];
wor[j] = wor[j+1];
wor[j+1] = temp;
}
2--; //删掉一个职工信息后职工总数相应-1
system("cls");
printf("\n\n删除成功!\n");
}
wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,
		wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
getch();
}
}

void modify()//修改职工工资数据
{
	pp=wor;
	int num,i=0;//num为接收用户输入的职工编号
    if((fp=fopen("modify.sys","wb+"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
        getch();
		exit(1);
	}
	fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
    printf(" 输入想要修改的员工工号:");
    scanf("%d",&num);
   Sleep(500);
   printf("\n\t查找相关数据.");
for(i=0;i<2;i++)
{
Sleep(250);
printf(".");
}
for(i=0;i<2;i++)
{
if(wor[i].id==num)
	{
	    printf("输入修改后职工的工号:");
		fflush(stdin);
		scanf('%s',&wor[i].id);
		printf("输入修改后职工的姓名:");
		fflush(stdin);
		scanf('%s',&wor[i].name);
		printf("输入修改后职工的岗位工资:");
		fflush(stdin);
		scanf('%f',&wor[i].gslary);
		printf("输入修改后职工的薪级工资:");
		fflush(stdin);
		scanf('%s',&wor[i].xslary);
		printf("输入修改后职工的职务津贴:");
		fflush(stdin);
		scanf('%s',&wor[i].zslary);
		printf("输入修改后职工的绩效工资:");
		fflush(stdin);
		scanf('%s',&wor[i].jslary);
        printf("输入修改后职工的绩效工资:");
		fflush(stdin);
		scanf('%s',&wor[i].jslary);
		printf("输入修改后职工的应发工资:");
		fflush(stdin);
		scanf('%s',&wor[i].sumslary);
		printf("输入修改后职工的个人所得税:");
		fflush(stdin);
		scanf('%s',&wor[i].personaltax);
		printf("输入修改后职工的实发工资:");
		fflush(stdin);
		scanf('%s',&wor[i].realslary);
		printf("   修改成功    ");
		wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,wor[i].xslary,
		wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
}
}
	}

void add()//增加职工工资数据
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
	fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
    printf(" 输入想要添加的员工工号:");
    scanf("%d",&num);
	for(i=0;i<2;i++)
	{
		if(wor[i].id==num) //判断职工编号信息否存在?
{
printf("职工工号信息已经存在!\n");
flag=0;
getch();
break;
}
}
if (flag!=0)
{
	2++;
	printf("输入修改后职工的工号:");
	fflush(stdin);
	scanf('%s',&wor[2-1].id);
	printf("输入修改后职工的姓名:");
	fflush(stdin);
	scanf('%s',&wor[2-1].name);
	printf("输入修改后职工的岗位工资:");
	fflush(stdin);
	scanf('%f',&wor[2-1].gslary);
	printf("输入修改后职工的薪级工资:");
	fflush(stdin);
	scanf('%s',&wor[2-1].xslary);
	printf("输入修改后职工的职务津贴:");
	fflush(stdin);
	scanf('%s',&wor[2-1].zslary);
	printf("输入修改后职工的绩效工资:");
	fflush(stdin);
	scanf('%s',&wor[2-1].jslary);
    printf("输入修改后职工的绩效工资:");
	fflush(stdin);
	scanf('%s',&wor[2-1].jslary);
	printf("输入修改后职工的应发工资:");
	fflush(stdin);
	scanf('%s',&wor[2-1].sumslary);
	printf("输入修改后职工的个人所得税:");
	fflush(stdin);
	scanf('%s',&wor[2-1].personaltax);
	printf("输入修改后职工的实发工资:");
	fflush(stdin);
	scanf('%s',&wor[2-1].realslary);
	wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gslary,
		wor[i].xslary,wor[i].zslary,wor[i].jslary,wor[i].sumslary,wor[i].personaltax,wor[i].realslary);
printf("   增加成功    ");
getch();
}
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
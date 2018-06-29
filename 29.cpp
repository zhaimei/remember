#include <stdio.h> //标准输入输出
#include <stdlib.h> //处理杂乱
#include <windows.h> //Sleep()
#include <string.h> //字符串操作
#include <conio.h> //系统输入输出   
#include <time.h> //时间相关
/**********************下面是对用到的全局常量声明*************************/
#define NAME 10 //职工职工姓名长度
//#define PASSWORD "123" //系统登陆密码
int shuru=0; //全局变量标记当前录入职工个数
FILE *fp; //声明一个文件指针
/**************************结构体定义************************************/
struct worker{ //职工工资的结构体
char name[NAME]; //职工职工姓名
char num; //职工编号
float gsalary;//岗位工资
float xsalary;//薪级工资
float zsalary;//职务津贴
float jsalary;//绩效工资
float sumsalary;//应发工资
float personaltax;//个人所得税
float realsalary;//实发工资
}*pp; //声明一个结构指针
/**********************下面是对用到的函数声明*****************************/
//void Password(); //密码验证函数

void read(struct worker wor[]); //录入读取职工工资数据函数
void write(struct worker wor[]); //保存职工工资数据函数
void find(struct worker wor[]); //查询职工工资数据函数
void list(struct worker wor[]); //浏览职工工资数据函数
void modify(struct worker wor[]); //修改职工工资数据函数
void del(struct worker wor[]); //删除职工工资数据函数
void Insertper(struct worker wor[]); //增加职工工资数据函数
void grsds(struct worker wor[],int n);//计算个人所得税函数
void Save(struct worker wor[]); //保存信息函数
void Menu();
//void Help();
//**************************程序主体**************************************
void main() //程序入口
{
system("color black"); //设置当前窗口的背景色和前景色
//Password(); //调用密码验函数
//Help(); //调用系统信息函数
Menu(); //调用菜单函数
}
void read(struct worker wor[]) //读取职工工资函数原形
{
pp=wor; //指针指向结构
system("cls"); //清屏
int i;
printf("请问你要输入几个职工的信息:");
scanf("%d",&shuru);
if((fp=fopen("read","wb+"))==NULL) //当前目录下是否存在read文件
{ //"wb+":读写打开或建立一个二进制文件,允许读和写
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
for(i=0;i<shuru;i++)
{
printf("输入职工编号:"); //输入职工编号
fflush(stdin);
scanf("%d",&wor[i].num);
printf("输入职工姓名:"); //输入职工姓名
fflush(stdin);
gets(wor[i].name);
//printf("输入职工的工资信息\n");
//printf("------------------------------\n");
printf("\n岗位工资: "); //岗位工资
fflush(stdin);
scanf("%f",&wor[i].gsalary);
printf("\n薪级工资: "); //薪级工资
fflush(stdin);
scanf("%f",&wor[i].xsalary);
printf("\n职务津贴: "); //职务津贴
fflush(stdin);
scanf("%f",&wor[i].zsalary);
printf("\n绩效工资: "); //绩效工资
fflush(stdin);
scanf("%f",&wor[i].jsalary);
printf("\n应发工资: "); //应发工资
fflush(stdin);
scanf("%f",&wor[i].sumsalary);
printf("\n个人所得税: "); //个人所得税
fflush(stdin);
scanf("%f",&wor[i].personaltax);
printf("\n实发工资: "); //实发工资
fflush(stdin);
scanf("%f",&wor[i].realsalary);

printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
	   wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);}
}
void modify(struct worker wor[])//修改职工工资数据
{
pp=wor;
int id,i=0; //id为接收用户输入的职工编号
if((fp=fopen("modify.sys","wb+"))==NULL)
{
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
    printf(" 输入想要修改的员工工号:");
scanf("%d",&id);
Sleep(500);
 //如果找到了就执行下面语句 ,找不到直接回主界面
{printf("\n\t查找相关数据.");
for(i=0;i<=15;i++)
{
Sleep(250);
printf(".");
}
for(i=0;i<shuru;i++)
{
if(wor[i].num==id)
 printf("输入修改后职工的工号:");
		fflush(stdin);
		scanf('%s',&wor[i].num);
		printf("输入修改后职工的姓名:");
		fflush(stdin);
		scanf('%s',&wor[i].name);
		printf("输入修改后职工的岗位工资:");
		fflush(stdin);
		scanf('%f',&wor[i].gsalary);
		printf("输入修改后职工的薪级工资:");
		fflush(stdin);
		scanf('%s',&wor[i].xsalary);
		printf("输入修改后职工的职务津贴:");
		fflush(stdin);
		scanf('%s',&wor[i].zsalary);
		printf("输入修改后职工的绩效工资:");
		fflush(stdin);
		scanf('%f',&wor[i].jsalary);
        printf("输入修改后职工的绩效工资:");
		fflush(stdin);
		scanf('%f',&wor[i].jsalary);
		printf("输入修改后职工的应发工资:");
		fflush(stdin);
		scanf('%f',&wor[i].sumsalary);
		printf("输入修改后职工的个人所得税:");
		fflush(stdin);
		scanf('%f',&wor[i].personaltax);
		printf("输入修改后职工的实发工资:");
		fflush(stdin);
		scanf('%f',&wor[i].realsalary);
		printf("   修改成功    ");
		wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gsalary,wor[i].xsalary,
		wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);


/*
printf("\n输入新职工编号:"); //输入职工编号
fflush(stdin);
scanf("%d",&wor[i].num);
printf("\n输入新职工姓名:"); //输入职工姓名
fflush(stdin);
gets(per[i].name);
printf("输入职工的工资信息\n");
printf("------------------------------\n");
printf("\n基本工资: ");
scanf("%f",&per[i].paid);
fflush(stdin);
printf("\n扣款: ");
scanf("%f",&per[i].discount);
fflush(stdin);
printf("\n 奖金: ");
scanf("%f",&per[i].extra);
printf("------------------------------\n");
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
fprintf(fp," %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\t\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].realpaid,per[i].sum);
*/
}
}
}
void find(struct worker wor[]) //查询职工工资信息
{
int i=0,j=0,id; //循环变量和用于接收职工编号
printf("请输入你要查询的职工编号:");
scanf("%d",&id);
for(i=0;i<shuru;i++)
{
if (wor[i].num==id) //如果找到你查询的数据就执行下面语句
{ //如果找不到。直接回程序主界%
	wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
	printf("\n职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
    printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
	   wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);
    system("pause");



/*
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
printf("\n职工编号 职工姓名 基本工资 扣款 奖金 应发工资 税金 实发工资 总工资 \n");
printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].gotpaid,per[i].fare,per[i].realpaid,per[i].sum);
system("pause");*/
}
}
}
void add(struct worker  wor[]) //添加职工工资信息
{
int flag=1;
pp=wor;
int i,id;
if((fp=fopen("insertdata.sys","wb+"))==NULL)
{
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
	fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
    printf(" 输入想要添加的员工工号:");
    scanf("%d",&id);
for(i=0;i<shuru;i++)
{
if(wor[i].num==id) //判断职工编号信息否存在?
{
printf("职工编号信息已经存在!\n");
flag=0;
getch();
break;
}
}
if (flag!=0)
{
    shuru++; //插入一个,原来的总数增加1
    printf("输入修改后职工的工号:");
	scanf('%s',&wor[shuru-1].num);//如果不存在..那么就把插入的信息放到结构数组最后
	printf("输入修改后职工的姓名:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].name);
	printf("输入修改后职工的岗位工资:");
	fflush(stdin);
	scanf('%f',&wor[shuru-1].gsalary);
	printf("输入修改后职工的薪级工资:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].xsalary);
	printf("输入修改后职工的职务津贴:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].zsalary);
	printf("输入修改后职工的绩效工资:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].jsalary);
	printf("输入修改后职工的应发工资:");
	fflush(stdin);
	//scanf('%s',&wor[shuru-1].sumsalary);
	fputs(&wor[i].sumsalary,fp);
	printf("输入修改后职工的个人所得税:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].personaltax);
	printf("输入修改后职工的实发工资:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].realsalary);
	wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
		wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);




/*
printf("请确认输入要插入职工编号:");
scanf("%d",&per[shuru-1].num); //如果不存在..那么就把插入的信息放到结构数组最后
printf("输入职工姓名:");
fflush(stdin);
gets(per[shuru-1].name);
printf("输入职工的工资信息\n");
printf("------------------------------\n");
printf("\n基本工资: ");
fflush(stdin);
scanf("%f",&per[shuru-1].paid);
printf("\n扣款: ");
fflush(stdin);
scanf("%f",&per[shuru-1].discount);
printf("\n奖金: "); //奖金
fflush(stdin);
printf("\n税金: "); //税金
fflush(stdin);
printf("------------------------------\n");
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
fprintf(fp," %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\t\n",per[shuru-1].num,per[shuru-1].name,per[shuru-1].paid,per[shuru-1].discount,per[shuru-1].extra,per[i].realpaid,per[shuru-1].sum);
*/
Sleep(500);
printf("添加数据成功!\n");
getch();
}                                                                                                                                      
}
void Listper(struct worker wor[]) //浏览所有职工工
{ 
int i=0;
for(i=0;i<shuru;i++)
{ wor[i].sumsalary=wor[i].gsalary+wor[i].xsalary+wor[i].xsalary+wor[i].zsalary;
/*if (per[i].gotpaid<2000)
per[i].fare=0;
else if (per[i].gotpaid>=2000&&per[i].gotpaid<4999)
per[i].fare=per[i].gotpaid*0.05;
else if (per[i].gotpaid>=5000&&per[i].gotpaid<10000)
per[i].fare=per[i].gotpaid*0.1;
else if (per[i].gotpaid>=10000&&per[i].gotpaid<99999)
per[i].fare=per[i].gotpaid*0.25;
else if (per[i].gotpaid>=100000)
per[i].fare=per[i].gotpaid*0.3;
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
}
printf("\n职工编号 职工姓名 基本工资 扣款 奖金 应发工资 税金 实发工资 总工资\n");
for(i=0;i<shuru;i++)
{
printf("\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t %4.1f\t %5.1f\t",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].gotpaid,per[i].fare,per[i].realpaid, per[i].sum);
}
getch();
}*/
void del(struct worker wor[]) //删除职工信息函数
{
pp=wor;
struct worker temp;
int delnum;
char ask;
int i,j;
if((fp=fopen("Deldata.sys","wb+"))==NULL)
{
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
system("cls");
printf("\n\n\t输入你要删除的职工的职工工号:");
fflush(stdin);
scanf("%d",&delnum);
printf("\n\t是否确认删除职工%d的信息(y/n)",delnum);
fflush(stdin);
ask = getchar();
if(ask != 'n')
{
for(i=0;i<shuru;i++)
{
if(wor[i].num == delnum)
break;
}
if(i > shuru)
printf("\n\t没有你要删除的职工!\n");
else
{
for(j=i;j<shuru;j++)
{
temp = wor[j];
wor[j] = wor[j+1];
wor[j+1] = temp;
}
shuru--; //删掉一个职工信息后职工总数相应-1
system("cls");
printf("\n\n删除成功!\n");
}
wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
		wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);
getch();
}
}

/*
void Sortper(struct person per[]) //排序函数
{
int i,j,chose; //i,j为循环变量 chose为接收用户输入的排序方式
struct person temp;
printf("排序前的数据为\n");
printf("\n职工编号 职工姓名 基本工资 扣款 奖金 应发工资 税金 实发工资 总工资\n");
for(i=0;i<shuru;i++)
{
printf("\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\t\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].realpaid,per[i].sum);
}
printf("\n1.按职工编号排序\t2.按总工资(高→低)排序\n");
printf("\n请您正确选择:");
fflush(stdin);
scanf("%d",&chose);
if(chose==1)
{
for(i=0;i<shuru-1;i++)
{
for(j=i+1;j<shuru;j++)
{
if(per[i].num>per[j].num)
{
temp=per[i];
per[i]=per[j];
per[j]=temp;
}
}
}
printf("\n职工编号 职工姓名 基本工资 扣款 奖金 应发工资 税金 实发工资 总工资\n");
for(i=0;i<shuru;i++)
{
printf("\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\t\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].realpaid,per[i].sum);
}
system("pause");
}
else if(chose==2)
{
for(i=0;i<shuru-1;i++)
{
for(j=i+1;j<shuru;j++)
{
if(per[i].sum<per[j].sum)
{
temp=per[i];
per[i]=per[j];
per[j]=temp;
}
}
}
printf("\n职工编号 职工姓名 基本工资 扣款 奖金 应发工资 税金 实发工资 总工资\n");
for(i=0;i<shuru;i++)
{
printf("\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].realpaid,per[i].sum);
}
system("pause");
}
}*/
/*void Password() //密码验证函数
{
char *pass=NULL; //初始化指针
int i,count;
time_t start,end; //时间函数
pass=(char *)malloc(255*sizeof(char)); //分配内存
while(1)
{
count=0;
printf("\n\n\n\n\n\t\t\t职 工 工 资 管 理 系 统 \n");
printf("\n\t\t UserName:李海蛟 \n");
printf("\n\t\t PassWord:");
while((count>=0)&&(pass[count++]=getch())!=13) //密码输入
{
if(pass[0]=='\b')
{
count=0;
continue;
}
else if(pass[count-1]=='\b')
{
printf("%c%c%c",'\b','\0','\b');
count-=2;
}
else
putchar('*');
}
pass[--count]='\0';
if(!strcmp(pass,password)) //开始验证
{
printf("\n\n\t\t\t\t\t\tLogining");
for(i=0;i<=25;i++)
{
Sleep(250);
printf(".");

system("cls");
printf("\n\n\n\n\n\n\n\n\n\t\t\t");
printf(" 欢 迎 登 陆 职 工 工 资 管 理 系 统 !\n\n");
start=time(NULL);
end=time(NULL);
while(end-start<2) //延时2秒执行以下程序
{
end=time(NULL);
}
/*system("cls");
free(pass); //释放储存密码的内存
return ;
}
free(pass); //释放密码错误的那块内存
pass=(char *)malloc(255*sizeof(char)); //重新分配储存密码内存
system("cls");
printf("\a\n\n\n\n\n\n\n\n\t\t\t\t密 码 错 误 !");
getch();
system("cls");
}
}*/
void Menu()
{
struct worker wor[50]; //最大职工人数
struct worker *p; //声明一个结构指针
p=wor; //指针指向结构变量per
int i,in; //接收用户的选择
char ch; //用于判断是否继续
do
{
system("cls");
printf("\n\n");
printf("\t\t　      ###  欢迎使用广西民族大学软件与信息安全学院 职 工 工 资 管 理 系 统  ###\n");
printf("\t\t　  *                    *\n");
printf("\t\t　请选择(1-7):\n");
printf("\t\t　*===========================================*\n");
printf("\t\t　|          1. 查询职工工资记录              |\n");
printf("\t\t　|                                           |\n");
printf("\t\t　|          2.　修改职工工资记录             |\n");
printf("\t\t　|                                           |\n");
printf("\t\t　|          3.　添加职工工资记录             |\n");
printf("\t\t　|                                           |\n");
printf("\t\t　|          4.　删除职工工资记录    　       |\n");
printf("\t\t　|                                           |\n");
printf("\t\t　|          5.　保存数据到文件               |\n");
printf("\t\t　|                                           |\n");
printf("\t\t　|          6.　浏览职工记录                 |\n");
printf("\t\t　|                                           |\n");
printf("\t\t　|          7.  退出系统                     |\n");
printf("\t\t　=============================================\n");
printf("\t\t　 你的选择是: ");
if(!(scanf("%d",&in)==1))
{
while((ch=getchar())!='\n')
putchar(ch);
printf(" 没有此选项,请正确选择!");
getch();
continue;
}
fflush(stdin);
switch(in)
{
/*case 1:
Inputper(per); //调用录入职工工资函数
break;
case 2:
Modifyper(per); //调用修改职工工资函函数
break;
case 3:
Findper(per); //调用查询职工工资函数
break;
case 4:
Listper(per); //调用浏览职工工资函数
break;
case 5:
Delper(per); //调用删除职工工资函数
break;
case 6:
Insertper(per); //插入职工工资信息
break;
case 7:
Sortper(per); //调用职工工资排序函数
break;
case 8:
Save(per); //保存职工工资函数
break;
case 9: //退出系统
break;
default:
printf("没有此选项，请正确选择!");
getch();
break;*/
case 1:
find(wor); //调用查询职工工资函数
break;
case 2:
modify(wor); //调用修改职工工资函函数
break;
case 3:
add(wor); //插入职工工资信息
break;
case 4:
del(wor); //调用删除职工工资函数
break;
case 5:
Save(wor); //保存职工工资函数
break;
case 6:
list(wor); //调用浏览职工工资函数
break;
case 7: //退出系统
break;
default:
printf("没有此选项，请正确选择!");
getch();
break;
}
while(in!=9);
system("cls");
//printf("\n\n\n\n\n\n\n\n\t\t\t");
//printf("谢 谢 使 用 本 系 统 !\n\n");
//printf("\n\n\t\t\t\t\tEnding");
for(i=0;i<=30;i++)
{
Sleep(300);
printf(".");
}
printf("\n");
}
}

/*void Help()
{
printf("====================================================================\n");
printf("\n\n\t\t\t\t系 统 信 息\n");
printf("====================================================================\n");
printf("\n\n\t\t本系统是职工工资管理系统,在职工的姓名栏可以输入汉字");
printf("\n\t\t如果在输入中没看到任何信息则是因为输入错误或无信息");
printf("\n\t\t系统中的 ：实发工资 = 基本工资 - 扣款 ，不需要输入");
printf("\n\t\t实发工资 ， 就可以直接输出实发工资，系统中的 ： ");
printf("\n\t\t总工资 = 基本工资 - 扣款 + 奖金。");
//printf("\n\t\t本系统制作者 : 李海蛟 \t QQ : 253181150");
//printf("\n\t\t E_mail : 253181150@qq.com ");
//printf("\n\t\t\t Made By VC6.0++\t 2013年6月18日\n");
printf("===================================================================\n");
printf("\n\n\t\t\t\t按<Enter>进入");
getchar();
}*/
void Save(struct worker wor[]) //职工工资保存函数
{
int i,j;
pp=wor; //指针指向结构
system("cls");
printf("\n\n\n\t\t正在保存信息,请耐心等候!!\n");
printf("\n\n\t\t\tSaving");
for((int)j=0;j<20;j++)
{
Sleep(300);
printf(".");
}
if((fp=fopen("per_list2.doc","wb+"))==NULL)
{
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
fprintf(fp,"职工工号 职工姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资 \n");
for(i=0;i<shuru;i++)
{
wor[i].sumslary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
//per[i].gotpaid=per[i].paid-per[i].discount;
if (per[i].gotpaid<2000)
per[i].fare=0;
else if (per[i].gotpaid>=2000&&per[i].gotpaid<4999)
per[i].fare=per[i].gotpaid*0.05;
else if (per[i].gotpaid>=5000&&per[i].gotpaid<10000)
per[i].fare=per[i].gotpaid*0.1;
else if (per[i].gotpaid>=10000&&per[i].gotpaid<99999)
per[i].fare=per[i].gotpaid*0.25;
else if (per[i].gotpaid>=100000)
per[i].fare=per[i].gotpaid*0.3;
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
fprintf(fp,"\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t %4.1f\t %5.1f\t",per[i].num,per[i].name,
		per[i].paid,per[i].discount,per[i].extra,per[i].gotpaid,per[i].fare,per[i].realpaid, per[i].sum);
}
}
}
}
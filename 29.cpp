#include <stdio.h> //��׼�������
#include <stdlib.h> //��������
#include <windows.h> //Sleep()
#include <string.h> //�ַ�������
#include <conio.h> //ϵͳ�������   
#include <time.h> //ʱ�����
/**********************�����Ƕ��õ���ȫ�ֳ�������*************************/
#define NAME 10 //ְ��ְ����������
//#define PASSWORD "123" //ϵͳ��½����
int shuru=0; //ȫ�ֱ�����ǵ�ǰ¼��ְ������
FILE *fp; //����һ���ļ�ָ��
/**************************�ṹ�嶨��************************************/
struct worker{ //ְ�����ʵĽṹ��
char name[NAME]; //ְ��ְ������
char num; //ְ�����
float gsalary;//��λ����
float xsalary;//н������
float zsalary;//ְ�����
float jsalary;//��Ч����
float sumsalary;//Ӧ������
float personaltax;//��������˰
float realsalary;//ʵ������
}*pp; //����һ���ṹָ��
/**********************�����Ƕ��õ��ĺ�������*****************************/
//void Password(); //������֤����

void read(struct worker wor[]); //¼���ȡְ���������ݺ���
void write(struct worker wor[]); //����ְ���������ݺ���
void find(struct worker wor[]); //��ѯְ���������ݺ���
void list(struct worker wor[]); //���ְ���������ݺ���
void modify(struct worker wor[]); //�޸�ְ���������ݺ���
void del(struct worker wor[]); //ɾ��ְ���������ݺ���
void Insertper(struct worker wor[]); //����ְ���������ݺ���
void grsds(struct worker wor[],int n);//�����������˰����
void Save(struct worker wor[]); //������Ϣ����
void Menu();
//void Help();
//**************************��������**************************************
void main() //�������
{
system("color black"); //���õ�ǰ���ڵı���ɫ��ǰ��ɫ
//Password(); //���������麯��
//Help(); //����ϵͳ��Ϣ����
Menu(); //���ò˵�����
}
void read(struct worker wor[]) //��ȡְ�����ʺ���ԭ��
{
pp=wor; //ָ��ָ��ṹ
system("cls"); //����
int i;
printf("������Ҫ���뼸��ְ������Ϣ:");
scanf("%d",&shuru);
if((fp=fopen("read","wb+"))==NULL) //��ǰĿ¼���Ƿ����read�ļ�
{ //"wb+":��д�򿪻���һ���������ļ�,�������д
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
for(i=0;i<shuru;i++)
{
printf("����ְ�����:"); //����ְ�����
fflush(stdin);
scanf("%d",&wor[i].num);
printf("����ְ������:"); //����ְ������
fflush(stdin);
gets(wor[i].name);
//printf("����ְ���Ĺ�����Ϣ\n");
//printf("------------------------------\n");
printf("\n��λ����: "); //��λ����
fflush(stdin);
scanf("%f",&wor[i].gsalary);
printf("\nн������: "); //н������
fflush(stdin);
scanf("%f",&wor[i].xsalary);
printf("\nְ�����: "); //ְ�����
fflush(stdin);
scanf("%f",&wor[i].zsalary);
printf("\n��Ч����: "); //��Ч����
fflush(stdin);
scanf("%f",&wor[i].jsalary);
printf("\nӦ������: "); //Ӧ������
fflush(stdin);
scanf("%f",&wor[i].sumsalary);
printf("\n��������˰: "); //��������˰
fflush(stdin);
scanf("%f",&wor[i].personaltax);
printf("\nʵ������: "); //ʵ������
fflush(stdin);
scanf("%f",&wor[i].realsalary);

printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
	   wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);}
}
void modify(struct worker wor[])//�޸�ְ����������
{
pp=wor;
int id,i=0; //idΪ�����û������ְ�����
if((fp=fopen("modify.sys","wb+"))==NULL)
{
printf("Cannot open file strike any key exit!");
getch();
exit(1);
}
fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
    printf(" ������Ҫ�޸ĵ�Ա������:");
scanf("%d",&id);
Sleep(500);
 //����ҵ��˾�ִ��������� ,�Ҳ���ֱ�ӻ�������
{printf("\n\t�����������.");
for(i=0;i<=15;i++)
{
Sleep(250);
printf(".");
}
for(i=0;i<shuru;i++)
{
if(wor[i].num==id)
 printf("�����޸ĺ�ְ���Ĺ���:");
		fflush(stdin);
		scanf('%s',&wor[i].num);
		printf("�����޸ĺ�ְ��������:");
		fflush(stdin);
		scanf('%s',&wor[i].name);
		printf("�����޸ĺ�ְ���ĸ�λ����:");
		fflush(stdin);
		scanf('%f',&wor[i].gsalary);
		printf("�����޸ĺ�ְ����н������:");
		fflush(stdin);
		scanf('%s',&wor[i].xsalary);
		printf("�����޸ĺ�ְ����ְ�����:");
		fflush(stdin);
		scanf('%s',&wor[i].zsalary);
		printf("�����޸ĺ�ְ���ļ�Ч����:");
		fflush(stdin);
		scanf('%f',&wor[i].jsalary);
        printf("�����޸ĺ�ְ���ļ�Ч����:");
		fflush(stdin);
		scanf('%f',&wor[i].jsalary);
		printf("�����޸ĺ�ְ����Ӧ������:");
		fflush(stdin);
		scanf('%f',&wor[i].sumsalary);
		printf("�����޸ĺ�ְ���ĸ�������˰:");
		fflush(stdin);
		scanf('%f',&wor[i].personaltax);
		printf("�����޸ĺ�ְ����ʵ������:");
		fflush(stdin);
		scanf('%f',&wor[i].realsalary);
		printf("   �޸ĳɹ�    ");
		wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].id,wor[i].name,wor[i].gsalary,wor[i].xsalary,
		wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);


/*
printf("\n������ְ�����:"); //����ְ�����
fflush(stdin);
scanf("%d",&wor[i].num);
printf("\n������ְ������:"); //����ְ������
fflush(stdin);
gets(per[i].name);
printf("����ְ���Ĺ�����Ϣ\n");
printf("------------------------------\n");
printf("\n��������: ");
scanf("%f",&per[i].paid);
fflush(stdin);
printf("\n�ۿ�: ");
scanf("%f",&per[i].discount);
fflush(stdin);
printf("\n ����: ");
scanf("%f",&per[i].extra);
printf("------------------------------\n");
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
fprintf(fp," %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\t\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].realpaid,per[i].sum);
*/
}
}
}
void find(struct worker wor[]) //��ѯְ��������Ϣ
{
int i=0,j=0,id; //ѭ�����������ڽ���ְ�����
printf("��������Ҫ��ѯ��ְ�����:");
scanf("%d",&id);
for(i=0;i<shuru;i++)
{
if (wor[i].num==id) //����ҵ����ѯ�����ݾ�ִ���������
{ //����Ҳ�����ֱ�ӻس�������%
	wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
	printf("\nְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
    printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
	   wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);
    system("pause");



/*
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
printf("\nְ����� ְ������ �������� �ۿ� ���� Ӧ������ ˰�� ʵ������ �ܹ��� \n");
printf("\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].gotpaid,per[i].fare,per[i].realpaid,per[i].sum);
system("pause");*/
}
}
}
void add(struct worker  wor[]) //���ְ��������Ϣ
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
	fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
    printf(" ������Ҫ��ӵ�Ա������:");
    scanf("%d",&id);
for(i=0;i<shuru;i++)
{
if(wor[i].num==id) //�ж�ְ�������Ϣ�����?
{
printf("ְ�������Ϣ�Ѿ�����!\n");
flag=0;
getch();
break;
}
}
if (flag!=0)
{
    shuru++; //����һ��,ԭ������������1
    printf("�����޸ĺ�ְ���Ĺ���:");
	scanf('%s',&wor[shuru-1].num);//���������..��ô�ͰѲ������Ϣ�ŵ��ṹ�������
	printf("�����޸ĺ�ְ��������:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].name);
	printf("�����޸ĺ�ְ���ĸ�λ����:");
	fflush(stdin);
	scanf('%f',&wor[shuru-1].gsalary);
	printf("�����޸ĺ�ְ����н������:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].xsalary);
	printf("�����޸ĺ�ְ����ְ�����:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].zsalary);
	printf("�����޸ĺ�ְ���ļ�Ч����:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].jsalary);
	printf("�����޸ĺ�ְ����Ӧ������:");
	fflush(stdin);
	//scanf('%s',&wor[shuru-1].sumsalary);
	fputs(&wor[i].sumsalary,fp);
	printf("�����޸ĺ�ְ���ĸ�������˰:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].personaltax);
	printf("�����޸ĺ�ְ����ʵ������:");
	fflush(stdin);
	scanf('%s',&wor[shuru-1].realsalary);
	wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
		wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);




/*
printf("��ȷ������Ҫ����ְ�����:");
scanf("%d",&per[shuru-1].num); //���������..��ô�ͰѲ������Ϣ�ŵ��ṹ�������
printf("����ְ������:");
fflush(stdin);
gets(per[shuru-1].name);
printf("����ְ���Ĺ�����Ϣ\n");
printf("------------------------------\n");
printf("\n��������: ");
fflush(stdin);
scanf("%f",&per[shuru-1].paid);
printf("\n�ۿ�: ");
fflush(stdin);
scanf("%f",&per[shuru-1].discount);
printf("\n����: "); //����
fflush(stdin);
printf("\n˰��: "); //˰��
fflush(stdin);
printf("------------------------------\n");
per[i].sum=per[i].paid-per[i].discount+per[i].extra;
per[i].realpaid=per[i].paid-per[i].discount;
fprintf(fp," %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\t\n",per[shuru-1].num,per[shuru-1].name,per[shuru-1].paid,per[shuru-1].discount,per[shuru-1].extra,per[i].realpaid,per[shuru-1].sum);
*/
Sleep(500);
printf("������ݳɹ�!\n");
getch();
}                                                                                                                                      
}
void Listper(struct worker wor[]) //�������ְ����
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
printf("\nְ����� ְ������ �������� �ۿ� ���� Ӧ������ ˰�� ʵ������ �ܹ���\n");
for(i=0;i<shuru;i++)
{
printf("\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t %4.1f\t %5.1f\t",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].gotpaid,per[i].fare,per[i].realpaid, per[i].sum);
}
getch();
}*/
void del(struct worker wor[]) //ɾ��ְ����Ϣ����
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
fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
system("cls");
printf("\n\n\t������Ҫɾ����ְ����ְ������:");
fflush(stdin);
scanf("%d",&delnum);
printf("\n\t�Ƿ�ȷ��ɾ��ְ��%d����Ϣ(y/n)",delnum);
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
printf("\n\tû����Ҫɾ����ְ��!\n");
else
{
for(j=i;j<shuru;j++)
{
temp = wor[j];
wor[j] = wor[j+1];
wor[j+1] = temp;
}
shuru--; //ɾ��һ��ְ����Ϣ��ְ��������Ӧ-1
system("cls");
printf("\n\nɾ���ɹ�!\n");
}
wor[i].sumsalary=wor[i].gsalary+wor[i].jsalary+wor[i].xsalary+wor[i].zsalary;
fprintf(fp,"\n%6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %5.1f\t  %5.1f\t %4.1f\t \n\n",wor[i].num,wor[i].name,wor[i].gsalary,
		wor[i].xsalary,wor[i].zsalary,wor[i].jsalary,wor[i].sumsalary,wor[i].personaltax,wor[i].realsalary);
getch();
}
}

/*
void Sortper(struct person per[]) //������
{
int i,j,chose; //i,jΪѭ������ choseΪ�����û����������ʽ
struct person temp;
printf("����ǰ������Ϊ\n");
printf("\nְ����� ְ������ �������� �ۿ� ���� Ӧ������ ˰�� ʵ������ �ܹ���\n");
for(i=0;i<shuru;i++)
{
printf("\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\t\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].realpaid,per[i].sum);
}
printf("\n1.��ְ���������\t2.���ܹ���(�ߡ���)����\n");
printf("\n������ȷѡ��:");
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
printf("\nְ����� ְ������ �������� �ۿ� ���� Ӧ������ ˰�� ʵ������ �ܹ���\n");
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
printf("\nְ����� ְ������ �������� �ۿ� ���� Ӧ������ ˰�� ʵ������ �ܹ���\n");
for(i=0;i<shuru;i++)
{
printf("\n %6d %8s %5.1f\t %5.1f\t %3.1f\t %5.1f\t %4.1f\n",per[i].num,per[i].name,per[i].paid,per[i].discount,per[i].extra,per[i].realpaid,per[i].sum);
}
system("pause");
}
}*/
/*void Password() //������֤����
{
char *pass=NULL; //��ʼ��ָ��
int i,count;
time_t start,end; //ʱ�亯��
pass=(char *)malloc(255*sizeof(char)); //�����ڴ�
while(1)
{
count=0;
printf("\n\n\n\n\n\t\t\tְ �� �� �� �� �� ϵ ͳ \n");
printf("\n\t\t UserName:��� \n");
printf("\n\t\t PassWord:");
while((count>=0)&&(pass[count++]=getch())!=13) //��������
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
if(!strcmp(pass,password)) //��ʼ��֤
{
printf("\n\n\t\t\t\t\t\tLogining");
for(i=0;i<=25;i++)
{
Sleep(250);
printf(".");

system("cls");
printf("\n\n\n\n\n\n\n\n\n\t\t\t");
printf(" �� ӭ �� ½ ְ �� �� �� �� �� ϵ ͳ !\n\n");
start=time(NULL);
end=time(NULL);
while(end-start<2) //��ʱ2��ִ�����³���
{
end=time(NULL);
}
/*system("cls");
free(pass); //�ͷŴ���������ڴ�
return ;
}
free(pass); //�ͷ����������ǿ��ڴ�
pass=(char *)malloc(255*sizeof(char)); //���·��䴢�������ڴ�
system("cls");
printf("\a\n\n\n\n\n\n\n\n\t\t\t\t�� �� �� �� !");
getch();
system("cls");
}
}*/
void Menu()
{
struct worker wor[50]; //���ְ������
struct worker *p; //����һ���ṹָ��
p=wor; //ָ��ָ��ṹ����per
int i,in; //�����û���ѡ��
char ch; //�����ж��Ƿ����
do
{
system("cls");
printf("\n\n");
printf("\t\t��      ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺ ְ �� �� �� �� �� ϵ ͳ  ###\n");
printf("\t\t��  *                    *\n");
printf("\t\t����ѡ��(1-7):\n");
printf("\t\t��*===========================================*\n");
printf("\t\t��|          1. ��ѯְ�����ʼ�¼              |\n");
printf("\t\t��|                                           |\n");
printf("\t\t��|          2.���޸�ְ�����ʼ�¼             |\n");
printf("\t\t��|                                           |\n");
printf("\t\t��|          3.�����ְ�����ʼ�¼             |\n");
printf("\t\t��|                                           |\n");
printf("\t\t��|          4.��ɾ��ְ�����ʼ�¼    ��       |\n");
printf("\t\t��|                                           |\n");
printf("\t\t��|          5.���������ݵ��ļ�               |\n");
printf("\t\t��|                                           |\n");
printf("\t\t��|          6.�����ְ����¼                 |\n");
printf("\t\t��|                                           |\n");
printf("\t\t��|          7.  �˳�ϵͳ                     |\n");
printf("\t\t��=============================================\n");
printf("\t\t�� ���ѡ����: ");
if(!(scanf("%d",&in)==1))
{
while((ch=getchar())!='\n')
putchar(ch);
printf(" û�д�ѡ��,����ȷѡ��!");
getch();
continue;
}
fflush(stdin);
switch(in)
{
/*case 1:
Inputper(per); //����¼��ְ�����ʺ���
break;
case 2:
Modifyper(per); //�����޸�ְ�����ʺ�����
break;
case 3:
Findper(per); //���ò�ѯְ�����ʺ���
break;
case 4:
Listper(per); //�������ְ�����ʺ���
break;
case 5:
Delper(per); //����ɾ��ְ�����ʺ���
break;
case 6:
Insertper(per); //����ְ��������Ϣ
break;
case 7:
Sortper(per); //����ְ������������
break;
case 8:
Save(per); //����ְ�����ʺ���
break;
case 9: //�˳�ϵͳ
break;
default:
printf("û�д�ѡ�����ȷѡ��!");
getch();
break;*/
case 1:
find(wor); //���ò�ѯְ�����ʺ���
break;
case 2:
modify(wor); //�����޸�ְ�����ʺ�����
break;
case 3:
add(wor); //����ְ��������Ϣ
break;
case 4:
del(wor); //����ɾ��ְ�����ʺ���
break;
case 5:
Save(wor); //����ְ�����ʺ���
break;
case 6:
list(wor); //�������ְ�����ʺ���
break;
case 7: //�˳�ϵͳ
break;
default:
printf("û�д�ѡ�����ȷѡ��!");
getch();
break;
}
while(in!=9);
system("cls");
//printf("\n\n\n\n\n\n\n\n\t\t\t");
//printf("л л ʹ �� �� ϵ ͳ !\n\n");
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
printf("\n\n\t\t\t\tϵ ͳ �� Ϣ\n");
printf("====================================================================\n");
printf("\n\n\t\t��ϵͳ��ְ�����ʹ���ϵͳ,��ְ�����������������뺺��");
printf("\n\t\t�����������û�����κ���Ϣ������Ϊ������������Ϣ");
printf("\n\t\tϵͳ�е� ��ʵ������ = �������� - �ۿ� ������Ҫ����");
printf("\n\t\tʵ������ �� �Ϳ���ֱ�����ʵ�����ʣ�ϵͳ�е� �� ");
printf("\n\t\t�ܹ��� = �������� - �ۿ� + ����");
//printf("\n\t\t��ϵͳ������ : ��� \t QQ : 253181150");
//printf("\n\t\t E_mail : 253181150@qq.com ");
//printf("\n\t\t\t Made By VC6.0++\t 2013��6��18��\n");
printf("===================================================================\n");
printf("\n\n\t\t\t\t��<Enter>����");
getchar();
}*/
void Save(struct worker wor[]) //ְ�����ʱ��溯��
{
int i,j;
pp=wor; //ָ��ָ��ṹ
system("cls");
printf("\n\n\n\t\t���ڱ�����Ϣ,�����ĵȺ�!!\n");
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
fprintf(fp,"ְ������ ְ������ ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������ \n");
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
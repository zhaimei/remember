#include <stdio.h>       //��׼�������
#include <windows.h>    //Sleep()�����ڴ�
#include <string.h>    //�ַ�������
#include <conio.h>    //ϵͳ������� getch()��getche()���������ڴ�  
#define TURE 1
void read();         //�������ļ��ж�ȡְ����������		
void write();       //��ְ�����������ļ���д���¼
void find();       //��ѯְ���������ݼ�¼
void modify();    //�޸�ְ���������ݼ�¼
void add();      //��ְ�����������ļ������Ӽ�¼
void del();     //��ְ�����������ļ���ɾ����¼
float grsds(float m);    //�����������˰
void list();            //���ְ����¼
struct worker          //����ְ���������ݽṹ��
{
	char workerID[10];     //ְ������
	char name[15];         //����
	float gsalary;         //��λ����
	float xsalary;         //н������
	float zsalary;         //ְ�����
	float jsalary;         //��Ч����
	float sumsalary;       //Ӧ������
	float personaltax;     //��������˰
	float realsalary;      //ʵ������
};
struct worker zggz[100];      //������¼ְ�����������100��Ԫ�صĽṹ������
int n=-1;                    //����ͳ��ְ������������ȫ�֣�
void write()                //����ְԱ��Ϣ
{
	FILE *fp;    //�����ļ�ָ��
	if(n==-1)   //ְ������Ϊ0ʱ
	{
		printf("û�����ݿɴ棡��������������˵���\n");
		getch();                      //�����Ժ��������û�����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س����ַ�������ʾ����Ļ�ϣ�
		return;
	}
	if((fp=fopen("gz.dat","wb"))!=NULL)            //�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��
	{
		fwrite(&zggz[0],sizeof(zggz[0]),n+1,fp);   //���м�¼һ��д���ļ�
		fclose(fp);                               //�ر��ļ�ָ��
		printf("\n\n\t%d��ְ����¼������ϣ�\n",n+1);
	}  
	else                                      //�ļ��򿪲��ɹ�ʱ
		printf("\t\t�޷���ְ�����������ļ���\n");
	printf("\n\t\t��������������˵���");
	getch();               //�����Ժ���
}
void find()               //��ѯְ���������ݺ���
{
	char gonghao[10];    //����ְ�������ַ�����
	int i;              //ѭ������
	if(n==-1)          //����Ϊ0˵�����ʼ�¼��δ���
	{
		printf("\n\n\t\t��ǰ��û��ְ�����ʼ�¼����������������˵���");
		getch();                 //�����Ժ���
		return;
	}
	printf("\t������ְ�����ţ�");   //��ʾ��Ϣ
	gets(gonghao);                 //�Ӽ��̶�ȡ����
	for(i=0;i<=n;i++)             //��ְ��������Χ��ѭ������
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)   //�Ƚϲ��ҵ�
		{
			printf("\n��ְ������������£�");
			printf("\n===================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
			printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
			printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
			printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
			printf("\n\t\t��������������˵���");
			getch();     //�����Ժ���
			break;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t���������ְ����������򲻴��ڣ�");
		printf("��������������˵���");
		getch();
		return;
	}
}
void list()    //���ְ���������ݺ���
{
	int i;
	system("cls");      //����
	printf("\n\n\t\t\tȫ��ְ������������£�\n");
	printf("\n===================================\n\n");
	printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
	printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","��������˰","ʵ������");
	for(i=0;i<=n;i++)
	{
		printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
		printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
		printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
		printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
	}
	printf("��������������˵���");
	getch();
	return;
}
void modify()             //�޸�ְ���������ݺ���
{
	char gonghao[10];    //����ְ�������ַ�����
	int i;              //ѭ������
	if(n==-1)          //����Ϊ0˵�����ʼ�¼��δ���
	{
		printf("\n\n\t\t��ǰ��û��ְ�����ʼ�¼����������������˵���");
		getch();
		return;
	}
	printf("\t�����빤�ţ�");//��ʾ��Ϣ
	gets(gonghao);          //�Ӽ��̶�ȡ�ַ���
	for(i=0;i<=n;i++)      //��ְ��������Χ��ѭ������
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)
		{
			printf("\n\n\t\t\tȫ��ְ������������£�\n");
			printf("\n===================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f",zggz[i].workerID,zggz[i].name,zggz[i].gsalary);
			printf("%9.2f%9.2f",zggz[i].xsalary,zggz[i].zsalary);
			printf("%9.2f%9.2f",zggz[i].jsalary,zggz[i].sumsalary);
			printf("%9.2f%9.2f\n",zggz[i].personaltax,zggz[i].realsalary);
			printf("\n\t\t�������ְ���µĸ�λ���ʣ�");
			scanf("%f",&zggz[i].gsalary);
			printf("\n\t\t�������ְ���µ�н�����ʣ�");
			scanf("%f",&zggz[i].xsalary);
			printf("\n\t\t�������ְ���µ�ְ�������");
			scanf("%f",&zggz[i].zsalary);
			printf("\n\t\t�������ְ���µļ�Ч���ʣ�");
			scanf("%f",&zggz[i].jsalary);
			zggz[i].sumsalary=zggz[i].gsalary+zggz[i].xsalary+zggz[i].zsalary+zggz[i].jsalary;  //����Ӧ������
			zggz[i].personaltax=grsds(zggz[i].sumsalary);              //�����������˰
			zggz[i].realsalary=zggz[i].sumsalary-zggz[i].personaltax; //����ʵ������
			printf("\n\t\t��ְ����Ӧ�������ǣ�%f",zggz[i].sumsalary);
			printf("\n\t\t��ְ���ĸ�������˰�ǣ�%f",zggz[i].personaltax);
			printf("\n\t\t��ְ����ʵ�������ǣ�%f",zggz[i].realsalary);
			printf("\n\n\t\t��ְ�����������޸ĳɹ�����������������˵���");
			getch();    //�����Ժ���
			return;
		}
	}
	printf("\n\t\t���������ְ����������򲻴��ڣ�");
	printf("��������������˵���");
	getch();     //�����Ժ���
	return;
}
void add()   //���ְ���������ݺ���
{
	printf("\t�����빤�ţ�");
	fflush(stdin);    //������̻�����
	gets(zggz[++n].workerID);
	printf("\t\t\t��������ְ��������");
	gets(zggz[n].name);
	printf("\n\t\t�������ְ���µĸ�λ���ʣ�");
	scanf("%f",&zggz[n].gsalary);
	printf("\n\t\t�������ְ���µ�н�����ʣ�");
	scanf("%f",&zggz[n].xsalary);
	printf("\n\t\t�������ְ���µ�ְ�������");
	scanf("%f",&zggz[n].zsalary);
	printf("\n\t\t�������ְ���µļ�Ч���ʣ�");
	scanf("%f",&zggz[n].jsalary);
	zggz[n].sumsalary=zggz[n].gsalary+zggz[n].xsalary+zggz[n].zsalary+zggz[n].jsalary;//����Ӧ������
	zggz[n].personaltax=grsds(zggz[n].sumsalary);   //�����������˰
	zggz[n].realsalary=zggz[n].sumsalary-zggz[n].personaltax;//����ʵ������
	printf("\t\tt��ְ����Ӧ�������ǣ�%f",zggz[n].realsalary);
	printf("\t\tt��ְ���ĸ�������˰�ǣ�%f",zggz[n].personaltax);
	printf("\t\t\t��ְ����ʵ�������ǣ�%f",zggz[n].realsalary);
	printf("\n\n\t\t\t����������ء�");
	getchar();
}
void del()  //ɾ��ְ���������ݺ���
{
	char gonghao[10];   //����ְ�������ַ�����
	int i,j;   //ѭ������
	char d;    //����ȷ��ɾ���ַ�y/n
	printf("\t�������ɾ��ְ�����ţ�");
	gets(gonghao);
	for(i=0;i<=n;i++)  //��ְ��������Χ��ѭ������
	{
		if(strcmp(zggz[i].workerID,gonghao)==0)   //�Ƚϲ��ҵ�
		{
			printf("\n\t\t��ȷ��Ҫɾ��%s��ְ��������Ϣ��y/n����",zggz[i].workerID);
			d=getche();
			if(d=='y'||d=='Y')  //ȷ��ɾ��
			{
				if(i==n)  //��������һ����¼
					n--;
				else    //�������һ����¼ʱ
				{
					for(j=i;j<=n;j++)  //�Ӹü�¼������¼����ǰһ����¼
					{
						strcpy(zggz[j].workerID,zggz[j+1].workerID);
						strcpy(zggz[j].name,zggz[j+1].name);
						zggz[j].gsalary=zggz[j+1].gsalary;
						zggz[j].xsalary=zggz[j+1].xsalary;
						zggz[j].zsalary=zggz[j+1].zsalary;
						zggz[j].jsalary=zggz[j+1].jsalary;
						zggz[j].sumsalary=zggz[j+1].sumsalary;
						zggz[j].personaltax=zggz[j+1].personaltax;
						zggz[j].realsalary=zggz[j+1].realsalary;
					}
					n--;
				}
				printf("\n\n\t\t��ְ���������ݳɹ�ɾ������������������˵���");
				getch();
				break;
			}
			else  //δȷ��ɾ����¼
			{
				printf("\n\n\t\t��ѡ���˲�ɾ����ְ����¼����������������˵���");
				getch();
				return;
			}
		}
	}
	if(i==n+1)  //δ�ҵ�ָ�����Ż�δɾ����¼
	{
		printf("\n\t\t����λ�޴˹��ţ���������������˵���");
		getch();
	}
}
float grsds(float m)   //�����������˰
{
	float pt;     //����Ӧ��˰���ö�
	float rt=0;  //����Ӧ��˰��
	int n;
	pt=m-2000;
	if(pt>0)
		if(pt<500)n=1;
		else if(pt<2000)n=2;
		else if(pt<5000)n=3;
		else if(pt<20000)n=4;
		else if(pt<40000)n=5;
		else if(pt<60000)n=6;
		else if(pt<80000)n=7;
		else if(pt<100000)n=8;
		else n=9;
		switch(n)    //�˴�����case���ص�
		{
		case 9:rt+=(pt-1000000)*0.45;pt=1000000;
		case 8:rt+=(pt-80000)*0.40;pt=80000;
		case 7:rt+=(pt-60000)*0.40;pt=60000;
		case 6:rt+=(pt-40000)*0.35;pt=40000;
		case 5:rt+=(pt-20000)*0.30;pt=20000;
		case 4:rt+=(pt-5000)*0.25;pt=5000;
		case 3:rt+=(pt-2000)*0.20;pt=2000;
		case 2:rt+=(pt-500)*0.15;pt=500;
		case 1:rt+=pt*0.05;
		}
		return rt;
}
void main()
{
	char ch;
	read();   //�������ļ��ж�ȡְ���������ݲ���ʼ��ְ�����ʽṹ������
	while(TURE)
	{
	system("cls");//��������
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
	printf("\n\t\t���ѡ���ǣ�");
	ch=getche();  //��������ַ����Ե���Ļ�ϣ�����󲻹ܻز��س��������ԣ�
	switch(ch)
	{
		case'1':find();break;       //��ѯ
		case'2':modify();break;     //�޸�
		case'3':add();break;        //���
		case'4':del();break;       //ɾ��
		case'5':write();break;     //����
		case'6':list();break;      //���
		case'7':return;            //�˳�
		default:printf("\t\t�밴�������������ѡ��1-7��\n");
		getch();
		}
	}
	return;
}
void read()  //��ȡְ���������ݺ���
{
	FILE *fp;
	if((fp=fopen("gz.dat","rb"))==NULL)     //�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��
	{
		printf("\n\n\tְ�����������ļ��޷��򿪣���Ϊ�գ�");
		printf("\n\n\t�����������˵���");
		getch();
		return;
	}
	else    //�ļ��򿪳ɹ�ʱ
	{
		n++;    //����ṹ�������±�
		while(fread(&zggz[n],sizeof(zggz[n]),1,fp)==1)
			n++;
		fclose(fp);    //�ر��ļ�ָ��
		printf("\n\n\tְ���������ݶ�ȡ��ϣ�����%d�ˣ�\n",n);
		printf("\n\t5���Ӻ������\n",n);    
		n--;        //����ְ����¼����
		Sleep(5000);//��ʱ5����
	}
}
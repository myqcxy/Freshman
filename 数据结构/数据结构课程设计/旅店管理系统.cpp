/*ס�޹���ģ�飺�����ͷ�Ԥ������ס�Ǽǡ����������������Ǽǡ��˷�����
�ͷ�����ģ�飺�����ͷ����á��ͷ���ѯ���޷�����
��ѯͳ��ģ�飺����Ԥ������ѯ��ס�޲�ѯ���˷���ѯ���ͷ��޷�ͳ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
void weihu();
void InputRoom();
void writetotxt();
void write1totxt();
void readfromtxt();
void kefangxinxi();
void xiugaikefang();
void tainjiakefang();
void shanchukefang();
void zhusuguanli();
void ruzhu();
void read1fromtxt();
void tuifang();
void findkefang();
void findkeren();
void findofroom();
void findofname();
void kerenxinxi();
void xufang();
/*ס�޹���ģ�飺�����ͷ�Ԥ����
��ס�Ǽǡ����������������Ǽǡ��˷�����*/
typedef struct patron//�͹���Ϣ
{
	int guenum;//����ס����� 
	char name[20];//�������� 
	char idnum[19];//�������֤��
	char phone[12];//�绰���� 
	char sex[5];//�����Ա� 
	int ruzhutime;//��סʱ�� 
	int timelong;//�ⷿʱ�� 
}parton;
parton hash1[MAX];
typedef struct Guest//ס�� 
{
	int guenum;//�ͷ���� 
	int maxnum;//�����ס���� 
	int shifouruzhu;//�Ƿ�������ס 
	double zujin;//���� 
	int num;//����ס���� 
}Guest;
Guest hash[MAX];
 
void InputRoom()
{
	int i;	
	printf("ע�⣡�����Ƿ�������˲����Ὣԭ�ͷ���Ϣ�������޷��ָ���Y/N��\n");
	char choice;
	scanf("%*c%c", &choice);
	if(choice!='Y'&&choice!='y')  return;
	Guest room;
	printf("�����뷿���ţ������Ϊ-1ʱ�������룩\n");
	while(scanf("%d", &room.guenum),room.guenum!=-1)
	{
		i=room.guenum%1000;
		if(hash[i].guenum)
		{
			printf("�Ѵ��ڴ˷��䣡���������룡\n");
			continue;
		}
		printf("�����������ס����\n");
		scanf("%d", &room.maxnum);
		printf("���������\n");
		scanf("%lf", &room.zujin);
		printf("�������Ƿ�������ס��(1=�У�0=û��)\n");
		scanf("%d",&room.shifouruzhu);
		printf("��������ס����:\n");
		scanf("%d", &room.num);		
		hash[i]=room;
		printf("�����뷿���ţ������Ϊ-1ʱ�������룩\n");
	}
	printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	for(i=0;i<MAX;i++)
	if(hash[i].guenum)
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);

	writetotxt();
	
}
void weihu()
{
	while(1)
	{
		printf("************************************\n");
		printf("****  ��������ͷ���Ϣ������ 1�� ***\n");
		printf("****  �޸Ŀͷ���Ϣ������     2�� ***\n");
		printf("****  ��ӿͷ���Ϣ������     3�� ***\n");
		printf("****  ɾ���ͷ���Ϣ������     4�� ***\n");
		printf("****  ������һ�˵�������     0�� ***\n");
		printf("************************************\n");
		int n;
		printf("����������ѡ��\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:InputRoom();break;
			case 2:xiugaikefang();break;
			case 3:tainjiakefang();break;
			case 4:shanchukefang();break;
			case 0:return;
		}
	}
}
void shanchukefang()
{
	int i,num;
	printf("������Ҫɾ���Ŀͷ���ţ�\n");
	scanf("%d", &num);
	i=num%MAX;
	if(!hash[i].guenum)
	{
		printf("�˿ͷ������ڣ�\n");
		return ;
	}
	printf("ɾ�����ɻָ����Ƿ�Ҫɾ����Y/N\n");
	char c;
	scanf("%*c%c", &c);
	if(c!='c'&&c!='C')
	return;
	hash[i].guenum=0;
	writetotxt();
}
void tainjiakefang()
{
	int i,num;
	printf("��������Ҫ��ӵĿͷ���ţ�\n");
	scanf("%d", &num);
	i=num%MAX;
	if(hash[i].guenum)
	{
		printf("�˷����Ѵ��ڣ�\n");
		return;
	}
		hash[i].guenum=num;
		printf("�����������ס����\n");
		scanf("%d", &hash[i].maxnum);
		printf("���������\n");
		scanf("%lf", &hash[i].zujin);
		printf("�������Ƿ�������ס��(1=�У�0=û��)\n");
		scanf("%d",&hash[i].shifouruzhu);
		printf("��������ס����:\n");
		scanf("%d", &hash[i].num);	
		printf("��ӳɹ���\n");	
		writetotxt();
}
void xiugaikefang()
{
	printf("��������Ҫ�޸ĵĿͷ��ı�ţ�\n");
	int num,i,j;
	scanf("%d", &num);
	i=num%MAX;
	if(!hash[i].guenum)
	{
		printf("�����ڴ˷��䣡\n");
		return;
	}
	printf("�˷�����ϢΪ��\n");
		printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		printf("�Ƿ�Ҫ�޸� �ǣ�Y����N��\n");
		char c;
		scanf("%*c%c", &c);
		if(c!='y'&&c!='Y')
		{
			printf("�޸�ȡ����\n");
			return;
		}
		printf("�����������ס����\n");
		scanf("%d", &hash[i].maxnum);
		printf("���������\n");
		scanf("%lf", &hash[i].zujin);
		printf("�������Ƿ�������ס��(1=�У�0=û��)\n");
		scanf("%d",&hash[i].shifouruzhu);
		printf("��������ס����:\n");
		scanf("%d", &hash[i].num);	
		printf("�޸ĳɹ���\n");	
		printf("�޸ĺ����ϢΪ��\n");
		printf("�˷�����ϢΪ��\n");
		printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
			printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		writetotxt();
}
void kefangxinxi()
{
	int i;
	printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	for(i=0;i<MAX;i++)
	if(hash[i].guenum)
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
}
void search()
{
	while(1)
	{
		printf("************************************\n");
		printf("****  ���ҿͷ���Ϣ������     1�� ***\n");
		printf("****  ���ҿ�����Ϣ������     2�� ***\n");
		printf("****  �������ס����Ϣ������ 3�� ***\n");
		printf("****  ������п�����Ϣ������ 4�� ***\n");
		printf("****  ������һ�˵�������     0�� ***\n");
		printf("************************************\n");
		int n;
		printf("����������ѡ��\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:findkefang();break;
			case 2:findkeren();break;
			case 3:kefangxinxi();break;
			case 4:kerenxinxi();break;
			case 0:return;
		}
	}
}
void kerenxinxi()
{
	int i,j=0;
	for(i=0;i<MAX;i++)
	if(hash1[i].guenum)
	{
		printf("ס�޷���ţ�%d ������%s ���֤�ţ�%s �绰���룺 %s �Ա� %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
		j=1;
	}
	if(!j) printf("������ס��\n");
}
void findkeren()
{
	int i,j=0;
	printf("*********************************\n");
	printf("****   ���շ������������ 1  ****\n");
	printf("****   ������������������ 2  ****\n");
	printf("*********************************\n");
	printf("����������ѡ��\n");
	int n;
	scanf("%d", &n);
	switch(n)
	{
		case 1:findofroom();break;
		case 2:findofname();break;
	}
}
void findofname()
{
	char name[20];
	printf("���������������\n");
	scanf("%s", name);
	int i,j=0;
	for(i=0;i<MAX;i++)
	if(!strcmp(hash1[i].name,name))
	{
		printf("ס�޷���ţ�%d ������%s ���֤�ţ�%s �绰���룺 %s �Ա� %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
		j=1;
	}
	if(!j )printf("���޴��ˣ���\n");
}
void findofroom()
{
	int i,num;
	printf("�����뷿���ţ�\n");
	scanf("%d", &num);
	i=num%MAX;
	if(!hash1[i].guenum)
	{
		printf("������ס!!\n") ;
		return;
	}
	printf("ס�޷���ţ�%d ������%s ���֤�ţ�%s �绰���룺 %s �Ա� %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
	
}
void findkefang()
{
	int i,j=0;
	printf("����ͷ�Ϊ��\n");
	printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	for(i=0;i<MAX;i++)
	if(!hash[i].shifouruzhu&&hash[i].guenum){
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		j=1;
	}
	if(!j) printf("�ͷ�����������\n");
		
}
void zhusuguanli()
{
	printf("************************************\n");
	printf("*****   ��ס������    1��       ****\n");
	printf("*****   �˷�������    2��       ****\n");
	printf("*****   ����������    3��       ****\n");
	printf("*****   �˳�������    0��       ****\n");
	printf("************************************\n");
	int n;
	printf("����������ѡ��\n");
	scanf("%d", &n);
	switch(n)
	{
		case 1:ruzhu();break;
		case 2:tuifang();break;
		case 3:xufang();break;
		case 0:return;
	}
}
void xufang()
{
	
}
void tuifang()
{
	printf("�����뽫Ҫ�˷��ķ���ţ�\n");
	int num,i;
	scanf("%d", &num);
	i=num%MAX;
	if(!hash1[i].guenum)
	{
		printf("�˷���û���������\n");
		return;
	}
	hash1[i].guenum=0;
	write1totxt();
	hash[i].shifouruzhu=0;
	hash[i].num=0;
	writetotxt();
	printf("�˷��ɹ�,��ӭ�´ι��٣�����\n");
}
void ruzhu()
{
	printf("��������ҪԤ���ķ����ţ�\n");
	parton keren;
	scanf("%d", &keren.guenum);
	int i;
	i=keren.guenum%MAX;
	if(!hash[i].guenum)
	{
		printf("���޴˷�!!\n");
		return;
	}
	if(hash[i].shifouruzhu)
	{
		printf("�˷����Ѿ�����!\n");
		return;
	}
	int n;
	printf("�����뼸����ס��\n");
	scanf("%d", &n);
	if(hash[i].maxnum<n)
	{
		printf("�����������ޣ���\n���������룺\n");
		return;
	}
		printf("���������������\n");
		scanf("%s", keren.name);
		printf("������������֤�ţ�\n");
		scanf("%s", keren.idnum);
		printf("��������˵绰���룺\n");
		scanf("%s", keren.phone);
		printf("����������Ա�\n");
		scanf("%s", keren.sex);
		printf("��������סʱ�䣺\n");
		scanf("%d", &keren.ruzhutime);
		printf("��������סʱ����\n");
		scanf("%d", &keren.timelong);
		hash1[i]=keren;
		hash[i].shifouruzhu=1;
		hash[i].num=n;
		FILE *fp;
		fp=fopen("kerenxinxi.txt","a");
		fprintf(fp,"%d %s %s %s %s %d %d\n", hash1[i].guenum,hash1[i].name,hash1[i].idnum,
		hash1[i].phone,hash1[i].sex,hash1[i].ruzhutime,hash1[i].timelong);
		fclose(fp);
		writetotxt();
		write1totxt();
}
int main()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		hash[i].guenum=0;
		hash1[i].guenum=0;
	} 
	readfromtxt();
	read1fromtxt();
	while(1)
	{
		printf("*************************************\n");
		printf("****    ��ӭʹ��ס�޹���ϵͳ    *****\n\n");
		printf("****    ס�޹��������� 1��      *****\n");
		printf("****    �ͷ����������� 2��      *****\n");
		printf("****    ��ѯͳ�������� 3��      *****\n");
		printf("****    �˳�������     0��      *****\n\n");
		printf("*************************************\n");
		int choice;
		printf("����������ѡ��\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:zhusuguanli();break;
			case 2: weihu();break;
			case 3:search();break;
			case 0: exit(0);
		}
	}
	
	
	
	
	
	return 0;
}
void write1totxt()
{
	FILE *fp;
	fp=fopen("kerenxinxi.txt","w");
	int i;
	for(i=0;i<MAX;i++)
	if(hash1[i].guenum)
	fprintf(fp,"%d %s %s %s %s %d %d",hash1[i].guenum,hash1[i].name,hash1[i].idnum,hash1[i].phone,
		hash1[i].sex,hash1[i].ruzhutime,hash1[i].timelong);
	fclose(fp);
}
void read1fromtxt()
{
	parton keren;
	FILE *fp;
	fp=fopen("kerenxinxi.txt","r");
	int i;
	while(!feof(fp))
	{
		fscanf(fp,"%d %s %s %s %s %d %d\n", &keren.guenum,keren.name,keren.idnum,keren.phone,
		keren.sex,&keren.ruzhutime,&keren.timelong);
		i=keren.guenum%MAX;
		hash1[i]=keren;
	}
	fclose(fp);
}
void readfromtxt()
{
	Guest room;
	FILE *fp;
	fp=fopen("roomxinxi.txt","r");
	int i;
	while(!feof(fp))
	{
		fscanf(fp,"%d %d %lf %d %d\n", &room.guenum,&room.maxnum,&room.zujin,
		&room.shifouruzhu,&room.num);
		i=room.guenum%MAX;
		hash[i]=room;
	}
	fclose(fp);
}
void writetotxt()
{
	int i;
	FILE *fp;
	fp=fopen("roomxinxi.txt","w");
	for(i=0;i<MAX;i++)
	if(hash[i].guenum)
	fprintf(fp,"%d %d %lf %d %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
	fclose(fp);
}

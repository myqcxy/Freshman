/*ס�޹���ģ�飺�����ͷ�Ԥ������ס�Ǽǡ����������������Ǽǡ��˷�����
�ͷ�����ģ�飺�����ͷ����á��ͷ���ѯ���޷�����
��ѯͳ��ģ�飺����Ԥ������ѯ��ס�޲�ѯ���˷���ѯ���ͷ��޷�ͳ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> 
#define MAX 1000//��ϣ��ı� 
typedef int Index;//hash��ַ���� 
typedef void Status;//�������� 
Status weihu();//�ͷ���Ϣ��ά�� 
Status InputRoom();//��ʼ���ͷ���Ϣ 
Status writetotxt();//���ͷ���Ϣд�뵽kefangxinxi.txt�ļ��� 
Status write1totxt();//��������Ϣд�뵽kerenxinxi.txt�ļ��� 
Status readfromtxt();//���ͷ���Ϣ��kefangxinxi.txt�ļ��ж�����hash���� 
Status read1fromtxt();//��������Ϣ��kerenxinxi.txt������hash1����
Index HashIndex(int num);//����num��hash�����е�λ�ã�ȡnum�ĺ���λ�����غ���λ��
Status kefangxinxi();//����ͷ���Ϣ 
Status xiugaikefang();//�޸Ŀͷ���Ϣ 
Status tainjiakefang();//��ӿͷ� 
Status shanchukefang();//ɾ���ͷ� 
Status zhusuguanli();//ס�޹���˵� 
Status ruzhu();//��ס���� 
Status tuifang();//�˷����� 
Status xufang();//�������� 
Status findprice();// ɸѡ��������Ŀͷ�
Status findkefang();//���ҿյĿͷ� 
Status findkeren();//���ҿ��� 
Status findofroom();//���տͷ����ҿ��� 
Status findofname();//�����������ҿ��� 
Status kerenxinxi();//���������Ϣ 
Status daoqitixing();//����������ڵĿ��� 
/*ס�޹���ģ�飺�����ͷ�Ԥ����
��ס�Ǽǡ�������ס�������Ǽǡ��˷�����*/
 
typedef struct
{
	int year;
	int mon;
	int day;
}ruzhutime;//��סʱ��Ľṹ�� 
typedef struct patron//�͹���Ϣ
{
	int guenum;//����ס����� 
	char name[20];//�������� 
	char idnum[19];//�������֤��
	char phone[12];//�绰���� 
	char sex[5];//�����Ա� 
	ruzhutime time;//��סʱ�� 
	int timelong;//�ⷿʱ�� 
	long int s; 
}parton;
parton hash1[MAX];//������˵Ĺ�ϣ�� 
typedef struct Guest//ס�� 
{
	int guenum;//�ͷ���� 
	int maxnum;//�����ס���� 
	int shifouruzhu;//�Ƿ�������ס 
	double zujin;//���� 
	int num;//����ס���� 
}Guest;
Guest hash[MAX];//����ͷ��Ĺ�ϣ�� 
Index HashIndex(int num)//����num��hash�����е�λ�ã�ȡnum�ĺ���λ�����غ���λ��
{
	return num%MAX;//ȡ����λ 
}
 
Status InputRoom()//��ʼ��������Ϣ 
{
	int i;	
	printf("ע�⣡�����Ƿ�������˲����Ὣԭ�ͷ���Ϣ�������޷��ָ���Y/N��\n");
	char choice;//ȷ�ϲ��� 
	scanf("%*c%c", &choice);
	if(choice!='Y'&&choice!='y')  return;
	Guest room;
	printf("�����뷿���ţ������Ϊ-1ʱ�������룩\n");
	while(scanf("%d", &room.guenum),room.guenum!=-1)//������Ϣ 
	{
		i=room.guenum%1000;
		if(hash[i].guenum)//����Ѿ�������˷������������� 
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
	for(i=0;i<MAX;i++)//���������Ŀͷ���Ϣ 
	if(hash[i].guenum)
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);

	writetotxt();//���ͷ���Ϣд���ļ� 
	
}
Status weihu()//�ͷ���Ϣ��ά�� 
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
		if(scanf("%d", &n)!=1)
		{
			printf("�������\n���˳���\n");
			return;
		}
		switch(n)//��Ӧ��ѡ�� 
		{
			case 1:InputRoom();break;//��ʼ���ͷ���Ϣ 
			case 2:xiugaikefang();break;//�޸Ŀͷ���Ϣ 
			case 3:tainjiakefang();break;//��ӿͷ� 
			case 4:shanchukefang();break;//ɾ���ͷ� 
			case 0:return;//������һ�˵� 
		}
	}
}
Status shanchukefang()//ɾ���ͷ�
{
	int i,num;
	printf("������Ҫɾ���Ŀͷ���ţ�\n");
	if(scanf("%d", &num)!=1)
	{
			printf("�������\n���˳���\n");
			return;
	}
	
	i=HashIndex(num);//��ϣ��ַ 
	if(!hash[i].guenum)//����ͷ����Ϊ0 
	{
		printf("�˿ͷ������ڣ�\n");
		return ;
	}
	printf("ɾ�����ɻָ����Ƿ�Ҫɾ����Y/N\n");//ȷ�ϲ��� 
	char c;
	if(scanf("%*c%c", &c)!=1)
	{
			printf("�������\n���˳���\n");
			return;
	}
	if(c!='Y'&&c!='y')//ȡ������ 
	return;
	hash[i].guenum=0;//���ͷ���Ϣ��ʼ��Ϊ0 
	writetotxt();//д���ļ� 
	printf("ɾ���ɹ���\n");
}
Status tainjiakefang()//��ӿͷ���Ϣ 
{
	int i,num;
	printf("��������Ҫ��ӵĿͷ���ţ�\n");
	if(scanf("%d", &num)!=1)
	{
			printf("�������\n���˳���\n");
			return;
	}
	i=HashIndex(num);//��ϣ��ַ 
	if(hash[i].guenum)//����Ų�Ϊ�� 
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
Status xiugaikefang()//�޸Ŀͷ���Ϣ 
{
	printf("��������Ҫ�޸ĵĿͷ��ı�ţ�\n");
	int num,i,j;
	scanf("%d", &num);
	i=HashIndex(num);//��ϣ��ַ 
	if(!hash[i].guenum)//�ͷ����Ϊ�� 
	{
		printf("�����ڴ˷��䣡\n");
		return;
	}
	printf("�˷�����ϢΪ��\n");//�޸Ŀͷ�֮ǰ����˿ͷ���Ϣ����ȷ�� 
		printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		printf("�Ƿ�Ҫ�޸� �ǣ�Y����N��\n");
		char c;
		scanf("%*c%c", &c);
		if(c!='y'&&c!='Y')//ȷ��ɾ�� 
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
		writetotxt();//���޸ĺ����Ϣд���ļ� 
}
Status kefangxinxi()//����ͷ���Ϣ
{
	int i;
	printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	for(i=0;i<MAX;i++)
	if(hash[i].guenum)//���ڿͷ� 
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
}
Status search()//����ģ�� 
{
	while(1)
	{
		printf("************************************\n");

		printf("****  ���ҿͷ���Ϣ������     1�� ***\n");
		printf("****  ���ҿ�����Ϣ������     2�� ***\n");
		printf("****  �������ס����Ϣ������ 3�� ***\n");
		printf("****  ������п�����Ϣ������ 4�� ***\n");
		printf("****  ɸѡ�ͷ�����������     5�� ***\n");
		printf("****  ����쵽�ڵĿ��������� 6�� ***\n");
		printf("****  ������һ�˵�������     0�� ***\n");
		printf("************************************\n");
		int n;
		printf("����������ѡ��\n");
		if(scanf("%d", &n)!=1)
		{
			printf("�������\n���˳���\n");
			return;
		}
		switch(n)
		{
			case 1:findkefang();break;//���ҿͷ� 
			case 2:findkeren();break;//���ҿ��� 
			case 3:kefangxinxi();break;//�ͷ���Ϣ��� 
			case 4:kerenxinxi();break;//������Ϣ��� 
			case 5:findprice();break;//ɸѡָ���Ŀͷ� 
			case 6:daoqitixing();break;
			case 0:return;//������һ�˵� 
		}
	}
}
Status daoqitixing()
{
	int i,j=0;
	time_t rawtime;//��ȡʱ���� 
	printf("�������ڿ�����ϢΪ��\n"); 
	for(i=0;i<MAX;i++)
	if(hash1[i].guenum)
	if(hash1[i].s-time(&rawtime)<=hash1[i].timelong*24*60*60)
	{
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		j=1;
	}
	if(!j) printf("�����ڿ쵽�ڵĿ��ˣ�\n");
	
}
Status findprice()//ɸѡָ���ͷ� 
{
	printf("������ָ���ļ۸����䣺\n");
	printf("��������С�ļ۸�\n");
	double low;
	scanf("%lf", &low);
	printf("���������ļ۸�\n");
	double high;
	scanf("%lf", &high);
	printf("������������\n");
	int s;
	scanf("%d",&s);
	int i;
	printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	for(i=0;i<MAX;i++)
	if(hash[i].zujin>=low&&hash[i].zujin<=high&&hash[i].maxnum>=s)//����ɸѡ���� 
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
	
	
}
Status kerenxinxi()//���������Ϣ 
{
	int i,j=0;
	for(i=0;i<MAX;i++)
	if(hash1[i].guenum)//����п��� 
	{
		printf("ס�޷���ţ�%d ������%s ���֤�ţ�%s �绰���룺 %s �Ա� %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
		j=1;//����п��� 
	}
	if(!j) printf("������ס��\n");
}
Status findkeren()//���ҿ��� 
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
		case 1:findofroom();break;//��������� 
		case 2:findofname();break;//���������� 
	}
}
Status findofname()//���������� 
{
	char name[20];
	printf("���������������\n");
	scanf("%s", name);
	int i,j=0;
	for(i=0;i<MAX;i++)
	if(!strcmp(hash1[i].name,name))//Ҫ���ҵ������������ͬ 
	{
		printf("ס�޷���ţ�%d ������%s ���֤�ţ�%s �绰���룺 %s �Ա� %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
		j=1;//�ҵ���� 
	}
	if(!j )printf("���޴��ˣ���\n");
}
Status findofroom()//���ͷ����� 
{
	int i,num;
	printf("�����뷿���ţ�\n");
	scanf("%d", &num);
	i=HashIndex(num);//��ϣ��ַ 
	if(!hash1[i].guenum)//����Ų����� 
	{
		printf("������ס!!\n") ;
		return;
	}
	printf("ס�޷���ţ�%d ������%s ���֤�ţ�%s �绰���룺 %s �Ա� %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
	
}
Status findkefang()//���ҿ���ͷ� 
{
	int i,j=0;
	printf("����ͷ�Ϊ��\n");
	printf("������ �����ס���� ��� �Ƿ����� ��ס����\n");
	for(i=0;i<MAX;i++)
	if(!hash[i].shifouruzhu&&hash[i].guenum){
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		j=1;//�ҵ���� 
	}
	if(!j) printf("�ͷ�����������\n");
		
}
Status zhusuguanli()//ס�޹��� 
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
		case 1:ruzhu();break;//��ס���� 
		case 2:tuifang();break;//�˷����� 
		case 3:xufang();break;//�������� 
		case 0:return;//������һ�˵� 
	}
}
Status xufang()//�������� 
{
	printf("��������Ҫ�����ķ���ţ�\n");
	int num,i;
	if(scanf("%d", &num)!=1)
	{
			printf("�������\n���˳���\n");
			return; 
	}
	i=HashIndex(num);//��ϣ��ַ 
	if(!hash1[i].guenum)//��δ��� 
	{
		printf("�˷�����δ�������\n");
		return;
	}
	printf("ס�޷���ţ�%d ������%s ��סʱ�䣺%d��%d��%d�� ��סʱ����%d��\n",hash1[i].guenum,hash1[i].name,
		hash1[i].time.year,hash1[i].time.mon,hash1[i].time.day,hash1[i].timelong);
	printf("�Ƿ����ѣ� Y/N\n");
	char c;
	if(scanf("%*c%c", &c)!=1)
	{
			printf("�������\n���˳���\n");
			return;
	}
	if(c!='y'&&c!='Y') return;//ȷ�ϲ��� 
	printf("���������ѵ�������\n");
	int day;
	scanf("%d", &day) ;
	hash1[i].timelong+=day;//�޸��ӳ���ס������ 
	printf("�޸ĺ����ϢΪ��\n"); 
	printf("ס�޷���ţ�%d ������%s ��סʱ�䣺%d��%d��%d�� ��סʱ����%d��\n",hash1[i].guenum,hash1[i].name,
		hash1[i].time.year,hash1[i].time.mon,hash1[i].time.day,hash1[i].timelong);
	write1totxt();//�޸ĺ�д���ļ� 
	 printf("���ѳɹ�����\n");

} 
Status tuifang()//�˷����� 
{
	printf("�����뽫Ҫ�˷��ķ���ţ�\n");
	int num,i;
	if(scanf("%d", &num)!=1)
	{
			printf("�������\n���˳���\n");
			return;
	}
	i=HashIndex(num);//��ϣ��ַ 
	if(!hash1[i].guenum)//û����� 
	{
		printf("�˷���û���������\n");
		return;
	}
	hash1[i].guenum=0;//���˿���ɾ�� 
	write1totxt();//������Ŀ�����Ϣ д���ļ� 
	hash[i].shifouruzhu=0;//�ͷ��޸�Ϊû������ס 
	hash[i].num=0;//��ס�����޸�Ϊ0 
	writetotxt();//���޸ĺ�� �ͷ���Ϣд���ļ� 
	printf("�˷��ɹ�,��ӭ�´ι��٣�����\n");
}
Status ruzhu()//��ס���� 
{
	findprice();
	printf("��������ҪԤ���ķ����ţ�\n");
	parton keren;
	if(scanf("%d", &keren.guenum)!=1)
	{
			printf("�������\n���˳���\n");
			exit(0);
	}
	int i;
	i=HashIndex(keren.guenum);//��ϣ��ַ 
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
	if(scanf("%d", &n)!=1)
	{
			printf("�������\n���˳���\n");
			return;
	}
	if(hash[i].maxnum<n)//������ס�������� 
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
		printf("��������סʱ�䣺�������գ����м��ÿո����\n");
		scanf("%d%d%d", &keren.time.year,&keren.time.mon,&keren.time.day);
		printf("��������סʱ����\n");
		scanf("%d", &keren.timelong);
		time_t rawtime;//��ȡʱ���� 
		keren.s=time(&rawtime);
		hash1[i]=keren;//��ס 
		hash[i].shifouruzhu=1;//�ͷ���Ϣ��Ϊ������ס 
		hash[i].num=n;//��ס���� 
		
		writetotxt();//д���޸ĺ�Ŀ��˺Ϳͷ���Ϣ 
		write1totxt();
}
int main()//������ 
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
		if(scanf("%d",&choice)!=1) //������벻�Ƿ� 
		{
			printf("�������\n���˳���\n");
			exit(0);
		}
		switch(choice)
		{
			case 1:zhusuguanli();break;//ס�޹���ģ�� 
			case 2: weihu();break;//�ͷ�ά��ģ�� 
			case 3:search();break;//������Ϣģ�� 
			case 0: printf("\n��лʹ�ñ��õ����ϵͳ\n\nhaut,�����Ƚ��Ƽ���\n");
			exit(0);//�˳� 
		}
	}
	
	
	
	
	
	return 0;
}
Status write1totxt()//��������Ϣд��kerenxinxi.txt�ļ� 
{
	FILE *fp;//�����ļ� 
	fp=fopen("kerenxinxi.txt","w");//��д�ķ�ʽ�� 
	int i;
	for(i=0;i<MAX;i++)
	if(hash1[i].guenum)
	fprintf(fp,"%d %s %s %s %s %d %d %d %d %d\n",hash1[i].guenum,hash1[i].name,hash1[i].idnum,hash1[i].phone,
		hash1[i].sex,hash1[i].time.year,hash1[i].time.mon,hash1[i].time.day,hash1[i].timelong,hash1[i].s);
	fclose(fp);//�ر��ļ� 
}
Status read1fromtxt()//���ļ�kerenxinxi.txt�ļ�����������Ϣ��hash1������ 
{
	parton keren;//�ݴ�Ŀ��� 
	FILE *fp;//�����ļ�ָ�� 
	fp=fopen("kerenxinxi.txt","r");//�Զ��ķ�ʽ���ļ� 
	int i;
	while(!feof(fp))//�����ļ�β 
	{
		fscanf(fp,"%d %s %s %s %s %d %d %d %d %d\n", &keren.guenum,keren.name,keren.idnum,keren.phone,
		keren.sex,&keren.time.year,&keren.time.mon,&keren.time.day,&keren.timelong,&keren.s);
		i=HashIndex(keren.guenum);//��ϣ��ַ 
		hash1[i]=keren;//��ֵ 
	}
	fclose(fp);//�ر��ļ� 
}
Status readfromtxt()//���ļ��ж�ȡ�ͷ���Ϣ 
{
	Guest room;
	FILE *fp;//�����ļ� 
	if((fp=fopen("roomxinxi.txt","r"))==NULL)
	{
		printf("���ļ�ʧ�ܣ�����\n");
		exit(0);
	}//���ķ�ʽ���ļ� 
	int i;
	while(!feof(fp))//�����ļ�β 
	{
		fscanf(fp,"%d %d %lf %d %d\n", &room.guenum,&room.maxnum,&room.zujin,
		&room.shifouruzhu,&room.num);
		i=HashIndex(room.guenum);//��ϣ��ַ 
		hash[i]=room;
	}
	if(fclose(fp))
	{
		printf("�ر��ļ�ʧ�ܣ�����\n");
		exit(0);
	}//�ر��ļ� 
}
Status writetotxt()//���ͷ���Ϣд���ļ� 
{
	int i;
	FILE *fp;
	if((fp=fopen("roomxinxi.txt","w"))==NULL)//���ķ�ʽ���ļ� 
	{
		printf("���ļ�ʧ�ܣ�����\n");
		exit(0);
	}
	for(i=0;i<MAX;i++)
	if(hash[i].guenum)//�пͷ� 
	fprintf(fp,"%d %d %lf %d %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
	fclose(fp);//�ر��ļ� 
}

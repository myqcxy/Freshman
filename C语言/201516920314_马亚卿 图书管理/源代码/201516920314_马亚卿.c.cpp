#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct mima
{
	char id[8];//�˺� 
	char phone[12];//���� 
	char passworld[16];//���� 
	struct mima *next;//�¸��ڵ�ĵ�ַ 
};
struct book
{
	int num;//ͼ���� 
	char bookname[30];//ͼ���� 
	char author[20];//���� 
	char press[30];//������ 
	char cate[30];//��� 
	int year, mon, day;//����ʱ�� 
	double price;//ͼ��۸� 
	int kucun;//����� 
	int  lend;//����� 
	struct book *next;//�¸��ڵ�ĵ�ַ 
};
typedef struct book LNode, *LinkList;
typedef struct mima LNode1, *LinkList1;

void creatid1();//ͼ��ṹ�Ľ���
void liulan();//���ͼ��
void login1();//����Ա��¼
void FIND();//����
void find1();//��������
void find2();//�����߲���
void find3();//���۸����
void READ();//���ͼ��
void CHANGE();//�޸�ͼ����Ϣ
void chan1(LinkList head);
void chan2(LinkList head);
void teacher();//��ʦ�˵�
void student();//ѧ���˵�
void login2();//ѧ����¼
void creatid2();//ѧ��ע��
void FINDbook();//����ͼ��
void tour();//�οͲ˵�
void  add();//���ͼ��
void READmine();//����ҵ�ͼ��
void tongji();//ͳ����Ϣ
void tongji2();//���������ͳ��
void tongji1();//�����ٵ�ͳ��
void xiugaixuesheng();
void INPUT(LinkList head);//����ͼ�飬�β�ΪҪ��������� 
void jieshu(LinkList head);//����˵����β�Ϊͼ������� 
void huanshu(LinkList head);//����˵����β�Ϊͼ������� 
void write(LinkList head);//��ͼ���ļ�д�룬�β�ΪҪд���ļ������� 
void writemy(LinkList head);//���ҵ�ͼ��д�룬�β�Ϊ �ҽ��ͼ������� 
void writeid(LinkList1 head);//�ѹ���Ա����Ϣд���ļ����β�Ϊ��ʦ����Ϣ������ 
void writeid1(LinkList1 head);//���ҵ���Ϣд���ļ��� �β�Ϊ���ҵ���Ϣ������ 
void mydel(LinkList head,LinkList p);//ɾ���ҽ��ͼ�飬�βηֱ�Ϊ���ҵ�ͼ�������Ҫɾ����ͼ�� 
void del(LinkList head);//ɾ��ͼ�飬�β�Ϊͼ������ 
void chan(LinkList head);//�޸�ͼ����Ϣ���β�Ϊͼ������ 
void kucundel(LinkList head,int num);//�����٣��βηֱ�Ϊͼ�������ͼ���� 
void print(LinkList head);//���ͼ����Ϣ���β�Ϊͼ������ 
void xiugaiziliao(char *id1);//�޸Ĺ���Ա�����ϣ��β�Ϊ��ʦ��id 
void xiugaiziliao1(char *id1);//�޸��ҵ����ϣ��β�Ϊ �ҵ�id 
LinkList priceDown(LinkList head);//���۸�����ң��β�Ϊͼ��������������õ����� 
LinkList paixu(LinkList head);//��ͼ���Ŵ�С�������� �β�Ϊͼ��������������õ�����
LinkList read();//���ļ��ж���ͼ�飬����һ��ͼ������ 
LinkList1 readid();//���ļ��ж������Ա�˺����룬������ʦ����Ϣ���� 
LinkList1 readid1();//���ļ��ж����ҵ��˺����룬 �����ҵ���Ϣ������ 
LinkList readmy();//�����ҽ���飬���ض�����ͼ������ 
LinkList priceUp(LinkList head);//���۸�������ң��β�ΪҪ��������������ź����ͼ������ 


int main()
{
    char id[8], passworld[16];
    int n1, n2;
    while(1)
    {
    	
    system("color F0");
    printf("��ӭ����ΰ��ĺ��Ϲ�ҵ��ѧͼ��ݣ����ǻ���������õľ�Ʒͼ�飺\n");
    printf("�����ǲ˵���\n");
    printf("*******************************\n");
    printf("*****  �������Լ�����ݣ�******\n");
    printf("*****  ��ʦ������1��     ******\n");
    printf("*****  ѧ��������2��     ******\n");
    printf("*****  �ο�������3��     ******\n");
    printf("*****  �뿪������0��     ******\n");
    printf("*******************************\n");
    printf("*****����������ѡ��:     ******\n");
    scanf("%d", &n1);
    switch(n1)
    {
    	case 1: teacher();break;
    	case 2: student();break;
    	case 3: tour();break;
    	case 0: exit(0);
	}
    }
			
	return 0;
}
void teacher()
{
	system("cls");
	printf("*******************************************\n");
	printf("*****    ��¼������1��               ******\n");
	printf("*****    ע��������2��               ******\n");
	printf("*****    �뿪������0��               ******\n");
	printf("*******************************************\n");	
	int n1;
	scanf("%d", &n1);
	switch(n1)
	{
		case 1:login1();system("cls");break;
		case 2:creatid1();break;
		case 0:return;

	}
} 
void login1()
{
    char id[20], passworld[20],id1[20], passworld1[20], phone1[15];
    printf("��ӭ������½���棺\n");
    printf("�������˺ţ�\n");    
    scanf("%s", id);
    printf("���������룺\n");
    int i, t=0;
    for(i=0;i<20;i++)
    {
    	passworld[i]=getch();
    	if(passworld[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld[i]='\0';
	puts(passworld); 
    FILE *fp;
    if((fp=fopen("teachid.txt","a+"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
    for(;!feof(fp);)
    {
    	fscanf(fp,"%s%s%s\n", id1,phone1, passworld1);
    	if(strcmp(id,id1)==0&&strcmp(passworld,passworld1)==0)
    	{
    		t=1;
    	} 
    		    
			
    } 		
    if(fclose(fp))
			    {
			    	printf("can not close this file!\n");
			    	exit(0);
			    }
		int  n, s;
		if(t==0){
			printf("�������!!\n");
			printf("��������������1��\n");
			printf("ע���˺�������2��\n");
			printf("�˳�������0��\n");
			scanf("%d", &s);
			switch(s) 
			{
				case 1: login1();break;
				case 2:creatid1();break;
				case 0:return;
				default :printf("����������������룺\n");login1();
			}
			
			
		} 
		
		printf("******    ��½�ɹ�����ѡ�����Ĳ�����     *****\n");
    		LinkList head;
			head=(LinkList)malloc(sizeof(LNode));
			head->next=NULL;
		while(1)
		{
			printf("*******************************************\n"); 
			printf("*****  ͼ����Ϣ����ϵͳ�˵���       *******\n");
			printf("*****  ¼��ͼ����Ϣ������1��        *******\n");
			printf("*****  ��ѯͼ����Ϣ������2��        *******\n");
			printf("*****  ͼ����Ϣ���������3��        *******\n");
			printf("*****  ͼ����Ϣ��ɾ�����޸�������4��*******\n");
			printf("*****  ��Ϣͳ��������5��            *******\n"); 
			printf("*****  �޸ĸ�������������6��        *******\n");
			printf("*****  �޸�ѧ��������������7��      *******\n");
			printf("*****  �˳��밴0��                  *******\n");
			
			printf("*******************************************\n");
			printf("����������ѡ�񣬲��Իس�������\n");
			scanf("%d", &n);
			switch(n)
			{
				case 1:INPUT(head);write(head);break;
				case 2:FIND();break;
				case 3:READ();break;
				case 4:CHANGE();break;
				case 5:tongji();break;
				case 6:xiugaiziliao(id);break; 
				case 7:xiugaixuesheng();break;
				case 0:return;
				
			}
		}
	
     
}
void xiugaixuesheng()
{
	printf("��������Ҫ�޸ĵ�ѧ�����˺ţ�\n");
	char num[8];
	scanf("%s", num);
	xiugaiziliao1(num);
}
void creatid1()
{
//	system("cls");
	printf("��ӭ����ע��ҳ�棺\n"); 
    FILE *fp;   
    char id1[20], id[20],phone1[15], passworld1[20],phone[15], passworld[20],
	passworld2[20];
    if((fp=fopen("teachid.txt","a+"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}

    printf("�������˺�����\n");
    scanf("%s", id);
    for(;!feof(fp);)
    {
    	fscanf(fp,"%s%s%s", id1, phone1, passworld1);
    	if(strcmp(id1,id)==0)
    	{
    		printf("�û����Ѵ��ڣ����������룺\n");
    		creatid1();
		}
	}
    
    printf("������绰���룺\n");
    scanf("%s", phone);

    printf("���������룺\n");
    int i;
    for(i=0;i<20;i++)
    {
    	passworld1[i]=getch();
    	if(passworld1[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld1[i]='\0';
    
    printf("��ȷ�����룺\n");
    for(i=0;i<20;i++)
    {
    	passworld2[i]=getch();
    	if(passworld2[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld2[i]='\0';
    if(strcmp(passworld1,passworld2)==0)
    {
    	printf("ע��ɹ������μ��������룺\n");
    	fprintf(fp,"%s ", id);
    	fprintf(fp,"%s ", phone);
    	fprintf(fp,"%s\n", passworld1);
    	printf("ע��ɹ������μ��������룡������\n������½��\n");
	}
    
    else
    {
        printf("�������벻һ�£�������ע�᣺\n");
        creatid1();
    }
    if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
    login1(); 
}
void INPUT(LinkList head)
{
	LinkList p, rear=head;//�տ�ʼβָ���ǿյ� 
	int num;//�������ͼ����Ϣ 
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	printf("����ͼ����Ϣ������ͼ���ŵ���-1��ʾ�������\n");
	printf("����ͼ���ţ�");
	scanf("%d", &num);

	while(num!=-1)
	{
		printf("������ͼ������");
		scanf("%s", bookname);
		printf("������ͼ�����ߣ�");
		scanf("%s", author);

		printf("������ͼ������磺");
		scanf("%s", press);

		printf("������ͼ�����");
		scanf("%s", cate);

		printf("������ͼ�����ʱ�䣨�� �� �գ���");
		scanf("%d%d%d", &year,&mon, &day) ;

		printf("������ͼ��۸�");
		scanf("%lf", &price);

		printf("������ͼ��Ĳ�����");
		scanf("%d", &kucun);

		printf("������ͼ�������ٱ���");
		scanf("%d", &lend);

			
		//β�巨
		p=(LinkList)malloc(sizeof(LNode)); 
		p->num=num;
		strcpy(p->bookname,bookname);
		strcpy(p->author,author);
		strcpy(p->press,press);
		strcpy(p->cate,cate);
		p->year=year;
		p->mon=mon;
		p->day=day;
		p->price=price;
		p->kucun=kucun;
		p->lend=lend;
		rear->next=p;//�½ڵ�ָ��β 
		rear=p;//����rear 
		printf("����ͼ���ţ�");
		scanf("%d", &num);
	}
	rear->next=NULL;//βָ����Ϊ�� 
}
void write(LinkList head)
{
	paixu(head);//д֮ǰ������ 
	LinkList ptr=head->next;
	FILE *fp;
	if((fp=fopen("book.txt","w"))==NULL)//���ļ� 
	{
		printf("can not open this file!\n");
		exit(0);
	}
	while(ptr)//д���ļ� 
	{
		fprintf(fp,"%d %s %s %s %s %d %d %d %lf %d %d\n",ptr->num, ptr->bookname, ptr->author, ptr->press, ptr->cate, ptr->year, ptr->mon, ptr->day,
		ptr->price,ptr-> kucun, ptr->lend);
		ptr=ptr->next;
	}
	if(fclose(fp))//�ر��ļ� 
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
}
void writemy(LinkList head)
{
	paixu(head);
	LinkList ptr=head->next;
	FILE *fp;
	if((fp=fopen("mybook.txt","w"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	while(ptr)
	{
		fprintf(fp,"%d %s %s %s %s %d %d %d %lf %d\n",ptr->num, ptr->bookname, ptr->author, ptr->press, ptr->cate, ptr->year, ptr->mon, ptr->day,
		ptr->price, ptr->lend);
		ptr=ptr->next;
	}
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
}
LinkList read()
{
	FILE *fp;
	if((fp=fopen("book.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	LinkList head, p;
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;

	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon,
		&day, &price, &kucun, &lend);
		p=(LinkList)malloc(sizeof(LNode));
		p->num=num;
		strcpy(p->bookname,bookname);
		strcpy(p->author,author);
		strcpy(p->press,press);
		strcpy(p->cate,cate);
		p->year=year;
		p->mon=mon;
		p->day=day;
		p->price=price;
		p->kucun=kucun;
		p->lend=lend;
		p->next=head->next;
		head->next=p;
	}
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
    	
	return head;//���ض�������Ϣ 
} 
LinkList readmy()
{
	FILE *fp;
	if((fp=fopen("mybook.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int lend;
	LinkList head, p;
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;

	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d\n", &num, bookname, author, press, cate, &year, &mon,
		&day, &price, &lend);
		p=(LinkList)malloc(sizeof(LNode));
		p->num=num;
		strcpy(p->bookname,bookname);
		strcpy(p->author,author);
		strcpy(p->press,press);
		strcpy(p->cate,cate);
		p->year=year;
		p->mon=mon;
		p->day=day;
		p->price=price;
		p->lend=lend;
		p->next=head->next;
		head->next=p;
	}
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
    	
	return head;
} 
void FIND()
{
	while(1)
	{
		int n;
		printf("*******************************\n");
		printf("*****  �����߲�ѯ�밴1��  *****\n");
		printf("*****  ������ѯ�밴2��  *****\n");
		printf("*****  ���۸��ѯ�밴3��  *****\n"); 
		printf("*****  �˳��밴0��        *****\n");
		printf("*****************************\n");	
		scanf("%d", &n);
		switch(n)
		{
			case 1:find1();break;
			case 2:find2();break;
			case 3:find3();break;
			case 0:return;
		}
	}
	
}
void find1()//�����߲�ѯ 
{
	FILE *fp;
	if((fp=fopen("book.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	
	char author1[20];
	printf("������Ҫ��ѯ����������\n");
	scanf("%s", author1);
	int count=1;
	for(;!feof(fp);)
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon, &day,
		&price, &kucun, &lend);
		if(strstr(author,author1)!=NULL)//�Ƚ����Ҫ��Ѱ����Ϣ*
		{
		 
			printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);	
			count=0;
			return;		
		}
		
	}
	if(count)
	
		printf("�Ҳ��������ߣ�\n");
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
		printf("�����������������������1��");
			printf("����������0��\n");
			int n;
			scanf("%d", &n);
			switch(n)
			{
				case 1:find1();break;
				case 0:return;
			}
	
}
void find2()//������ѯ 
{
	FILE *fp;
	if((fp=fopen("book.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	
	char cate1[20];
	printf("������Ҫ��ѯ�����\n");
	scanf("%s", cate1);
	int count=1;
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon, &day,
		&price, &kucun, &lend);
		if(strstr(cate,cate1)!=NULL)/*�Ƚ����Ҫ��Ѱ����Ϣ*/ 
		{
			printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);	
			count=0;	
		}
	}
	if(count)
	{
			printf("�Ҳ��������\n");	
			
	fclose(fp);
			printf("��������������������1��");
			printf("����������0��\n");
			int n;
			scanf("%d", &n);
			switch(n)
			{
				case 1:find2();break;
				case 0:return;
			}
	}

}
void READ()//���ͼ�� 
{
	
	FILE *fp;
	if((fp=fopen("book.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	printf("ͼ����ϢΪ��\n"); 
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon,
		&day, &price, &kucun, &lend);
		printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);
	}
	if(fclose(fp))
	{
		printf("can not close this file!\n");
		exit(0);
	}
}
LinkList paixu(LinkList head)//��ѧ�Ŵӵ͵������� 
{
    LinkList temp1,temp2,q,p;
    for(q=head;q->next!=NULL;q=q->next)
        for(p=q->next;p->next!=NULL;p=p->next)
        {
            if(p->next->num<q->next->num)//����������� 
                if(q->next==p)
                {
                    temp1=p->next;
                    p->next=p->next->next;
                    temp1->next=q->next;
                    q->next=temp1;
                    p=temp1;
                }
                else//��������� 
                {
                    temp1=p->next;
                    temp2=q->next;
                    p->next=p->next->next;
                    q->next=q->next->next;
                    temp1->next=q->next;
                    q->next=temp1;
                    temp2->next=p->next;
                    p->next=temp2;
                }
        }
    return head;
}
void CHANGE()//�޸� 
{
	while(1)
	{
		printf("******************************************\n");
		printf("*****   ���������1��          ***********\n");
		printf("*****   ɾ��������2��          ***********\n");
		printf("*****   �޸�������3��          ***********\n");
		printf("*****   ������һ��������0��    ***********\n");
		printf("******************************************\n");
		int n;
		printf("\n����������ѡ��\n\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1: add();break;
			case 2: del(read());break;
			case 3: chan(read());break;
			case 0:return;
		}
	}
	
}
void   add()//��� 
{
	LinkList p, ptr=read(), q=ptr; 
	printf("��������Ҫ�����ͼ���ţ�����ͼ���ŵ���-1�ǽ�����\n");
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	scanf("%d", &num);

	if(num!=-1)
	{
		while(ptr)
		{
			if(ptr->num==num)
			{
				printf("��ӳɹ�����\n");
				ptr->kucun++; 
				write(q);
				return;
			}
			else
				ptr=ptr->next;	
		}
		ptr=read();
		printf("������ͼ������");
		scanf("%s", bookname);
		printf("������ͼ�����ߣ�");
		scanf("%s", author);
		printf("������ͼ������磺");
		scanf("%s", press);
		printf("������ͼ�����");
		scanf("%s", cate);
		printf("������ͼ�����ʱ�䣨�� �� �գ���");
		scanf("%d%d%d", &year,&mon, &day) ;
		printf("������ͼ��۸�");
		scanf("%lf", &price);
		printf("������ͼ��Ĳ�����");
		scanf("%d", &kucun);
		printf("������ͼ�������ٱ���");
		scanf("%d", &lend);
		p=(LinkList)malloc(sizeof(LNode));
		p->num=num;
		strcpy(p->bookname,bookname);
		strcpy(p->author,author);
		strcpy(p->press,press);
		strcpy(p->cate,cate);
		p->year=year;
		p->mon=mon;
		p->day=day;
		p->price=price;
		p->kucun=kucun;
		p->lend=lend;
		p->next=ptr->next;
		ptr->next=p;
		write(ptr);
		printf("��ӳɹ�!!\n");
	}
	
}
void add1(LinkList q)
{
	LinkList head=read(); 

		q->next=head->next;
		head->next=q;
		write(head);
	printf("\n�޸ĳɹ�����\n");
	
	
}
void del(LinkList head)
{
	LinkList  p=head,ptr; 
	ptr=p->next;
	printf("��������Ҫɾ����ͼ���ţ�\n");
	int num,t=1;
	scanf("%d", &num);
		while(p->next)
		{
			if(ptr->num==num)
			{
				t=0;
				printf("��ɾ����ͼ����ϢΪ��\n");
				printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",ptr->num, ptr->bookname, ptr->author, ptr->press, ptr->cate, ptr->year, ptr->mon, ptr->day,
				ptr->price, ptr->kucun, ptr->lend);
				printf("�Ƿ�Ҫɾ����ͼ�飺ɾ��������1��ȡ��������0��\n");
			int a;
			scanf("%d", &a);
			if(a==0) return;
			else
			break;
			}
			
			p=p->next;
			ptr=p->next;
		}		
			if(t==0)
			{
				p->next=ptr->next;
				free(ptr);
			} 	
		
		if(t)
		{
			printf("�Ҳ�����ͼ�飬���������룺\n");
			return;
		}
		write(head);
		printf("\n�޸ĳɹ�����\n");
		
}
void chan1(LinkList head)
{
	int num, t=1;
	double price;
	printf("������Ҫ�޸ĵ�ͼ���ţ�");
	scanf("%d", &num);
	
	LinkList  p=head->next;
	while(p)
	{
		if(p->num==num)
		{
			printf("��ͼ�����ϢΪ:\n"); 
			printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",p->num, p->bookname, p->author, p->press, p->cate, p->year, p->mon, p->day,
			p->price, p->kucun, p->lend);
			printf("������Ҫ�޸ĵļ۸�\n");
			scanf("%lf", &price);
			p->price=price;		
			t=0;								
		}
			p=p->next;
	}
		if(t)
		{
			printf("�����ڴ�ͼ�飬���������룺\n");
			return;
		}	
		write(head);
		printf("\n�޸ĳɹ�����\n");
}
void chan2(LinkList head)
{
	int num, kucun, t=1;
	printf("������Ҫ�޸ĵ�ͼ���ţ�");
	scanf("%d", &num);
	scanf("%d", &kucun);
	LinkList  p=head->next;
	while(p)
	{
		if(p->num==num)
		{
			printf("��ͼ�����ϢΪ��\n"); 
			printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",p->num, p->bookname, p->author, p->press, p->cate, p->year, p->mon, p->day,
			p->price, p->kucun, p->lend);
			printf("������Ҫ�޸ĵĿ�棺\n");
			scanf("%d", &kucun);
			p->kucun=kucun;		
			t=0;
						
			}
			p=p->next;
		}
		if(t)
		{
			printf("�����ڴ�ͼ�飬���������룺\n");
			return;
		}	
		write(head);
		printf("\n�޸ĳɹ�����\n");
}
void chan(LinkList head)
{
	printf("*********************************************\n");
	printf("*****      �޸�ͼ��۸������� 1��      *******\n");
	printf("*****      �޸�ͼ���������� 2��      *******\n");
	printf("*****      �������˵�������   0��      *******\n");
	printf("**********************************************\n");
	int n;
	scanf("%d", &n);
	LinkList  p=head->next; 
	switch(n)
	{
		case 1:chan1(head);	break; 
		case 2:chan2(head); break;
		case 0: return;
	}
	

}
void student()
{
	printf("*******************************************\n");
	printf("*****    ��¼������1��               ******\n");
	printf("*****    ע��������2��               ******\n");
	printf("*****    �뿪������0��               ******\n");
	printf("*******************************************\n");	
	int n1;
	scanf("%d", &n1);
	switch(n1)
	{
		case 1:login2();break;
		case 2:creatid2();break;
		case 0:return;
	}
}
void login2()
{
	system("cls");
    char id[20], passworld[20],id1[20], passworld1[20], phone1[15];
    printf("�������˺ţ�\n"); 
    scanf("%s", id);
    printf("���������룺\n");
    int i,t=0;
    for(i=0;i<20;i++)
    {
    	passworld[i]=getch();
    	if(passworld[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld[i]='\0';
    FILE *fp;
    if((fp=fopen("studentid.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
    
    while(!feof(fp))
    {
    	fscanf(fp,"%s%s%s\n", id1,phone1, passworld1);
    	if(strcmp(id,id1)==0&&strcmp(passworld,passworld1)==0)
    	{
    		t=1;
    	} 
    }
    	
    		    if(fclose(fp))
			    {
			    	printf("can not close this file!\n");
			    	exit(0);
			    }
    		
		int  n,s;
		if(t==0){
			printf("�������!!\n");
			printf("��������������1��\n");
			printf("ע���˺�������2��\n");
			printf("�˳�������0��\n");
			scanf("%d", &s);
			switch(s) 
			{
				case 1: login2();break;
				case 2:creatid2();break;
				case 0:return;
				default:printf("����������������룺\n");login2();
			}
			
			
		} 
		printf("******    ��½�ɹ�����ѡ�����Ĳ�����     *****\n");
    		LinkList head;
			head=(LinkList)malloc(sizeof(LNode));
			head->next=NULL;
		while(1)
		{
			printf("*****************************************************\n"); 
			printf("*****  ͼ����Ϣ����ϵͳ�˵���      			  *******\n");
			printf("*****  ����������1��                          *******\n");
			printf("*****  ��ѯͼ����Ϣ������2��        		  *******\n");
			printf("*****  �ҽ��ĵĵ�ͼ����Ϣ���������3��        *******\n");
			printf("*****  ����������4��		 				  *******\n");
			printf("*****  �޸ĸ�����Ϣ������5��                      *******\n");
			printf("*****  �˳��밴0��                  		  *******\n");
			printf("*****************************************************\n");
			printf("����������ѡ�񣬲��Իس�������\n");
			scanf("%d", &n);
			switch(n)
			{
				case 1:jieshu(read());break;
				case 2:FINDbook();break;
				case 3:READmine();break;
				case 4:huanshu(readmy());break;
				case 5:xiugaiziliao1(id1);break;
				case 0:return;
			}
		
	
	}
    printf("����������������룺\n");
    if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
    login2();      
}
void creatid2()
{
//	system("cls");
    FILE *fp;   
    char id1[20], id[20],phone1[15], passworld1[20],phone[15], passworld[20],
	passworld2[20];
    if((fp=fopen("studentid.txt","a+"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}

    printf("�������˺�����\n");
    scanf("%s", id);
    for(;!feof(fp);)
    {
    	fscanf(fp,"%s%s%s", id1, phone1, passworld1);
    	if(strcmp(id1,id)==0)
    	{
    		printf("�û����Ѵ��ڣ����������룺\n");
    		creatid1();
		}
	}
    
    printf("������绰���룺\n");
    scanf("%s", phone);
    
    printf("���������룺\n");
    int i;
    for(i=0;i<20;i++)
    {
    	passworld1[i]=getch();
    	if(passworld1[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld1[i]='\0';
    
    printf("��ȷ�����룺\n");
    for(i=0;i<20;i++)
    {
    	passworld2[i]=getch();
    	if(passworld2[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld2[i]='\0';
    if(strcmp(passworld1,passworld2)==0)
    {
    	printf("ע��ɹ������μ��������룺\n");
    	fprintf(fp,"%s ", id);
    	fprintf(fp,"%s ", phone);
    	fprintf(fp,"%s\n", passworld1);
	}
    
    else
    {
        printf("�������벻һ�£�������ע�᣺\n");
        creatid2();
    }
    if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
    login2(); 
}
void jieshu(LinkList head)
{
	LinkList p;
	LinkList head1;
	head1=(LinkList)malloc(sizeof(LNode));
	head1->next=NULL;
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	int t=1;
	printf("����Ҫ���ͼ����Ϣ������ͼ���ŵ���-1��ʾ�������\n");
	printf("����ͼ���ţ�");
	scanf("%d", &num);
	head=head->next;
	while(head)
	{
		if(head->num==num&&head->kucun>0)
		{
			t=0;
			printf("�����ĵ�ͼ����ϢΪ��\n");
				printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",head->num, head->bookname, head->author, head->press, head->cate, head->year, head->mon, head->day,
				head->price, head->kucun, head->lend);
				printf("�Ƿ�Ҫ���Ĵ�ͼ�飺��������1����������0��\n");
			int a;
			scanf("%d", &a);
			if(a==0) return;
			else{
			kucundel(read(),num);
			write(read());
			break;}
		}
		head=head->next;
	}
	if(head==NULL)
	{
		t=1;
		
	 } 
	 if(t==1){
	 	printf("�����ڴ�ͼ�飡����\n"); 
	 	return;
	 } 
	 if(t==0) printf("����ɹ������䰮ͼ�飡\n");
	putchar(10);
	FILE *fp;
    if((fp=fopen("mybook.txt","a"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	
		fprintf(fp,"%d ", head->num);
		
		fprintf(fp,"%s ", head->bookname);
		
		fprintf(fp,"%s ", head->author);
		
		fprintf(fp,"%s ", head->press);
		
		fprintf(fp,"%s ", head->cate);
		
		fprintf( fp, "%d %d %d ", head->year, head->mon, head->day);
		
		fprintf(fp,"%f ", head->price);
		
		
		fprintf(fp,"%d\n", 1);
		
	
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
}
void kucundel(LinkList head,int num)
{
	LinkList  p=head->next; 
	int lend;
		while(p)
		{
			if(p->num==num)
			{

				p->kucun--;
				p->lend++;				
			}
			p=p->next;
		}
		write(head);
}
void kucunadd(LinkList head,LinkList p)
{
	LinkList q;
	int lend;
	q=head->next;
		while(q)
		{
			if(q->num==p->num)
			{

				q->kucun++;
				q->lend--;	
				write(head);
				return;	
			}
			q=q->next;
		}
		
		if(q==NULL)
		{
			add1(p);
			return;
		}
		
}
void FINDbook()
{
	
	while(1)
	{
		system("cls");
		int n;
		printf("*******************************\n\n");
		printf("*****  �����߲�ѯ�밴1��  *****\n");
		printf("*****  ������ѯ�밴2��  *****\n");
		printf("*****  ���۸�����밴3��  *****\n");
		printf("*****  �˳��밴0��        *****\n");
		printf("*****************************\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:find1();break;
			case 2:find2();break;
			case 3:find3();break;
			case 0:return;
		}
	}
	
}
void find3()
{
	system("cls");
	while(1)
	{
		printf("*********************************************\n");
		printf("*****     ���۸�����������1��         *******\n");
		printf("*****     ���۸���������2��         *******\n");
		printf("*****     ����������0��               *******\n");
		printf("*********************************************\n");
		int n;
		printf("\n����������ѡ��\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1: print(priceUp(read()));break;
			case 2:print(priceDown(read()));break;
			case 0:return;
			
			
		}
	}
	
	
}
LinkList priceUp(LinkList head)
{
	LinkList temp1,temp2,q,p;
    for(q=head;q->next!=NULL;q=q->next)
        for(p=q->next;p->next!=NULL;p=p->next)
        {
            if(p->next->price<q->next->price)
                if(q->next==p)
                {
                    temp1=p->next;
                    p->next=p->next->next;
                    temp1->next=q->next;
                    q->next=temp1;
                    p=temp1;
                }
                else
                {
                    temp1=p->next;
                    temp2=q->next;
                    p->next=p->next->next;
                    q->next=q->next->next;
                    temp1->next=q->next;
                    q->next=temp1;
                    temp2->next=p->next;
                    p->next=temp2;
                }
        }
    return head;
	
	
	
	
}
LinkList priceDown(LinkList head)
{
	LinkList temp1,temp2,q,p;
    for(q=head;q->next!=NULL;q=q->next)
        for(p=q->next;p->next!=NULL;p=p->next)
        {
            if(p->next->price>q->next->price)
                if(q->next==p)
                {
                    temp1=p->next;
                    p->next=p->next->next;
                    temp1->next=q->next;
                    q->next=temp1;
                    p=temp1;
                }
                else
                {
                    temp1=p->next;
                    temp2=q->next;
                    p->next=p->next->next;
                    q->next=q->next->next;
                    temp1->next=q->next;
                    q->next=temp1;
                    temp2->next=p->next;
                    p->next=temp2;
                }
        }
    return head;
				
}
void print(LinkList head)
{
	system("cls");
	LinkList p=head->next;
	printf("ͼ����ϢΪ��\n");
	while(p)
	{		
		printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",p->num, p->bookname, p->author, p->press, p->cate, p->year, p->mon, p->day,
			p->price, p->kucun, p->lend);		
								
		p=p->next;
	}
}
void READmine()
{
	FILE *fp;
	if((fp=fopen("mybook.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	printf("�ҽ��ĵ�ͼ�飺\n");
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d\n", &num, bookname, author, press, cate, &year, &mon,
		&day, &price, &lend);
		printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ�������%d��.\n",num, bookname, author, press, cate, year, mon, day,
			price,  lend);
	}
				
}
void huanshu(LinkList head)
{
	system("cls");
	LinkList p;
	LinkList head1;
	int num;
	int t=1;
	READmine();
	printf("����Ҫ����ͼ����Ϣ������ͼ���ŵ���-1��ʾ�������\n");
	printf("����ͼ���ţ�");
	scanf("%d", &num);
	head=head->next;
	while(head)
	{
		if(head->num==num)
		{
			t=0;
			printf("���黹��ͼ����ϢΪ��\n");
				printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",head->num, head->bookname, head->author, head->press, head->cate, head->year, head->mon, head->day,
				head->price, head->kucun, head->lend);
				printf("�Ƿ�Ҫ�黹��ͼ�飺��������1����������0��\n");
			int a;
			scanf("%d", &a);
			if(a==0) return;
			else{
			kucunadd(read(),head);
			mydel(readmy(),head);
			break;}
		}
		head=head->next;
	}
	if(t==1) printf("�����ڴ�ͼ�飡����\n"); 
	if(t==0) printf("����ɹ��� ��л����ʹ��.\n");
	if(head==NULL)
	{
		printf("û�н���飺\n");
		return;
	 } 
	putchar(10);
 
}
void mydel(LinkList head,LinkList p)
{
	LinkList  q=head; 
		while(q)
		{
			if(q->next->num==p->num)
			{
				q->next=p->next;
				free(p);
				break;
			}
			q=q->next;
		}
		writemy(head);
}
void tour()
{
	system("cls");
	while(1)
	{
		printf("********************************************\n");
		printf("*******    ���������1��              ******\n");
		printf("*******    ����������0��              ******\n");
		printf("********************************************\n");
		int n;
		printf("����������ѡ��\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1: liulan();break;
			case 0:return;
		}
	}
	
	
}
void liulan()
{
	system("cls");
	while(1)
	{
		int n;
		printf("*******************************\n");
		printf("*****  �����߲�ѯ�밴1��  *****\n");
		printf("*****  ������ѯ�밴2��  *****\n");
		printf("*****  ���۸��ѯ�밴3��  *****\n");
		printf("*****  ���ͼ����Ϣ�밴4��*****\n");
		printf("*****  �˳��밴0��        *****\n");
		printf("*****************************\n");	
		scanf("%d", &n);
		switch(n)
		{
			case 1:find1();break;
			case 2:find2();break;
			case 3:find3();break;
			case 4:READ();break;
			case 0:return;
		}
	
	}
	
	
}
void tongji()
{
	system("cls");
	while(1)
	{
		printf("*************************************************\n");
		printf("*****   ͳ�ƽ���϶���鼮��Ϣ������1��**********\n");
		printf("*****   ͳ�ƽ�����ٵ��鼮��Ϣ������2��**********\n");
		printf("*****   �˳�������0��                  **********\n");
		printf("*************************************************\n");
		printf("\n����������ѡ��\n");
		int n;
		scanf("%d", &n);
		switch(n)
		{
			case 1:tongji1();break;
			case 2:tongji2();break;
			case 0:return;
		}
		
				
	}	
	
}
void tongji1()
{
	system("cls");
	printf("��������Ҫ�����ڽ�����ٱ����ϵ�ͼ�飺\n");
	int s;
	scanf("%d", &s);
	FILE *fp;
	if((fp=fopen("book.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	int num;
	int t=0;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon,
		&day, &price, &kucun, &lend);
		if(lend>=s)
		{
			printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);
		}
		
	}
	if(t==0) printf("�����ڽ��%d�����ϵ�ͼ�飡\n");
	if(t==1) printf("���%d�����ϵ�ͼ��Ϊ��\n");
	if(fclose(fp))
	{
		printf("can not open this file!\n");
		exit(0);
	}
}
void tongji2()
{
	system("cls");
	printf("��������Ҫ�����ڽ�����ٱ����µ�ͼ�飺\n");
	int s;
	scanf("%d", &s);
	FILE *fp;
	if((fp=fopen("book.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	int t=0;
	int num;
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon,
		&day, &price, &kucun, &lend);
		if(lend<s)
		{
			t=1;
			printf("ͼ���ţ�%d��ͼ������%s�����ߣ�%s�������磺%s��ͼ�����%s ������ʱ�䣺%d��%d��%d�գ�ͼ��۸�%.2fԪ����棺%d���������%d��.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);
		}
		
	}
	if(t==0) printf("�����ڽ��%d�����µ�ͼ�飡\n");
	if(t==1) printf("���%d�����µ�ͼ��Ϊ��\n");
	if(fclose(fp))
	{
		printf("can not open this file!\n");
		exit(0);
	}
}
void xiugaiziliao(char *id1)
{
 system("cls");
	char phone[15],passworld[20], id[20];
	printf("�������޸ĺ�ĵ绰���룺\n") ;
	scanf("%s",phone);
	printf("�������޸ĺ�����룺\n");
	scanf("%s", passworld);
	LinkList1 head=readid();
	LinkList1 p=head->next;
	while(p)
	{
		if(strcmp(p->id,id1)==0)
		{
			strcpy(p->phone,phone);
			strcpy(p->passworld,passworld);
		}
		p=p->next;
	}
	writeid(head);		
}
void writeid(LinkList1 head)
{
	LinkList1 ptr=head->next;
	FILE *fp;
	if((fp=fopen("teachid.txt","w"))==NULL)
	{
		
		printf("can not open this file!\n");
		
		exit(0);
	}
	while(ptr)
	{
		fprintf(fp,"%s %s %s\n", ptr->id, ptr->phone, ptr->passworld);
		ptr=ptr->next;
	}
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
}
LinkList1 readid()
{
	
	FILE *fp;
	if((fp=fopen("teachid.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	char id[20],phone[20],passworld[20];
	LinkList1 head, p;
	head=(LinkList1)malloc(sizeof(LNode1));
	head->next=NULL;

	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s\n", id,phone,passworld);
		p=(LinkList1)malloc(sizeof(LNode1));
		strcpy(p->id,id);
		strcpy(p->phone,phone);
		strcpy(p->passworld,passworld);
		p->next=head->next;
		head->next=p;
	}
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
    	
	return head;
} 
void xiugaiziliao1(char *id1)
{
 system("cls");
	char phone[15],passworld[20], id[20];
	printf("�������޸ĺ�ĵ绰���룺\n") ;
	scanf("%s",phone);
	printf("�������޸ĺ�����룺\n");
	scanf("%s", passworld);
	LinkList1 head=readid1();
	LinkList1 p=head->next;
	while(p)
	{
		if(strcmp(p->id,id1)==0)
		{
			strcpy(p->phone,phone);
			strcpy(p->passworld,passworld);
		}
		p=p->next;
	}
	writeid1(head);	
	printf("�޸ĳɹ������μ�������Ϣ����\n");	
}
void writeid1(LinkList1 head)
{
	LinkList1 ptr=head->next;
	FILE *fp;
	if((fp=fopen("studentid.txt","w"))==NULL)
	{
		
		printf("can not open this file!\n");
		
		exit(0);
	}
	while(ptr)
	{
		fprintf(fp,"%s %s %s\n", ptr->id, ptr->phone, ptr->passworld);
		ptr=ptr->next;
	}
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
}
LinkList1 readid1()
{
	
	FILE *fp;
	if((fp=fopen("studentid.txt","r"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}
	char id[20],phone[20],passworld[20];
	LinkList1 head, p;
	head=(LinkList1)malloc(sizeof(LNode1));
	head->next=NULL;

	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s\n", id,phone,passworld);
		p=(LinkList1)malloc(sizeof(LNode1));
		strcpy(p->id,id);
		strcpy(p->phone,phone);
		strcpy(p->passworld,passworld);
		p->next=head->next;
		head->next=p;
	}
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
    	
	return head;
} 


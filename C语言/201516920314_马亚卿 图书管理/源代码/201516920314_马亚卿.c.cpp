#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct mima
{
	char id[8];//账号 
	char phone[12];//密码 
	char passworld[16];//密码 
	struct mima *next;//下个节点的地址 
};
struct book
{
	int num;//图书编号 
	char bookname[30];//图书名 
	char author[20];//作者 
	char press[30];//出版社 
	char cate[30];//类别 
	int year, mon, day;//出版时间 
	double price;//图书价格 
	int kucun;//库存量 
	int  lend;//借出量 
	struct book *next;//下个节点的地址 
};
typedef struct book LNode, *LinkList;
typedef struct mima LNode1, *LinkList1;

void creatid1();//图书结构的建立
void liulan();//浏览图书
void login1();//管理员登录
void FIND();//查找
void find1();//按类别查找
void find2();//按作者查找
void find3();//按价格查找
void READ();//浏览图书
void CHANGE();//修改图书信息
void chan1(LinkList head);
void chan2(LinkList head);
void teacher();//老师菜单
void student();//学生菜单
void login2();//学生登录
void creatid2();//学生注册
void FINDbook();//查找图书
void tour();//游客菜单
void  add();//添加图书
void READmine();//浏览我的图书
void tongji();//统计信息
void tongji2();//按借出最多的统计
void tongji1();//按最少的统计
void xiugaixuesheng();
void INPUT(LinkList head);//插入图书，形参为要插入的链表 
void jieshu(LinkList head);//借书菜单，形参为图书的链表 
void huanshu(LinkList head);//还书菜单，形参为图书的链表 
void write(LinkList head);//向图书文件写入，形参为要写入文件的链表 
void writemy(LinkList head);//向我的图书写入，形参为 我借的图书的链表 
void writeid(LinkList1 head);//把管理员的信息写入文件，形参为老师的信息的链表 
void writeid1(LinkList1 head);//把我的信息写入文件， 形参为老我的信息的链表 
void mydel(LinkList head,LinkList p);//删除我借的图书，形参分别为，我的图书的链表，要删除的图书 
void del(LinkList head);//删除图书，形参为图书链表 
void chan(LinkList head);//修改图书信息，形参为图书链表 
void kucundel(LinkList head,int num);//库存减少，形参分别为图书链表和图书编号 
void print(LinkList head);//输出图书信息，形参为图书链表 
void xiugaiziliao(char *id1);//修改管理员的资料，形参为老师的id 
void xiugaiziliao1(char *id1);//修改我的资料，形参为 我的id 
LinkList priceDown(LinkList head);//按价格降序查找，形参为图书链表，返回排序好的链表 
LinkList paixu(LinkList head);//按图书编号从小到大排序， 形参为图书链表，返回排序好的链表
LinkList read();//从文件中读入图书，返回一个图书链表 
LinkList1 readid();//从文件中读入管理员账号密码，返回老师的信息链表 
LinkList1 readid1();//从文件中读入我的账号密码， 返回我的信息的链表 
LinkList readmy();//查找我借的书，返回读出的图书链表 
LinkList priceUp(LinkList head);//按价格升序查找，形参为要排序的链表，返回排好序的图书链表 


int main()
{
    char id[8], passworld[16];
    int n1, n2;
    while(1)
    {
    	
    system("color F0");
    printf("欢迎来到伟大的河南工业大学图书馆，我们会给你最有用的精品图书：\n");
    printf("以下是菜单：\n");
    printf("*******************************\n");
    printf("*****  请输入自己的身份：******\n");
    printf("*****  教师请输入1：     ******\n");
    printf("*****  学生请输入2：     ******\n");
    printf("*****  游客请输入3：     ******\n");
    printf("*****  离开请输入0：     ******\n");
    printf("*******************************\n");
    printf("*****请输入您的选择:     ******\n");
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
	printf("*****    登录请输入1：               ******\n");
	printf("*****    注册请输入2：               ******\n");
	printf("*****    离开请输入0：               ******\n");
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
    printf("欢迎来到登陆界面：\n");
    printf("请输入账号：\n");    
    scanf("%s", id);
    printf("请输入密码：\n");
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
			printf("输入错误!!\n");
			printf("继续输入请输入1：\n");
			printf("注册账号请输入2：\n");
			printf("退出请输入0：\n");
			scanf("%d", &s);
			switch(s) 
			{
				case 1: login1();break;
				case 2:creatid1();break;
				case 0:return;
				default :printf("输入错误，请重新输入：\n");login1();
			}
			
			
		} 
		
		printf("******    登陆成功，请选择您的操作：     *****\n");
    		LinkList head;
			head=(LinkList)malloc(sizeof(LNode));
			head->next=NULL;
		while(1)
		{
			printf("*******************************************\n"); 
			printf("*****  图书信息管理系统菜单：       *******\n");
			printf("*****  录入图书信息请输入1：        *******\n");
			printf("*****  查询图书信息请输入2：        *******\n");
			printf("*****  图书信息浏览请输入3：        *******\n");
			printf("*****  图书信息的删除与修改请输入4：*******\n");
			printf("*****  信息统计请输入5：            *******\n"); 
			printf("*****  修改个人资料请输入6：        *******\n");
			printf("*****  修改学生的密码请输入7：      *******\n");
			printf("*****  退出请按0：                  *******\n");
			
			printf("*******************************************\n");
			printf("请输入您的选择，并以回车结束：\n");
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
	printf("请输入需要修改的学生的账号：\n");
	char num[8];
	scanf("%s", num);
	xiugaiziliao1(num);
}
void creatid1()
{
//	system("cls");
	printf("欢迎来到注册页面：\n"); 
    FILE *fp;   
    char id1[20], id[20],phone1[15], passworld1[20],phone[15], passworld[20],
	passworld2[20];
    if((fp=fopen("teachid.txt","a+"))==NULL)
	{
		printf("can not open this file!\n");
		exit(0);
	}

    printf("请输入账号名：\n");
    scanf("%s", id);
    for(;!feof(fp);)
    {
    	fscanf(fp,"%s%s%s", id1, phone1, passworld1);
    	if(strcmp(id1,id)==0)
    	{
    		printf("用户名已存在，请重新输入：\n");
    		creatid1();
		}
	}
    
    printf("请输入电话号码：\n");
    scanf("%s", phone);

    printf("请输入密码：\n");
    int i;
    for(i=0;i<20;i++)
    {
    	passworld1[i]=getch();
    	if(passworld1[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld1[i]='\0';
    
    printf("请确定密码：\n");
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
    	printf("注册成功，请牢记您的密码：\n");
    	fprintf(fp,"%s ", id);
    	fprintf(fp,"%s ", phone);
    	fprintf(fp,"%s\n", passworld1);
    	printf("注册成功，请牢记您的密码！！！！\n请您登陆：\n");
	}
    
    else
    {
        printf("两次密码不一致，请重新注册：\n");
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
	LinkList p, rear=head;//刚开始尾指针是空的 
	int num;//定义各种图书信息 
	char bookname[30];
	char author[20];
	char press[30];
	char cate[30];
	int year, mon, day;
	double price;
	int kucun;
	int lend;
	printf("输入图书信息，输入图书编号等于-1表示输入结束\n");
	printf("输入图书编号：");
	scanf("%d", &num);

	while(num!=-1)
	{
		printf("请输入图书名：");
		scanf("%s", bookname);
		printf("请输入图书作者：");
		scanf("%s", author);

		printf("请输入图书出版社：");
		scanf("%s", press);

		printf("请输入图书类别：");
		scanf("%s", cate);

		printf("请输入图书出版时间（年 月 日）：");
		scanf("%d%d%d", &year,&mon, &day) ;

		printf("请输入图书价格：");
		scanf("%lf", &price);

		printf("请输入图书的册数：");
		scanf("%d", &kucun);

		printf("请输入图书借出多少本：");
		scanf("%d", &lend);

			
		//尾插法
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
		rear->next=p;//新节点指向尾 
		rear=p;//更新rear 
		printf("输入图书编号：");
		scanf("%d", &num);
	}
	rear->next=NULL;//尾指针置为空 
}
void write(LinkList head)
{
	paixu(head);//写之前先排序 
	LinkList ptr=head->next;
	FILE *fp;
	if((fp=fopen("book.txt","w"))==NULL)//打开文件 
	{
		printf("can not open this file!\n");
		exit(0);
	}
	while(ptr)//写入文件 
	{
		fprintf(fp,"%d %s %s %s %s %d %d %d %lf %d %d\n",ptr->num, ptr->bookname, ptr->author, ptr->press, ptr->cate, ptr->year, ptr->mon, ptr->day,
		ptr->price,ptr-> kucun, ptr->lend);
		ptr=ptr->next;
	}
	if(fclose(fp))//关闭文件 
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
    	
	return head;//返回读出的信息 
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
		printf("*****  按作者查询请按1：  *****\n");
		printf("*****  按类别查询请按2：  *****\n");
		printf("*****  按价格查询请按3：  *****\n"); 
		printf("*****  退出请按0：        *****\n");
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
void find1()//按作者查询 
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
	printf("请输入要查询的作者名：\n");
	scanf("%s", author1);
	int count=1;
	for(;!feof(fp);)
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon, &day,
		&price, &kucun, &lend);
		if(strstr(author,author1)!=NULL)//比较输出要查寻的信息*
		{
		 
			printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);	
			count=0;
			return;		
		}
		
	}
	if(count)
	
		printf("找不到该作者：\n");
	if(fclose(fp))
    {
    	printf("can not close this file!\n");
    	exit(0);
    }
		printf("继续按照作者则查找请输入1：");
			printf("返回请输入0：\n");
			int n;
			scanf("%d", &n);
			switch(n)
			{
				case 1:find1();break;
				case 0:return;
			}
	
}
void find2()//按类别查询 
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
	printf("请输入要查询的类别：\n");
	scanf("%s", cate1);
	int count=1;
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon, &day,
		&price, &kucun, &lend);
		if(strstr(cate,cate1)!=NULL)/*比较输出要查寻的信息*/ 
		{
			printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);	
			count=0;	
		}
	}
	if(count)
	{
			printf("找不到该类别：\n");	
			
	fclose(fp);
			printf("继续按照类别查找请输入1：");
			printf("返回请输入0：\n");
			int n;
			scanf("%d", &n);
			switch(n)
			{
				case 1:find2();break;
				case 0:return;
			}
	}

}
void READ()//浏览图书 
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
	printf("图书信息为：\n"); 
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%s%s%s%d%d%d%lf%d%d\n", &num, bookname, author, press, cate, &year, &mon,
		&day, &price, &kucun, &lend);
		printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);
	}
	if(fclose(fp))
	{
		printf("can not close this file!\n");
		exit(0);
	}
}
LinkList paixu(LinkList head)//按学号从低到高排序 
{
    LinkList temp1,temp2,q,p;
    for(q=head;q->next!=NULL;q=q->next)
        for(p=q->next;p->next!=NULL;p=p->next)
        {
            if(p->next->num<q->next->num)//如果两书相邻 
                if(q->next==p)
                {
                    temp1=p->next;
                    p->next=p->next->next;
                    temp1->next=q->next;
                    q->next=temp1;
                    p=temp1;
                }
                else//如果不想临 
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
void CHANGE()//修改 
{
	while(1)
	{
		printf("******************************************\n");
		printf("*****   添加请输入1：          ***********\n");
		printf("*****   删除请输入2：          ***********\n");
		printf("*****   修改请输入3：          ***********\n");
		printf("*****   返回上一层请输入0：    ***********\n");
		printf("******************************************\n");
		int n;
		printf("\n请输入您的选择：\n\n");
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
void   add()//添加 
{
	LinkList p, ptr=read(), q=ptr; 
	printf("请输入需要插入的图书编号：（当图书编号等于-1是结束）\n");
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
				printf("添加成功！！\n");
				ptr->kucun++; 
				write(q);
				return;
			}
			else
				ptr=ptr->next;	
		}
		ptr=read();
		printf("请输入图书名：");
		scanf("%s", bookname);
		printf("请输入图书作者：");
		scanf("%s", author);
		printf("请输入图书出版社：");
		scanf("%s", press);
		printf("请输入图书类别：");
		scanf("%s", cate);
		printf("请输入图书出版时间（年 月 日）：");
		scanf("%d%d%d", &year,&mon, &day) ;
		printf("请输入图书价格：");
		scanf("%lf", &price);
		printf("请输入图书的册数：");
		scanf("%d", &kucun);
		printf("请输入图书借出多少本：");
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
		printf("添加成功!!\n");
	}
	
}
void add1(LinkList q)
{
	LinkList head=read(); 

		q->next=head->next;
		head->next=q;
		write(head);
	printf("\n修改成功！！\n");
	
	
}
void del(LinkList head)
{
	LinkList  p=head,ptr; 
	ptr=p->next;
	printf("请输入需要删除的图书编号：\n");
	int num,t=1;
	scanf("%d", &num);
		while(p->next)
		{
			if(ptr->num==num)
			{
				t=0;
				printf("所删除的图书信息为：\n");
				printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",ptr->num, ptr->bookname, ptr->author, ptr->press, ptr->cate, ptr->year, ptr->mon, ptr->day,
				ptr->price, ptr->kucun, ptr->lend);
				printf("是否要删除此图书：删除请输入1，取消请输入0！\n");
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
			printf("找不到此图书，请重新输入：\n");
			return;
		}
		write(head);
		printf("\n修改成功！！\n");
		
}
void chan1(LinkList head)
{
	int num, t=1;
	double price;
	printf("请输入要修改的图书编号：");
	scanf("%d", &num);
	
	LinkList  p=head->next;
	while(p)
	{
		if(p->num==num)
		{
			printf("此图书的信息为:\n"); 
			printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",p->num, p->bookname, p->author, p->press, p->cate, p->year, p->mon, p->day,
			p->price, p->kucun, p->lend);
			printf("请输入要修改的价格：\n");
			scanf("%lf", &price);
			p->price=price;		
			t=0;								
		}
			p=p->next;
	}
		if(t)
		{
			printf("不存在此图书，请重新输入：\n");
			return;
		}	
		write(head);
		printf("\n修改成功！！\n");
}
void chan2(LinkList head)
{
	int num, kucun, t=1;
	printf("请输入要修改的图书编号：");
	scanf("%d", &num);
	scanf("%d", &kucun);
	LinkList  p=head->next;
	while(p)
	{
		if(p->num==num)
		{
			printf("此图书的信息为：\n"); 
			printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",p->num, p->bookname, p->author, p->press, p->cate, p->year, p->mon, p->day,
			p->price, p->kucun, p->lend);
			printf("请输入要修改的库存：\n");
			scanf("%d", &kucun);
			p->kucun=kucun;		
			t=0;
						
			}
			p=p->next;
		}
		if(t)
		{
			printf("不存在此图书，请重新输入：\n");
			return;
		}	
		write(head);
		printf("\n修改成功！！\n");
}
void chan(LinkList head)
{
	printf("*********************************************\n");
	printf("*****      修改图书价格请输入 1：      *******\n");
	printf("*****      修改图书库存请输入 2：      *******\n");
	printf("*****      返回主菜单请输入   0：      *******\n");
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
	printf("*****    登录请输入1：               ******\n");
	printf("*****    注册请输入2：               ******\n");
	printf("*****    离开请输入0：               ******\n");
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
    printf("请输入账号：\n"); 
    scanf("%s", id);
    printf("请输入密码：\n");
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
			printf("输入错误!!\n");
			printf("继续输入请输入1：\n");
			printf("注册账号请输入2：\n");
			printf("退出请输入0：\n");
			scanf("%d", &s);
			switch(s) 
			{
				case 1: login2();break;
				case 2:creatid2();break;
				case 0:return;
				default:printf("输入错误！请重新输入：\n");login2();
			}
			
			
		} 
		printf("******    登陆成功，请选择您的操作：     *****\n");
    		LinkList head;
			head=(LinkList)malloc(sizeof(LNode));
			head->next=NULL;
		while(1)
		{
			printf("*****************************************************\n"); 
			printf("*****  图书信息管理系统菜单：      			  *******\n");
			printf("*****  借书请输入1：                          *******\n");
			printf("*****  查询图书信息请输入2：        		  *******\n");
			printf("*****  我借阅的的图书信息浏览请输入3：        *******\n");
			printf("*****  还书请输入4：		 				  *******\n");
			printf("*****  修改个人信息请输入5：                      *******\n");
			printf("*****  退出请按0：                  		  *******\n");
			printf("*****************************************************\n");
			printf("请输入您的选择，并以回车结束：\n");
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
    printf("输入错误，请重新输入：\n");
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

    printf("请输入账号名：\n");
    scanf("%s", id);
    for(;!feof(fp);)
    {
    	fscanf(fp,"%s%s%s", id1, phone1, passworld1);
    	if(strcmp(id1,id)==0)
    	{
    		printf("用户名已存在，请重新输入：\n");
    		creatid1();
		}
	}
    
    printf("请输入电话号码：\n");
    scanf("%s", phone);
    
    printf("请输入密码：\n");
    int i;
    for(i=0;i<20;i++)
    {
    	passworld1[i]=getch();
    	if(passworld1[i]=='\r') break;
    	printf("*");
	}
	putchar(10);
	passworld1[i]='\0';
    
    printf("请确定密码：\n");
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
    	printf("注册成功，请牢记您的密码：\n");
    	fprintf(fp,"%s ", id);
    	fprintf(fp,"%s ", phone);
    	fprintf(fp,"%s\n", passworld1);
	}
    
    else
    {
        printf("两次密码不一致，请重新注册：\n");
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
	printf("输入要借的图书信息，输入图书编号等于-1表示输入结束\n");
	printf("输入图书编号：");
	scanf("%d", &num);
	head=head->next;
	while(head)
	{
		if(head->num==num&&head->kucun>0)
		{
			t=0;
			printf("所借阅的图书信息为：\n");
				printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",head->num, head->bookname, head->author, head->press, head->cate, head->year, head->mon, head->day,
				head->price, head->kucun, head->lend);
				printf("是否要借阅此图书：是请输入1，否请输入0！\n");
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
	 	printf("不存在此图书！！！\n"); 
	 	return;
	 } 
	 if(t==0) printf("借书成功！请珍爱图书！\n");
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
		printf("*****  按作者查询请按1：  *****\n");
		printf("*****  按类别查询请按2：  *****\n");
		printf("*****  按价格查找请按3：  *****\n");
		printf("*****  退出请按0：        *****\n");
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
		printf("*****     按价格升序请输入1：         *******\n");
		printf("*****     按价格降序请输入2：         *******\n");
		printf("*****     返回请输入0：               *******\n");
		printf("*********************************************\n");
		int n;
		printf("\n请输入您的选择：\n");
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
	printf("图书信息为：\n");
	while(p)
	{		
		printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",p->num, p->bookname, p->author, p->press, p->cate, p->year, p->mon, p->day,
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
	printf("我借阅的图书：\n");
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
		printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；借出：%d本.\n",num, bookname, author, press, cate, year, mon, day,
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
	printf("输入要还的图书信息，输入图书编号等于-1表示输入结束\n");
	printf("输入图书编号：");
	scanf("%d", &num);
	head=head->next;
	while(head)
	{
		if(head->num==num)
		{
			t=0;
			printf("所归还的图书信息为：\n");
				printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",head->num, head->bookname, head->author, head->press, head->cate, head->year, head->mon, head->day,
				head->price, head->kucun, head->lend);
				printf("是否要归还此图书：是请输入1，否请输入0！\n");
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
	if(t==1) printf("不存在此图书！！！\n"); 
	if(t==0) printf("还书成功！ 感谢您的使用.\n");
	if(head==NULL)
	{
		printf("没有借此书：\n");
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
		printf("*******    浏览请输入1：              ******\n");
		printf("*******    返回请输入0：              ******\n");
		printf("********************************************\n");
		int n;
		printf("请输入您的选择：\n");
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
		printf("*****  按作者查询请按1：  *****\n");
		printf("*****  按类别查询请按2：  *****\n");
		printf("*****  按价格查询请按3：  *****\n");
		printf("*****  浏览图书信息请按4：*****\n");
		printf("*****  退出请按0：        *****\n");
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
		printf("*****   统计借书较多的书籍信息请输入1：**********\n");
		printf("*****   统计借书较少的书籍信息请输入2：**********\n");
		printf("*****   退出请输入0：                  **********\n");
		printf("*************************************************\n");
		printf("\n请输入您的选择：\n");
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
	printf("请输入需要查找在借出多少本以上的图书：\n");
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
			printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);
		}
		
	}
	if(t==0) printf("不存在借出%d本以上的图书！\n");
	if(t==1) printf("借出%d本以上的图书为：\n");
	if(fclose(fp))
	{
		printf("can not open this file!\n");
		exit(0);
	}
}
void tongji2()
{
	system("cls");
	printf("请输入需要查找在借出多少本以下的图书：\n");
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
			printf("图书编号：%d；图书名：%s；作者：%s；出版社：%s；图书类别：%s ；出版时间：%d年%d月%d日；图书价格：%.2f元；库存：%d本；借出：%d本.\n",num, bookname, author, press, cate, year, mon, day,
			price, kucun, lend);
		}
		
	}
	if(t==0) printf("不存在借出%d本以下的图书！\n");
	if(t==1) printf("借出%d本以下的图书为：\n");
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
	printf("请输入修改后的电话号码：\n") ;
	scanf("%s",phone);
	printf("请输入修改后的密码：\n");
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
	printf("请输入修改后的电话号码：\n") ;
	scanf("%s",phone);
	printf("请输入修改后的密码：\n");
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
	printf("修改成功，请牢记您的信息！！\n");	
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


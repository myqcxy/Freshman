/*住宿管理模块：包括客房预订、入住登记、客人续往、调房登记、退房结账
客房管理模块：包括客房设置、客房查询、宿费提醒
查询统计模块：包括预订房查询、住宿查询、退房查询、客房宿费统计
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
/*住宿管理模块：包括客房预订、
入住登记、客人续往、调房登记、退房结账*/
typedef struct patron//客官信息
{
	int guenum;//客人住房编号 
	char name[20];//客人姓名 
	char idnum[19];//客人身份证号
	char phone[12];//电话号码 
	char sex[5];//客人性别 
	int ruzhutime;//入住时间 
	int timelong;//租房时长 
}parton;
parton hash1[MAX];
typedef struct Guest//住房 
{
	int guenum;//客房编号 
	int maxnum;//最大入住人数 
	int shifouruzhu;//是否有人入住 
	double zujin;//房租 
	int num;//已入住人数 
}Guest;
Guest hash[MAX];
 
void InputRoom()
{
	int i;	
	printf("注意！！！是否继续，此操作会将原客房信息覆盖且无法恢复（Y/N）\n");
	char choice;
	scanf("%*c%c", &choice);
	if(choice!='Y'&&choice!='y')  return;
	Guest room;
	printf("请输入房间编号，（编号为-1时结束输入）\n");
	while(scanf("%d", &room.guenum),room.guenum!=-1)
	{
		i=room.guenum%1000;
		if(hash[i].guenum)
		{
			printf("已存在此房间！请重新输入！\n");
			continue;
		}
		printf("请输入最大入住人数\n");
		scanf("%d", &room.maxnum);
		printf("请输入租金：\n");
		scanf("%lf", &room.zujin);
		printf("请输入是否有人入住：(1=有；0=没有)\n");
		scanf("%d",&room.shifouruzhu);
		printf("请输入入住人数:\n");
		scanf("%d", &room.num);		
		hash[i]=room;
		printf("请输入房间编号，（编号为-1时结束输入）\n");
	}
	printf("房间编号 最大入住人数 租金 是否有人 入住人数\n");
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
		printf("****  重新输入客房信息请输入 1： ***\n");
		printf("****  修改客房信息请输入     2： ***\n");
		printf("****  添加客房信息请输入     3： ***\n");
		printf("****  删除客房信息请输入     4： ***\n");
		printf("****  返回上一菜单请输入     0： ***\n");
		printf("************************************\n");
		int n;
		printf("请输入您的选择：\n");
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
	printf("请输入要删除的客房编号：\n");
	scanf("%d", &num);
	i=num%MAX;
	if(!hash[i].guenum)
	{
		printf("此客房不存在！\n");
		return ;
	}
	printf("删除不可恢复，是否要删除！Y/N\n");
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
	printf("请输入需要添加的客房编号：\n");
	scanf("%d", &num);
	i=num%MAX;
	if(hash[i].guenum)
	{
		printf("此房间已存在！\n");
		return;
	}
		hash[i].guenum=num;
		printf("请输入最大入住人数\n");
		scanf("%d", &hash[i].maxnum);
		printf("请输入租金：\n");
		scanf("%lf", &hash[i].zujin);
		printf("请输入是否有人入住：(1=有；0=没有)\n");
		scanf("%d",&hash[i].shifouruzhu);
		printf("请输入入住人数:\n");
		scanf("%d", &hash[i].num);	
		printf("添加成功！\n");	
		writetotxt();
}
void xiugaikefang()
{
	printf("请输入需要修改的客房的编号：\n");
	int num,i,j;
	scanf("%d", &num);
	i=num%MAX;
	if(!hash[i].guenum)
	{
		printf("不存在此房间！\n");
		return;
	}
	printf("此房间信息为：\n");
		printf("房间编号 最大入住人数 租金 是否有人 入住人数\n");
	printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		printf("是否要修改 是（Y）否（N）\n");
		char c;
		scanf("%*c%c", &c);
		if(c!='y'&&c!='Y')
		{
			printf("修改取消！\n");
			return;
		}
		printf("请输入最大入住人数\n");
		scanf("%d", &hash[i].maxnum);
		printf("请输入租金：\n");
		scanf("%lf", &hash[i].zujin);
		printf("请输入是否有人入住：(1=有；0=没有)\n");
		scanf("%d",&hash[i].shifouruzhu);
		printf("请输入入住人数:\n");
		scanf("%d", &hash[i].num);	
		printf("修改成功！\n");	
		printf("修改后的信息为：\n");
		printf("此房间信息为：\n");
		printf("房间编号 最大入住人数 租金 是否有人 入住人数\n");
			printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		writetotxt();
}
void kefangxinxi()
{
	int i;
	printf("房间编号 最大入住人数 租金 是否有人 入住人数\n");
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
		printf("****  查找客房信息请输入     1： ***\n");
		printf("****  查找客人信息请输入     2： ***\n");
		printf("****  浏览所有住房信息请输入 3： ***\n");
		printf("****  浏览所有客人信息请输入 4： ***\n");
		printf("****  返回上一菜单请输入     0： ***\n");
		printf("************************************\n");
		int n;
		printf("请输入您的选择：\n");
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
		printf("住宿房间号：%d 姓名：%s 身份证号：%s 电话号码： %s 性别： %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
		j=1;
	}
	if(!j) printf("无人入住！\n");
}
void findkeren()
{
	int i,j=0;
	printf("*********************************\n");
	printf("****   按照房间查找请输入 1  ****\n");
	printf("****   按照姓名查找请输入 2  ****\n");
	printf("*********************************\n");
	printf("请输入您的选择：\n");
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
	printf("请输入客人姓名：\n");
	scanf("%s", name);
	int i,j=0;
	for(i=0;i<MAX;i++)
	if(!strcmp(hash1[i].name,name))
	{
		printf("住宿房间号：%d 姓名：%s 身份证号：%s 电话号码： %s 性别： %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
		j=1;
	}
	if(!j )printf("查无此人！！\n");
}
void findofroom()
{
	int i,num;
	printf("请输入房间编号：\n");
	scanf("%d", &num);
	i=num%MAX;
	if(!hash1[i].guenum)
	{
		printf("无人入住!!\n") ;
		return;
	}
	printf("住宿房间号：%d 姓名：%s 身份证号：%s 电话号码： %s 性别： %s \n",hash1[i].guenum,hash1[i].name,
		hash1[i].idnum,hash1[i].phone,hash1[i].sex);
	
}
void findkefang()
{
	int i,j=0;
	printf("空余客房为：\n");
	printf("房间编号 最大入住人数 租金 是否有人 入住人数\n");
	for(i=0;i<MAX;i++)
	if(!hash[i].shifouruzhu&&hash[i].guenum){
		printf("%d             %d       %.2f     %d        %d\n", hash[i].guenum,hash[i].maxnum,hash[i].zujin,
		hash[i].shifouruzhu,hash[i].num);
		j=1;
	}
	if(!j) printf("客房爆满！！！\n");
		
}
void zhusuguanli()
{
	printf("************************************\n");
	printf("*****   入住请输入    1：       ****\n");
	printf("*****   退房请输入    2：       ****\n");
	printf("*****   续房请输入    3：       ****\n");
	printf("*****   退出请输入    0：       ****\n");
	printf("************************************\n");
	int n;
	printf("请输入您的选择：\n");
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
	printf("请输入将要退房的房间号：\n");
	int num,i;
	scanf("%d", &num);
	i=num%MAX;
	if(!hash1[i].guenum)
	{
		printf("此房间没有租出！！\n");
		return;
	}
	hash1[i].guenum=0;
	write1totxt();
	hash[i].shifouruzhu=0;
	hash[i].num=0;
	writetotxt();
	printf("退房成功,欢迎下次光临！！！\n");
}
void ruzhu()
{
	printf("请输入需要预定的房间编号：\n");
	parton keren;
	scanf("%d", &keren.guenum);
	int i;
	i=keren.guenum%MAX;
	if(!hash[i].guenum)
	{
		printf("查无此房!!\n");
		return;
	}
	if(hash[i].shifouruzhu)
	{
		printf("此房间已经有人!\n");
		return;
	}
	int n;
	printf("请输入几人入住：\n");
	scanf("%d", &n);
	if(hash[i].maxnum<n)
	{
		printf("超过人数上限！！\n请重新输入：\n");
		return;
	}
		printf("请输入客人姓名：\n");
		scanf("%s", keren.name);
		printf("请输入客人身份证号：\n");
		scanf("%s", keren.idnum);
		printf("请输入客人电话号码：\n");
		scanf("%s", keren.phone);
		printf("请输入客人性别：\n");
		scanf("%s", keren.sex);
		printf("请输入入住时间：\n");
		scanf("%d", &keren.ruzhutime);
		printf("请输入入住时长：\n");
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
		printf("****    欢迎使用住宿管理系统    *****\n\n");
		printf("****    住宿管理请输入 1：      *****\n");
		printf("****    客房管理请输入 2：      *****\n");
		printf("****    查询统计请输入 3：      *****\n");
		printf("****    退出请输入     0：      *****\n\n");
		printf("*************************************\n");
		int choice;
		printf("请输入您的选择：\n");
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

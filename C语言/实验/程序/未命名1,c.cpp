#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
//定义的相关变量 
typedef struct student
{
 char name[38];
 int StuId;
 int Borrow;
 
}Stu; 
typedef struct DATE
{
 int year;
 int month;
 int day;
 
}Date;
typedef struct book 
{
 char ID[23];
 char Name[20];
 char Writer[30];
 char Type[45];
 char Publish[150]; 
 Date Time;
 double Price;
 int InNum;
 int OutNum; 
 struct book *next; 
  
}Book,*LinkList; 
int m;
//自定义函数 
void Save(LinkList head); //图书信息由链表保存在文件f1中
void  MangeMenu1(LinkList head);//管理员可操作系统菜单
void LoadBookNews(LinkList head);//图书信息的录入功能 【把图书馆存储的图书信息由链表存入到一个文件中 】
void LookBookNews(LinkList head);//游览图书信息 【把保存在文件中的图书信息输出到屏幕上供用户查看】 
void AddBookNews(LinkList head);//添加图书信息 
/*void DelBOOKNews(LinkList head);//删除图书信息【撤销现图书馆里的某图书】*/
int main()
{
 
 int select; 
 LinkList head;
 head=(LinkList)malloc(sizeof(Book));
 head->next=NULL;
 
 while(1)
 {  
  system("color F0");
  printf("   欢迎进入本校图书管理系统   \n");
  printf("说明:在本程序中欲执行某功能请根据菜单提示输入相应数字代码\n");
  printf("------------------\n");
  printf("------------------\n");
  printf("1:管理员登入      2:学生登入     0:退出现程序\n");
  printf("请选择你的身份\n");
  scanf("%d",&select);
  
  switch(select)
  {
   case 1:MangeMenu1(head);break;
   /*case 2:StuMenu2(head);break;*/ 
   case 0:exit(0);break; 
  } 
 }
  
 return 0; 
}
/*管理员可操作系统菜单*/
void  MangeMenu1(LinkList head) 
{ 
 system("cls");
 int select1; 
 while(1)
 {
  printf("*****************欢迎来到管理员系统*****************\n");
  printf("--------\n");
  printf("--------\n");
  printf("1:录入图书信息\n"); 
  printf("2:游览图书信息\n"); 
  printf("3:添加图书信息\n");
  printf("4:删除图书信息\n");
  printf("5:修改图书信息\n");
  printf("6:查询图书信息\n");
  printf("7:调序图书信息\n"); 
  printf("0:返回上个菜单\n");
  printf("-------\n");
  printf("-------\n"); 
  printf("请输入你要执行的操作代码\n");
  scanf("%d",&select1); 
  
  switch(select1)
  {
   case 1:LoadBookNews(head);break; 
   case 2:LookBookNews(head);break; 
   case 3:AddBookNews(head);break; 
   /*case 4:printf("请输入你要删除书本数目：\n");DelBOOKNews(head);break; */ 
   /*case 5:UpdateBookNews(head);break; 
   case 6:SearBookNews3(head) ;break;*/ 
   case 0:return;break; 
  
  } 
 }
}
/*图书信息由链表保存在文件f1中*/
void Save(LinkList head) 
{
 FILE *fp;
 LinkList p;
 
 if((fp=fopen("f1.txt","w"))==NULL) 
 {
  printf("File Open Fail\n");
  exit(0); 
 } 
 
 p=head->next; 
 while(p)
 {
  fprintf(fp,"%s  %s  %s  %s  %s  %d  %d  %d  %.2lf  %d  %d\n",p->ID,p->Name,p->Writer,p->Type,p->Publish,p->Time.year,p->Time.month,p->Time.day,p->Price,p->InNum,p->OutNum); 
  p=p->next; 
 } 
 
 fclose(fp);
 
}
/*图书信息的录入功能*/     //把图书馆存储的图书信息写入链表中然后由链表存入到一个文件
void LoadBookNews(LinkList head)
{
 FILE *fp;
 LinkList p,rear=head;
 char a[20]; 
 
 printf("请输入录入的图书信息,当停止录入时输入图书编号为-1\n");
 while(printf("请输入图书编号："),scanf("%s",a),strcmp(a,"-1") !=0)
 { 
 
  p=(LinkList)malloc(sizeof(Book)); 
  
  strcpy(p->ID,a);
  printf("请输入图书名；");
  scanf("%s",&p->Name); 
  printf("请输入作者；");
  scanf("%s",&p->Writer); 
  printf("请输入类型：");
  scanf("%s",&p->Type); 
  printf("请输入出版社；");
  scanf("%s",&p->Publish); 
  printf("请输入出版时间（年 月 日）：");
  scanf("%d%d%d",&p->Time.year,&p->Time.month,&p->Time.day); 
  printf("请输入价格：");
  scanf("%lf",&p->Price); 
  printf("请输入现库存：");
  scanf("%d",&p->InNum);
  printf("请输入借出量：");
  scanf("%d",&p->OutNum);
  
  rear->next=p;
  rear=p;    
 }
 rear->next=NULL;
 
 Save(head);
} 
/*游览图书信息 */      //把保存在文件中的图书信息输出到屏幕上供用户查看  
void LookBookNews(LinkList head)
{
 FILE *fp; 
 LinkList p,rear=head;
 
 if((fp=fopen("f1.txt","r"))==NULL) 
 {
  printf("File Open Fail\n");
  exit(0); 
 } 
 
 while(!feof(fp)) 
 { 
  p=(LinkList)malloc(sizeof(Book)); 
  fscanf(fp,"%s%s%s%s%s%d%d%d%lf%d%d\n",&p->ID,&p->Name,&p->Writer,&p->Type,&p->Publish,&p->Time.year,&p->Time.month,&p->Time.day,&p->Price,&p->InNum,&p->OutNum);
  rear->next=p;
  rear=p;   
 } 
 rear->next=NULL; 
 
 printf("输出依次为：编号--书名--作者---类型---出版社---出版时间---书价---现库存---借出量\n");
 printf("\n");
 p=head->next;
 while(p) 
 { 
  printf("%s---%s---%s---%s---%s---%d.%d.%d---%.2f---%d---%d\n",p->ID,p->Name,p->Writer,p->Type,p->Publish,p->Time.year,p->Time.month,p->Time.day,p->Price,p->InNum,p->OutNum); 
  p=p->next; 
 } 
 
 if(fclose(fp))
 {
  printf("File Close Fail\n");
  exit(0); 
 } 
}
/*添加图书信息 */                       //针对管理员 
void AddBookNews(LinkList head)
{
 char a[20];  
 FILE *fp;
 LinkList p,rear=head;
 
 printf("请输入你要添加的课本信息，当停止添加时输入图书编号为-1\n");
 while(printf("请输入图书编号："),scanf("%s",a),strcmp(a,"-1") !=0) 
 { 
  p=(LinkList)malloc(sizeof(Book));
  
  strcpy(p->ID,a);
  printf("请输入图书名；");
  scanf("%s",&p->Name); 
  printf("请输入作者；");
  scanf("%s",&p->Writer); 
  printf("请输入类型：");
  scanf("%s",&p->Type); 
  printf("请输入出版社；");
  scanf("%s",&p->Publish); 
  printf("请输入出版时间（年 月 日）：");
  scanf("%d%d%d",&p->Time.year,&p->Time.month,&p->Time.day); 
  printf("请输入价格：");
  scanf("%lf",&p->Price); 
  printf("请输入现库存：");
  scanf("%d",&p->InNum);
  printf("请输入借出量：");
  scanf("%d",&p->OutNum);
  
  
  rear->next=p;
  rear=p; 
 } 
 rear->next=NULL;
 
 if((fp=fopen("f1.txt","a"))==NULL)
 {
  printf("File Open Fail\n");
  exit(0); 
 } 
 
 p=head->next;
 while(p)
 { 
  fprintf(fp,"%s%s%s%s%s%d%d%d%f%d%d\n",p->ID,p->Name,p->Writer,p->Type,p->Publish,p->Time.year,p->Time.month,p->Time.day,p->Price,p->InNum,p->OutNum);
  p=p->next; 
 } 
 
 if(fclose(fp))
 {
  printf("File Close Fail\n");
  exit(0); 
 } 
}   
/*删除图书信息*/
/*void DelBOOKNews(LinkList head)
{ 
 int i;
 char b[34]; 
 LinkList p,rear=head,pre; 
 FILE *fp;
 
 if((fp=fopen("f1.txt","r"))==NULL)
 {
  printf("File Open Fail\n");
  exit(0);  
 } 
 while(!feof(fp)) 
 {
  p=(LinkList)malloc(sizeof(Book));
  fscanf(fp,"%s%s%s%s%s%d%d%d%f%d%d\n",p->ID,p->Name,p->Writer,p->Type,p->Publish,p->Time.year,p->Time.month,p->Time.day,p->Price,p->InNum,p->OutNum);
  
  rear->next=p;
  rear=p; 
 } 
 rear->next=NULL; 
 
 scanf("%d",&m);   //读入要删除的图书数目【撤销现图书馆里的某图书】 
 for(i=0;i<m;i++)
 {
  printf("请输入该图书编号\n");
  scanf("%s",b);
   
  pre=head;
  while(pre)
  {
   if(strcmp(b,pre->next->ID)==0) 
   {
    p=pre->next;
    printf("你要删除的图书信息为:\n");
    printf("%s%s%s%s%s%d%d%d%f%d%d\n",p->ID,p->Name,p->Writer,p->Type,p->Publish,p->Time.year,p->Time.month,p->Time.day,p->Price,p->InNum,p->OutNum);
    
    pre->next=p->next;
    free(p);
    break;
   } 
   pre=pre->next;
   if(!pre->next->next)
   {
    if(strcmp(pre->next->ID,b)==0)
    {
     p=pre->next;
     printf("你要删除的图书信息为:\n");
     printf("%s---%s---%s---%s---%s---%d---%d---%d---%f---%d---%d\n",p->ID,p->Name,p->Writer,p->Type,p->Publish,p->Time.year,p->Time.month,p->Time.day,p->Price,p->InNum,p->OutNum);
     
     pre->next=NULL;
     free(p);
     break;
    } 
   }  
  } 
 } 
} 
 */ 

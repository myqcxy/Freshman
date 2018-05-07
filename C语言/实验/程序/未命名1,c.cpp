#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
//�������ر��� 
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
//�Զ��庯�� 
void Save(LinkList head); //ͼ����Ϣ�����������ļ�f1��
void  MangeMenu1(LinkList head);//����Ա�ɲ���ϵͳ�˵�
void LoadBookNews(LinkList head);//ͼ����Ϣ��¼�빦�� ����ͼ��ݴ洢��ͼ����Ϣ��������뵽һ���ļ��� ��
void LookBookNews(LinkList head);//����ͼ����Ϣ ���ѱ������ļ��е�ͼ����Ϣ�������Ļ�Ϲ��û��鿴�� 
void AddBookNews(LinkList head);//���ͼ����Ϣ 
/*void DelBOOKNews(LinkList head);//ɾ��ͼ����Ϣ��������ͼ������ĳͼ�顿*/
int main()
{
 
 int select; 
 LinkList head;
 head=(LinkList)malloc(sizeof(Book));
 head->next=NULL;
 
 while(1)
 {  
  system("color F0");
  printf("   ��ӭ���뱾Уͼ�����ϵͳ   \n");
  printf("˵��:�ڱ���������ִ��ĳ��������ݲ˵���ʾ������Ӧ���ִ���\n");
  printf("------------------\n");
  printf("------------------\n");
  printf("1:����Ա����      2:ѧ������     0:�˳��ֳ���\n");
  printf("��ѡ��������\n");
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
/*����Ա�ɲ���ϵͳ�˵�*/
void  MangeMenu1(LinkList head) 
{ 
 system("cls");
 int select1; 
 while(1)
 {
  printf("*****************��ӭ��������Աϵͳ*****************\n");
  printf("--------\n");
  printf("--------\n");
  printf("1:¼��ͼ����Ϣ\n"); 
  printf("2:����ͼ����Ϣ\n"); 
  printf("3:���ͼ����Ϣ\n");
  printf("4:ɾ��ͼ����Ϣ\n");
  printf("5:�޸�ͼ����Ϣ\n");
  printf("6:��ѯͼ����Ϣ\n");
  printf("7:����ͼ����Ϣ\n"); 
  printf("0:�����ϸ��˵�\n");
  printf("-------\n");
  printf("-------\n"); 
  printf("��������Ҫִ�еĲ�������\n");
  scanf("%d",&select1); 
  
  switch(select1)
  {
   case 1:LoadBookNews(head);break; 
   case 2:LookBookNews(head);break; 
   case 3:AddBookNews(head);break; 
   /*case 4:printf("��������Ҫɾ���鱾��Ŀ��\n");DelBOOKNews(head);break; */ 
   /*case 5:UpdateBookNews(head);break; 
   case 6:SearBookNews3(head) ;break;*/ 
   case 0:return;break; 
  
  } 
 }
}
/*ͼ����Ϣ�����������ļ�f1��*/
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
/*ͼ����Ϣ��¼�빦��*/     //��ͼ��ݴ洢��ͼ����Ϣд��������Ȼ����������뵽һ���ļ�
void LoadBookNews(LinkList head)
{
 FILE *fp;
 LinkList p,rear=head;
 char a[20]; 
 
 printf("������¼���ͼ����Ϣ,��ֹͣ¼��ʱ����ͼ����Ϊ-1\n");
 while(printf("������ͼ���ţ�"),scanf("%s",a),strcmp(a,"-1") !=0)
 { 
 
  p=(LinkList)malloc(sizeof(Book)); 
  
  strcpy(p->ID,a);
  printf("������ͼ������");
  scanf("%s",&p->Name); 
  printf("���������ߣ�");
  scanf("%s",&p->Writer); 
  printf("���������ͣ�");
  scanf("%s",&p->Type); 
  printf("����������磻");
  scanf("%s",&p->Publish); 
  printf("���������ʱ�䣨�� �� �գ���");
  scanf("%d%d%d",&p->Time.year,&p->Time.month,&p->Time.day); 
  printf("������۸�");
  scanf("%lf",&p->Price); 
  printf("�������ֿ�棺");
  scanf("%d",&p->InNum);
  printf("������������");
  scanf("%d",&p->OutNum);
  
  rear->next=p;
  rear=p;    
 }
 rear->next=NULL;
 
 Save(head);
} 
/*����ͼ����Ϣ */      //�ѱ������ļ��е�ͼ����Ϣ�������Ļ�Ϲ��û��鿴  
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
 
 printf("�������Ϊ�����--����--����---����---������---����ʱ��---���---�ֿ��---�����\n");
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
/*���ͼ����Ϣ */                       //��Թ���Ա 
void AddBookNews(LinkList head)
{
 char a[20];  
 FILE *fp;
 LinkList p,rear=head;
 
 printf("��������Ҫ��ӵĿα���Ϣ����ֹͣ���ʱ����ͼ����Ϊ-1\n");
 while(printf("������ͼ���ţ�"),scanf("%s",a),strcmp(a,"-1") !=0) 
 { 
  p=(LinkList)malloc(sizeof(Book));
  
  strcpy(p->ID,a);
  printf("������ͼ������");
  scanf("%s",&p->Name); 
  printf("���������ߣ�");
  scanf("%s",&p->Writer); 
  printf("���������ͣ�");
  scanf("%s",&p->Type); 
  printf("����������磻");
  scanf("%s",&p->Publish); 
  printf("���������ʱ�䣨�� �� �գ���");
  scanf("%d%d%d",&p->Time.year,&p->Time.month,&p->Time.day); 
  printf("������۸�");
  scanf("%lf",&p->Price); 
  printf("�������ֿ�棺");
  scanf("%d",&p->InNum);
  printf("������������");
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
/*ɾ��ͼ����Ϣ*/
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
 
 scanf("%d",&m);   //����Ҫɾ����ͼ����Ŀ��������ͼ������ĳͼ�顿 
 for(i=0;i<m;i++)
 {
  printf("�������ͼ����\n");
  scanf("%s",b);
   
  pre=head;
  while(pre)
  {
   if(strcmp(b,pre->next->ID)==0) 
   {
    p=pre->next;
    printf("��Ҫɾ����ͼ����ϢΪ:\n");
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
     printf("��Ҫɾ����ͼ����ϢΪ:\n");
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

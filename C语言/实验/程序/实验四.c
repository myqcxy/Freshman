#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stud
{
	char id[13], name[21];
	int score1, score2, score3;
	int sum;
	struct stud *next;

};
void  CreateStuList(  struct  stud  *head );
void   PrintStuList(  struct  stud  *head );
void   StuListInsert(  struct  stud  *head);
void  StuListDelete(struct  stud  *head );
void   PrintStuList(  struct  stud  *head );
void   StaticScoreList(  struct  stud  *head );
struct stud *   paixu(struct stud *head); 
int main()
{
	struct stud *head;
	head=(struct stud *)malloc(sizeof(struct stud));
	head->next=NULL;
	
	
	int choice;
	while(1)
	{
		printf("=========================================\n");
		printf("*****  欢迎访问学生信息管理系统：********\n");
		printf("*****  1: 创建链表。             ******\n");
		printf("*****  2: 插入元素。             ******\n");
		printf("*****  3: 删除元素。             ******\n");
		printf("*****  4: 显示元素。             ******\n");
		printf("*****  5: 输出不及格学生的信息： ******\n");
		printf("*****  6: 排序                   ******\n");
		printf("*****  0：退出程序。             ******\n");
		printf("========================================\n");
		printf("请输入您的选择：\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :CreateStuList(head );break;
			case 2 :StuListInsert(head);break;
			case 3 :StuListDelete(head );break;
			case 4 :PrintStuList(head );break;
			case 5 :StaticScoreList(head );break;
			case 6 :head=paixu(head);break;
			case 0 :exit(0);break;
		}
}




	return 0;
}
void  CreateStuList(  struct  stud  *head )
{
	struct stud *p, *ptr=head;
	char id[13], name[21];
	int score1, score2, score3;
	int sum;

	while(	printf("请输入学号：\n"),scanf("%s", id), id[0]!='#')
	{
		printf("请输入姓名 和三门成绩：\n");
		scanf("%s%d%d%d", name, &score1, &score2, &score3);
		p=(struct stud *)malloc(sizeof(struct stud));
		strcpy(p->id,id);
		strcpy(p->name,name);
		p->score1=score1;
		p->score2=score2;
		p->score3=score3;
		p->sum=score1+score2+score3;
		ptr->next=p;
		ptr=p;
	}
	p->next=NULL;

}
void   PrintStuList(  struct  stud  *head )
{
	struct stud *p=head->next;
	while(p)
	{
		printf("学号：姓名：成绩：         总成绩：\n");
		printf("%s     %s %5d %5d %5d %5d\n", p->id, p->name, p->score1, p->score2, p->score3, p->sum);
		p=p->next;
	}


}
void   StuListInsert( struct  stud  *head)
{
	struct stud *p=head->next;
	printf("请输入需要插入的学生学号：");
	char id[13];
	scanf("%s", id);
	while(p)
	{
		if(strcmp(p->id,id)==0)
		{
			printf("输入的学号已经存在，请重新输入：");
		
			scanf("%s", id);	
			p=head->next;
		}
		else
			p=p->next;	
	}
	p=head->next;
	char name[21];
	int score1, score2, score3, sum;
	printf("请输入姓名和三门成绩：\n");
	scanf("%s", name);
	scanf("%d", &score1);
	scanf("%d", &score2);
	scanf("%d", &score3);
	p=(struct stud *)malloc(sizeof(struct stud));
	strcpy(p->id,id);
	p->score1=score1;
	p->score2=score2;
	p->score3=score3;
	p->sum=score1+score2+score3;
	p->next=head->next;
	head->next=p;
}
void  StuListDelete(struct  stud  *head )
{
	char id[13];
	printf("请输入要删除的学生的学号：");
	scanf("%s", &id);
	struct stud *p=head, *ptr;
	while(p)
	{
		printf("sdf,");
		ptr=p->next;
		if(strcmp(ptr->id,id)==0)
		{
			break;
		}
	}
		p->next=ptr->next;
		free(ptr);
	
}
void   StaticScoreList(  struct  stud  *head )
{
	head=head->next;
	while(head)
	{
		if(head->score1<60||head->score2<60||head->score3<60)
		{
			printf("%s  %s  %d  %d %d %d\n", head->id, head->name ,head->score1, head->score2, head->score3, head->sum);
		}
		head=head->next;
	}	
}
struct stud *  paixu(struct stud *head)
{
	
	struct stud *first, *tail, *p_min, *p, *min;
	first=NULL;
	while(head!=NULL)
	{
	 	for(p=head,min=head;p->next!=NULL;p=p->next)
		{
			if(strcmp(p->next->id,min->id)<0)
			{
		
				p_min=p;
				min=p->next;
			}
		}
			if (first == NULL) /*如果有序链表目前还是一个空链表*/
			{
				first = min; /*第一次找到键值最小的节点。*/
				tail = min; /*注意：尾指针让它指向最后的一个节点。*/
			}
			else /*有序链表中已经有节点*/
			{
				tail->next = min; /*把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
				tail = min; /*尾指针也要指向它。*/
			}
	
			/*第二件事*/
			if (min == head) /*如果找到的最小节点就是第一个节点*/
			{
				head = head->next; /*显然让head指向原head->next,即第二个节点，就OK*/
			}
			else /*如果不是第一个节点*/
			{
				p_min->next = min->next; /*前次最小节点的next指向当前min的next,这样就让min离开了原链表。*/
			}
		
}
	if (first != NULL) /*循环结束得到有序链表first*/
	{
		tail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL*/
	}
		head = first;
		return head;					
}

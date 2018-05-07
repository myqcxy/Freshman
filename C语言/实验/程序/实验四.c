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
		printf("*****  ��ӭ����ѧ����Ϣ����ϵͳ��********\n");
		printf("*****  1: ��������             ******\n");
		printf("*****  2: ����Ԫ�ء�             ******\n");
		printf("*****  3: ɾ��Ԫ�ء�             ******\n");
		printf("*****  4: ��ʾԪ�ء�             ******\n");
		printf("*****  5: ���������ѧ������Ϣ�� ******\n");
		printf("*****  6: ����                   ******\n");
		printf("*****  0���˳�����             ******\n");
		printf("========================================\n");
		printf("����������ѡ��\n");
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

	while(	printf("������ѧ�ţ�\n"),scanf("%s", id), id[0]!='#')
	{
		printf("���������� �����ųɼ���\n");
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
		printf("ѧ�ţ��������ɼ���         �ܳɼ���\n");
		printf("%s     %s %5d %5d %5d %5d\n", p->id, p->name, p->score1, p->score2, p->score3, p->sum);
		p=p->next;
	}


}
void   StuListInsert( struct  stud  *head)
{
	struct stud *p=head->next;
	printf("��������Ҫ�����ѧ��ѧ�ţ�");
	char id[13];
	scanf("%s", id);
	while(p)
	{
		if(strcmp(p->id,id)==0)
		{
			printf("�����ѧ���Ѿ����ڣ����������룺");
		
			scanf("%s", id);	
			p=head->next;
		}
		else
			p=p->next;	
	}
	p=head->next;
	char name[21];
	int score1, score2, score3, sum;
	printf("���������������ųɼ���\n");
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
	printf("������Ҫɾ����ѧ����ѧ�ţ�");
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
			if (first == NULL) /*�����������Ŀǰ����һ��������*/
			{
				first = min; /*��һ���ҵ���ֵ��С�Ľڵ㡣*/
				tail = min; /*ע�⣺βָ������ָ������һ���ڵ㡣*/
			}
			else /*�����������Ѿ��нڵ�*/
			{
				tail->next = min; /*�Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/
				tail = min; /*βָ��ҲҪָ������*/
			}
	
			/*�ڶ�����*/
			if (min == head) /*����ҵ�����С�ڵ���ǵ�һ���ڵ�*/
			{
				head = head->next; /*��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK*/
			}
			else /*������ǵ�һ���ڵ�*/
			{
				p_min->next = min->next; /*ǰ����С�ڵ��nextָ��ǰmin��next,��������min�뿪��ԭ����*/
			}
		
}
	if (first != NULL) /*ѭ�������õ���������first*/
	{
		tail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL*/
	}
		head = first;
		return head;					
}

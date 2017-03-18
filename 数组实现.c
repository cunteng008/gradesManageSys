#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PASSWORD "123456"/*��½����*/
#define MAX_PEOPLE 300/*�ܴ�����������*/
#define COURSES 5/*�γ̸���*/

struct student
{
    int num;/*ѧ��*/
	char name[20];/*����*/
	char sex[4];/*�Ա�*/
    double Math;/*��ѧ�ɼ�*/
	double Chinese;/*���ĳɼ�*/
	double English;/*Ӣ��ɼ�*/
    double Computer;/*���������*/
	double PE;/*�����ɼ�*/
	double average;/*ƽ����*/
	double gross;/*gross��һ��ѧ�����ſε��ܷ�*/                                                

};
typedef struct student STUDENT;
STUDENT stu[MAX_PEOPLE];
int n;/* ȫ�ֱ�����ʵ��ѧ������*/      
                                                          
struct course_data/*���Ƶĵ�����*/                                            
{
    double pass_rate;/*������*/
	double excellent_rate;/*������*/
	double average;/*�γ�ƽ����*/
	double standard_deviation;/*��׼��*/
	double highest_grade;/*��߷�*/
	double lowest_grade;/*��ͷ�*/
	
}Math,Chinese,English,Computer,PE;

void introduce();/*����*/
void Denglu(short *);/*��¼*/
int menu();/*���˵�*/
void get_initial_data();/*��ѧ���ṹ�帳��ֵ*/


void sort();/*������*/
void average_descending_sort();/*��ѧ����ƽ���ֽ�����*/
void num_ascending_sort();/*��ѧ�Ž�����*/
void Math_descending_sort();/*����ѧ�ɼ���������*/
void Chinese_descending_sort();
void English_descending_sort();
void Computer_descending_sort();
void PE_descending_sort();



void insert();/*���빦��*/
void insert_students_follow_student_num_ascending_order();/*��ѧ���������*/
void insert_students_follow_average_grades_descending_order();/*��ѧ����ƽ���ֽ������*/
void insert_on_the_end();/*ֻ��Ҫ�����ѧ�����ݷ���ĩβ*/

void search();/*����һ��ѧ�����ݹ���*/
void half_search_a_student_data_according_to_num();/*����ѧ�������۰����*/
void sequential_search_a_student_data_according_to_num();/*����ѧ��˳�����*/


void Delete_a_student_according_to_num();/*ɾ��һ��ѧ������*/

void calculate_all_courses_data();/*�������еĿγ�����*/

double  calculate_students_stardard_daviation();/*ѧ���ı�׼��*/
void demonstrate();/*���û�ɸѡҪչʾ��ѧ����������*/
void demonstrate_all_failing_at_least_a_course_students_data();/*�������*/
void demonstrate_all_excellent_students_datas();/*�����*/
void demonstrate_all_students_data();/*����ѧ����*/
void demonstrate_all_courses_data();/*���пγ̵�*/

void save_present_student_data();/*���浱ǰ�����ݵ��ļ�*/


int main()
{
    short times=1;/*��������ĵĴ���*/
	int choice;
	

    introduce();
    Denglu(&times);

	if(times>3)
		exit(0);
    printf("\n\n****��ӭ��½ѧ���ɼ�����ϵͳ****\n\n");

    do
	{
    
        choice=menu();
		switch(choice)
		{
		    
			case 1: get_initial_data();
				    break;
	        case 2: sort();
				    break;
			case 3: insert();
				    break;
			case 4: Delete_a_student_according_to_num();
				    break;
			case 5:search();
				   break;
			case 6:calculate_all_courses_data(); 
				   break;
			case 7:demonstrate();
                   break;
			case 8:save_present_student_data();
				   break;

        }
	}while(choice!=0);
	
	return 0;
}



/************************************************
Function:�Գ���ļ򵥽���
Parameter:��
**************************************************/
void introduce()
{
	printf("\n\n**************************************************************\n");
	    printf("** �ó����ѧ���ɼ������򡢲�ѯ�����롢ƽ���֡���׼��ȹ��ܣ�**\n");
		printf("** �����Լ�����ſε������ͷ֡�ƽ���֡����������ʡ���׼�**\n");
		printf("** (ȫ������.c)����Ϊȫ�����ݵı�����ļ����ƣ����ɵ�stu.c�� **\n");
		printf("** ��ŵ�ֻ�ж������ļ���ѧ�����ݣ��´�Ҫ���þͽ������C���� **\n");
		printf("** c���ļ��м��ɡ�                                           **\n");
		printf("**************************************************************\n");
}



/*******************************************
function:�����½����
parameter:һ���������������ŵĵ�ַ
*********************************************/
void Denglu(short *times)
{
	char password[11];
	
	printf("�������¼����(���볬�����ξͻ��Զ��˳�):");
	while(*times<=3)
	{
	  gets(password);
	  
	  if(strcmp(password,PASSWORD)==0)
		return;
	  else
		  printf("�������!\n");
	  
	 (*times)++;
	}
	

}


/**************************
function:���˵�
parameter:��
*****************************/   
int menu()
{
	int choice;

	

	printf("\n\n0----------�˳�\n");
    printf("\n1----------��ʼ��ѧ������");
    printf("\n2----------����\n");
	printf("\n3----------����ѧ����Ϣ\n");
    printf("\n4----------����ѧ��ɾ��һ��ѧ������\n");
    printf("\n5----------��ѧ�Ų���һ��ѧ����Ϣ\n");
	printf("\n6----------�������еĿγ�����\n");
    printf("\n7---------��ӡ����\n");
    printf("\n8---------���浱ǰ������\n");

    printf("������һ����(0 to 8):\n");
    do
	{
		scanf("%d",&choice);
	}while(choice<0||choice>8);
	puts("\n");

	return choice;
}


/***************************************
Function:���ѧ���ĳ�ʼ����
Parameter:��
****************************************/
void get_initial_data()
{
	int choice;
	printf("��ѡ��õ�ѧ�����ݵķ�ʽ\n");
	printf("1----------��������\n");
	printf("2----------�ļ�����\n");
	printf("0----------�˳�ѡ��:");
		do
		{
			scanf("%d",&choice);
			if(choice==0)
				return;
		}while(choice<1||choice>2);
	if(choice==1)
	{
	  int i;
	  char t[20];
      printf("������Ҫ�����ѧ������(less than %d)\n"
		    "������������Ϊ0�����˳�������ѡ��:",MAX_PEOPLE);
      do
	  {
	   scanf("%d%*c",&n);
	   if(n==0)
		   return;
	   if(n>MAX_PEOPLE)
		   printf("�ռ䲻��!");
	  }while(n<0||n>MAX_PEOPLE); /*��������ݸ������ܴ����������*/
      printf("\n����������ѧ����ѧ��+����+�Ա�+�����Ŀ�ĳɼ�\n"
		     "(�������ġ�Ӣ�������������)\n\n");
    
	  for(i=0;i<n;i++)
	  {
       gets(t); stu[i].num=atoi(t);/*���ַ���ת��Ϊ����*/
       
	   gets(stu[i].name);  
       
	   gets(stu[i].sex);   
	   
	   scanf("%lf %lf %lf %lf %lf",&stu[i].Math,&stu[i].Chinese,
		      &stu[i].English,&stu[i].Computer,&stu[i].PE);
       fflush(stdin); /*fflush(stdin)��������뻺��������*/  
       puts("******************");
       stu[i].gross=(stu[i].Math+stu[i].Chinese+stu[i].English+
		             stu[i].Computer+stu[i].PE);
	   stu[i].average=(stu[i].Math+stu[i].Chinese+stu[i].English+
		             stu[i].Computer+stu[i].PE)/COURSES;
	   
                                                                    
	   
	  }
	  printf("�������ݳɹ�!");
	}
	else if(choice==2)
    {
       FILE *out_fp;
	   int i=0;
	   char review;
       printf("\n\n�㽫��ѷ���C�̵���Ϊc���ļ��е�stu.c�ļ�����ǰ���벢������\n"
 		   "�����ݵ��룬��ȷ�Ͻ�����������Ƿ���ȷ?(Y��N):  ");  /*���Ҫ������ļ�*/
	   scanf("%c%*c",&review);
	   if(review=='N'||review=='n')
		return;
	    else
		{
		  if( (out_fp=fopen("C:\\c\\stu.c","rb")) !=NULL)
		  {
		    n=0;
		    while(fread(&stu[i],sizeof(STUDENT),1,out_fp)==1)
			{
			  n++;
			  if(n>=MAX_PEOPLE)  /*�ж�����������ݸ����Ƿ�������ֵ*/
			  {
				  printf("û���㹻λ�÷���ȫ��ѧ������,��Щ���ݿ��ܲ��ܵ������!");
				  return;         
			  }
			  i++;
			}
		  }
		}
		printf("����ѧ�����ݳɹ�!\n");
	}


}









/******************************
function:����˵�
parameter:��
**********************************/
void sort()
{
	
	int choice;
	printf("��ѡ������ķ�ʽ:\n");
	printf("%-30s","1.��ƽ���ֽ�����");  
    printf("%-30s","2.��ѧ��������");
	putchar('\n');                         
	printf("%-30s","3.����ѧ�ɼ�������");
	printf("%-30s","4.�����ĳɼ�������");
	putchar('\n');
	printf("%-30s","5.��Ӣ��ɼ�������");
	printf("%-30s","6.��������ɼ�������");
	putchar('\n');
	printf("%-30s","7.�������ɼ�������");
	printf("%-30s","0.�˳���ѡ��:");
	putchar('\n');
	do
	{
		scanf("%d",&choice);
		if(choice==0)
			return;
	}while(choice>7||choice<0);
	switch(choice)
	{
	   case 1:average_descending_sort();
		      break;
	   case 2:num_ascending_sort();
			  break;
	   case 3:Math_descending_sort();
			  break;
	   case 4:Chinese_descending_sort();
		      break;
	   case 5:English_descending_sort();
		      break;
	   case 6:Computer_descending_sort();
		      break;
	   case 7:PE_descending_sort();
		      break;
	}
}      


/******************************
function:��ѧ����ƽ���ֽ�����
parameter:��
*******************************/
void average_descending_sort()
{
	STUDENT temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if( (stu[k].average) < (stu[j].average) )
				k=j;
		}
		if(i!=k)
		{
			temp=stu[k];
			stu[k]=stu[i];
			stu[i]=temp;
		}
	}
  
}

/**************************
function:��ѧ��������
parameter:��
********************************/
void num_ascending_sort()
{
	STUDENT temp;     /*����ʱ�ṹ��������������*/
	int i,j,k;
	for(i=0;i<n-1;i++) 
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if( (stu[k].num) > (stu[j].num) )
				k=j;
		}
		if(i!=k)
		{
			temp=stu[k];
			stu[k]=stu[i];
			stu[i]=temp;
		}
	}
  
}

/**********************
function:�����Ƴɼ�������
parameter:��
***********************/
void Math_descending_sort()
{
	int i,j;
	STUDENT temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(stu[j].Math<stu[j+1].Math)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
}

void Chinese_descending_sort()
{
	int i,j;
	STUDENT temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(stu[j].Chinese<stu[j+1].Chinese)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
}
void English_descending_sort()
{
	int i,j;
	STUDENT temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(stu[j].English<stu[j+1].English)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
}
void Computer_descending_sort()
{
	int i,j;
	STUDENT temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(stu[j].Computer<stu[j+1].Computer)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
}
void PE_descending_sort()
{
	int i,j;
	STUDENT temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(stu[j].PE<stu[j+1].PE)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
}






/**********************************
function:����ѧ�����ݵĲ˵�
parameter:��
*************************************/
void insert()
{
	int choice; 
	printf("��ѡ����뷽ʽ:\n");
	printf("1----------ѧ��ƽ���ֽ���\n");
	printf("2----------ѧ������\n");
	printf("3----------��ĩβ\n");
    printf("0----------�˳���ѡ��):");

	do
	{
       scanf("%d",&choice);
	   if(choice==0)
		   return;
	  
	}while(choice<0||choice>3);

	switch(choice)
	{
	   case 1:insert_students_follow_average_grades_descending_order();
		      break;
	   case 2:insert_students_follow_student_num_ascending_order();
		      break;
	   case 3:insert_on_the_end();
	}
}

/*********************************
function:��ѧ���������
parament:��
***********************************/
void insert_students_follow_student_num_ascending_order()
{
	int add_num,i,j;
	STUDENT *add_stu;
	printf("\n������Ҫ�����ѧ������(����֮ǰ�뽫�������ѧ����ѧ��������)\n,"
		    "������������Ϊ0�����˳���ѡ��:");
	do
	{
		scanf("%d",&add_num);
        if(add_num==0)
			return;	                     /*return ��Ҫ�˳����ڵĺ���*/
	    if((add_num+n)>=MAX_PEOPLE)
			printf("�ռ䲻�����뿼������һ����Сֵ���˳�\n");
	}while(add_num<=0||(add_num+n)>=MAX_PEOPLE);

    add_stu=(STUDENT *)malloc(add_num*sizeof(STUDENT));
    
    printf("\n����������ѧ����ѧ��+����+�Ա�+�����Ŀ�ĳɼ�\n"
		     "(�������ġ�Ӣ�������������)\n\n");
	for(j=0;j<add_num;j++)
	{
       scanf("%d%*c",&add_stu[j]);
       
	   gets(add_stu[j].name);  
       
	   gets(add_stu[j].sex);   
	   
	   scanf("%lf %lf %lf %lf %lf",&add_stu[j].Math,&add_stu[j].Chinese,
		      &add_stu[j].English,&add_stu[j].Computer,&add_stu[j].PE);
       fflush(stdin);  
       puts("******************");
       add_stu[j].gross=(add_stu[j].Math+add_stu[j].Chinese+add_stu[j].English+
		             add_stu[j].Computer+add_stu[j].PE);
       
	   add_stu[j].average=(add_stu[j].Math+add_stu[j].Chinese+add_stu[j].English+
		             add_stu[j].Computer+add_stu[j].PE)/COURSES;
       
	   for(i=0;i<=n;i++)
	   {
		   if(i==n)
		   {
			   stu[n]=add_stu[j];
               n++;
			   break;
			   
		   }
		   if(add_stu[j].num<=stu[i].num)
		   {
			     int k;
			     for(k=n-1;k>=i;k--)
				 {
				   stu[k+1]=stu[k];
				 }
                 stu[i]=add_stu[j];
                 n++;
                 break;
		   }
	   }
	   
           
	}
    free(add_stu);
}

/*****************************************
function:��ѧ��ƽ���ֽ������
parameter:��
*******************************************/
void insert_students_follow_average_grades_descending_order()
{
	int add_num,i,j;
	STUDENT *add_stu;
	printf("\n������Ҫ�����ѧ������(����֮ǰ�뽫�����ѧ����ƽ���ֽ�����)\n,"
		    "������������Ϊ0�����˳���ѡ��:");
	do
	{
		scanf("%d",&add_num);
        if(add_num==0)
			return;                                  /*return ��Ҫ�˳����ڵĺ���*/
        if((add_num+n)>=MAX_PEOPLE)
			printf("�ռ䲻�����뿼������һ����Сֵ���˳�!\n");
	}while(add_num<0||(add_num+n)>=MAX_PEOPLE);

    add_stu=(STUDENT *)malloc(add_num*sizeof(STUDENT));
    
    printf("\n����������ѧ����ѧ��+����+�Ա�+�����Ŀ�ĳɼ�\n"
		     "(�������ġ�Ӣ�������������)\n\n");
	for(j=0;j<add_num;j++)
	{
       scanf("%d%*c",&add_stu[j]);
       
	   gets(add_stu[j].name);  
       
	   gets(add_stu[j].sex);   
	   
	   scanf("%lf %lf %lf %lf %lf",&add_stu[j].Math,&add_stu[j].Chinese,
		      &add_stu[j].English,&add_stu[j].Computer,&add_stu[j].PE);
       fflush(stdin);  
       puts("******************");
       add_stu[j].gross=(add_stu[j].Math+add_stu[j].Chinese+add_stu[j].English+
		             add_stu[j].Computer+add_stu[j].PE);
       
	   add_stu[j].average=(add_stu[j].Math+add_stu[j].Chinese+add_stu[j].English+
		             add_stu[j].Computer+add_stu[j].PE)/COURSES;
       
	   for(i=0;i<=n;i++)
	   {
		   if(i==n)
		   {
			   stu[n]=add_stu[j];
               n++;
			   break;
			   
		   }
		   if(add_stu[j].average>=stu[i].average)
		   {
			     int k;
			     for(k=n-1;k>=i;k--)
				 {
				   stu[k+1]=stu[k];
				 }
                 stu[i]=add_stu[j];
                 n++;
                 break;
		   }
	   }
	   
           
	}
    free(add_stu);
}
/*******************************
function:ֻ��ѧ�����ݲ��뵽ĩβ
parameter:��
********************************/
void insert_on_the_end()
{
   int add_num,j;

	printf("\n������Ҫ�����ѧ������\n,"
		    "(������������Ϊ0�����˳���ѡ��):");
	do
	{
		scanf("%d",&add_num);
        if(add_num==0)
			return;/*return ��Ҫ�˳����ڵĺ���*/
        if((add_num+n)>=MAX_PEOPLE)
			printf("�ռ䲻�����뿼������һ����Сֵ���˳�\n");
	}while(add_num<=0||(add_num+n)>=MAX_PEOPLE);

    
    
    printf("\n����������ѧ����ѧ��+����+�Ա�+�����Ŀ�ĳɼ�\n"
		     "(�������ġ�Ӣ�������������)\n\n");

    for(j=0;j<add_num;j++)
	{
       scanf("%d%*c",&stu[n]);
       
	   gets(stu[n].name);  
       
	   gets(stu[n].sex);   
	   
	   scanf("%lf %lf %lf %lf %lf",&stu[n].Math,&stu[n].Chinese,
		      &stu[n].English,&stu[n].Computer,&stu[n].PE);
       fflush(stdin);  
       puts("******************");
       stu[n].gross=(stu[n].Math+stu[n].Chinese+stu[n].English+
		             stu[n].Computer+stu[n].PE);
       
	   stu[j].average=(stu[n].Math+stu[n].Chinese+stu[n].English+
		             stu[n].Computer+stu[n].PE)/COURSES;
	   n++;
	   if(n>MAX_PEOPLE)
	   { 
		   printf("��û�п�λ!");
		   return;
	   }
	}
	
}
       

/**********************************
function:��ѧ��ɾ��һ��ѧ����Ϣ
parament:��
************************************/
void Delete_a_student_according_to_num()
{
	 int delete_num,i;
     printf("\n������һ��Ҫɾ����ѧ��ѧ��\n"
		     "��������ѧ��Ϊ0�����˳���ѡ��:");
	 do
	 {
		 scanf("%d",&delete_num);
		 if(delete_num==0)
			 return;
	 }while(delete_num<0);
	 for(i=0;i<n;i++)
	 {
		 if(delete_num==stu[i].num)
		 {
			 int k;
			 for(k=i+1;k<n;k++)
				 stu[k-1]=stu[k];
             printf("\nDelete successfully!");      /*Ϊʲôɾ���ɹ�����仰û�б���ӡ����*/
			 n--;
			 break;
		 }
	 }
	 if(i==n)
		 printf("û��Ҫɾ����ѧ������!\n");
	 
     
}





/***********************************
function:��ѯ�˵�
parameter:��
*************************************/
void search()
{
	int choice;
	printf("��ѡ���������\n");
    printf("1----------��ѧ�������۰����\n");
	printf("2----------��ѧ���������\n");
	printf("0----------�˳���ѡ��:");
	do
	{
		scanf("%d",&choice);
		if(choice==0)
			return;
	}while(choice<0||choice>2);
	switch(choice)
	{
	   case 1:half_search_a_student_data_according_to_num();
		      break;
	   case 2:sequential_search_a_student_data_according_to_num();
		      break;
	}
}

/*****************************
function:��ѧ�������۰����
parameter:��
******************************/    
void half_search_a_student_data_according_to_num()    
{
	int search_num; 
    int mid=0,end,head;

	printf("������һ����Ҫ���ҵ�ѧ��(�ڴ�֮ǰ������ѧ�����ݱ�����"
		     "��ѧ�������)\n"
			  "��������ѧ��Ϊ0�����˳���ѡ��:");
	do
	{
		scanf("%d",&search_num);
		if(search_num==0)
			return;
	}while(search_num<0);
    
	  
	  head=0;end=n-1;        /*�۰����*/
	  while(end>=head)
	  {
		mid=(head+end)/2;
		if(search_num>stu[mid].num)
		   head=mid+1;
		else if(search_num<stu[mid].num)
		   end=mid-1;
        else if(search_num==stu[mid].num)
		{
          printf("\n%d\n",stu[mid].num);
		  puts(stu[mid].name);
		  puts(stu[mid].sex);
		  printf("��ѧ�����ġ�Ӣ������������:");
		  printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n",stu[mid].Math,stu[mid].Chinese,
		           stu[mid].English,stu[mid].Computer,stu[mid].PE);
		  printf("ƽ���֡��ܷ�:%.2lf  %.2lf\n\n",stu[mid].average,stu[mid].gross);
          puts("************");
		  return;
        }
	  }
	

	if(search_num!=stu[mid].num)
		printf("\n����ʧ��!\n");
    
}

/****************************
function:��ѧ��ѧ��˳�����
parameter:��
*****************************/
void sequential_search_a_student_data_according_to_num()
{  
	int search_num;  /*Ҫ���ҵ�ѧ��*/
    int i;

	printf("������һ����Ҫ���ҵ�ѧ��"
		     "(��������ѧ��Ϊ0�����˳���ѡ��):");
	do
	{
		scanf("%d",&search_num);
		if(search_num==0)
			return;
	}while(search_num<0);
    
	  
	  
	for(i=0;i<n;i++)
    {
		 if(search_num==stu[i].num)
		 {
          printf("\n%d\n",stu[i].num);
		  puts(stu[i].name);
		  puts(stu[i].sex);
		  printf("��ѧ�����ġ�Ӣ������������:");
		  printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n",stu[i].Math,stu[i].Chinese,
		           stu[i].English,stu[i].Computer,stu[i].PE);
		  printf("ƽ���֡��ܷ�:%.2lf  %.2lf\n\n",stu[i].average,stu[i].gross);
          puts("************");
		  return;
        }
	} 
	

	if(search_num==n)
		printf("\n����ʧ��!\n");
    
}



/********************************
function:��������ѧ������
parameter:��
***********************************/
void calculate_all_courses_data()
{
        int i,j;
		double Math_sum=0,Chinese_sum=0,English_sum=0,/*���Ƶ��ܷ�*/
			   Computer_sum=0,PE_sum=0;
        
	    int Math_pass=0,     Math_excellent=0,/*pass�Ǽ���excellent�����㣬����Ĳ�����λ������*/
	        Chinese_pass=0,  Chinese_excellent=0,
			English_pass=0,  English_excellent=0,
		    Computer_pass=0, Computer_excellent=0,
			PE_pass=0,       PE_excellent=0;

		

       /*�����ѧ�Ƶ��ܷ�*/
		for(i=0;i<n;i++)
		{
				Math_sum+=stu[i].Math;
				Chinese_sum+=stu[i].Chinese;
				English_sum+=stu[i].English;
				Computer_sum+=stu[i].Computer;
				PE_sum+=stu[i].PE;
				
			
		}

        Math.average=Math_sum/n;
		Chinese.average=Chinese_sum/n;
		English.average=English_sum/n;
		Computer.average=Computer_sum/n;
		PE.average=PE_sum/n;
        

	
        /*�ܼƸ���ѧ�Ƶ�����ͼ�������*/
		for(i=0;i<n;i++)
		{
			if(stu[i].Math>=60)
				Math_pass++;
			if(stu[i].Math>=90)
                Math_excellent++;

			if(stu[i].Chinese>=60)
                Chinese_pass++;
			if(stu[i].Chinese>=90)
				Chinese_excellent++;

			if(stu[i].English>=60)
				English_pass++;
			if(stu[i].English>=90)
				English_excellent++;
				
			

			if(stu[i].Computer>=60)
				Computer_pass++;
			if(stu[i].Computer>=90)
				Computer_excellent++;

			if(stu[i].PE>=60)
				PE_pass++;
			if(stu[i].PE>=90)
				PE_excellent++;
		}
        
	    /*�������ѧ�Ƶ������ʺͼ�����*/
		Math.pass_rate=(double)Math_pass/n;
	    Math.excellent_rate=(double)Math_excellent/n;

		Chinese.pass_rate=(double)Chinese_pass/n;
		Chinese.excellent_rate=(double)Chinese_excellent/n;

		English.pass_rate=(double)English_pass/n;
        English.excellent_rate=(double)English_excellent/n;
	

		Computer.pass_rate=(double)Computer_pass/n;
		Computer.excellent_rate=(double)Computer_excellent/n;

		PE.pass_rate=(double)PE_pass/n;
		PE.excellent_rate=(double)PE_excellent/n;

    /*�������ѧ�Ƶı�׼��*/
    for(j=0;j<COURSES;j++)
	{
       double sum1=0,sum2=0;
	   int i;
	  if(j==0)
	 {
	   for(i=0;i<n;i++)
         sum2+=(stu[i].Math-Math.average)*(stu[i].Math-Math.average);
	   Math.standard_deviation=sqrt(sum2/n);
	 }

     else if(j==1)
	 {
	   for(i=0;i<n;i++)
         sum2+=(stu[i].Chinese-Chinese.average)*(stu[i].Chinese-Chinese.average);
	   Chinese.standard_deviation=sqrt(sum2/n);
	 }
	 else if(j==2)
	 {
	   for(i=0;i<n;i++)
         sum2+=(stu[i].English-English.average)*(stu[i].English-English.average);
	   English.standard_deviation=sqrt(sum2/n);
	 } 
     else if(j==3)
	 {
	   for(i=0;i<n;i++)
         sum2+=(stu[i].Computer-Computer.average)*(stu[i].Computer-Computer.average);
	   Computer.standard_deviation=sqrt(sum2/n);
	 } 
     else if(j==4)
	 {
	   for(i=0;i<n;i++)
         sum2+=(stu[i].PE-PE.average)*(stu[i].PE-PE.average);
	   PE.standard_deviation=sqrt(sum2/n);
	 } 
	
    }

    /*�������ҳ����Ƶ���ߺ���ͷ�*/
	Math.highest_grade=0;      Math.lowest_grade=stu[0].Math;
	Chinese.highest_grade=0;   Chinese.lowest_grade=stu[0].Chinese;
	English.highest_grade=0;   English.lowest_grade=stu[0].English;
	Computer.highest_grade=0;  Computer.lowest_grade=stu[0].Computer;
	PE.highest_grade=0;        PE.lowest_grade=stu[0].PE;
	for(i=0;i<n;i++)
	{
		if(Math.highest_grade<=stu[i].Math)
			Math.highest_grade=stu[i].Math;
		if(Math.lowest_grade>=stu[i].Math)
			Math.lowest_grade=stu[i].Math;

		if(Chinese.highest_grade<=stu[i].Chinese)
			Chinese.highest_grade=stu[i].Chinese;
		if(Chinese.lowest_grade>=stu[i].Chinese)
			Chinese.lowest_grade=stu[i].Chinese;

		if(English.highest_grade<=stu[i].English)
			English.highest_grade=stu[i].English;
		if(English.lowest_grade>=stu[i].English)
			English.lowest_grade=stu[i].English;

		if(Computer.highest_grade<=stu[i].Computer)
			Computer.highest_grade=stu[i].Computer;
		if(Computer.lowest_grade>=stu[i].Computer)
			Computer.lowest_grade=stu[i].Computer;

		if(PE.highest_grade<=stu[i].PE)
			PE.highest_grade=stu[i].PE;
		if(PE.lowest_grade>=stu[i].PE)
			PE.lowest_grade=stu[i].PE;
    }
}

/**************************************
function:����ȫ��ѧ������ƽ���ֵı�׼��
patameter:��
return:double���͵�ѧ����׼��
***************************************/
double  calculate_students_stardard_daviation()
{
    double sum1=0,sum2=0;
	int i;
	for(i=0;i<n;i++)
    {
		sum1+=stu[i].average;
		
	}
	for(i=0;i<n;i++)
       sum2+=(stu[i].average-sum1/n)*(stu[i].average-sum1/n);
	return sqrt(sum2/n);
	
}




/************************************
function:չʾ�������ݵĲ˵�
parameter:��
**************************************/
void demonstrate()
{
	int choice;
	printf("��ѡ���ӡ����������:\n");
	printf("1----------�в������Ŀ��ѧ��\n");
	printf("2----------������\n" );
	printf("3----------ȫ��ѧ��\n");
	printf("4----------ȫ���γ�\n");
	printf("5----------ȫ��ѧ���Ϳγ�:");
	do
	{
		scanf("%d",&choice);
	}while(choice<1||choice>5);
	switch(choice)
	{
	   case 1:demonstrate_all_failing_at_least_a_course_students_data();
		      break;
	   case 2:demonstrate_all_excellent_students_datas();
		      break;
	   case 3:demonstrate_all_students_data();
		      break;
	   case 4:demonstrate_all_courses_data();
		      break;
	   case 5:demonstrate_all_students_data();
		      demonstrate_all_courses_data();
			  break;
	}
}
	
/******************************
function:չʾ�в����������ѧ��
parameter:��
*******************************/
void demonstrate_all_failing_at_least_a_course_students_data()
{
	int i;
      puts("********************************************************************************");
      printf("%6s%8s%6s%8s%8s%8s%8s%8s%8s%8s\n","ѧ��","����","�Ա�","��ѧ",
		      "����","Ӣ��","�����","����","ƽ����","�ܷ�");
	for(i=0;i<n;i++)
	{
		if(stu[i].Math<60 ||stu[i].Chinese<60)
        {

		    printf("%6d",stu[i].num);
		    printf("%8s",stu[i].name);
		    printf("%6s",stu[i].sex);
		 
		    printf("%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf",stu[i].Math,stu[i].Chinese,
		           stu[i].English,stu[i].Computer,stu[i].PE);
		    printf("%8.2lf %8.2lf\n",stu[i].average,stu[i].gross);
		}
		else if(stu[i].English<60||stu[i].Computer<60||stu[i].PE<60)
		{
            printf("%6d",stu[i].num);
		    printf("%8s",stu[i].name);
		    printf("%6s",stu[i].sex);
		 
		    printf("%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf",stu[i].Math,stu[i].Chinese,
		           stu[i].English,stu[i].Computer,stu[i].PE);
		    printf("%8.2lf %8.2lf\n",stu[i].average,stu[i].gross);
		}
	   
	}
    puts("********************************************************************************");
}

/**************************
function:չʾ������
parameter:��
***************************/
void demonstrate_all_excellent_students_datas()
{
	int i;
      puts("********************************************************************************");
      printf("%6s%8s%6s%8s%8s%8s%8s%8s%8s%8s\n","ѧ��","����","�Ա�","��ѧ",
		      "����","Ӣ��","�����","����","ƽ����","�ܷ�");
      for(i=0;i<n;i++)
	  {
          if(stu[i].average>=90)
		  {
		    printf("%6d",stu[i].num);
		    printf("%8s",stu[i].name);
		    printf("%6s",stu[i].sex);
		 
		    printf("%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf",stu[i].Math,stu[i].Chinese,
		           stu[i].English,stu[i].Computer,stu[i].PE);
		    printf("%8.2lf %8.2lf\n",stu[i].average,stu[i].gross);
		  }
	  }
	  
      puts("********************************************************************************");
}

/**********************************
function:չʾ����ѧ��������
parameter:��
***********************************/
void demonstrate_all_students_data()
{
	  int i;
	  puts("********************************************************************************");
      printf("%6s%8s%6s%8s%8s%8s%8s%8s%8s%8s\n","ѧ��","����","�Ա�","��ѧ",
		      "����","Ӣ��","�����","����","ƽ����","�ܷ�");
      for(i=0;i<n;i++)
	  {
		  printf("%6d",stu[i].num);
		  printf("%8s",stu[i].name);
		  printf("%6s",stu[i].sex);
		 
		  printf("%8.2lf%8.2lf%8.2lf%8.2lf%8.2lf",stu[i].Math,stu[i].Chinese,
		           stu[i].English,stu[i].Computer,stu[i].PE);
		  printf("%8.2lf %8.2lf\n",stu[i].average,stu[i].gross);
	  }
	  printf("ѧ������:%d\n",n);
	  printf("ȫ��ѧ���ĳɼ���׼����:%.2lf\n",
		      calculate_students_stardard_daviation());
      puts("********************************************************************************");
      
}     

/*******************************
function:չʾ���пγ̵�����
parameter:��
*********************************/
void demonstrate_all_courses_data()
{
	
	 puts("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
     printf("\t%10s%10s%10s%10s%10s%10s\n","������","������","��߷�","��ͷ�","ƽ����","��׼��");
	 printf("%8s%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf\n","��ѧ",Math.pass_rate, Math.excellent_rate,
		      Math.highest_grade, Math.lowest_grade, Math.average, Math.standard_deviation);

	 printf("%8s%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf\n","����",Chinese.pass_rate, Chinese.excellent_rate,
		     Chinese.highest_grade,Chinese.lowest_grade,Chinese.average,Chinese.standard_deviation);

	 printf("%8s%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf\n","Ӣ��",English.pass_rate,English.excellent_rate,
		     English.highest_grade,English.lowest_grade,English.average,English.standard_deviation);

	 printf("%8s%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf\n","�����",Computer.pass_rate,Computer.excellent_rate,
		      Computer.highest_grade,Computer.lowest_grade,Computer.average,Computer.standard_deviation);

	 printf("%8s%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf%10.2lf\n","����",PE.pass_rate,PE.excellent_rate,
		     PE.highest_grade,PE.lowest_grade,PE.average, PE.standard_deviation);
     puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
}


 




/****************************************************************
function:��������ѧ�����ݵ�stu.c,��ȫ�����ݵ����û����������ļ���
parameter:��
*****************************************************************/
 void save_present_student_data()
 {
	 FILE *fp,*fp2;
     
	 int count,i;
	
	 /*����ѧ�����ݵ�stu.c*/
	 if( (fp=fopen("stu.c","wb")) !=NULL)
	 {
         count=fwrite(stu,sizeof(STUDENT),n,fp);
		 if(count!=n)
			 return;

	 };
     fclose(fp);
     

	 /*����ȫ�����ݵ�  user (Ҫ������û���)*/

     
     if((fp2=fopen("ȫ������.c","w"))!=NULL)
	 {
         
         fputs("*************************************************************************************\n",fp2);
      fprintf(fp2,"%6s %8s %6s %8s %8s %8s %8s %8s %8s %8s\n","ѧ��","����","�Ա�","��ѧ",
		      "����","Ӣ��","�����","����","ƽ����","�ܷ�");

      for(i=0;i<n;i++)
	  {
		  fprintf(fp2,"%6d ",stu[i].num);
		  fprintf(fp2,"%8s ",stu[i].name);
		  fprintf(fp2,"%6s ",stu[i].sex);
		 
		  fprintf(fp2,"%8.2lf %8.2lf %8.2lf %8.2lf %8.2lf",stu[i].Math,stu[i].Chinese,
		           stu[i].English,stu[i].Computer,stu[i].PE);
		  fprintf(fp2,"%8.2lf %8.2lf\n",stu[i].average,stu[i].gross);
	  }
      fprintf(fp2,"ѧ������:%d\n",n);
	  fprintf(fp2,"ȫ��ѧ����ƽ���ɼ���׼����:%.2lf\n",
		      calculate_students_stardard_daviation());
     fputs("****************************************************************************************\n",fp2);
      fputs("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n",fp2);
     fprintf(fp2,"\t %10s %10s %10s %10s %10s %10s\n","������","������","��߷�","��ͷ�","ƽ����","��׼��");
	 fprintf(fp2,"%8s %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf\n","��ѧ",Math.pass_rate, Math.excellent_rate, Math.highest_grade,
		      Math.lowest_grade, Math.average, Math.standard_deviation);
	 fprintf(fp2,"%8s %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf\n","����",Chinese.pass_rate, Chinese.excellent_rate,
		     Chinese.highest_grade, Chinese.lowest_grade, Chinese.average, Chinese.standard_deviation);

	 fprintf(fp2,"%8s %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf\n","Ӣ��",English.pass_rate, English.excellent_rate,
		     English.highest_grade, English.lowest_grade, English.average, English.standard_deviation);

	 fprintf(fp2,"%8s %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf\n","�����",Computer.pass_rate, Computer.excellent_rate,
		      Computer.highest_grade, Computer.lowest_grade, Computer.average,Computer.standard_deviation);

	 fprintf(fp2,"%8s %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf %10.2lf\n","����",PE.pass_rate,PE.excellent_rate,
		      PE.highest_grade,PE.lowest_grade,PE.average,PE.standard_deviation);
     fputs("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",fp2);
     
     fclose(fp2);
	 printf("�ѽ����ϵ�ѧ�����ݱ��浽�˵�ǰλ�õ�stu.c�ͺ�ȫ�����ݱ�������() �ļ���!");
	}
 }


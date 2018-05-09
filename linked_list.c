#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define SIZE 30

struct Book * merge(struct Book * lptr1,struct Book *lptr2);
struct Book * divide(struct Book * lptr);
struct Book* Union(struct Book *list1,struct Book *list2);
struct Book* intersection(struct Book *list1,struct Book *list2);
struct Book* set_diff(struct Book *list1,struct Book *list2);
struct Book* symmetric_diff(struct Book *list1,struct Book *list2);
struct Book * mergesort(struct Book *ptr);
struct Book* add(struct Book *ptr,struct Book *ptr1);

struct Book
{
	char author[SIZE];
	char book[SIZE];
	int yop;
	int noc;
	struct Book *next;
};

int main()
{
	struct Book *head,*temp,*head1,*head2,*head3;			//head is the pointer pointing to the start of the link list of records of author's
	int a,b,exit,z;				
	
	//function declarations
	
	struct Book * create_record(int n,struct Book*ptr);
	int print(struct Book*ptr);
	struct Book * insert(struct Book* ptr);
	int getnumrecords(struct Book *ptr);
	void Is_empty(struct Book* ptr);
	void Is_full(struct Book* ptr);
	struct Book* getTopBookAuthor(struct Book *ptr);
	void mostPopularAuthor(struct Book *ptr);
	struct Book* Delete(struct Book* ptr);		
	struct Book* Unique(struct Book *ptr);
	void least_pop_author(struct Book *ptr,int p, int k);
	void kth_pop( struct Book *ptr ,int k );
	 
	//intialisng the pointer to null
	head=NULL;
	//printing the to chk weather or not the records are empty
	printf("                                                       --BEGIN--          \n");
	//print(head);
	exit=1;
	while(exit!=0)
	{
		printf("\n -----ENTER YOUR CHOICE----- \n\n 1.  CREATING RECORDS \n 2.  INSERSTION  \n 3.  DELETION \n 4.  NO. OF RECORDS \n 5.  RECORD FULL? \n 6.  RECORD EMPTY \n 7.  GET TOP MOST AUTHOR \n 8.  MOST POPULAR AUTHOR \n 9.  UNIQUE LIST \n 10. LEAST POPULAR AUTHOR \n 11. Kth POPULAR AUTHOR \n 12. UNION \n 13. INTERSECTION \n 14. SET DIFFERENCE \n 15. SYMMETRIC DIFFERENCE \n 16. EXIT \n ");
		printf("\n");
		scanf("%d",&b);
		printf("\n");
		switch(b)
		{
			case(1):
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head=create_record(a,head);
					print(head);
					break;
			case(2):
					head=insert (head);
					print(head);
					break;
			case(3):
					head=Delete(head);
					print(head);
					break;
			case(5):
					Is_full(head);
					//print(head)
					break;
			case(4):
					a=getnumrecords(head);
					printf(" EXISITING RECORDS ARE -> %d\n",a);
					//print(head)
					break;
			case(6):
					Is_empty(head);
					//print(head)
					break;
			case(7):
					temp=getTopBookAuthor(head);
					if(temp==NULL)
					{
						printf("BOOK NOT PRESENT IN RECORDS \n");
					}
					else
					{
						printf("TOP BOOK AUTHOR is -> %s\n",temp->author);
					}
					//print(head)
					break;
			case(8):
					mostPopularAuthor(head);
					break;
			case(9):
					printf("Enter the no of records you want to create \n");
					scanf("%d",&a);
					head1=create_record(a,head1);
					head1=Unique(head1);
					print(head1);
					break;
			case(10):
					printf("Enter the no of records you want to create \n");
					scanf("%d",&a);
					head1=create_record(a,head1);
					printf("Enter the no of copies per author\n");
					scanf("%d",&a);
					printf("Enter the percentage of\n");
					scanf("%d",&z);
					least_pop_author(head,a,z);
					break;
			case(11):
					head=NULL;
					printf("Enter the no of records you want to create \n");
					scanf("%d",&a);
					head=create_record(a,head);
					printf(" Enter the kth position \n");
					scanf("%d",&z);
					kth_pop( head , z);
					break;
			case(12):
					head1=NULL;
					head2=NULL;
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head1=create_record(a,head1);
					print(head1);
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head2=create_record(a,head2);
					//print(head2);
					printf("ENTERING UNION\n");
					head3=Union(head1,head2);
					printf("RETURNING UNION\n");
					print(head3);
					head1=NULL;
					head2=NULL;
					head3=NULL;
					break;
			case(13):
					head1=NULL;
					head2=NULL;
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head1=create_record(a,head1);
					print(head1);
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head2=create_record(a,head2);
					print(head2);
					head3=intersection(head1,head2);
					if(head3==NULL)
					{
						printf("RECORD EMPTY\n");
					}
					else
					{
						printf("\n                                      THE INTERSECTION IS\n");
						print(head3);
					}
					free(head1);
					free(head2);
					free(head3);
					break;
			case(14):
					head1=NULL;
					head2=NULL;
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head1=create_record(a,head1);
					print(head1);
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head2=create_record(a,head2);
					print(head2);
					head3=set_diff(head1,head2);
					if(head3==NULL)
					{
						printf("RECORD EMPTY\n");
					}
					else
					{
						printf("\n                                      THE SET DIFFERENCE IS\n");
						print(head3);
					}
					free(head1);
					free(head2);
					free(head3);
					break;
			case(15):
					head1=NULL;
					head2=NULL;
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head1=create_record(a,head1);
					print(head1);
					printf("\nEnter the no of records you want to create\n");
					scanf("%d",&a);
					head2=create_record(a,head2);
					print(head2);
					head3=symmetric_diff(head1,head2);
					if(head3==NULL)
					{
						printf("RECORD EMPTY\n");
					}
					else
					{
						printf("\n                                      THE SYMMETRIC DIFFERENCE IS\n");
						print(head3);
					}
					free(head1);
					free(head2);
					free(head3);
					break;
			case(16):
					exit=0;
					break;
			default:
					printf("\n -----ENTER A VALID CHOICE----- \n");
		}
	}
	return(0);
}

struct Book* Union(struct Book *list1,struct Book *list2)
{
	struct Book *ret_ptr,*l1;
	l1=list1;
	if(list1==NULL)
	{
		ret_ptr=list2;
	}
	else if(list2==NULL)
	{
		ret_ptr=list1;
	}
	else if(list1!=NULL&&list2!=NULL)
	{
		while(list1->next!=NULL)
		{
			list1=list1->next;
		}
		list1->next=list2;
		print(l1);
		ret_ptr=mergesort(l1);
		print(ret_ptr);
		
	}
	else if(list1==NULL&&list2==NULL)
	{
		ret_ptr=NULL;
	}
	return(ret_ptr);
}

void least_pop_author(struct Book *ptr,int p, int k)
{
	struct Book *temp;
	int n,total,per,done=0;
	temp=ptr;
	n=0;
	total=0;
	
	if(ptr!=NULL)
	{
		while(ptr!=NULL)
		{ 
			n=0; 
			total=0;
			while(done==0&&temp!=NULL)  
			{
				if(strcmp(temp->author,ptr->author)==0)
				{ 
					total++;
					if(temp->noc<p)
					{
						n++;
					}
					temp=temp->next;
				}
				else
				{
					per=(n*100)/(total);
					if(per>=k)
					{
						 printf("LEAST POPULAR AUTHOR IS : %s",ptr->author);
					}
					done=1;
					ptr=temp;
					temp=NULL;
				}
				
			}
			temp=ptr;
			done=0;
		}
	}
	else
	{
		printf("RECORDS ARE EMPTY\n");
	}
}

struct Book* intersection(struct Book *list1,struct Book *list2)
{
	struct Book *l1,*l2,*ret_ptr,*ptr,*lptr,*temp;
	l1=list1;
	l2=list2;
	lptr=NULL;
	ret_ptr=NULL;
	if(l1!=NULL&&l2!=NULL)
	{
		ptr=(struct Book *) malloc(sizeof(struct Book));
		ret_ptr=ptr;
		ptr->next=NULL;
		while(l1!=NULL&&l2!=NULL)
		{
			if((strcmp(l1->author,l2->author)==0)&&(strcmp(l1->book,l2->book)==0))
			{
				if(l1->yop<l2->yop)
				{
					temp=(struct Book *) malloc(sizeof(struct Book));
					strcpy(temp->author,l1->author);
					strcpy(temp->book,l1->book);
					temp->noc=l1->noc;
					temp->yop=l1->yop;
					temp->next=lptr;
					ptr->next=temp;
					ptr=temp;
					l1=l1->next;
					l2=l2->next;			
				}	
				else
				{
					temp=(struct Book *) malloc(sizeof(struct Book));
					strcpy(temp->author,l2->author);
					strcpy(temp->book,l2->book);
					temp->noc=l2->noc;
					temp->yop=l2->yop;
					temp->next=lptr;
					ptr->next=temp;
					ptr=temp;
					l1=l1->next;
					l2=l2->next;
				}
			}
			else
			{
				if(strcmp(l1->author,l2->author)<0)
				{
					l1=l1->next;
				}
				else
				{
					l2=l2->next;
				}
			}
		}
		ret_ptr=ret_ptr->next;
		ptr->next=NULL;
	}
	else if(l1==NULL||l2==NULL)
	{
		ret_ptr=NULL;
	}
	return(ret_ptr);
}

struct Book* set_diff(struct Book *list1,struct Book *list2)
{
	struct Book *l1,*l2,*temp,*inter,*ptr,*lptr,*ret_ptr;
	l1=list1;
	l2=list2;
	lptr=NULL;
	ret_ptr =NULL;
	inter=intersection(l1,l2);
//	print(inter);
	l1=list1;
	if(inter==NULL)
	{
		ret_ptr=l1;
	}
	else
	{
		ptr=(struct Book*) malloc(sizeof(struct Book));
		ptr->next=NULL;
		ret_ptr=ptr;
		while(l1!=NULL&&inter!=NULL)
		{
			if(strcmp(l1->author,inter->author)<0)
			{
				temp=(struct Book*) malloc(sizeof(struct Book));
				strcpy(temp->author,l1->author);
				strcpy(temp->book,l1->book);
				temp->noc=l1->noc;
				temp->yop=l1->yop;
				temp->next=lptr;
				ptr->next=temp;
				ptr=temp;
				l1=l1->next;
			}
			else if(strcmp(l1->author,inter->author)>0)
			{
				inter=inter->next;
			}
			else if(strcmp(l1->author,inter->author)==0)
			{
				if(strcmp(l1->book,inter->book)==0)
				{
					inter=inter->next;
					l1=l1->next;
				}
				else if(strcmp(l1->book,inter->book)<0)
				{
					temp=(struct Book*) malloc(sizeof(struct Book));
					strcpy(temp->author,l1->author);
					strcpy(temp->book,l1->book);
					temp->noc=l1->noc;
					temp->yop=l1->yop;
					temp->next=lptr;
					ptr->next=temp;
					ptr=temp;
					l1=l1->next;
				}
				else if(strcmp(l1->author,inter->author)>0)
				{
					inter=inter->next;
				}
			}
		}
		while(l1!=NULL)
		{
			temp=(struct Book*) malloc(sizeof(struct Book));
			strcpy(temp->author,l1->author);
			strcpy(temp->book,l1->book);
			temp->noc=l1->noc;
			temp->yop=l1->yop;
			temp->next=lptr;
			ptr->next=temp;
			ptr=temp;
			l1=l1->next;
		}
		ret_ptr=ret_ptr->next;
	}
	return(ret_ptr);
}

struct Book* symmetric_diff(struct Book *list1,struct Book *list2)
{
	struct Book *l1,*l2,*temp1,*temp2,*ret_ptr;
	l1=list1;
	l2=list2;
	temp2=intersection(l1,l2);
//	print(temp2);
	l1=list1;
	l2=list2;
	temp1=Union(l1,l2);
//	print(temp1);
	ret_ptr=set_diff(temp1,temp2);
	return(ret_ptr);
}

/*struct Book* Union(struct Book *list1,struct Book *list2)
{
	struct Book *l1,*l2,*temp,*ptr,*ret_ptr=NULL,*lptr=NULL;
	l1=list1;
	l2=list2;
	
	if(l1!=NULL&&l2!=NULL)
	{
		ptr=(struct Book *) malloc(sizeof(struct Book));
		ret_ptr=ptr;
		ptr->next=NULL;
		while(l1!=NULL)
		{
			while(l2!=NULL)
			{
			
			if((strcmp(l1->author,l2->author)==0)&&(strcmp(l1->book,l2->book)==0))
			{
				if(l1->yop>l2->yop)
				{
					temp=(struct Book *) malloc(sizeof(struct Book));
					strcpy(temp->author,l1->author);
					strcpy(temp->book,l1->book);
					temp->noc=l1->noc;
					temp->yop=l1->yop;
					temp->next=lptr;
					ptr->next=temp;
					ptr=temp;
					l1=l1->next;
					l2=l2->next;			
				}	
				else
				{
					temp=(struct Book *) malloc(sizeof(struct Book));
					strcpy(temp->author,l2->author);
					strcpy(temp->book,l2->book);
					temp->noc=l2->noc;
					temp->yop=l2->yop;
					temp->next=lptr;
					ptr->next=temp;
					ptr=temp;
					l1=l1->next;
					l2=l2->next;
				}
			}
			else if(strcmp(l1->author,l2->author)<0)
			{
				temp=(struct Book *) malloc(sizeof(struct Book));
				strcpy(temp->author,l1->author);
				strcpy(temp->book,l1->book);
				temp->noc=l1->noc;
				temp->yop=l1->yop;
				temp->next=lptr;
				ptr->next=temp;
				ptr=temp;
				l1=l1->next;
			}
			else if(strcmp(l1->author,l2->author)>0)
			{
				temp=(struct Book *) malloc(sizeof(struct Book));
				strcpy(temp->author,l2->author);
				strcpy(temp->book,l2->book);
				temp->noc=l2->noc;
				temp->yop=l2->yop;
				temp->next=lptr;
				ptr->next=temp;
				ptr=temp;
				l2=l2->next;
			}
			else
			{
				if(strcmp(l1->book,l2->book)<0)
				{
					temp=(struct Book *) malloc(sizeof(struct Book));
					strcpy(temp->author,l1->author);
					strcpy(temp->book,l1->book);
					temp->noc=l1->noc;
					temp->yop=l1->yop;
					temp->next=lptr;
					ptr->next=temp;
					ptr=temp;
					l1=l1->next;
				}
				else
				{
					temp=(struct Book *) malloc(sizeof(struct Book));
					strcpy(temp->author,l2->author);
					strcpy(temp->book,l2->book);
					temp->noc=l2->noc;
					temp->yop=l2->yop;
					temp->next=lptr;
					ptr->next=temp;
					ptr=temp;
					l2=l2->next;	
				}
			}
		}
		if(l1!=NULL)
		{
			while(l1!=NULL)
			{
				temp=(struct Book *) malloc(sizeof(struct Book));
				strcpy(temp->author,l1->author);
				strcpy(temp->book,l1->book);
				temp->noc=l1->noc;
				temp->yop=l1->yop;
				temp->next=lptr;
				ptr->next=temp;
				ptr=temp;
				l1=l1->next;
			}
		}
		else if(l2!=NULL)
		{
			temp=(struct Book *) malloc(sizeof(struct Book));
			strcpy(temp->author,l2->author);
			strcpy(temp->book,l2->book);
			temp->noc=l2->noc;
			temp->yop=l2->yop;
			temp->next=lptr;
			ptr->next=temp;
			ptr=temp;
			l2=l2->next;
		}	
		ret_ptr=ret_ptr->next;
	}
	else if(l1==NULL&&l2==NULL)
	{
		ret_ptr=NULL;
	}
	else if(l2==NULL)
	{
		ret_ptr=list1;
	}
	else
	{
		ret_ptr=list2;
	}
	return(ret_ptr);
}*/

struct Book* Unique(struct Book *ptr)
{
	struct Book *prv,*pv_prv,*lptr,*ret_ptr;
	pv_prv=NULL;
	prv=ptr;
	lptr=prv->next;
	if(prv==NULL)
	{
		ret_ptr=NULL;
	}
	else if(prv!=NULL&&lptr==NULL)
	{
		ret_ptr=prv;
	}
	else 
	{
		while(lptr!=NULL)
		{
			if(strcmp(prv->author,lptr->author)==0&&strcmp(prv->book,lptr->book)==0)
			{
				if(prv->yop>lptr->yop)
				{
					prv->next=lptr->next;
					free(lptr);
					lptr=prv->next;
				}
				else
				{
					prv->noc=lptr->noc;
					prv->yop=lptr->yop;
					prv->next=lptr->next;
					free(lptr);
					lptr=prv->next;
				}
			}
			else
			{
			
				prv=lptr;
				lptr=lptr->next;
			}
		}
	}
	ret_ptr=ptr;
	return(ret_ptr);
}

void mostPopularAuthor(struct Book *ptr)
{
	struct Book *l1,*l2,*temp,*lptr;
	temp=(struct Book*)malloc(sizeof(struct Book));
	l1=ptr;
	lptr=NULL;
	//strcpy(temp->author,l1->author);
	temp->noc=0;
	l2=l1;
	if(ptr!=NULL)
	{
		while(l2!=NULL)
		{	
			temp->noc=0;
			strcpy(temp->author,l2->author);
			while(l1!=NULL)
			{
				if(strcmp(l2->author,l1->author)==0)
				{
					temp->noc=temp->noc+l1->noc;
					l1=l1->next;
				}
				else 
				{
					lptr=add(temp,lptr);
					l2=l1;
					l1=NULL;
				}
			}
			l1=l2;
		}
	}
	else
	{
		printf(" RECORD IS EMPTY \n");
	}
	temp=lptr;
	l1=(struct Book*) malloc(sizeof(struct Book));
	strcpy(l1->author,lptr->author);
	l1->noc=lptr->noc;
	while(lptr!=NULL)
	{
		if(l1->noc<lptr->noc)
		{
			strcpy(l1->author,lptr->author);
			l1->noc=lptr->noc;
		}
	}
	lptr=temp;
	while(lptr!=NULL)
	{
		if(l1->noc=lptr->noc)
		{
			printf(" TOP MOST AUTHOR is -> %s",l1->author);
		}
	}
	free(l1);
	free(temp);
}
struct Book* add(struct Book *ptr,struct Book *ptr1)
{
	struct Book *l; 
	l=(struct Book*)malloc(sizeof(struct Book));
	strcpy(l->author,ptr->author);
	l->noc=ptr->noc;
	l->next=ptr1;
	return(l);
}

struct Book* Delete(struct Book* ptr)
{
	struct Book *prv,*lptr,*temp,*ret_ptr;
	int done=0;
	temp=(struct Book*)malloc(sizeof(struct Book));
	prv=ptr;			//prv is the pointer to the node previous to lptr
	lptr=ptr->next;
	printf("ENTER THE AUTHOR WHOSE BOOK YOU WANT TO DELETE AND THE BOOK NAME \n ");
	scanf("%s",temp->author);
	scanf("%s",temp->book);
	if(ptr==NULL)
	{
		printf("RECORDS ARE EMPTY\n");
		ret_ptr=ptr;
	}
	else if((prv!=NULL)&&(lptr==NULL))
	{
		
		if(strcmp(prv->author,temp->author)==0&&strcmp(prv->book,temp->book)==0)
		{
			free(temp);
			free(prv);
			printf("DELETED SUCCESFULLY\n");
			ret_ptr=lptr;
		}
		else
		{
			printf("PROVIDED INFORMATION IS INCORRECT\n");
			free(temp);
			ret_ptr=ptr;
		}
	}
	else if((prv!=NULL)&&(lptr!=NULL))
	{
		if(strcmp(prv->author,temp->author)==0&&strcmp(prv->book,temp->book)==0)
		{
			free(temp);
			free(prv);
			printf("DELETED SUCCESFULLY\n");
			ret_ptr=lptr;
		}
		else 
		{
			while(lptr!=NULL&&done==0)
			{
				if(strcmp(lptr->author,temp->author)==0&&strcmp(lptr->book,temp->book)==0)
				{
					prv->next=lptr->next;
					free(lptr);
					done=1;
					free(temp);
					printf("DELETED SUCCESFULLY\n");
					ret_ptr=ptr;
				}
				else
				{
					prv=lptr;
					lptr=lptr->next;
				}
			}
		}
	}
	return(ret_ptr);
}

struct Book* getTopBookAuthor(struct Book *ptr)
{
	struct Book *temp,*ret_ptr;
	int cmp;
	temp=(struct Book*) malloc(sizeof(struct Book));
	temp->noc=0;
	printf("Enter the books name\n");
	scanf("%s",temp->book);
	while(ptr!=NULL)
	{
		cmp=strcmp(ptr->book,temp->book);
		if(cmp==0)
		{
				if(ptr->noc>temp->noc)
				{
					temp=ptr;
					ptr=ptr->next;
				}
				else
				{
					ptr=ptr->next;
				}
		}
		else
		{
			ptr=ptr->next;
		}
	}
	
	if(temp->noc==0)
	{
		free(temp);
		ret_ptr=NULL;
	}
	else
	{
		ret_ptr=temp;
	}
	return(ret_ptr);
}

void Is_full(struct Book* ptr)
{
	struct Book*temp;
	temp=(struct Book*)malloc (sizeof(struct Book));
	if(temp==NULL)
	{
		printf("\n RECORDS FULL \n");
	}
	else
	{
		printf("\n RECORDS NOT FULL \n");
	}
	free(temp);
}

int getnumrecords(struct Book * ptr)
{
	int ret_val=0;
	while(ptr!=NULL)
	{
		ret_val++;
		ptr=ptr->next;	
	} 
	return(ret_val);
}

struct Book* mergesort(struct Book *ptr)
{
	struct Book *ptr1,*ret_ptr;
	ret_ptr=ptr;
	
	if(ptr->next!=NULL)
	{
		ptr1=divide(ptr);
		
		//printf("list1 from original list:\n");
		//print(ptr);

		//printf("list2 from original list:\n");
		//print(ptr1);
		
		ptr=mergesort(ptr);			//calling recursively mergesort function
		ptr1=mergesort(ptr1);		//calling recursively mergesort function
		
		ret_ptr=merge(ptr,ptr1);	//merging the two sorted list/records
	}
	return(ret_ptr);
}
struct Book * merge(struct Book * lptr1,struct Book *lptr2)
{
	struct Book *temp,*ret_ptr;
	int cmp;						//to save the output of comparision of two strings
	if(lptr1==NULL)
	{
		ret_ptr=lptr2;
	}
	else if(lptr2==NULL)
	{
		ret_ptr=lptr1;
	}
	else
	{
		cmp=strcmp(lptr1->author,lptr2->author);
		if(cmp<0)
		{
			temp=lptr1;
			lptr1=lptr1->next;
		}
		else if(cmp>0)
		{
			temp=lptr2;
			lptr2=lptr2->next;
		}
		else
		{
			cmp=strcmp(lptr1->book,lptr2->book);
			if(cmp<0)
			{
				temp=lptr1;
				lptr1=lptr1->next;
			}
			else if(cmp>0)
			{
				temp=lptr2;
				lptr2=lptr2->next;
			}
			else
			{
				if(lptr1->yop>lptr2->yop)
				{
					temp=lptr1;
					lptr1=lptr1->next;
					lptr2=lptr2->next;	
				}
				else if(lptr1->yop<lptr2->yop)
				{
					temp=lptr2;
					lptr1=lptr1->next;
					lptr2=lptr2->next;
				}
				else
				{
				temp=lptr1;
			    lptr1=lptr1->next;
			    lptr2=lptr2->next;
				}
			}
		}
	}
	ret_ptr=temp;
	while(lptr1!=NULL&&lptr2!=NULL)
	{
		cmp=strcmp(lptr1->author,lptr2->author);
		if(cmp<0)
		{
			temp->next=lptr1;
			temp=lptr1;
			lptr1=lptr1->next;
		}
		else if(cmp>0)
		{
			temp->next=lptr2;
			temp=lptr2;
			lptr2=lptr2->next;
		}
		else
		{
			cmp=strcmp(lptr1->book,lptr2->book);
			if(cmp<0)
			{
				temp->next=lptr1;
				temp=lptr1;
				lptr1=lptr1->next;
			}
			else if(cmp>0)
			{
				temp->next=lptr2;
				temp=lptr2;
				lptr2=lptr2->next;
			}
			else
			{ 	
				if(lptr1->yop>lptr2->yop)
				{
					temp->next=lptr1;
					temp=lptr1;
					lptr1=lptr1->next;
					lptr2=lptr2->next;	
				}
				else if(lptr1->yop<lptr2->yop)
				{
					temp->next=lptr2;
					temp=lptr2;
					lptr1=lptr1->next;
					lptr2=lptr2->next;
				}
				else
				{
					temp->next=lptr1;
				   	temp=lptr1;
				   	lptr2=lptr2->next;
				   	lptr1=lptr1->next;
				}
				
			}
				
		}	
	}
	if(lptr1!=NULL)
	{
		temp->next=lptr1;
	}
	else if(lptr2!=NULL)
	{
		temp->next=lptr2;
	}
	
	return(ret_ptr);
}

struct Book *divide(struct Book *ptr)
{
	struct Book *slow,*fast,*ret_ptr; // ret_ptr is the pointer that points where we broke the list/record
	slow=ptr;
	fast=ptr->next->next;
	while(fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
		}
	}
	ret_ptr=slow->next;
	slow->next=NULL;
	return(ret_ptr);
}


void Is_empty(struct Book* ptr)
{
	if(ptr==NULL)
	{
		printf(" RECORDS EMPTY \n");
	}
	else
	{
		printf(" NOT EMPTY \n");
	}
}

struct Book * insert(struct Book* ptr)
{
	struct Book *temp,*search;
	int found=0,cmp=1;
	search=ptr;
	temp=(struct Book *) malloc(sizeof(struct Book));
	
		//inputing data of records 
		
		printf("Enter the Author's name \n");
		scanf("%s",temp->author);
		printf("Book's name \n");
		scanf("%s",temp->book);
		printf("Year of Publication \n");
		scanf("%d",&temp->yop);
		printf("Number of available copies\n");
		scanf("%d",&temp->noc);
		
		if(ptr==NULL)							//inserting new record as list is empty
		{
			temp->next=ptr;
			ptr=temp;
		}
		else
		{
			while(search!=NULL&&found==0)		//searching if or not the record already exists if it does we update the values of yop and noc
			{
				cmp=strcmp(search->author,temp->author);
				if(cmp==0)
				{
					cmp=strcmp(search->book,temp->book);
					if(cmp==0)
					{
						found=1;
						search->yop=temp->yop;
						search->noc=temp->noc;
					}
					else
					{
						search=search->next;
					}
				}
				else
				{
					search=search->next;
				}
			}
			if(found==0)					//record does not exists so inserting new record
			{
				temp->next=ptr;
				ptr=temp;
			}
		}
	ptr=mergesort(ptr);
	return(ptr);
}

struct Book * create_record(int n,struct Book*ptr)
{
	struct Book *temp;
	int i;
	for(i=0;i<n;i++)
	{
		temp=(struct Book *) malloc(sizeof(struct Book));
		
			//inputing data for record
			
			printf("\n\nEnter the Author's name \n");
			scanf("%s",temp->author);
			printf("Book's name \n");
			scanf("%s",temp->book);
			printf("Year of Publication \n");
			scanf("%d",&temp->yop);
			printf("Number of available copies\n");
			scanf("%d",&temp->noc);
			
		temp->next=ptr;
		ptr=temp;
	}
	ptr=mergesort(ptr);
	return(ptr);
}

int print(struct Book *ptr)
{
	if(ptr==NULL)
	{
		printf("\n RECORD IS EMPTY \n\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("                      AUTHOR : %s \n",ptr->author);
			printf("                      BOOK : %s \n",ptr->book);
			printf("                      YEAR OF PUBLICATION : %d\n",ptr->yop);
			printf("                      NO. OF AVAILABLE COPIES : %d\n",ptr->noc);
			ptr=ptr->next;
		}
	}
	return(0);
}

void kth_pop(struct Book *ptr ,int k )
{
	struct Book *temp;
	int a[SIZE],i,j,swap;
	temp=ptr;
	for(i=0;i<SIZE;i++)
	{
		a[i]=0;
	}
	i=0;
	while(temp!=NULL)
	{
		a[i]=temp->noc;
		i++;
	}
	temp=ptr;
	for(i=0;i<SIZE;i++)
	{
		for(j=i+1;j<SIZE;j++)
		{
			if(a[i]<a[j])
			{
				swap=a[i];
				a[i]=a[j];
				a[j]=swap;	
			}
			else if(a[i]=a[j])
			{
				a[j]=0;
			}
		}
	}
	for(i=0;i<SIZE;i++)
	{
		for(j=i+1;j<SIZE;j++)
		{
			if(a[i]<a[j])
			{
				swap=a[i];
				a[i]=a[j];
				a[j]=swap;	
			}
		}
	}
	printf(" Enter the value of kth position \n");
	while(temp!=NULL)
	{
		if(temp->noc==a[k-1])
		{
			printf(" THE Kth POPULAR AUTHOR IS : %s ",temp->author);
		}
	}	
}

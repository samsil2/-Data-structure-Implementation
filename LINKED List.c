#include <stdio.h>
#include <stdlib.h>
 

typedef struct   list{
	int v;//variable for storing value
	struct list *n; //storing refencence(ptr) 
}h; 

h*cr()
{
return (h*)malloc(sizeof(h)); //memory allocate 
}

//insertion function
void insert(h*t,int data){
while(t->n!=NULL) 
{
t=t->n;//updating
}
t->n=cr();  //Make next of new node as head
t->n->v=data; //put in the data
t->n->n=NULL; //
}

//display function
void display(h * t)
{
	while(t->n!=NULL)
	{
		printf("%d -> ",t->n->v);
t=t->n;
	}
	printf("NULL\n");
}
//search function
int search(h*t,int data)
{
int i=0;
while(t->n!=NULL)
{
i++;
if(data==t->n->v)
{
printf("\nvalue found.Location= %d\n",i);
return i;
}
t=t->n;
}
}
//insert after 
void insert_after(h * t,int search,int data)
{
	while(t->n!=NULL)
	{
		if(t->n->v == search)
{
h *store = t->n->n;
t->n->n = cr();
t->n->n->v = data;
t->n->n->n = store;
printf("\n %d is inserted\n",data);
}
t=t->n;
	}
}

//delete function
int deletef(h *t, int data)
{
while(t->n != NULL)
{
if(t->n->v == data)
{
t->n = t->n->n;
printf("\n%d is deleted\n",data);
return 0;
}
t = t->n;
}
}

//node counting function
void countNode(h *t)
{
int count = 0;
while(t->n != NULL)
{
count++;
t = t->n ;
}
printf("\n %d nodes found.\n", count);
}

/* Driver program to test above functions*/
int main()
{
	h*f=cr();//allocate node
	 
f->n=NULL; /* Start with the empty list */
//for insertion passing reference and value as argument
insert(f, 5);  // Insert 5.  So linked list becomes 5->NULL
insert(f, 9);  // Insert 9.  So linked list becomes 9->NULL
insert(f, 11);   // Insert 11.  So linked list becomes 11->NULL
insert(f, 9);  // Insert 9.  So linked list becomes 9->NULL
printf("Display:\n");
display (f);//passing reference as argument
printf("\nTotal nodes:\n");
countNode(f );//passing reference as argument
printf("\nSearch value:\n");
search(f, 11);//for searching we pass reference and key value as argument
printf("\nInsert after:\n");
insert_after (f, 11, 44);//
printf("\nDelete node:\n");
deletef (f, 9);//for  deletion  passing reference and value as argument
printf("\nAgain Display:\n");
display(f);
}

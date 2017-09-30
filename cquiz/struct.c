#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct stu1
{
	int roll;
	char *name;
	double marks;
}STU1;

typedef struct stu2
{
	int roll;
	char *name;
	double marks;
}STU2;



union cqbu
{
	int a;
	char b;
};
	
struct cqbs
{
	int a;
	char b;
};


typedef struct gullu
{
	int num;
	struct gullu **p;
	struct gullu ***q;
}cqb;

struct mystruct
{
	int a;
	char b;
}*p;

int main()
{
	
/*	STU1 s1={25,"Shashank",84.57}, *p1;
	static STU2 *p2;
	p1 = &s1;
	memccpy(p2,p1,'\0',sizeof(STU1));
	printf("%d\n",p2->roll);
	printf("%s\n",p2->name);
	printf("%lf\n",p2->marks);
*/

///#######################---------#########################//////
	
/*	union cqbu u={25};
	struct cqbs *qs = (struct cqbs *)&u;
	union cqbu *qu = (union cqbu *)&u;
	
	printf("%d %d\n",qs->a,qs->b);	
	printf("%d %d\n",qu->a,qu->b);	
*/	
	
///#######################---------#########################//////
	
/*	static cqb *var1, **var2;
	cqb temp = {5,&var1,&var2};
	var2 = &var1;
	var1->num=25;
	printf("%d  %d\n",**(temp.q),***(temp.q));	
*/	
	
///#######################---------#########################//////
	
	struct mystruct ms={400,'A'};
	printf("%d %d\n",p->a,p->b);				
					
	
	
		
	
	return 0;
}	

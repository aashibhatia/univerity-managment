#include<stdio.h>
#include<math.h>
#include<string.h>

struct university
{
	char collname[100];
	char collid[10];
	char address[100];
	char course[10];
	
}uni;


struct student 
{
	char fname[20];
	char lname[20];
	char gender[10];
	long long contact;
	int year;
	char roll[15];
	char pass[15];
	char branch[4];
	int pointer;
	struct university co;
}stud;


void insert_coll()
{
		int ch;
		FILE* fc;
		fc=fopen("coll.dat","a");
		do
		{
		
			printf("\n ENTER COLLAGE NAME --- ");
			scanf("%s",uni.collname);
			printf("\n ENTER COLLAGE ID --- ");
			scanf("%s",uni.collid);
			printf("\n ENTER COLLAGE ADDRESS--- ");
			scanf("%s",uni.address);
			printf("\n ENTER COURSE--- ");
			scanf("%s",uni.course);
			fwrite(&uni,sizeof(uni),1,fc);
			printf("\n WANT TO ENTER MORE RECORD(press 1)----");
			scanf("%d",&ch);
		}
		while (ch==1);
		fclose(fc);
}


void insert_stud()
{
		FILE* fs;
		fs=fopen("stu.dat","a");
		printf("\n ENTER STUDENT  FIRST NAME --- ");
		scanf("%s",stud.fname);
		printf("\n ENTER STUDENT  LAST NAME --- ");
		scanf("%s",stud.lname);
		printf("\n GENDER---(f/m)");
		scanf("%s",stud.gender);
		printf("\n ENTER STUDENT ROLL NUMBER--- ");
		scanf("%s",stud.roll);
		printf("\n ENTER PASSWORD--- ");
		scanf("%s",stud.pass);
		printf("\n ENTER CONTACT NUMBER--- ");
		scanf("%lld",&stud.contact);
		printf("\n ENTER BRANCH--- ");
		scanf("%s",stud.branch);
		printf("\n ENTER COLLAGE NAME--- ");
		scanf("%s",stud.co.collname);
		fwrite(&stud,sizeof(stud),1,fs);
		fclose(fs);	
}

void dis_coll()//DISPLAY COLLAGE DETAILS
{
	FILE* fc;
	fc=fopen("coll.dat","r");
	if (fc==NULL)
	{
		printf("CAN'T OPEN THIS FILE!!!");
		
	}
		printf("\tCOLLAGE NAME\t\tCOLLAGE ID\tADDRESS\t\tCOURSE\n");
	//fseek(fc, 0, SEEK_SET);
	while(fread(&uni,sizeof(uni),1,fc))
	{
		//int i=1;
		
		printf("\t\t%s\t\t%s\t\t%s\t\t\t%s\n" ,uni.collname,uni.collid,uni.address,uni.course);
		//i++;
	
	}
	fclose(fc);
}
	
void dis_stud()
{
	char rollno[20],pass[20];
	FILE* fc;
	fc=fopen("stu.dat","r");
	if(fc==NULL)
	{
		printf("CAN'T OPEN THIS FILE!!!");
	}
	printf("\n TO SEE DETAIL FIRST U HAVE TO LOGIN....");
	printf("\n ENTER ROLL NUMBER...");
	scanf ("%s",rollno);
	printf("\n ENTER PASSWORD...");
	scanf("%s", pass);
	int flag=0;
	if (fc==NULL)
	{
		printf("CAN'T OPEN THIS FILE!!!");
		
	}
	printf("\tNAME\t\tGENDER\t\tCONTACT NUMBER\t\t\tYEAR\t\tBRANCH\t\tCOLLAGE  ");
	
	while (fread(&stud,sizeof(stud),1,fc))
	{
		if(strcmp(rollno,stud.roll)==0 && strcmp(pass,stud.pass)==0)
		{
			flag=1;
			
			
			printf("\n\t%s %s\t\t%s\t\t%lld\t\t\t%d\t\t\t%s\t\t%s", stud.fname,stud.lname ,stud.gender,stud.contact,stud.year,stud.branch,stud.co.collname);
			break;
		}
		
	}
	
	if(!flag)
		printf("\nENTER CORRECT ROLL NO OR PASSWORD!!!\n\n");
	fclose(fc);
	

	
	}	
	
void studen()
{
	FILE* f;
	int flag=0;
	char collage[50];
	f=fopen("stu.dat","r");
	if (f==NULL)
	{
		printf("CAN'T OPEN THIS FILE!!!");
		
	}
	printf("ENTER THE NAME OF COLLAGE--- ");// STUDENT LIST BELONG TO SAME COLLAGE
	scanf("%s",collage);
	printf(" NAME\t ROLLNO.");
	while(fread(&stud,sizeof(stud),1,f))
	{
		if(strcmp(collage,stud.co.collname)==0 )
		{
			flag=1;
			printf("\n%s %s\t%s",stud.fname,stud.lname,stud.roll);
		}
	
		
	}
	if(flag!=1)
	printf("RECORD NOT FOUND!!! LOL");
	fclose(f);
	
}
int main()
{
	int ch,c,s;
	printf("\t\t\t -----------------UNIVERSITY MANAGEMENT------------------ ");
	do {
		printf("\n--MENU--");
		printf("\n1.COLLAGE DETAILS--- ");
		printf("\n2.STUDENTS DETAILS--- ");
		printf("\n3.EXIT");
		printf("\nENTER YOUR CHOICE-------- ");
		scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			{
				printf("\n\t\t--------COLLAGE-------- ");
				printf("\n MENU ");
				printf("\n1.ENTER NEW RECORD--- ");
				printf("\n2.DISPLAY--- ");
				printf("\nENTER YOUR CHOICE-------- ");
				scanf("%d",&c);
				if(c==1)
				insert_coll();
				else if(c==2)
				dis_coll();
				else printf("\nYOU ENTER WRONG CHOICE........!!!!");
				break;
			}
		case 2:
			{
				printf("\n\t -------STUDENT------- ");
				printf("\nMENU-- ");
				printf("\n1.ENTER NEW RECORD--- ");
				printf("\n2.DISPLAY DETAILS OF THE STUDENT--- ");//USER HAVE TO ENTER THEIR CORRECT ROLL NUMBER AND PASSWORD.
				printf("\n3.STUDENTS IN SAME COLLAGE");
				printf("\nENTER YOUR CHOICE-------- ");
				scanf("%d",&s);
				if(s==1)
				insert_stud();
				else if(s==2)
				dis_stud();//USER HAVE TO ENTER THEIR CORRECT ROLL NUMBER AND PASSWORD.
				else if(s==3)
				studen();
				else printf("\nYOU ENTER WRONG CHOICE........!!!!");
				break;
				/*enter  for both cases and break*/
			}
		case 3: break;
		
		default: printf("\n CHOOSE CORRECT OPTION.... ");
				break;
   	}
		
	}while(ch!=3);

	return 0;
	
	
}


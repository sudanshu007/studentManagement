#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<strings.h>

typedef struct
{
	char sfname[20];
	char slname[20];
	char gfname[20];
	char glname[20];
	char fac[10];
	int roll;
	char gender[7];
              int year;
	char phone[15];
	char add[20];
	char dob[10];

}STUDENT;

int main()
{
   	 STUDENT s;
	int choice,recsize,id,choice1,r,y,g,i;
	FILE *fp,*ft;
	char q,another,fn[20],ln[20];
	fp=fopen("studentdata.dat","rb+");
	if(fp==NULL)
	{
		fp=fopen( "studentdata.dat","wb+");
		if(fp==NULL)
		{
			printf("File cannot be accessed");
			getch();
			exit(1);
		}
	}
	recsize=sizeof(s);

    printf("\t\t           ***********************     \n");
    printf("\t\t        **      S T U D E N T      **\n");
    printf("\t\t     **        D A T A B A S E       **\n");
    printf("\t\t        **      S Y S T E M        **\n");
    printf("\t\t           ***********************     \n\n");

    while(1)
    {
        printf("\n\n");
        printf("\t|=================|\n");
        printf("\t|___MAIN___MENU___|\n");
        printf("\t|=================|\n\n");
        printf("\t _____________________\n");
        printf("\t|[1].List Records     |\n\t|[2].Add Records      |\n\t|[3].|Delete Records  |\n\t|[4].|Modify Records  |\n\t|[5].Search Records   |\n\t|[6].Exit             |\n");
printf("\t|_____________________|\n");
              printf("\n\n\tEnter your choice  :  ");
	fflush(stdin);
	scanf("%d",&choice);
	printf("\n\n");
              switch(choice)
	{
 	       case 1:
                    	rewind(fp);
                             printf("\n\t\t\t     |==================|\n\t\t\t     | LIST of STUDENTS              |\n\t\t\t     |==================|\n\n");
                 	printf("NAME\t             Roll no.    Address       Phone no.       Faculty  Year\n");

                	 while((fread(&s,recsize,1,fp))==1)
                 	{
                         		printf("%-9s%-12s%-12d%-14s%-15s %-        9s%d\n",s.sfname,s.slname,s.roll,s.add,s.phone,s.fac,s.year);

                 }
                 printf("\n\n");

                 break;



            case 2:
	fseek(fp,0,SEEK_END);
	another='Y';
	printf("\n\t\t\t     |======================|\n\t\t\t     | ADD STUDENT'S RECORD |\n\t\t\t     |======================|\n\n");
                while((another=='Y')|| (another=='y'))
	{
	     printf("Enter the student's first name\t:   ");
                    scanf("%s",s.sfname);
                    fflush(stdin);
                    printf("Enter the student's last name\t:   ");
                    scanf("%s",s.slname);
                    fflush(stdin);
                    printf("Enter the roll no.\t:   ");
                    scanf("%d",&s.roll);
                    printf("Enter the faculty\t:   ");
                    scanf("%s",s.fac);
                    fflush(stdin);
                    printf("Enter the Address\t:   ");
                    scanf("%s",s.add);
                    fflush(stdin);
                    printf("Enter the phone no.\t:   ");
                    scanf("%s",s.phone);
                    printf("Enter the year joined\t:   ");
                    scanf("%d",&s.year);
                    printf("Enter the Guardian's first name\t:   ");
                    scanf("%s",s.gfname);
                    fflush(stdin);
                    printf("Enter Guardian's last name\t:   ");
                    scanf("%s",s.glname);
                    fflush(stdin);
                    printf("Enter the Date of Birth\t:   ");
                    scanf("%s",s.dob);
                    fflush(stdin);
                    printf("Enter the Gender\t:   ");
                    scanf("%s",s.gender);
                    printf("\n\n");
	     fwrite(&s,recsize,1,fp);
	     printf(" Add another Record (Y/N): ");
  	     fflush(stdin);
	    another=getchar();
	     printf("\n");
	}
break;
case 3:
        another='Y';
        printf("\n\t\t\t     |=========================|\n\t\t\t     | DELETE STUDENT'S RECORD |\n\t\t\t     |=========================|\n\n");
        while((another=='Y')|| (another=='y'))
        {
 	fread(&s,recsize,1,fp);
               printf("Enter the first name of the student to be deleted :  ");
	scanf("%s",fn);
	printf("Enter the last name of the student to be deleted :  ");
	scanf("%s",ln);
	rewind(fp);
 if(strcmp(s.sfname,fn)==0&&strcmp(s.slname,ln)==0)
                    {
                           printf("\n");
                             printf("\nName            :   %s %s",s.sfname,s.slname);
                             printf("\nGender          :   %s",s.gender);
                             printf("\nDate of Birth   :   %s",s.dob);
                            printf("\nGuardian Name   :   %s %s",s.gfname,s.glname);
                             printf("\nFaculty         :   %s\nRoll no.        :   %d\nYear Joined     :   %d\nAddress         :   %s\nContact no.     :   %s\n\n\n",s.fac,s.roll,s.year,s.add,s.phone);
                              printf("\n\n");
                               q='k';
                                 while(1)
                                 {
                                           if((q=='y')||(q=='Y'))
                                                 {
                                                         ft=fopen("TEMP.dat","wb");
                                                          while((fread(&s,recsize,1,fp))==1)
				     {
                                               if((strcmp(s.sfname,fn)!=0)&&(strcmp(s.slname,ln)!=0))
						          fwrite(&s,recsize,1,ft);
				      }
				       fclose(fp);
				       fclose(ft);
                                                                 remove("studentdata.dat");	                                                                 		                                                   rename("TEMP.dat","studentdata.dat");
			                       fp=fopen("studentdata.dat","rb+");
                                                                    break;
                                                        }
                                                        if((q!='y')&&(q!='Y')&&(q!='n')&&(q!='N'))
                                                        {
                                                                                                  printf("Confirm Data Delete (Y/N)   :   ");
                                                                                                  q=getche();
                                                                                                  printf("\n\n");

                                                        }
                                                        if((q=='n')||(q=='N'))
                                                        {
                                                                              break;
                                                        }


                                                     }


                    }
                    else
                    {
                        printf("Sorry!!\nNo match Found\n\n\n");
                    }

					printf("\nDo you want to Delete another Record(Y/N): ");
					fflush(stdin);
					another=getchar();
	}

	break;
	case 4:
	another='Y';
	printf("\n\t\t\t     |=========================|\n\t\t\t     | MODIFY STUDENT'S RECORD |\n\t\t\t     |=========================|\n\n");
while((another=='Y')|| (another=='y'))
	{
		printf("Enter first name of student to modify : ");
		scanf("%s",fn);
		printf("\nEnter last name of student to modify : ");
		scanf("%s",ln);
                    	rewind(fp);
		while((fread(&s,recsize,1,fp))==1)
		{
			if((strcmp(s.sfname,fn)==0)&&(strcmp(s.slname,ln)==0))
			{
                                                     printf("\n");
                                                     printf("\nName            :   %s %s",s.sfname,s.slname);
                                                     printf("\nGender          :   %s",s.gender);

                                                     printf("\nDate of Birth   :   %s",s.dob);
                                                     printf("\nGuardian Name   :   %s %s",s.gfname,s.glname);
                                                     printf("\nFaculty         :   %s\nRoll no.        :   %d\nYear Joined     :   %d\nAddress         :   %s\nContact no.     :   %s\n\n\n",s.fac,s.roll,s.year,s.add,s.phone);
                                                     printf("\n\n");

                                                     printf("\nEnter the student's new first name\t");
                                                     scanf("%s",s.sfname);
                                                     fflush(stdin);
                                                     printf("Enter the student's new last name\t");
                                                     scanf("%s",s.slname);
                                                     fflush(stdin);
                                                     printf("Enter the new roll no.\t");
                                                     scanf("%d",&s.roll);
                                                     printf("Enter new faculty\t");
                                                     scanf("%s",s.fac);
                                                     fflush(stdin);
                                                     printf("Enter the new Address\t");
                                                     scanf("%s",s.add);
                                                     fflush(stdin);
                                                     printf("Enter the new phone no.\t");
                                                     scanf("%s",s.phone);
                                                     printf("Enter the new year joined\t");
                                                     scanf("%d",&s.year);
                                                     printf("Enter the Guardian's new first name\t");
                                                     scanf("%s",s.gfname);
                                                     fflush(stdin);
                                                     printf("Enter Guardian's new last name\t");
                                                     scanf("%s",s.glname);
                                                     fflush(stdin);
                                                     printf("Enter the new Date of Birth\t");
                                                     scanf("%s",s.dob);
                                                     fflush(stdin);
                                                     printf("Enter new Gender\t");
                                                     scanf("%s",s.gender);
                                                     fflush(stdin);
                                                     printf("\n\n");

 fseek(fp,-recsize,SEEK_CUR);
 fwrite(&s,recsize,1,fp);
 break;
			}
	else
                         {
                             printf("\nSorry!!\nNo match Found\n");
                         }
	}
	printf("Do you want to Modify another record(Y/N): ");
	printf("\n\n");
               fflush(stdin);
	another=getchar();
}

break;

	case 5:
               another='Y';
               printf("\n\t\t\t     |=========================|\n\t\t\t     | SEARCH STUDENT'S RECORD |\n\t\t\t     |=========================|\n\n");
	while((another=='Y')|| (another=='y'))
{
                                         rewind(fp);
                                         fread(&s,recsize,1,fp);

       printf("\n\nSearch By:\n[1]Name\n[2]Roll no.\n");
                                         printf("Enter your choice [1] or [2]   :   ");
                                         scanf("%d",&choice1);
                                         switch(choice1)
                                         {
                                                        case 1:
                                                             printf("\nEnter the first name\t");
                                                             scanf("%s",fn);
                                                             printf("\nEnter the last name\t");
                                                             scanf("%s",ln);
                                                             if((strcmp(s.sfname,fn)==0)&&(strcmp(s.slname,ln)==0))
                                                             {
                                                                                           printf("\nName            :   %s %s",s.sfname,s.slname);
                                                                                           printf("\nGender          :   %s",s.gender);
                                                                                           printf("\nDate of Birth   :   %s",s.dob);
                                                                                           printf("\nGuardian Name   :   %s %s",s.gfname,s.glname);
                                                                                           printf("\nFaculty         :   %s\nRoll no.        :   %d\nYear Joined     :   %d\nAddress         :   %s\nContact no.     :   %s\n\n\n",s.fac,s.roll,s.year,s.add,s.phone);
                                                             }

                                                             else
                                                             {
                                                                 printf("\nSorry!!\nNo match Found\n");
                                                             }

                                                             break;

                                                             case 2:
                                                             printf("\nEnter the Roll no.   :   ");
                                                             scanf("%d",&r);
                                                             printf("\nEnter the Year joined   :   ");
                                                             scanf("%d",&y);
                                                             printf("\n\n");
                                                             if((r==s.roll)&&(y==s.year))
                                                             {
                                                                  printf("\nName            :   %s %s",s.sfname,s.slname);
                                                                  printf("\nGender          :   %s",s.gender);
                                                                  fflush(stdout);
                                                                  printf("\nDate of Birth   :   %s",s.dob);
                                                                  printf("\nGuardian Name   :   %s %s",s.gfname,s.glname);
                                                                  printf("\nFaculty         :   %s\nRoll no.        :   %d\nYear Joined     :   %d\nAddress         :   %s\nContact no.     :   %s\n\n\n",s.fac,s.roll,s.year,s.add,s.phone);
                                                                  }

                                                                  else
                                                                  {
                                                                  printf("\nSorry!!\nNo match Found\n");
                                                                  }
                                                                  break;


                                                                  default:
                                                                  printf("\n\n\nINVALID CHOICE\n\n");
                                                                  getch();
                                                                  }

       printf("\nDo you want to Search another record(Y/N): ");
                  printf("\n\n");
                  fflush(stdin);
                  another=getchar();
                  }



             break;

             case 6:
				fclose(fp);
                printf("\nThank You for using our programm... :)\n");
				getch();
                exit(1);
                break;

             default:
                     printf("        INVALID CHOICE\n\n\n\n\n");
                     getch();
}
	}
	fclose(fp);
	return(0);
}

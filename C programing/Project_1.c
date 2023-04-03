#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
void add_record();
void view_records();
void search_records();
void delete();
struct student
{
    char name[20];
    char course[20];
    long roll;
    float cgpa;
    char city[20];
};
int main()
{
    system("cls");
    int choice;
    
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\tStudent record management System ");
    printf("\n\n\t\t\t\t\t\t----------***************----------\n");
    printf("\n\t\t\t\t\t\t1: Add student record\n");
    printf("\n\t\t\t\t\t\t2: View Student records\n");
    printf("\n\t\t\t\t\t\t3: Search Record\n");
    printf("\n\t\t\t\t\t\t4: Delete Records\n");
    printf("\n\t\t\t\t\t\t5: Exit: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        add_record();
        break;

    case 2:
        system("cls");
        view_records();
        break;

    case 3:
        system("cls");
        search_records();
        break;
    case 4:    
        system("cls");
        delete();
        break;
    case 5:
        system("cls");
        return 0;
        break;
    default :
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\tPlease enter valid input!");
    }
    getch();
    return 0;
}
void add_record()
{   
    system("cls");
    FILE *fptr;
    struct student add;
    char another;
    fptr = fopen("file.txt", "ab+");
    
    if (fptr == NULL)
    {
        printf("\n\n\n\n\n\t\t\t\t\tCan't open the file!");
    }
    do
    {
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t**************Add details of student**************");
        printf("\n\n\n\t\t\t\t\t\tEnter the details of student:\n");

        printf("\n\t\t\t\t\t\tEnter student's name: ");
        scanf("%s", &add.name);
        printf("\n\t\t\t\t\t\tEnter student's course: ");
        scanf("%s", &add.course);
        printf("\n\t\t\t\t\t\tEnter student's roll no: ");
        scanf("%ld", &add.roll);
        printf("\n\t\t\t\t\t\tEnter the CGPA obtained: ");
        scanf("%g", &add.cgpa);
        printf("\n\t\t\t\t\t\tEnter student's address: ");
        scanf("%s", &add.city);

        fwrite(&add, sizeof(add), 1, fptr);

        printf("\n\t\t\t\t\t\tDo you want store more records? (Y/N): ");
        scanf("%s",&another);
        
    } while (another == 'y' || another == 'Y');

    fclose(fptr);
    main();
}
void view_records()
{
    system("cls");
    int inp;
    struct student add;

    FILE *ptr;
    ptr = fopen("file.txt", "rb+");
    char c;

    printf("\n\n\n\t\t\t\t\t\t    *****Details of students*****\n\n");
    printf("\t\t\t\t-----------------------------------------------------------------------\n\n");

    printf("\n\t\t\t\tName\t\tCourse\t\tRoll no\t\tCGPA\t\tAddress\n");
    printf("\t\t\t\t_______________________________________________________________________\n\n");
    while (fread(&add, sizeof(struct student), 1, ptr))
    {
        printf("\n\t\t\t\t%s\t\t%s\t\t%ld\t\t%g\t\t%s\n",add.name,add.course,add.roll,add.cgpa,add.city);
    }
    fclose(ptr);
    printf("\n\n\n\n\t\t\t\tPress 1 to enter main menu: ");
    scanf("%d", &inp);
    switch (inp)
    {
    case 1:
        main();
    }
}
void search_records()
{   
    FILE *ptr;
    struct student add;
    ptr = fopen("file.txt","rb+");
    
    long roll; 
    int a,val = 0;
    printf("\n\n\n\n\n\n\n\t\t\t\t\t___________*Search student record*___________\n\n");
    printf("\n\n\t\t\t\t\tEnter the roll no: ");
    scanf("%ld",&roll);
    
    
    while(fread(&add,sizeof(add),1,ptr) > 0 && val == 0)
    if(roll == add.roll)
    {   
        val = 1;
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t___________*Search student record*___________\n\n");
        printf("\n\t\t\t\t\t1 record found for %ld",roll);
        printf("\n\n\t\t\t\t\t---------------------------------------------\n\n");
        printf("\t\t\t\t\tName of student           : %s\n\n", add.name);
        printf("\t\t\t\t\tCourse of student         : %s\n\n", add.course);
        printf("\t\t\t\t\tStudent's roll no         : %ld\n\n", add.roll);
        printf("\t\t\t\t\tCGPA obtained by student  : %g\n\n", add.cgpa);
        printf("\t\t\t\t\tAddress of student        : %s\n", add.city);
        printf("\t\t\t\t\t_____________________________________________\n\n");
        printf("\t\t\t\t\tPress 1 to enter main menu: ");
    }
    fclose(ptr);
    scanf("%d",&a);
    if (a == 1)
    {
        main();
    }
    
}

void delete()
{
    FILE *ptr1, *ptr2;
    struct student add;
    char ch[20];
    int inp;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t__________Delete student's record__________\n");
    printf("\n\t\t\t\t\tEnter student's name: ");
    scanf("%s",ch);
    
    ptr1 = fopen("file.txt","rb+");
    ptr2 = fopen("temp.txt","wb+");

    while(fread(&add,sizeof(struct student),1,ptr1))
    {
        if (strcmp(add.name,ch) != 0)
        {
            fwrite(&add,sizeof(struct student),1,ptr2);
        }
    }
    printf("\n\t\t\t\t\tRecord deleted successfully.....");
    printf("\n\t\t\t\t\t_________________________________\n");
    fclose(ptr1);
    fclose(ptr2);
    remove("file.txt");
    rename("temp.txt","file.txt");
    printf("\n\t\t\t\t\tPress 1 to enter main menu: ");
    scanf("%d",&inp);
    if(inp == 1){
        main();
    }   
}

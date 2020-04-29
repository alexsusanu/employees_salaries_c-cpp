#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "colours.h"
#define MAX_NAME 30
#define MAX_FILE 10

int ckf_ex();
FILE *write_f(const char file[MAX_FILE]);
FILE *read_f(const char file[MAX_FILE]);
int add_employee();
int id();

int main()
{
    return 0;
}

int id()
{
    srand(time(NULL));
    return rand() % 100;
}
int add_employee(FILE *file)
{	
    char reply;
    //char file[MAX_FILE];
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    int salary, age;

    //printf("Insert filename to open: ");
    //scanf("%s", file);
    //FILE *f = fopen(file, "a");
    FILE *f = file;

    if (f == NULL)
    {
	puts("Can't open file. Exiting..");
	exit(EXIT_FAILURE);
    }
    
    puts("Insert employees details as folllow: ");
    puts("Insert FIRST NAME: ");
    scanf("%s", first_name);
    
    puts("Insert LAST NAME: ");
    scanf("%s", last_name);

    puts("Insert age");
    scanf("%d", &age);

    puts("Insert salary");
    scanf("%d", &salary);

    puts("Your inserted as follow: ");
    printf("Name: %s Surname: %s Age: %d Salary: %d\n", first_name, last_name, age, salary);
    printf(bold_red);
    printf("To confirm type y / to start over type n: ");
    printf(reset);
    scanf(" %c", &reply);

    if (reply == 'y')
    {
	fprintf(f, "%d,%s,%s,%d,%d", id(), first_name, last_name, age, salary);
	fprintf(f, "\n");
	fclose(f); 
    }else
    {
	//add_employee();
	printf("after Y");
    }
    
    
    return 0;
}

int ckf_ex()
{
    static char file[10];
    
    printf("Insert name for file to check if exists: ");
    scanf("%s", file);
    if (access(file, F_OK) == 0)
    {	
	printf("File exists already.");
	return 0;
    }
    return -1;
}
FILE *write_f(const char file[MAX_FILE])
{	
    FILE *f = NULL;
    char c;
 
    printf("If you wish to write to file, type:\n");
    printf(bold_blue);
    printf("w for writing mode\n");
    printf(reset);
    bool flag = true;
    while (flag)
    {	
	scanf(" %c", &c);
	if(c == 'w')
	{	
	    if (access(file, W_OK))
	    {
		printf("Opening file in ");
		printf(bold_red);
		printf("WRITING MODE .. ");
		printf(reset);
	    }
	    f = fopen(file, "a");
	    flag = false;
	    return f;
	}
	printf("Invalid option. Choose w: ");
    }
    return NULL;
}
    
FILE *read_f(const char file[MAX_FILE])
{	
    FILE *f = NULL;
    char c;    

    printf("If you wish to read the file, type:\n");
    printf(bold_blue);
    printf("r for writing mode\n");
    printf(reset);
    bool flag = true;
    while (flag)
    {	
	scanf(" %c", &c);
	if(c == 'r')
	{	
	    if (access(file, R_OK))
	    {
		printf("Opening file in ");
		printf(bold_red);
		printf("READ MODE .. ");
		printf(reset);
	    }
	    f = fopen(file, "r");
	    flag = false;
	    return f;
	}
	printf("Invalid option. Choose r: ");
    }
    return NULL;
}

int create_file() //bold_redunant, as other func create file if not exist
{	
    char file[MAX_FILE];
    puts("Use this option to create an empty file.");
    printf("Insert name for file: ");
    scanf("%s", file);
    FILE *f = fopen(file, "w"); 
    if (f == NULL)
    {

	puts("Can't open file. Exiting..");
	exit(EXIT_FAILURE);

    }else 
    {
	fprintf(f, "%s,%s,%s,%s,%s", "ID","FIRST NAME","LAST NAME","AGE","SALARY");
	fprintf(f, "\n");
	fclose(f);
	printf("Empty file created as: %s\n", file);
	exit(EXIT_SUCCESS);
    }

}

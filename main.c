#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "colours.h"
#define MAX_NAME 30
#define MAX_FILE 10

/* check file exists, if yes return pointer to that file in 'a' mode (write&read) */
FILE *ckf_ex();
/* add new employee. arg is pointer to file from the ckf_ex() func */
int add_employee(FILE *file);
/*create new file with id name age salary */
int create_file();
/*read from csv file */
int read_file();
/*generate random id */
int id();

int main()
{	
    FILE *f = ckf_ex();
    read_file(f);
    return 0;
}

int read_file(FILE *file)
{	
    char c;
    FILE *f = file;
    if (f == NULL)
    {
	printf("Can't read file");
    }
    while ((c = fgetc(f)) != EOF)
    {
	printf("%c", c);
    }
    fclose(f);
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

FILE *ckf_ex() // return pointer to file if file exists, 'a' mode
{	
    static char file[10];
    char c;
    FILE *f = NULL;
    printf("Insert filename: ");
    scanf("%s", file);

    if (access(file, F_OK) == 0)
    {	
	printf("File exists already.\n");
	printf("Opening file in ");
	printf(bold_red);
	printf("WRITING MODE .. ");
	printf(reset);
	f = fopen(file, "a+");
	return f;
    }else
    {
	printf("File doesn't exists\n");
	printf("If you wish to create new file, type y: ");
	scanf(" %c", &c);
	if(c == 'y')
	{
	   create_file();
	}else
	{
	    printf("Abording..\n");
	    exit(EXIT_FAILURE);
	} 
    }
 
    //if (access(file, W_OK))
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

LAB 5

Q1. Write a program to create a new text file and write some text into it. Open the file in append 

mode and add more text to it. Read the contents of the file and display them on the console.

#include <stdio.h>

int main(){

 FILE *fptr = fopen("test_file.txt", "w");

 fprintf(fptr, "This is my test file\nI have opened it in write 

mode\n");

 fclose(fptr);

 fptr = fopen("test_file.txt", "a");

 fprintf(fptr, "But now I have opened it in append mode\n");

 fclose(fptr);

 fptr = fopen("test_file.txt", "r");

 char str[50];

 while (fgets(str, 50, fptr) != NULL){

 printf("%s", str);}

 

 fclose(fptr);

 return 0;}

Q2. Create a program that reads a text file and counts the number of words in it. Display the total 

number of words at the end.

#include <stdio.h>

int main(){

 FILE *fptr = fopen("test_file.txt", "r");

 char str[100];

 int i, words = 0;

 while (fgets(str, 50, fptr) != NULL){

 i = 0;

 while(str[i] != '\0'){

 if(str[i] == ' ' || str[i] == '\n'){

 words++;}

 i++;

 }

 }

 printf("%d", words);

 fclose(fptr);

 return 0;

} 

Q3.Implement a student database system using a file. Include features to add, delete, modify, and 

display student records.

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int viewRec(FILE *fptr)

{

 fptr = fopen("students.txt", "r");

 char myString[100];

 int j = 0;
printf("%3s %10s %3s %3s\n\n","S. no", "Name", "Roll", 

"Marks");

 while(fgets(myString, sizeof(myString), fptr) != NULL){

 printf("%4d %s", j+1, myString); // loop to write different 

lines

 j++;

 }

 printf("\n");

 fclose(fptr);

 return j;

}

struct Student

{

 char name[100];

 char roll_num[10];

 char marks[4];

};

int main(){

 struct Student *stud = malloc(sizeof(struct Student));

 FILE *fptr;

 int ch;

 char mod[50];

 char myString[100]; // buffer

 char *my_word = malloc(sizeof(char));

 int i = 1, j,k, num, del_num, mod_rec;

 fptr = fopen("students.txt", "r");

 while(fgets(myString, sizeof(myString), fptr) != NULL){

 // printf("%s", myString);

 stud = realloc(stud, i * sizeof(struct Student));

 j = 0;

 while(myString[j] == ' '){ j++;}

 k = 0;

 my_word = realloc(my_word, 0 * sizeof(char));

 while(myString[j] != ' '){

 my_word = realloc(my_word, (k+1) * sizeof(char));

 my_word[k] = myString[j];

 k++;

 j++;

 }

 strcpy(stud[i-1].name, my_word);

 my_word = realloc(my_word, 0 * sizeof(char));

 while(myString[j] == ' '){ j++;}

 k = 0;

 while(myString[j] != ' '){

 my_word = realloc(my_word, (k+1) * sizeof(char));

 my_word[k] = myString[j];

 k++;

 j++;

 }

 strcpy(stud[i-1].roll_num, my_word);

 my_word = realloc(my_word, 0 * sizeof(char));

 while(myString[j]== ' '){ j++;}

 k = 0;

 while(myString[j] != '\n' && myString[j] != ' ' && myString[j] !

= '\0'){

 my_word = realloc(my_word, (k+1) * sizeof(char));

 my_word[k] = myString[j];

 k++;

 j++;}

 strcpy(stud[i-1].marks, my_word);

 strcpy(my_word, "");

 I++;}

 printf("\n");

 fclose(fptr);

 while(1){

 printf("\nSelect an option:\n1. Add Record\n2. View Records\n3. 

Delete Record\n4. Modify Record\n5. Exit\n");

 scanf("%d", &ch);

 // ch = 3;

 printf("\n");

 switch (ch)

 {

 case 1: 

 printf("Enter the name: ");

 scanf("%s", stud[i-1].name);

 printf("Enter the roll number: ");

 scanf("%s", stud[i-1].roll_num);

 printf("Enter the marks: ");

 scanf("%s", stud[i-1].marks);

 fptr = fopen("students.txt", "a");

 fprintf(fptr, "%10s %3s %3s\n", stud[i-1].name, 

stud[i-1].roll_num, stud[i-1].marks);

 stud = realloc(stud, i * sizeof(struct Student));

 i++;

 fclose(fptr);

 break;

 

 case 2:

 viewRec(fptr);

 break;

 case 3:

 num = viewRec(fptr);

 printf("\nEnter the record number to delete: ");

 scanf("%d", &del_num);

 fptr = fopen("students.txt", "w");

 if(del_num > 0 && del_num <= num){

 for(int k = 0; k<num; k++){

 if((k+1) == del_num) {continue;}

 fprintf(fptr, "%10s %3s %3s\n", stud[k].name, 

stud[k].roll_num, stud[k].marks);

 }

 fclose(fptr);}
else{

 printf("Enter a valid record number\n");}

 break;

 

 case 4:

 num = viewRec(fptr);

 printf("\nEnter the record number to modify: ");

 scanf("%d", &del_num);

 if(del_num > 0 && del_num <= num){

 printf("\nEnter the field number to modify:\n1. Name\n2. 

Roll Number\n3. Marks\n");

 scanf("%d", &mod_rec);

 printf("\nEnter the new data:\n");

 scanf("%s", mod);

 switch (mod_rec)

 {

 case 1:

 strcpy(stud[del_num-1].name, mod);

 break;

 case 2:

 strcpy(stud[del_num-1].roll_num, mod);

 break;

 case 3:

 strcpy(stud[del_num-1].marks, mod);

 break;

 

 default:

 printf("Enter a valid field number: ");

 }

 num = viewRec(fptr);

 fptr = fopen("students.txt", "w");

 for(int k = 0; k<num; k++){

 fprintf(fptr, "%10s %3s %3s\n", 

stud[k].name, stud[k].roll_num, stud[k].marks);

 }

 fclose(fptr);

 }

 else{

 printf("Enter a valid record number\n");}

 

 break; 

 case 5:

 fclose(fptr);

 return 0;

 

 default:

 printf("Enter a valid choice!\n");}}

 return 0;

}

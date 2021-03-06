#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define MAXLINE 4096
#include "history.h"


void printToken(char *a);

void successChange(char *b);

int main()
{
struct hist *history;
history=init_history();
  
char buff1[MAXLINE];
char buff2[MAXLINE];
fprintf(stderr,"$");
//Print $
while (fgets(buff1, MAXLINE, stdin) != NULL) {
if(strlen(buff1)==1){
fprintf(stderr,"$");  
}
else{
int count=strlen(buff1);
count--;
buff1[count]='\0'; //replace newline with NULL

strncpy(buff2,buff1,MAXLINE);

char *token = strtok(buff2," ");

add_history(history,buff1);

if (strcmp("exit",token)==0) {
  clear_history(history);
  exit(0);
}
else if(strcmp("cd",token)==0){
char *ch=strtok(buff1," ");

  successChange(ch);  

}

else if (strcmp("history",token)==0){
print_history(history);
  
}

else {

printToken(token);

}  

fprintf(stderr,"$");
}
  
}

clear_history(history);

return 0;
}

void successChange(char *token){
token = strtok(NULL," ");
if (token==NULL){
printf("error: Enter the valid path\n");
  
}
else{
int dir=chdir(token);
if(dir ==0){

char *dirch=getcwd(NULL,0);
printf("%s\n", dirch);  
free(dirch);
}
else{
printf("error: ");
printf(token);
printf(" does not exist\n");  
} 
}
  
}

void printToken(char *token){
int i = 0;
while (token != NULL){
printf ("[%d] %s\n",i, token);
token = strtok (NULL, " ");
i++;
  
}
i=0;
}

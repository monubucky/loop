#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<error.h>

long count_characters(FILE *);

int main(){
	
	FILE *fp,*fq;
	int i=0;
	char ch[50],ph[50],temp;
	fp=fopen("new.txt","w");
	printf("write to store in file:");
	gets(ch);
	fprintf(fp,"%s",&ch);
	fclose(fp);
	
	fp=fopen("new.txt","r");
	 int cnt = count_characters(fp); 
        fseek(fp, -1L, 2);     // makes the pointer fp1 to point at the last character of the file
        printf("Number of characters to be copied %d\n", ftell(fp));
 
        while (cnt)
        {
            ph[i] = fgetc(fp);
          
            fseek(fp, -2L, 1);     // shifts the pointer to the previous character
            cnt--;
            i++;
        }
        printf("%s",ph);
        fclose(fp);
	fp=fopen("new.txt","r");
	fq=fopen("new1.txt","w");
	
	
	while(temp!=EOF){
		if(temp!=EOF){
		
		
		
		temp=fgetc(fp);
		fputc(temp,fq);
	}
	
		
	}
	
	fclose(fp);
	fclose(fq);
	return 0;
}
long count_characters(FILE *f) 
{
    fseek(f, -1L, 2);
    long last_pos = ftell(f); // returns the position of the last element of the file
    last_pos++;
    return last_pos;
}

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    FILE *f;   //pointer for file
    char str[500];
    f=fopen("student_record.csv","r"); //reading file by file pointer.

    int marks_A[6]={0,0,0,0,0,0};       // Array for marks of assignments of Sec-A;
    int marks_B[6]={0,0,0,0,0,0};       // Array for marks of assignments of Sec-B;
    if(f==NULL)
        printf("Error occured!!");  // throw this error if file doesn't exist / null.

    else {

        int i=0;
        int total_A=0;
        int total_B=0;

        while(fgets(str,500,f))
        {       
                int j=0;
                int check =0;   // if check is 1 then it denotes sec-a and 2 for sec-b.
                int m=0;
                char* token = strtok(str, ",");
                while (token != NULL) {
                        // check and count total students of sec-A
                    if(i>0 && j==1 && token[0]=='A' ) {
                        check=1;
                        total_A+=1;


                    }

                        // check and count total students of sec-B
                    if(i>0 && j==1 && token[0]=='B' ) {
                        check=2;
                        total_B+=1;


                    }
                    int x = atoi(token); // covert string into integer
                    
                    //Adding marks of Assignment of Sec-A.
                    if(check==1 && j>1) {

                        marks_A[m]+=x;
                        m++;

                    }
                    //Adding marks of Assignment of Sec-B.
                    if(check==2 && j>1) {

                        marks_B[m]+=x;
                        m++;

                    }

                    token = strtok(NULL, ",");
                    j++;
                }

                i++;
        }

        int id=fork();      //fork system call
        double AvgOfA[6];   // this is for Average of sec-A.
        double AvgOfB[6];   // this is for Average of sec-B.
                
            
                if(id==0){

                    for(int i=0 ; i<6;i++){

                        // here child process created and it calculates the average of sec-A.
                    AvgOfA[i] = (double)marks_A[i]/(double)total_A;
                    printf("Assignment:-%d    Sec-A    %lf\n" ,(i+1), AvgOfA[i]);

                    }
                    printf("\n");
                    exit(0); // exit system call
                }
                printf("\n");
                if(id>0){
                    waitpid(id , NULL , 0);     //waitpid system call

                    for(int i=0 ; i<6;i++){
                        
                    // here Parent process created and it calculates the average of sec-B.
                    AvgOfB[i] = (double)marks_B[i]/(double)total_B;
                    printf("Assignment:-%d    Sec-B    %lf\n" ,(i+1), AvgOfB[i]);

                }
                printf("\n");
                
            }

    } 
    fclose(f);

    return 0;
}
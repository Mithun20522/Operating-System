To compile and run the program:-
        



Q1
                *****WITH PROCESSESS*****

In this question , first we read the CSV file and access section and marks of 
all the 6 assignments in string format and then by using stdtok we convert this string in token which is replaced in single 
one-one word by (,) and then convert into int by using atoi() function.

System calls:-
a) fork()--> by using this we make a child process with id zero of parent process 
             so in child process we calculate average of Sec-A and in parent process we calculate average of sec-B.
b) waitpid()--> by using this we can stop parent class untill child process completed
                so after our parent process start running.
c) exit()--> by using this we are terminating the child process just after execution.

               *****WITH THREADS*****

in this part we perfom same steps like in above , here just a additional step we have done is to calculate average of assignments across both the sections.
here we have created 3 function of void type which is used in thread call.

Threads :-
a) pthread_create()--> by using this we just created 3 new thread with some arguments i.e for sectionA , sectionB and for Both so it will perform working for these functions and 
                    calculates Average of marks for sec-A ,sec-B and for across the both sections.
b) pthread_join()--> this is just simple use to provide clean enviromnent ( by waiting to termination of thread ) for another thread or for default execution.
                    here we also created 3 pthread_join() i.e for Sec-A , Sec-B and for across both the sections.
#include <stdio.h>
#include <string.h>

int main(){
    char StudentName[20] ;
    int grade;
    int average ;
    int econ , english , maths , other;
    int HighestAverage=0;
    int SecondHighestAverage=0;
    char HighestStudent[20] , SecondHighestStudent[20];

    while(1){
        printf("\nEnter the student name( to stop, enter \"End of Data\") : ");
        scanf("%[^\n]",StudentName);

        if (strcmp(StudentName , "End of Data")==0){
            break;}

        printf("Enter the marks of Economics : ");
        scanf("%d",&econ);
        printf("Enter the marks of English : ");
        scanf("%d",&english);
        printf("Enter the marks of Mathematics : ");
        scanf("%d",&maths);
        printf("Enter the marks of Other Subject : ");
        scanf("%d",&other);

        getchar();  //To clear the buffer

        // reject invalid marks
        if (econ < 0 || econ > 100 || english < 0 || english > 100 || maths < 0 || maths > 100 || other < 0 || other > 100) {
            printf("Invalid marks entered. Try again.\n");
            continue;  }


        // calculate the average
        average = (econ + english + maths + other)/4; // calculate the average

        printf("Name :%s , ",StudentName);
        printf("Average : %d , ",average);

        //identify the grade and print it
        if (average<=50)
            { printf("Grade : fail\n");}

        else if (51<=average && average<=64)
         { printf("Grade : Credit\n");}

        else if (65<=average && average<=79)
         { printf("Grade : Distinction\n");}

        else if (80<=average && average<=100)
         { printf("Grade : Honours\n");}

        // identify the Highest and Second Highest average students

        if ((econ < 50 || english < 50 || maths < 50 || other < 50) && average <= 79)
        { continue; } //Skip students with marks below 50 unless average > 79


       // Update highest and second-highest averages
        if (average > HighestAverage) {

            strcpy(SecondHighestStudent, HighestStudent);
            SecondHighestAverage = HighestAverage;

            strcpy(HighestStudent, StudentName);
            HighestAverage = average;  }

         else if (average > SecondHighestAverage) {
            strcpy(SecondHighestStudent, StudentName);
            SecondHighestAverage = average; }

    } // end of the while loop


   //final print about the highest and second highest average students
    if (HighestAverage == 0) {
        printf("\nNo valid Highest average student found.\n");  }

    else {  printf("\n%s got the highest average : %d\n", HighestStudent, HighestAverage);

            if(SecondHighestAverage > 0) {
                printf("\n%s got the second highest average : %d\n", SecondHighestStudent, SecondHighestAverage); }

            else { printf("\nNo second highest average student found.\n"); }
        }

return 0;
}

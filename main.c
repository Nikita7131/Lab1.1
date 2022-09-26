#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define D_Name "Нікіта"
#define D_Surname "Мартиненко"

struct studet {
  char Name[120];
  char Surname[120];
  int grade_1;
  int grade_2;
  int grade_3;
  double avg_grade;
} stud[1000];

int i;
double Top_Grade;




int main(){

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    printf("ctreated by: ");
    printf("%s %s Ре-22\n", D_Name, D_Surname);

    while(1){

     printf("\n");
     printf("=================================================================================\n");
     printf("#%d введіть: ім'я,прізвище,grade1,grade2,grade3:",i);
     scanf("%s %s %d %d %d",&stud[i].Name, &stud[i].Surname, &stud[i].grade_1, &stud[i].grade_2, &stud[i].grade_3);
     stud[i].avg_grade = (stud[i].grade_1+stud[i].grade_2+stud[i].grade_3+3)/3;
     printf("result avarage: %s %s = %lf\n", stud[i].Name, stud[i].Surname, stud[i].avg_grade - 1);
     printf("\n");
     if(stud[i].avg_grade > Top_Grade){ // дааа, можна було зробити сортирований список, но на годинку 1:5 і я хочу спати ...
      Top_Grade = stud[i].avg_grade;
     }
     printf(" Top : %lf",Top_Grade);
      i ++;

    }

}




#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include<stdbool.h>


#define D_Name "Нікіта"
#define D_Surname "Мартиненко"


  char console_Name[120];
  char console_Surname[120];
  int console_grade_1;
  int console_grade_2;
  int console_grade_3;
  double console_avg_grade;

#define Stud_NB 100

struct studet {
  char Name[120];
  char Surname[120];
  double avg_grade;
} stud[Stud_NB];


  unsigned long input_cnt;



int main(){

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    printf("ctreated by: ");
    printf("%s %s Ре-22\n", D_Name, D_Surname);


    while(1){

     printf("\n");
     printf("=================================================================================\n");
     printf("#%d введіть: ім'я,прізвище,grade1,grade2,grade3: ",input_cnt);
     scanf("%s %s %d %d %d",&console_Name, &console_Surname, &console_grade_1, &console_grade_2, &console_grade_3); // приймуємо інформацію
     console_avg_grade = (double)(console_grade_1 + console_grade_2 + console_grade_3)/3; // рахуємо середне арифметичне
     printf(" avarage: %s %s = %lf\n", console_Name, console_Surname, console_avg_grade); // випльовуємо середне арифметичне в консоль
     printf("\n");
     input_cnt ++; // щотчик студентів


     bool DropList = 0;
     unsigned long DropMark = 0;

     // знаходим місце куди покласти нове значення за збільшенням + здвигаєм весь список вниз
     for (unsigned long i = 0; i < Stud_NB; i++) {
       if(DropList == 0){
        if(stud[i].avg_grade < console_avg_grade){ // перевірка на менше значення
         DropMark = i;
         DropList = 1;
        }
       }else{ // здвиг всього массиву
        if(stud[Stud_NB - i].avg_grade < console_avg_grade){ // без цьої фігні будуть баги
        stud[Stud_NB - i].avg_grade = (double)stud[(Stud_NB-1)-i].avg_grade;


        for(byte c = 0; c <= 120; c++){ // копіювання всіх елеменітів массиву імен
         stud[Stud_NB - i].Name[c] = stud[(Stud_NB-1)-i].Name[c];
        }
        for(byte c = 0; c <= 120; c++){ // копіювання всіх елеменітів массиву призвіщь
         stud[Stud_NB - i].Surname[c] = stud[(Stud_NB-1)-i].Surname[c];
        }



       }
      }
     }

     // ложим нове значення в масиив
     stud[DropMark].Name[0] = console_Name;
     stud[DropMark].Surname[0] = console_Surname;
     stud[DropMark].avg_grade = console_avg_grade;

     printf("TOP:\n");

     for (unsigned long i = 0; i < 10; i++) {
      printf("№%d %s %s = %lf\n",i + 1, stud[i].Name, stud[i].Surname, stud[i].avg_grade );
     }

   }

}

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
  int console_grade_4;
  int console_grade_5;

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
    printf("%s %s РТФ Ре-22\n", D_Name, D_Surname);

    system("color 2");

    while(1){

     printf("\n");
     printf("=================================================================================\n");
    while(console_grade_1 == 0 || console_grade_2 == 0 || console_grade_3 == 0 || console_grade_4 == 0 || console_grade_5 == 0 || console_grade_1 > 12 || console_grade_2 > 12  || console_grade_3 > 12 || console_grade_4 > 12  || console_grade_5 > 12 ){ // перевіряєм правильність данних
      printf("#%d введіть: ім'я,прізвище,grade1,grade2,grade3,grade4,grade5: ",input_cnt);
      scanf("%s %s %d %d %d %d %d",&console_Name, &console_Surname, &console_grade_1, &console_grade_2, &console_grade_3, &console_grade_4, &console_grade_5); // приймаємо інформацію
    }
     console_avg_grade = (double)(console_grade_1 + console_grade_2 + console_grade_3 + console_grade_4 + console_grade_5)/5; // рахуємо середне арифметичне
     printf(" averagemark : %s %s = %lf\n", console_Name, console_Surname, console_avg_grade); // випльовуємо середне арифметичне в консоль
     printf("\n");
     input_cnt ++; // щотчик студентів


     bool DropList = 0;
     unsigned long DropMark = 0;

     // знаходим місце куди покласти нове значення за збільшенням + здвигаєм весь список вниз
     for (unsigned long i = 0; i < Stud_NB; i++) {
       if(DropList == 0){
        if(stud[i].avg_grade < console_avg_grade){ // перевірка на менше значення
         DropMark = i; //
         DropList = 1;
        }
       }else{ // здвиг всього массиву
        if(stud[Stud_NB - i].avg_grade < console_avg_grade){ // без цьої фігні будуть баги
        stud[Stud_NB - i].avg_grade = (double)stud[(Stud_NB-1)-i].avg_grade;
        for(byte c = 0; c <= 120; c++){stud[Stud_NB - i].Name[c] = stud[(Stud_NB-1)-i].Name[c];} // перенесення всіх елеменітів массиву імен
        for(byte c = 0; c <= 120; c++){stud[Stud_NB - i].Surname[c] = stud[(Stud_NB-1)-i].Surname[c];}// перенесення всіх елеменітів массиву призвіщь
       }
      }
     }


     // ложим нове значення в масиив
     for(byte c = 0; c <= 120; c++){stud[DropMark].Name[c] = console_Name[c];} // копіювання всіх елеменітів массиву імен
     for(byte c = 0; c <= 120; c++){stud[DropMark].Surname[c] = console_Surname[c];}// копіювання всіх елеменітів массиву призвіщь
     stud[DropMark].avg_grade = console_avg_grade;

     console_grade_1 = 0;
     console_grade_2 = 0;
     console_grade_3 = 0;

     // виводим в консоль топ студентів
     printf("TOP:\n");


     unsigned long StNb = 0;
     while(StNb < Stud_NB){
       if(stud[StNb].avg_grade != 0){
        printf("№%d %s %s = %lf\n",StNb + 1, stud[StNb].Name, stud[StNb].Surname, stud[StNb].avg_grade );
       }
      StNb ++;
      }


   }

}


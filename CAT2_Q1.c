(i)An array:-is a data structure that stores a collection of elements of the same type in contiguous memory locations



/*
Name:Sammy Njuguna 
Reg.No.CT101/G/28858/25
Date:6 Nov,2025
2D array
*/
#include <stdio.h>
 int main() {
     
     int scores[4][2] = {
         {65, 92},
         {35, 70},
         {84, 72},
         {59, 67}
     };
     // Print the elements of the array
     printf("Elements of the array:\n");
     for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 2; j++) {
             printf("%d ", scores[i][j]);
         }
         printf("\n");
     }
     return 0;
 }

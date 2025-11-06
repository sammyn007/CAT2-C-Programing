/*
Name:Sammy Njuguna 
Reg.no.:CT101/G/28858/25
Date:6 Nov,2025
Description:working calculator 
*/

#include <stdio.h>
 int main() {
     float hours_worked, hourly_wage, gross_pay, taxes, net_pay;
     
     // prompt user to enter hours worked in a week
     
     printf("Enter hours worked in a week: ");
     scanf("%f", &hours_worked);
     
     // prompt user to enter hourly wage
     
     printf("Enter hourly wage: ");
     scanf("%f", &hourly_wage);
     
     // Calculate gross pay
     if (hours_worked <= 40) {
         gross_pay = hours_worked * hourly_wage;
     } else {
         gross_pay = (40 * hourly_wage) + ((hours_worked - 40) * (1.5 * hourly_wage));
     }
     // Calculate taxes
     if (gross_pay <= 600) {
         taxes = 0.15 * gross_pay;
     } else {
         taxes = (0.15 * 600) + (0.20 * (gross_pay - 600));
     }
     // Calculate net pay
     net_pay = gross_pay - taxes;
     
     printf("Gross pay: $%.2f\n", gross_pay);
     printf("Taxes: $%.2f\n", taxes);
     printf("Net pay: $%.2f\n", net_pay);
     return 0;
 }
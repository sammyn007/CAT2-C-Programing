/*
Name:Sammy Njuguna
Reg.no.:CT101/G/28858/25
Date:6 Nov,2025
*/
#include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>  
 #define NUM_INTEGERS 10
 void write_integers_to_file();
 void process_file_and_write_results();
 void display_files();
 int main() {
     write_integers_to_file();
     process_file_and_write_results();
     display_files();
     return 0;
 }
 void write_integers_to_file() {
     FILE *fptr = fopen("input.txt", "w");
     if (!fptr) {
         fprintf(stderr, "Error opening input.txt for writing: %s\n", strerror(errno));
         exit(EXIT_FAILURE);
     }
     printf("Enter %d integers:\n", NUM_INTEGERS);
     for (int i = 0; i < NUM_INTEGERS; i++) {
         int n;
         printf("Integer %d: ", i + 1);
         if (scanf("%d", &n) != 1) {
             fprintf(stderr, "Invalid input. Please enter an integer.\n");
             while (getchar() != '\n'); 
             i--;
             continue;
         }
         fprintf(fptr, "%d\n", n);
     }
     fclose(fptr);
     printf("Wrote to input.txt\n");
 }
 void process_file_and_write_results() {
     FILE *in = fopen("input.txt", "r");
     if (!in) {
         fprintf(stderr, "Error opening input.txt for reading: %s\n", strerror(errno));
         return;
     }
     FILE *out = fopen("output.txt", "w");
     if (!out) {
         fprintf(stderr, "Error opening output.txt for writing: %s\n", strerror(errno));
         fclose(in);
         return;
     }
     int n, sum = 0, count = 0;
     double avg = 0.0;
     while (fscanf(in, "%d", &n) == 1) {
         sum += n;
         count++;
     }
     fclose(in);
     if (count > 0) {
         avg = (double)sum / count;
         fprintf(out, "Sum: %d\nAverage: %.2f\n", sum, avg);
     } else {
         fprintf(out, "No numbers found in input.txt\n");
     }
     fclose(out);
     printf("Wrote sum/avg to output.txt\n");
 }
 void display_files() {
     char* files[] = {"input.txt", "output.txt"};
     for(int i = 0; i < 2; i++){
         FILE *fptr;
         int ch;
         printf("\n--- Contents of %s ---\n", files[i]);
         fptr = fopen(files[i], "r");
         if (!fptr) {
             fprintf(stderr, "Error opening %s for display: %s\n", files[i], strerror(errno));
             continue;
         }
         while ((ch = fgetc(fptr)) != EOF) {
             putchar(ch);
         }
         fclose(fptr);
     }
 }
#include <stdio.h>

/* print Celsius-Fahrenheit table */
void main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("Celsius to Fahrenheit\n");
  printf("%3s %6s\n", "C", "F");

  celsius = lower;
  while (celsius <= upper) {
    fahr = ((9.0/5.0) * celsius) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    /* %3.0f says that a floating-point number is to be printed
       at least three characters wide, with no decimal point and no fraction digits.
       %6.1f says that a floating-point number is to be printed
       at least 6 characters wide, with 1 digit after the decimal point */
    celsius = celsius + step;
  }
}

#include <stdio.h>

/* print Celsius-Fahrenheit or Fahrenheit-Celsius table based on user input */
/* use functions for conversion */

#define NUMCHO	3               /* number of choices */
#define LOWER 	0
#define UPPER 	300
#define STEP 		20

int chkcho(int);                /* check choice */
float cf(int);                  /* Celsius-Fahrenheit */
float fc(int);                  /* Fahrenheit-Celsius */
float kc(int);                  /* Kelvin-Celsius */

int cho[NUMCHO + 1];

int main()
{
  int i, c, cidx, t;
  float ot;
  extern int cho[];

  cho[0] = 'k';
  cho[1] = 'c';
  cho[2] = 'f';
  cho[3] = 'c';                 /* to make the same operation (cidx + 1) produce the right letter for each conversion heading */

  printf("Enter c for C-F, f for F-C, or k for K-C:\n");
  while ((cidx = chkcho(c = getchar())) >= NUMCHO) {
    if (c != '\n')              /*  to keep the line below from printing twice after the first unrecognized entry */
      printf("Unrecognized entry. Please enter c for C-F, f for F-C, or k for K-C: ");
  }

  printf("%3c %6c\n", cho[cidx], cho[cidx + 1]); /* conversion heading */
  for (t = LOWER; t <= UPPER; t = t + STEP) {
    switch (cho[cidx]) {
      case 'c':
        ot = cf(t);
        break;
      case 'f':
        ot = fc(t);
        break;
      case 'k':
        ot = kc(t);
        break;
    }
    printf("%3d %6.1f\n", t, ot);
  }
  return 0;
}


int chkcho(int c) {
  extern int cho[];
  int i;
  for (i = 0; i < NUMCHO; ++i) {
    if (c == cho[i]) {
      break;
    }
  }
  return i;
}


float cf(int t) {
  return ((9.0/5.0) * t) + 32.0;
}


float fc(int t) {
  return (5.0/9.0) * (t - 32.0);
}


float kc(int t) {
  return t - 273.15;
}

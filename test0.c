#include <math.h>
#include <stdio.h>
#include <string.h>

int next_permutation(int n, char **s);

int main() {
  char result[50];
  scanf_s("%[^\n]%c", result);
  printf("%s\n", result);
  scanf_s("\n");
  scanf_s("%s", result);
  printf("%s\n", result);
  printf("hi salah \n");

  return 0;
}
// Didn`t understand this function from hackerrank
int next_permutation(int n, char **s) {
  for (int i = n - 1; i > 0; i--)
    if (strcmp(s[i], s[i - 1]) > 0) {
      int j = i + 1;
      for (; j < n; j++)
        if (strcmp(s[j], s[i - 1]) <= 0)
          break;
      char *t = s[i - 1];
      s[i - 1] = s[j - 1];
      s[j - 1] = t;
      for (; i < n - 1; i++, n--) {
        t = s[i];
        s[i] = s[n - 1];
        s[n - 1] = t;
      }
      return 1;
    }
  for (int i = 0; i < n - 1; i++, n--) {
    char *t = s[i];
    s[i] = s[n - 1];
    s[n - 1] = t;
  }
  return 0;
}

// Somecases terminated bacause of time limit also from hackerrank
/*its solution by making the iterator be (start) instead of counter in the for
 * loop --> start = counter*/
int marks_summation(int *marks, int number_of_students, char gender) {
  char counter = 0;
  unsigned int sum = 0;
  if ('g' == gender) {
    counter = 1;
  } else {
    counter = 0;
  }
  for (; counter < number_of_students; counter += 2) {
    sum += marks[counter];
  }

  return sum;
}

// --> printing pattern using loops
void print_pattern() {
  char counter1 = 0;
  char counter2 = 0;
  char temp = 0;
  int n, size;
  scanf("%d", &n);
  // size = (2 * n - 1);

  for (counter1 = n - 1; counter1 > -n; counter1--) {

    for (counter2 = n - 1; counter2 > -n; counter2--) {
      if (abs(counter1) >= abs(counter2)) {
        printf("%i ", abs(counter2) + 1);
      } else if (abs(counter2) > abs(counter1)) {
        printf("%i ", abs(counter2) + 1);
      }
    }
    printf("\n");
  }
}
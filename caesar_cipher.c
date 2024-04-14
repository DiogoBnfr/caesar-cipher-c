#include <stdio.h>
#include <string.h>
#include <ctype.h>

char caesar_shift(char c, int key) {
  int shift_c = c + key;
  if (ispunct(c) || isspace(c)) return c;
  if (iscntrl(c)) return ' ';
  if (islower(c)) {
    if (shift_c > 'z') return ('a' - 1) + (shift_c - 'z');
    if (shift_c < 'a') return ('z' + 1) - ('a' - shift_c);
  }
  if (isupper(c)) if (shift_c > 'Z') {
    if (shift_c > 'Z') return ('A' - 1) + (shift_c - 'Z');
    if (shift_c < 'A') return ('Z' + 1) - ('A' - shift_c);
  }
  if (isdigit(c)) {
    if (shift_c > '9') return ('0' - 1) + (shift_c - '9');
    if (shift_c < '0') return ('9' + 1) - ('0' - shift_c);
  }
  return (char)c + key;
}

void caesar_encrypt (int key) {
  printf ("insert the message:\n");

  char buffer[2048];
  char c;
  for (int i = 0; (c = getchar()) != EOF; ++i)
    buffer[i] = caesar_shift (c, key);
  printf ("output message:\n");
  for (int i = 0; i < (int)strlen (buffer); ++i)
    printf ("%c", buffer[i]);
}

void caesar_decrypt (int key) {
  caesar_encrypt (key * -1);
}

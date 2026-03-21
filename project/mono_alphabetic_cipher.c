#include <stdio.h>
#include <string.h>

int main() {
  char upperKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
  char lowerKey[] = "qwertyuiopasdfghjklzxcvbnm";
  char text[100];
  int i, j;

  printf("Enter plaintext: ");
  fgets(text, sizeof(text), stdin);
  int len = strlen(text);
  if (len > 0 && text[len - 1] == '\n')
    text[len - 1] = '\0';

  // Step 1: Encrypt text[] in-place
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z')
      text[i] = upperKey[text[i] - 'A'];
    else if (text[i] >= 'a' && text[i] <= 'z')
      text[i] = lowerKey[text[i] - 'a'];
  }
  printf("Encrypted : %s\n", text);

  // Step 2: Decrypt text[] in-place (reverse lookup)
  for (i = 0; text[i] != '\0'; i++) {
    for (j = 0; j < 26; j++) {
      if (upperKey[j] == text[i]) {
        text[i] = 'A' + j;
        break;
      }
      if (lowerKey[j] == text[i]) {
        text[i] = 'a' + j;
        break;
      }
    }
  }
  printf("Decrypted : %s\n", text);

  return 0;
}

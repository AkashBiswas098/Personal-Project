#include <stdio.h>
#include <string.h>

int main() {
  char text[100];
  char key[50];
  int i, ki, keyLen;

  printf("Enter plaintext : ");
  fgets(text, sizeof(text), stdin);
  int len = strlen(text);
  if (text[len - 1] == '\n')
    text[len - 1] = '\0';

  printf("Enter key       : ");
  fgets(key, sizeof(key), stdin);
  len = strlen(key);
  if (key[len - 1] == '\n')
    key[len - 1] = '\0';
  keyLen = strlen(key);

  // Normalize key to lowercase
  for (i = 0; i < keyLen; i++)
    if (key[i] >= 'A' && key[i] <= 'Z')
      key[i] = key[i] - 'A' + 'a';

  // Encrypt in-place
  ki = 0;
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = (char)(((text[i] - 'A' + key[ki % keyLen] - 'a') % 26) + 'A');
      ki++;
    } else if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = (char)(((text[i] - 'a' + key[ki % keyLen] - 'a') % 26) + 'a');
      ki++;
    }
  }
  printf("Encrypted       : %s\n", text);

  // Decrypt in-place
  ki = 0;
  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] =
          (char)(((text[i] - 'A' - (key[ki % keyLen] - 'a') + 26) % 26) + 'A');
      ki++;
    } else if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] =
          (char)(((text[i] - 'a' - (key[ki % keyLen] - 'a') + 26) % 26) + 'a');
      ki++;
    }
  }
  printf("Decrypted       : %s\n", text);

  return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
  FILE *authors = fopen("authors.txt", "r");
  FILE *vybor = fopen ("vybor.txt", "w");
  char word1[100],word2[100],word3[100],word4[100];
  char napr[100];

  printf("%s", "Напиши необходимое направление:\nМатематика\nФизика\nПрограммирование\n");
  scanf("%s", napr);
  printf("Вы ввели: %s. Результаты по вашему запросу записаны в файл vybor.txt\n", napr);
  while (!feof(authors)) {
    fscanf(authors, "%s", word1);
    fscanf(authors, "%s", word2);
    fscanf(authors, "%s", word3);
    fscanf(authors, "%s\n", word4);
    if (!strcmp(napr, word2)) {
      fprintf(vybor, "Имя: %s", word1);
      fprintf(vybor, "\tНаправление: %s", word2);
      fprintf(vybor, "\tГод: %s", word3);
      fprintf(vybor, "\tСтраниц: %s", word4);
      fprintf(vybor, "\n");
    }
  }

  fclose(authors);
  fclose(vybor);
  return 0;
}

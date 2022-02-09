#include <stdio.h>
#include <string.h>

struct author {
  char name[20];
  char spec[30];
  char year[5];
  char pages[10];
};
typedef struct author Author;
void show(Author c);
struct author inpstud(void);

int main() {
  FILE *authors = fopen("authors.txt", "r");
  FILE *vybor = fopen ("vybor.txt", "w");
  char napr[100];
  Author x;

  printf("%s", "Напиши необходимое направление:\nМатематика\nФизика\nПрограммирование\n");
  scanf("%s", napr);
  printf("Вы ввели: %s. Результаты по вашему запросу записаны в файл vybor.txt\n", napr);
  while (!feof(authors)) {
    fscanf(authors, "%s", x.name);
    fscanf(authors, "%s", x.spec);
    fscanf(authors, "%s", x.year);
    fscanf(authors, "%s\n", x.pages);
    if (!strcmp(napr, x.spec)) {
      fprintf(vybor, "Имя: %s", x.name);
      fprintf(vybor, "\tНаправление: %s", x.spec);
      fprintf(vybor, "\tГод: %s", x.year);
      fprintf(vybor, "\tСтраниц: %s", x.pages);
      fprintf(vybor, "\n");
    }
  }

  fclose(authors);
  fclose(vybor);
  return 0;
}

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
  struct author *p = &x;

  printf("%s", "Напиши необходимое направление:\nМатематика\nФизика\nПрограммирование\n");
  scanf("%s", napr);
  printf("Вы ввели: %s. Результаты по вашему запросу записаны в файл vybor.txt\n", napr);
  while (!feof(authors)) {
    fscanf(authors, "%s", p->name);
    fscanf(authors, "%s", p->spec);
    fscanf(authors, "%s", p->year);
    fscanf(authors, "%s\n", p->pages);
    if (!strcmp(napr, p->spec)) {
      fprintf(vybor, "Имя: %s", p->name);
      fprintf(vybor, "\tНаправление: %s", p->spec);
      fprintf(vybor, "\tГод: %s", p->year);
      fprintf(vybor, "\tСтраниц: %s", p->pages);
      fprintf(vybor, "\n");
    }
  }

  fclose(authors);
  fclose(vybor);
  return 0;
}


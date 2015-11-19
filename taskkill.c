#include <stdio.h>
#include <stdlib.h>

int menu();
void lista_processos();
void mata_processo_nome();
void mata_processo_PID();
void mata_processo(char *comando);

FILE *arq;
int op, i;
char processo[1000], cmd_kill[2000], op_menu[2000];

int main() {

  while (menu() == 1);

  system("pause");
  return 0;
}

void lista_processos() {
  char c;
  system("cls");
  system("tasklist > saida_cmd.txt");
  arq = fopen("saida_cmd.txt", "r");

  while( (c = fgetc(arq))!= EOF )
    printf("%c", c);

  fclose(arq);
}

int menu() {
 int valida = 1;

  printf("\n##  1   | List Process");
  printf("\n##  2   | Kill Process by PID");
  printf("\n##  3   | Kill Process by name");
  printf("\n##  4+  | Clear screen");
  printf("\n##  0   | EXIT");
  printf("\n\n##  Your Option is: ");

  do {
    valida = 1;
    scanf("%s", op_menu);

    for (i = 0; op_menu[i] != '\0'; i++)
      if( isdigit(op_menu[i]) == 0 )
        valida = 0;

    if (valida == 0)
      printf("\nOnly positive, numbers: ");

  } while (valida != 1);

  op = atoi(op_menu);

  if (op == 0)
    return 0;
  else if (op == 1)
    lista_processos();
  else if (op == 2)
    mata_processo_PID();
  else if (op == 3)
    mata_processo_nome();
  else
    system("cls");

  return 1;
}

void mata_processo(char *comando) {
  printf("\nexecuta: %s", comando);
}

void mata_processo_nome() {
  printf("\nName of process(example: \"chrome.exe\"): ");
  scanf("%s", processo);

  sprintf(cmd_kill, "TASKKILL /F /IM \"%s\"", processo);
  system("cls");
  system(cmd_kill);

}

void mata_processo_PID() {
  printf("\nPID of process(example: \"1050\"): ");
  scanf("%s", processo);

  sprintf(cmd_kill, "TASKKILL /F /PID \"%s\"", processo);
  system("cls");
  system(cmd_kill);
}

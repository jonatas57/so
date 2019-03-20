/*
 * Duas abordagens para preencher um segmento de dados.
 */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/resource.h>

#define PAGESIZE 4096
#define N 800000

char mat[N][PAGESIZE];

void preenche_lento(char c) {
  int i,j;
  printf("Inicio preenche lento.\n");
  for (i = 0; i < N; i++)
    for (j = 0; j < PAGESIZE; j++)
      mat[i][j] = c;
  printf("Fim preenche lento.\n");
}

int main() {
  struct rusage uso;

  char *topo = sbrk(0);
  printf("Topo da área de dados = %p\n", topo);

  preenche_lento('*');
  getrusage(RUSAGE_SELF, &uso);
  printf("Falhas de página sem ida ao disco: %lu\n", uso.ru_minflt);
  printf("Falhas de página com ida ao disco: %lu\n", uso.ru_majflt);

  return 0;
}

#include <fcntl.h>

main() {

int arquivo = open("testeSync.txt", O_RDWR | O_CREAT, 0777);

int i = 0;
while(i < 1000) {
   write(arquivo, "0", 1);
   fsync(arquivo);
   i++;
}

close(arquivo);

}

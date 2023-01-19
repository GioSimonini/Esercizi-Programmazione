#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]) {
  if (argc != 2)
    return 0;
  if(strstr(argv[2], argv[1]))
    return 1;
  if(strstr(argv[1], argv[2]))
    return 2;
}

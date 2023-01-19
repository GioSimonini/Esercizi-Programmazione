#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
int sum = 0;
for (int i = 1; i < argc; i++) {
if (atoi(argv[i]) < 0) {
sum = -1;
break;
}
sum += atoi(argv[i]);
}
printf("%d\n", sum);
return sum;
}

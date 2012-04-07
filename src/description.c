#include <sys/types.h>

#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {

  u_int64_t mask = 1ULL;

  for ( ; mask < (1ULL << 54); mask <<= 1) {

    printf("%luULL\n", mask);

  }

  return 0;

}

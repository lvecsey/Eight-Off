#include <stdio.h>
#include <assert.h>

#include <unistd.h>

#include <errno.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>

#include "headers.h"

#include <gsl/gsl_rng.h>

#include <sys/stat.h>
#include <fcntl.h>

int shuffle_fill(u_int64_t *fill, gsl_rng *r, int available_cards, int iter) {

  u_int64_t mask;

  assert(fill!=NULL && r!=NULL && available_cards>0 && iter>0);

  assert(available_cards>=iter);

  while(iter>0) {

    mask = 1ULL << gsl_rng_uniform_int(r, available_cards);
    *fill++ = mask;
    available_cards--;

    iter--;

  }

  return 0;

}

int main(int argc, char *argv[]) {

  unsigned char outbuf[ sizeof(u_int64_t) * 54 ];

  int len;

  u_int64_t cmd;

  struct timespec ts;

  int write_retval;

  u_int64_t *num = (u_int64_t*) outbuf;

  int available_cards = 52;

  gsl_rng *r = gsl_rng_alloc(gsl_rng_taus);

  if (r==NULL) return -1;

  {

    int read_bytes;

    int urandom_fd = open("/dev/urandom", O_RDONLY);

    unsigned long int s;

    if (urandom_fd==-1) return -1;

    read_bytes = read(urandom_fd, &s, sizeof(unsigned long int));
    if (read_bytes != sizeof(unsigned long int)) return -1;

    gsl_rng_set(r, s);

    close(urandom_fd);

  }

  *num++ = EIGHTOFF_CARDARRAY;

  shuffle_fill(num, r, available_cards, 48);
  available_cards -= 48;

  *num++ = EIGHTOFF_FREEBIN;

  shuffle_fill(num, r, available_cards, 4);
  available_cards -= 4;

  write_retval = write(1, outbuf, sizeof(outbuf));
  if (write_retval != sizeof(outbuf)) {
    return -1;
  }

  gsl_rng_free(r);

  return 0;

}

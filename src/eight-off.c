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

int shuffle_fill(u_int64_t *fill, gsl_rng *r, int available_cards) {

  u_int64_t *swap_selection, *end_fill = fill + available_cards;

  u_int64_t *base = fill;

  assert(fill!=NULL && r!=NULL && available_cards>0);

  while(fill < end_fill) {

    swap_selection = base + gsl_rng_uniform_int(r, available_cards);

    *fill++ = (swap_selection < fill) ? *swap_selection : 1ULL << (swap_selection - fill);
    *swap_selection = 1ULL << (available_cards-1);

    available_cards--;

  }

  return 0;

}

int main(int argc, char *argv[]) {

  unsigned char outbuf[ sizeof(u_int64_t) * 54 ];

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

  shuffle_fill(num, r, available_cards);

  num += 48;
  num[4] = num[0];

  *num++ = EIGHTOFF_FREEBIN;

  write_retval = write(1, outbuf, sizeof(outbuf));
  if (write_retval != sizeof(outbuf)) {
    fprintf(stderr, "%s: Expected write of %ld but got %d.\n", __FUNCTION__, sizeof(outbuf), write_retval);
    return -1;
  }

  gsl_rng_free(r);

  return 0;

}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

#include "card_names.h"

#include "show_card.h"

#include "headers.h"

int main(int argc, char *argv[]) {

  ssize_t read_bytes;

  u_int64_t entry;

  u_int16_t num_reads;

  int in_fd = (getenv("PROTO") != NULL) ? 6 : 0;

  num_reads = 1;
  
  read_bytes = read(in_fd, &entry, sizeof(u_int64_t));
  if (read_bytes != sizeof(u_int64_t)) {
    printf("%s: Failed to read sizeof u_int64_t bytes.\n", __FUNCTION__);
    return -1;
  }

  if (entry != EIGHTOFF_CARDARRAY) {
    printf("%s: Failed to match CARDARRAY begin card set.\n", __FUNCTION__);
    return -1;
  }

  for (num_reads = 48; num_reads > 0; num_reads--) {

    read_bytes = read(in_fd, &entry, sizeof(u_int64_t));
    if (read_bytes != sizeof(u_int64_t)) {
      fprintf(stderr, "%s: read returned read_bytes=%ld instead of %ld.\n", __FUNCTION__, read_bytes, sizeof(u_int64_t));
      return -1;
    }

    show_card(entry);

  }

  read_bytes = read(in_fd, &entry, sizeof(u_int64_t));
  if (read_bytes != sizeof(u_int64_t)) {
    fprintf(stderr, "%s: read returned read_bytes=%ld instead of %ld.\n", __FUNCTION__, read_bytes, sizeof(u_int64_t));
    return -1;
  }

  if (entry != EIGHTOFF_FREEBIN) {
    printf("%s: Failed to match FREEBIN card set.\n", __FUNCTION__);
    return -1;
  }

  for (num_reads = 4; num_reads > 0; num_reads--) {

    read_bytes = read(in_fd, &entry, sizeof(u_int64_t));
    if (read_bytes != sizeof(u_int64_t)) {
      printf("%s: read returned read_bytes=%ld instead of %ld.\n", __FUNCTION__, read_bytes, sizeof(u_int64_t));
      return -1;
    }

    show_card(entry);

  }

  return 0;

}

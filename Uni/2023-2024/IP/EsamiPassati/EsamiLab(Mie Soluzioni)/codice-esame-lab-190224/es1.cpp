#include "funz.h"

unsigned int numIterSequenzaSiracusa(unsigned int vinit) {
  unsigned int n = 0;

  while (vinit > 1) {
    if (vinit % 2 == 0) {
      vinit = vinit / 2;
    } else {
      vinit = 3 * vinit + 1;
    }
    ++n;
  }
  return n;
}

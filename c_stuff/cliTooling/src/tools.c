#include <stdint.h>
#include <stdlib.h>
#include "tools.h"

uint8_t *buf_init(const size_t buf_size){
  size_t size = (buf_size == 0) ? default_buffer_size
                 : buf_size;

  return malloc(size);
}

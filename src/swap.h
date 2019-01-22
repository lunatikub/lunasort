#ifndef SWAP_H__
#define SWAP_H__

static inline void swap(uint32_t *a, uint32_t *b)
{
  uint32_t tmp = *a;
  *a = *b;
  *b = tmp;
}

#endif /* !SWAP_H__ */

#ifndef FILE_H__
#define FILE_H__

#include <stddef.h>

/* File IO - reading an entire file into memory. */
char *filetobuf(const char *file_path, size_t *len);

#endif /* !FILE_H__ */
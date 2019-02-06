#include <stdio.h>
#include <stdlib.h>

#include <lunasort/utils/file.h>

char *filetobuf(const char *file_path, size_t *len)
{
    FILE *infile;
    char *buffer;

    infile = fopen(file_path, "r");

    if (infile == NULL) {
        return NULL;
    }

    /* Get the number of bytes */
    fseek(infile, 0L, SEEK_END);
    *len = ftell(infile);

    /* Reset the file position indicator to 
    the beginning of the file */
    int n = fseek(infile, 0L, SEEK_SET);
    if (n != 0) {
        return NULL;
    }

    /* Allocate sufficient memory for the
    buffer to hold the text */
    buffer = calloc(*len, sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }

    /* Copy all the text into the buffer */
    fread(buffer, sizeof(char), *len, infile);
    fclose(infile);

    return buffer;
}
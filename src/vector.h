#ifndef YACDSLIB_VECTOR_H
#define YACDSLIB_VECTOR_H

typedef struct vector {
    int* array;
    size_t used;
    size_t size;
} vector_t;

vector_t create_empty_vector(size_t initial_size);

#endif //YACDSLIB_VECTOR_H

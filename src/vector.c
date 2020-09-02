#include <stdlib.h>
#include "vector.h"

vector_t create_empty_vector(size_t initial_size){
    vector_t v = {
        malloc(initial_size * sizeof(int)),
        0,
        initial_size
    };
    return v;
}

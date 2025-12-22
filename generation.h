#pragma once

#include "publication.h"
#include <stdbool.h>

Publication publication_generate_random(void);

void publication_generate_to_csv(unsigned int count, const char* filename);

void publication_generate_to_stdout(unsigned int count);

const char* bool_to_yes_no(bool value);
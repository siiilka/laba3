#pragma once

#include "publication.h"
#include <stdio.h>
#include <stddef.h>

int publication_print_as_csv(const Publication* pub, char* buffer, size_t buffer_size);

void publication_print_formatted(FILE* stream, const Publication* pub);

void publication_print_table(FILE* stream, const Publication* publications, size_t count);

void publication_print_table_header(FILE* stream);
void publication_print_table_footer(FILE* stream);
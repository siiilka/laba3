#pragma once

#include "publication.h"
#include <stdbool.h>
#include <ctype.h>
#include <stddef.h>

void string_trim(char* str);
bool string_is_all_digits(const char* str);
bool string_parse_boolean(const char* str);

bool publication_validate_year(unsigned short year);
bool publication_validate_volume(unsigned short volume);
bool publication_validate_page_count(unsigned short page_count);
bool publication_validate_citations(unsigned int citations);
bool publication_validate_string_field(const char* field, size_t max_length);

int csv_count_fields(const char* csv_line);
char* csv_get_field(const char* csv_line, int field_index);
void csv_escape_string(const char* src, char* dest, size_t dest_size);
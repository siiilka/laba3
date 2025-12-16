#pragma once

#include "publication.h"
#include <stdbool.h>
#include <ctype.h>

void trim_string(char* str);
bool is_all_digits(const char* str);
bool parse_boolean(const char* str);

bool validate_year(int year);
bool validate_volume(int volume);
bool validate_page_count(int page_count);
bool validate_citations(int citations);
bool validate_string_field(const char* field, size_t max_length);

int count_csv_fields(const char* csv_line);
char* get_csv_field(const char* csv_line, int field_index);
void escape_csv_string(const char* src, char* dest, size_t dest_size);
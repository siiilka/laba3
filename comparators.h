#pragma once

#include "publication.h"

typedef int (*comparator_func)(const Publication*, const Publication*);

int compare_title(const Publication* a, const Publication* b);
int compare_author(const Publication* a, const Publication* b);
int compare_year(const Publication* a, const Publication* b);
int compare_citations(const Publication* a, const Publication* b);
int compare_volume(const Publication* a, const Publication* b);
int compare_pages(const Publication* a, const Publication* b);
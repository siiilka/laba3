#pragma once

#include "publication.h"

int publication_compare_by_title(const Publication* a, const Publication* b);
int publication_compare_by_author(const Publication* a, const Publication* b);
int publication_compare_by_year(const Publication* a, const Publication* b);
int publication_compare_by_citations(const Publication* a, const Publication* b);
int publication_compare_by_volume(const Publication* a, const Publication* b);
int publication_compare_by_pages(const Publication* a, const Publication* b);

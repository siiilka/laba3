#pragma once

#include "publication.h"

typedef int (*Comparator)(const Publication*, const Publication*);

int compareByTitle(const Publication* a, const Publication* b);
int compareByAuthor(const Publication* a, const Publication* b);
int compareByYear(const Publication* a, const Publication* b);
int compareByCitations(const Publication* a, const Publication* b);
int compareByVolume(const Publication* a, const Publication* b);
int compareByPages(const Publication* a, const Publication* b);
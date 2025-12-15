#include "publication.h"
#include <string.h>

int compareByTitle(const Publication* a, const Publication* b) 
{
    return strcmp(a->title, b->title);
}

int compareByAuthor(const Publication* a, const Publication* b) 
{
    int surname_cmp = strcmp(a->author_surname, b->author_surname);
    if (surname_cmp != 0) return surname_cmp;
    return strcmp(a->author_initials, b->author_initials);
}

int compareByYear(const Publication* a, const Publication* b) 
{
    return a->year - b->year;
}

int compareByCitations(const Publication* a, const Publication* b) 
{
    return a->citations - b->citations;
}

int compareByVolume(const Publication* a, const Publication* b) 
{
    return a->volume - b->volume;
}

int compareByPages(const Publication* a, const Publication* b) 
{
    return a->page_count - b->page_count;
} 
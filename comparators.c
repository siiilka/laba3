#include "publication.h"
#include <string.h>

int publication_compare_by_title(const Publication* a, const Publication* b) 
{
    if (a == NULL || b == NULL) return 0;
    return strcmp(a->title, b->title);
}

int publication_compare_by_author(const Publication* a, const Publication* b) 
{
    if (a == NULL || b == NULL) return 0;
    
    int surname_cmp = strcmp(a->author_surname, b->author_surname);
    if (surname_cmp != 0) return surname_cmp;
    return strcmp(a->author_initials, b->author_initials);
}

int publication_compare_by_year(const Publication* a, const Publication* b) 
{
    if (a == NULL || b == NULL) return 0;
    if (a->year < b->year) return -1;
    if (a->year > b->year) return 1;
    return 0;
}

int publication_compare_by_citations(const Publication* a, const Publication* b) 
{
    if (a == NULL || b == NULL) return 0;
    if (a->citations < b->citations) return -1;
    if (a->citations > b->citations) return 1;
    return 0;
}

int publication_compare_by_volume(const Publication* a, const Publication* b) 
{
    if (a == NULL || b == NULL) return 0;
    if (a->volume < b->volume) return -1;
    if (a->volume > b->volume) return 1;
    return 0;
}

int publication_compare_by_pages(const Publication* a, const Publication* b) 
{
    if (a == NULL || b == NULL) return 0;
    if (a->page_count < b->page_count) return -1;
    if (a->page_count > b->page_count) return 1;
    return 0;
}

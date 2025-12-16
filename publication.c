#include "publication.h"
#include <string.h>
#include <stdio.h>

void copyPublication(Publication* dest, const Publication* src) 
{
    if (!dest || !src) return;
    
    strncpy(dest->title, src->title, sizeof(dest->title) - 1);
    dest->title[sizeof(dest->title) - 1] = '\0';
    
    strncpy(dest->author_surname, src->author_surname, sizeof(dest->author_surname) - 1);
    dest->author_surname[sizeof(dest->author_surname) - 1] = '\0';
    
    strncpy(dest->author_initials, src->author_initials, sizeof(dest->author_initials) - 1);
    dest->author_initials[sizeof(dest->author_initials) - 1] = '\0';
    
    strncpy(dest->journal, src->journal, sizeof(dest->journal) - 1);
    dest->journal[sizeof(dest->journal) - 1] = '\0';
    
    dest->year = src->year;
    dest->volume = src->volume;
    dest->is_rinc = src->is_rinc;
    dest->page_count = src->page_count;
    dest->citations = src->citations;
}

bool isValidPublication(const Publication* pub) 
{
    if (!pub) return false;
    
    if (pub->title[0] == '\0' || 
        pub->author_surname[0] == '\0' ||
        pub->author_initials[0] == '\0' ||
        pub->journal[0] == '\0') {
        return false;
    }
    
    if (pub->year < 1900 || pub->year > 2024) return false;
    if (pub->volume <= 0) return false;
    if (pub->page_count <= 0) return false;
    if (pub->citations < 0) return false;
    
    return true;
}
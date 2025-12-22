#include "publication.h"
#include <string.h>

bool publication_copy(Publication* dest, const Publication* src) 
{
    if (dest == NULL || src == NULL) {
        return false;
    }
    
    memcpy(dest, src, sizeof(Publication));
    return true;
}

bool publication_is_valid(const Publication* pub) 
{
    if (pub == NULL) {
        return false;
    }
    
    if (pub->title[0] == '\0' || 
        pub->author_surname[0] == '\0' ||
        pub->author_initials[0] == '\0' ||
        pub->journal[0] == '\0') {
        return false;
    }
    
    if (pub->year < 1900 || pub->year > 2024) return false;
    if (pub->volume == 0 || pub->volume > 1000) return false;
    if (pub->page_count == 0 || pub->page_count > 5000) return false;
    if (pub->citations > 1000000) return false;
    
    return true;
}
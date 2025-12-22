#include "internal.h"
#include "publication.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void create_shortened_display(const char* source, char* dest, 
                                     size_t dest_size, size_t max_length)
{
    if (source == NULL || dest == NULL || dest_size == 0) 
    {
        if (dest && dest_size > 0) 
        {
            dest[0] = '\0';
        }
        return;
    }
    
    size_t src_len = strlen(source);
    
    if (src_len <= max_length) 
    {
        strncpy(dest, source, dest_size - 1);
        dest[dest_size - 1] = '\0';
        return;
    }
   
    if (max_length < 3) 
    {
        dest[0] = '\0';
        return;
    }
    
    size_t copy_len = max_length - 3;  
    strncpy(dest, source, copy_len);
    dest[copy_len] = '\0';
    strcat(dest, "...");
}

static void create_author_display(const char* surname, const char* initials, 
                                 char* dest, size_t dest_size) 
{
    if (surname == NULL || initials == NULL || dest == NULL || dest_size == 0) 
    {
        if (dest && dest_size > 0) 
        {
            dest[0] = '\0';
        }
        return;
    }
    
    int written = snprintf(dest, dest_size, "%s %s", surname, initials);
    
    if (written < 0 || (size_t)written >= dest_size) 
    {
        dest[0] = '\0';
        return;
    }
    
    if (strlen(dest) > 20 && dest_size > 20) 
    {
        create_shortened_display(dest, dest, dest_size, 20);
    }
}

int publication_print_as_csv(const Publication* pub, char* buffer, size_t buffer_size) 
{
    if (pub == NULL || buffer == NULL || buffer_size == 0) 
    {
        return -1;
    }
    
    char escaped_title[512];
    char escaped_surname[256];
    char escaped_initials[32];
    char escaped_journal[256];
    
    csv_escape_string(pub->title, escaped_title, sizeof(escaped_title));
    csv_escape_string(pub->author_surname, escaped_surname, sizeof(escaped_surname));
    csv_escape_string(pub->author_initials, escaped_initials, sizeof(escaped_initials));
    csv_escape_string(pub->journal, escaped_journal, sizeof(escaped_journal));
    
    const char* rinc_str;
    if (pub->is_rinc) 
    {
        rinc_str = "YES";
    } 
    else 
    {
        rinc_str = "NO";
    }
    
    int result = snprintf(buffer, buffer_size,
        "%s,%s,%s,%s,%u,%u,%s,%u,%u",
        escaped_title,
        escaped_surname,
        escaped_initials,
        escaped_journal,
        pub->year,
        pub->volume,
        rinc_str,
        pub->page_count,
        pub->citations);
    
    if (result < 0 || (size_t)result >= buffer_size) 
    {
        return -1;
    }
    
    return result;
}

void publication_print_formatted(FILE* stream, const Publication* pub) 
{
    if (stream == NULL || pub == NULL) 
    {
        return;
    }
    
    char title_display[34];    
    char author_display[22];   
    char journal_display[22];  
    
    create_shortened_display(pub->title, title_display, sizeof(title_display), 30);
    create_author_display(pub->author_surname, pub->author_initials, 
                         author_display, sizeof(author_display));
    create_shortened_display(pub->journal, journal_display, sizeof(journal_display), 20);
    
    const char* rinc_display;
    if (pub->is_rinc) 
    {
        rinc_display = "YES";
    } 
    else 
    {
        rinc_display = "NO";
    }
    
    fprintf(stream,
        "| %-30s | %-20s | %-20s | %-6u | %-6u | %-3s | %-6u | %-7u |\n",
        title_display,
        author_display,
        journal_display,
        pub->year,
        pub->volume,
        rinc_display,
        pub->page_count,
        pub->citations);
}

void publication_print_table_header(FILE* stream)
{
    if (stream == NULL) 
    {
        return;
    }
    
    fprintf(stream, "+--------------------------------+----------------------+----------------------+--------+--------+-----+--------+---------+\n");
    fprintf(stream, "| %-30s | %-20s | %-20s | %-6s | %-6s | %-3s | %-6s | %-7s |\n",
            "Название", "Автор", "Журнал", "Год", "Том", "РИНЦ", "Страниц", "Цитир.");
    fprintf(stream, "+--------------------------------+----------------------+----------------------+--------+--------+-----+--------+---------+\n");
}

void publication_print_table_footer(FILE* stream)
{
    if (stream == NULL) 
    {
        return;
    }
    
    fprintf(stream, "+--------------------------------+----------------------+----------------------+--------+--------+-----+--------+---------+\n");
}


void publication_print_table(FILE* stream, const Publication* publications, size_t count)
{
    if (stream == NULL || publications == NULL || count == 0) 
    {
        return;
    }
    
    publication_print_table_header(stream);
    
    for (size_t i = 0; i < count; i++) 
    {
        publication_print_formatted(stream, &publications[i]);
    }
    
    publication_print_table_footer(stream);
}
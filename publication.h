#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef struct 
{
    char title[256];
    char author_surname[100];
    char author_initials[10];
    char journal[150];

    int year;
    int volume;
    bool is_rinc;
    int page_count;

    int citations;
} Publication;

int parsePublicationFromCSV(const char* csvLine, Publication* pub);

int printPublicationAsCSV(const Publication* pub, char* buffer, size_t bufferSize);

void printPublicationFormatted(FILE* stream, const Publication* pub);

void generateRandomPublication(Publication* pub);

int compareByTitle(const Publication* a, const Publication* b);
int compareByAuthor(const Publication* a, const Publication* b);
int compareByYear(const Publication* a, const Publication* b);
int compareByCitations(const Publication* a, const Publication* b);
int compareByVolume(const Publication* a, const Publication* b);
int compareByPages(const Publication* a, const Publication* b);

void copyPublication(Publication* dest, const Publication* src);
bool isValidPublication(const Publication* pub);

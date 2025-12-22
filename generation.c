#include "publication.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NUM_TITLES 5
#define NUM_SURNAMES 5
#define NUM_INITIALS 5
#define NUM_JOURNALS 5

#define MIN_YEAR 2000
#define MAX_YEAR 2024
#define YEAR_RANGE (MAX_YEAR - MIN_YEAR + 1)

#define MIN_VOLUME 1
#define MAX_VOLUME 50
#define VOLUME_RANGE (MAX_VOLUME - MIN_VOLUME + 1)

#define MIN_PAGES 5
#define MAX_PAGES 100
#define PAGES_RANGE (MAX_PAGES - MIN_PAGES + 1)

#define MIN_CITATIONS 0
#define MAX_CITATIONS 10000
#define CITATIONS_RANGE (MAX_CITATIONS - MIN_CITATIONS + 1)

#define RINC_PROBABILITY 50

static const char* bool_to_yes_no(bool value)
{
    if (value) {
        return "YES";
    } else {
        return "NO";
    }
}

Publication publication_generate_random(void) 
{
    Publication pub = {0}; 
    
    static const char* titles[NUM_TITLES] = 
    {
        "Красивая математика для первокурсников",
        "История зоологии — история животных",
        "Проблемы агрохимии в современном земледелии",
        "Тайны вселенной",
        "Калибровка блока гироскопа"
    };
    
    static const char* surnames[NUM_SURNAMES] = 
    {
        "Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов"
    };
    
    static const char* initials[NUM_INITIALS] = 
    {
        "А.А.", "Б.Б.", "С.С.", "Д.Д.", "Е.Е."
    };
    
    static const char* journals[NUM_JOURNALS] = 
    {
        "Астрономический журнал", 
        "Алгебра и анализ",
        "Агрохимия",
        "Автоматика и телемеханика",
        "Зоологический журнал"
    };
    
    static int seeded = 0;
    if (seeded == 0) 
    {
        srand((unsigned int)time(NULL)); 
        seeded = 1;
    }

    strncpy(pub.title, titles[rand() % NUM_TITLES], sizeof(pub.title) - 1);
    pub.title[sizeof(pub.title) - 1] = '\0';
    
    strncpy(pub.author_surname, surnames[rand() % NUM_SURNAMES], sizeof(pub.author_surname) - 1);
    pub.author_surname[sizeof(pub.author_surname) - 1] = '\0';
    
    strncpy(pub.author_initials, initials[rand() % NUM_INITIALS], sizeof(pub.author_initials) - 1);
    pub.author_initials[sizeof(pub.author_initials) - 1] = '\0';
    
    strncpy(pub.journal, journals[rand() % NUM_JOURNALS], sizeof(pub.journal) - 1);
    pub.journal[sizeof(pub.journal) - 1] = '\0';
    
    pub.year = MIN_YEAR + rand() % YEAR_RANGE;
    pub.volume = MIN_VOLUME + rand() % VOLUME_RANGE;
    pub.is_rinc = ((rand() % 100) < RINC_PROBABILITY);
    pub.page_count = MIN_PAGES + rand() % PAGES_RANGE;
    pub.citations = MIN_CITATIONS + rand() % CITATIONS_RANGE;
    
    return pub;
}

void publication_generate_to_csv(unsigned int count, const char* filename)
{
    if (filename == NULL || count == 0) {
        return;
    }
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Ошибка: не удалось открыть файл %s\n", filename);
        return;
    }
    
    fprintf(file, "Название публикации,Фамилия первого автора,Инициалы первого автора,Название журнала,Год публикации,Том журнала,Входит в РИНЦ,Количество страниц,Цитирований\n");
    
    for (unsigned int i = 0; i < count; i++) {
        Publication pub = publication_generate_random();
        
        fprintf(file, "%s,%s,%s,%s,%u,%u,%s,%u,%u\n",
                pub.title,
                pub.author_surname,
                pub.author_initials,
                pub.journal,
                pub.year,
                pub.volume,
                bool_to_yes_no(pub.is_rinc),
                pub.page_count,
                pub.citations);
    }
    
    fclose(file);
}

void publication_generate_to_stdout(unsigned int count)
{
    if (count == 0) {
        return;
    }
    
    printf("Название публикации,Фамилия первого автора,Инициалы первого автора,Название журнала,Год публикации,Том журнала,Входит в РИНЦ,Количество страниц,Цитирований\n");
    
    for (unsigned int i = 0; i < count; i++) 
    {
        Publication pub = publication_generate_random();
        
        printf("%s,%s,%s,%s,%u,%u,%s,%u,%u\n",
               pub.title,
               pub.author_surname,
               pub.author_initials,
               pub.journal,
               pub.year,
               pub.volume,
               bool_to_yes_no(pub.is_rinc),
               pub.page_count,
               pub.citations);
    }
}
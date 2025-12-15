#include "publication.h"

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

void generateRandomPublication(Publication* pub) 
{
    if (pub == NULL) 
    {
        return;
    }

    static const char* titles[NUM_TITLES] = 
    {
        "Красивая математика для первокурсников",
        "История зоологии — история животных",
        "Проблемы агрохимии в современном земледелии",
        "Тайны вслеленной",
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
    if (seeded == 0) {
        srand((unsigned int)time(NULL)); 
        seeded = 1;
    }

    strcpy(pub->title, titles[rand() % NUM_TITLES]);
    
    strcpy(pub->author_surname, surnames[rand() % NUM_SURNAMES]);
    
    strcpy(pub->author_initials, initials[rand() % NUM_INITIALS]);
    
    strcpy(pub->journal, journals[rand() % NUM_JOURNALS]);
    
    pub->year = MIN_YEAR + rand() % YEAR_RANGE;
    
    pub->volume = MIN_VOLUME + rand() % VOLUME_RANGE;
    
    pub->is_rinc = ((rand() % 100) < RINC_PROBABILITY);
    
    pub->page_count = MIN_PAGES + rand() % PAGES_RANGE;
    
    pub->citations = MIN_CITATIONS + rand() % CITATIONS_RANGE;
}
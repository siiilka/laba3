#include "publication.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>

void generateRandomPublication(Publication* pub) 
{
    if (!pub) return;
    
    static const char* titles[] = 
    {
        "Красивая математика для первокурсников",
        "История зоологии — история животных",
        "Проблемы агрохимии в современном земледелии",
        "Тайны вслеленной",
        "Калибровка блока гироскопа"
    };
    
    static const char* surnames[] = 
    {
        "Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов"
    };
    
    static const char* initials[] = {"А.А.", "Б.Б.", "С.С.", "Д.Д.", "Е.Е."};
    
    static const char* journals[] = 
    {
        "Астрономический журнал", 
        "Алгебра и анализ",
        "Агрохимия",
        "Автоматика и телемеханика",
        "Зоологический журнал"
    };
    
    
}


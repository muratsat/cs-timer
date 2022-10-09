#include <time.h>

typedef struct tm DataTime;

// Устанавливает текущее системное данного компьютера
DataTime SetCurrentTime();

// Преобразует данную в формат DataTimer
// YY-MM-DD HH:MIN:SEC
DataTime GetTime(char* time_string);

// Печатает день недели (7-дневка, понедельник - 1 день)
char PrintWeekDay(DataTime t);
#include <time.h>

typedef struct tm DataTime;

// Устанавливает текущее системное данного компьютера
DataTime SetCurrentTime();

// Преобразует данную в формат DataTimer
// YY-MM-DD HH:MIN:SEC
DataTime GetTime(char* time_string);

// Печатает день недели (7-дневка, понедельник - 1 день)
char PrintWeekDay(DataTime t);

// Прибавляет к дате время, записанное как строка
// DD HH:MIN:SEC
DataTime After(DataTime time, char* time_delta);

// Вычисляет значение DataTime до DD HH:MIN:SEC
DataTime Before(DataTime time, char* time_delta);

// DataTime After(DataTime time, char* time_delta_string) {
//   DataTime new_time = time;
//   DataTime time_delta= {0};
//   strftime(time_delta_string, 26, "%Y-%m-%d %H:%M:%S", &time_delta);

//   new_time.tm_mday += time_delta.tm_mday;
//   new_time.tm_hour += time_delta.tm_hour;
//   new_time.tm_min += time_delta.tm_min;
//   new_time.tm_sec += time_delta.tm_sec;

//   mktime(&new_time);
//   return new_time;
// }

// DataTime Before(DataTime time, char* time_delta_string) {
//   DataTime time_delta = {0};
//   strftime(time_delta_string, 26, "%Y-%m-%d %H:%M:%S", &time_delta);

//   time.tm_mday -= time_delta.tm_mday;
//   time.tm_hour -= time_delta.tm_hour;
//   time.tm_min -= time_delta.tm_min;
//   time.tm_sec -= time_delta.tm_sec;

//   mktime(&time);
//   return time;
// }

#include "header.h"

// в планах сделать в либе:
// бинарное дерево
// двухсвязный список
// 
// мержсорт (не факт) (нужен вектор)
// бинарный поиск (нужен вектор)
// 
// побольше дефайнов для длинных тИпов const unsigned char и т.п.
// немного макросов для операций min max и т.п. (аудитор ахтунг!)
// сделать БОЛЬ_шинство функций более универсальными (смари принт секцию)

// ========================================================================= //

// не скомпилится, потому что я поменял функцию mx_printstr()

int main(int argc, char **argv) {
    if (argc && argv)
        mx_printstr("Hello World!\n");
}
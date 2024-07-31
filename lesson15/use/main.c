#include <stdio.h>
#include <stdint.h>
#include "input.h"
#include "../lib/inc/run.h"
#include "type.h"

int main() {
#ifdef DEBUG_FLAG
    printf("Debug Flag Enable");
#endif
    enum pattern_type choice;
    intmax_t line;
    while (1) {
        choice = getPattern();
        line = getLine(choice);
        runPattern(choice, line);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "run.h"
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

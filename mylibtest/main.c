#include <stdio.h>
#include <stdint.h>
#include "run.h"

int main() {
    enum pattern_type choice = 1;
    intmax_t line = 3;

	runPattern(choice, line);

    return 0;
}

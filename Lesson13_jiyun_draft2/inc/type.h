#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>
#define MAX_LINE 300

// 전역변수 extern 선언
extern intmax_t h_value[MAX_LINE];
extern intmax_t result[MAX_LINE];
extern intmax_t last_result[MAX_LINE];
extern intmax_t temp[MAX_LINE];

enum pattern_type{ // Pattern 1~8: enumeration
	pattern_triangle = 1,
	pattern_invert_triangle,
	pattern_diamond,
	pattern_parallelogram,
	pattern_invert_pyramid,
	pattern_height_triangle,
	pattern_length_triangle,
	pattern_random_option
};

#endif

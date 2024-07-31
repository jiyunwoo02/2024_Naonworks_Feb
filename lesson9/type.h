#ifndef TYPE_H
#define TYPE_H

// Q. 입력 부분에서 실행 부분으로 넘겨주는 pattern 부분의 Parameter를 enum으로 변경하여 준다.
// 사용자에게 입력받는 pattern 번호를 enum으로? - int choice를 enum pattern_type choice로 대체하자

enum pattern_type{ // Pattern 1~5: enumeration
	pattern_triangle = 1,
	pattern_invert_triangle,
	pattern_diamond,
	pattern_parallelogram,
	pattern_invert_pyramid
}; // ; 붙여야 한다!!

#endif

// pattern_type1과 다른 enum 상수명은 사용자가 입력한 값과 직접적으로 매핑되는 것이 아니다
// 이러한 상수는 코드의 가독성과 유지 보수성을 향상시키기 위해 사용된다
// 사용자가 1 입력 -- getPatern() 함수에 의해 return -- main() 함수에서 패턴 선택에 사용 -- switch문따라 선택
// pattern_type1은 단순히 첫 번째 패턴을 나타내는 게 아니다.
// 해당 패턴이 무엇을 나타내는지를 의미적으로 표현하는 데 사용된다.

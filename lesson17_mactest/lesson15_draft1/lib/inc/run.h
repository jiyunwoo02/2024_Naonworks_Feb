#include <stdbool.h>

enum TYPE{
   TRI=1,
   REVERSE_TRI,
   DIA,
   RIGHT_ALIGNED_SQUARE,
   RIGHT_ALIGNED_INV_TRI,
   ASC,
   STEPWISE,
   RANDOM_ASC
 };


int inputCheckType();
int inputCheckNum(enum TYPE typeNumber);


void printRandomAscendingTrinangle(int n);
void printStepWiseTriangle(int n);
void printAscendingTriangle(int n);
void printTriangle(int n);
void printReverseTriangle(int n);
void printDiamond(int n);
void printRightAlignedSquare(int n);
void printRightAlignedInvertedTriangle(int n);


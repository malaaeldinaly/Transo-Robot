#include <stdio.h>
#include "utils.h"

void test_utils() {
    printf("Running test_utils...\n");

    utilityFunction1();
    utilityFunction2(42);
}

int main() {
    test_utils();
    return 0;
}
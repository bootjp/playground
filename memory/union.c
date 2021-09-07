#include <stdio.h>

union UNION {
        char ch;
        int n;
};

int main() {
        union UNION obj;
        obj.n = 320;
        printf("%d" , obj.ch);

        return 0;
}

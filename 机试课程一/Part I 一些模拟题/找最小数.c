#include <stdio.h>
#define INT_MAX 0x3f3f3f3f

struct numPair {
    int x, y;
};

int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        struct numPair min, temp;
        min.x = INT_MAX, min.y = INT_MAX;
        while(n--) {
            scanf("%d %d",&temp.x, &temp.y);
            if(temp.x < min.x || (temp.x == min.x && temp.y < min.y)) {
                min = temp;
            }
        }
        printf("%d %d\n",min.x, min.y);
    }
    return 0;
}
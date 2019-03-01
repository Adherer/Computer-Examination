#include <stdio.h>
#include <string.h>
int main() {
    char a[] = "as", b[] = "asaassdfdasdfdasdfd";
    puts(a);
    puts(b);
    printf("%d\n", fun(a, b));
    return 0;
}
int fun(char *a,char *b) { 
   int i, j = 0;
   int len = strlen(b);
   for(i = 0;i < len - 1;i++) {
       if(a[0] == b[i] && a[1] == b[i+1]) {
           j++;
       }
   }
   return j;
}

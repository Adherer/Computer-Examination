#include <cstdio>
#include <stack>
using namespace std;

int main() {
    stack<int> S;
    int n, num;
    char c;
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i = 0; i < n; i++){
            c = getchar();
            scanf("%c", &c);
            switch(c){
                case 'A' : if(S.empty()) {
                               printf("E\n"); 
                           } else {
                                printf("%d\n", S.top());
                           } 
                           break;
                case 'P' : scanf("%d", &num); 
                           S.push(num); 
                           break;
                case 'O' : if(!S.empty()) {
                               S.pop();
                           } 
                           break;
            }
        }
        printf("\n");
        while(!S.empty()) {
            S.pop();
        }
    }
     
    return 0;
}
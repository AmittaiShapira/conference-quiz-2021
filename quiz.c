#include <stdio.h>

int main() {
    char ans[1000];
    int i, j, count = 0;
    char *str = "12[1]2 ECNE[2]EF[3]OC [4]CNE[5]LECXE W[6] EH[7] N[8][9]J";
    
    while (str[count] != '\0') {
        count++;
    }
    j = count - 1;
    for (i = 0; i <count; i++) {
         ans[i] = str[j];
         j--;
    }
    printf("Quiz answer: %s", ans);
}

#include <stdio.h>

int main() {
    char ans[1000];
    int i, j, count = 0;
    char *str = "1212 ECNE2EF3OC 4CNE5LECXE W6 EH7 N89J";
    
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

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int visited[26] = {0};  // for 'a' to 'z'

    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++) {
        int index = str[i] - 'a';

        if(visited[index] == 1) {
            printf("%c", str[i]);
            return 0;
        }

        visited[index] = 1;
    }

    printf("-1");  // no repeated character
    return 0;
}

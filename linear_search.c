#include <stdio.h>
#include <stdlib.h>
#define MAX_INDEX 9

struct {
    int key;
    char *data;
} table[10];

static void set_data();
static char *search(int key);

int main(int argc, char *argv[])
{
    set_data();

    char *tmp_key = argv[1];
    if (tmp_key == NULL || tmp_key == '\0') {
        printf("Specify index of data \n");
        return 0;
    }

    int key = atoi(tmp_key);
    char *result = search(key);
    if (result != NULL && result != '\0') {
        printf("result: %c \n", result);
    } else {
        printf("No result \n");
    }
    return 0;
}

static void set_data()
{
    int i = 0;
    for (i; i <= MAX_INDEX; i++) {
        table[i].key = i;
        char *data = 'A' + i;
        table[i].data = data;
    }
}

/**
 * Simple linear search
 */
static char *search(int key)
{
    int i = 0;
    char *result = NULL;
    while (i <= MAX_INDEX) {
        if (table[i].key == key) {
            result = table[i].data;
        }
        i++;
    }
    return result;
}

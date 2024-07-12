#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_POSITION_LENGTH 20

typedef struct {
    int jersey_no;
    char name[MAX_NAME_LENGTH];
    int age;
    char position[MAX_POSITION_LENGTH];
    int goals;
} Player;

void insertionSort(Player arr[], int n) {
    for (int i = 1; i < n; i++) {
        Player key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && (arr[j].age > key.age ||(arr[j].age == key.age && strcmp(arr[j].name, key.name) > 0))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printPlayers(Player arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Jersey No: %d , Name: %s , Age: %d , Position: %s , Goals: %d \n",
               arr[i].jersey_no, arr[i].name, arr[i].age, arr[i].position, arr[i].goals);
    }
}

int main() {
    int n;
    printf("Enter the number of players: ");
    scanf("%d", &n);

    Player players[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for player %d\n", i + 1);
        printf("Jersey No: ");
        scanf("%d", &players[i].jersey_no);
        printf("Name: ");
        scanf("%s", players[i].name);
        printf("Age: ");
        scanf("%d", &players[i].age);
        printf("Position: ");
        scanf("%s", players[i].position);
        printf("Goals: ");
        scanf("%d", &players[i].goals);
    }

    insertionSort(players, n);

    printf("Sorted players by age and name:\n");
    printPlayers(players, n);

    return 0;
}

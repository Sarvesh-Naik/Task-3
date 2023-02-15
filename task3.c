#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook {
    char name[50];
    char number[20];
    struct phonebook *next;
};

struct phonebook *head = NULL;

void add_entry() {
    struct phonebook *new_entry = (struct phonebook*) malloc(sizeof(struct phonebook));
    printf("Enter name: ");
    scanf("%s", new_entry->name);
    printf("Enter number: ");
    scanf("%s", new_entry->number);
    new_entry->next = head;
    head = new_entry;
}

void remove_entry() {
    char name[50];
    printf("Enter name to remove: ");
    scanf("%s", name);
    struct phonebook *current = head;
    struct phonebook *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("%s has been removed from the phone book.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%s not found in the phone book.\n", name);
}

void search_entry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    struct phonebook *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }
    printf("%s not found in the phone book.\n", name);
}

void display_entries() {
    struct phonebook *current = head;
    if (current == NULL) {
        printf("Phone book is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("Name: %s\nNumber: %s\n\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Search entry\n");
        printf("4. Display entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                remove_entry();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                display_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}

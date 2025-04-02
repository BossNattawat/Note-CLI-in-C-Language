#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOTES 10
#define NOTE_LENGTH 256

char notes[MAX_NOTES][NOTE_LENGTH];
int noteCount = 0;

void createNote() {
    if (noteCount >= MAX_NOTES) {
        printf("Note storage is full!\n");
        return;
    }

    while (getchar() != '\n');

    printf("Create Note: ");
    fgets(notes[noteCount], NOTE_LENGTH, stdin);
    
    notes[noteCount][strcspn(notes[noteCount], "\n")] = 0;

    noteCount++;
    printf("\nNote saved!\n");
}

void viewNotes(){
    if (noteCount == 0) {
        printf("\nNo notes available.\n\n");
        return;
    }

    printf("\n---------- All notes ----------\n\n");
    for(int i = 0; i < noteCount; i++){
        printf("%d. %s\n", i + 1, notes[i]);
    }
}

void deleteNote(){
    if (noteCount == 0) {
        printf("\nNo notes to delete.\n\n");
        return;
    }

    int noteIndex;
    printf("Enter note number to delete (1-%d): ", noteCount);
    scanf("%d", &noteIndex);

    if(noteIndex < 1 || noteIndex > noteCount){
        printf("Invalid note number.\n");
        return;
    }

    for (int i = noteIndex - 1; i < noteCount - 1; i++) {
        strcpy(notes[i], notes[i + 1]);
    }

    noteCount--;
    printf("\nNote deleted successfully.\n");

}

int main(){

    int selectedMenu;

    while(1){
        printf("\n---------- Note App ----------\n\n");
        printf("Note Menu:\n1. Create Note\n2. View Notes\n3. Delete Note\n4. Exit\n\n");
        printf("Select a menu: ");
        scanf("%d", &selectedMenu);

        switch(selectedMenu){
            case 1:
                createNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                deleteNote();
                break;
            case 4: {
                char confirmExit;
                printf("\nConfirm exit (y/n): ");
                while (getchar() != '\n'); 
                scanf("%c", &confirmExit);

                if (tolower(confirmExit) == 'y') {
                    printf("Exiting...\n");
                    return 0;
                }
                break;
            }
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}
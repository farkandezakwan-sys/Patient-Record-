#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
    char doctor[50];
    char city[30];
    char phone[15];
};

struct Patient p[MAX];
int count = 0;

// ---------------- ADD ----------------
void addPatient() {
    if(count >= MAX) {
        printf("Database full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &p[count].id);

    // check duplicate
    for(int i = 0; i < count; i++) {
        if(p[i].id == p[count].id) {
            printf("ID already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", p[count].name);

    do {
        printf("Enter Age: ");
        scanf("%d", &p[count].age);
    } while(p[count].age <= 0 || p[count].age >= 120);

    printf("Enter Gender: ");
    scanf("%s", p[count].gender);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p[count].disease);

    printf("Enter Doctor: ");
    scanf(" %[^\n]", p[count].doctor);

    printf("Enter City: ");
    scanf("%s", p[count].city);

    printf("Enter Phone: ");
    scanf("%s", p[count].phone);

    count++;
    printf("Patient added successfully!\n");
}

// ---------------- DISPLAY ----------------
void displayAll() {
    if(count == 0) {
        printf("No records found!\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("\nID: %d", p[i].id);
        printf("\nName: %s", p[i].name);
        printf("\nAge: %d", p[i].age);
        printf("\nDisease: %s", p[i].disease);
        printf("\nDoctor: %s", p[i].doctor);
        printf("\nCity: %s", p[i].city);
        printf("\nPhone: %s\n", p[i].phone);
    }
}

// ---------------- SEARCH ----------------
void searchPatient() {
    int choice, found = 0;
    char name[50], disease[50];

    printf("1. Search by ID\n2. Search by Name\n3. Search by Disease\nChoice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        int id;
        printf("Enter ID: ");
        scanf("%d", &id);

        for(int i = 0; i < count; i++) {
            if(p[i].id == id) {
                found = 1;
                printf("\nFound: %s (%s)\n", p[i].name, p[i].disease);
            }
        }
    }

    else if(choice == 2) {
        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        for(int i = 0; i < count; i++) {
            if(strcmp(p[i].name, name) == 0) {
                found = 1;
                printf("\n%s - %s\n", p[i].name, p[i].disease);
            }
        }
    }

    else if(choice == 3) {
        printf("Enter Disease: ");
        scanf(" %[^\n]", disease);

        for(int i = 0; i < count; i++) {
            if(strcmp(p[i].disease, disease) == 0) {
                found = 1;
                printf("\n%s - %s\n", p[i].name, p[i].city);
            }
        }
    }

    if(!found) printf("No matching records!\n");
}

// ---------------- DELETE ----------------
void deletePatient() {
    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(p[i].id == id) {
            for(int j = i; j < count - 1; j++) {
                p[j] = p[j + 1];
            }
            count--;
            found = 1;
            printf("Deleted successfully!\n");
            break;
        }
    }

    if(!found) printf("Record not found!\n");
}

// ---------------- UPDATE ----------------
void updatePatient() {
    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(p[i].id == id) {
            printf("Enter New Disease: ");
            scanf(" %[^\n]", p[i].disease);

            printf("Enter New Doctor: ");
            scanf(" %[^\n]", p[i].doctor);

            found = 1;
            printf("Updated successfully!\n");
            break;
        }
    }

    if(!found) printf("Record not found!\n");
}

// ---------------- MAIN ----------------
int main() {
    int choice;

    do {
        printf("\n--- Patient Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. Display All\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addPatient(); break;
            case 2: displayAll(); break;
            case 3: searchPatient(); break;
            case 4: updatePatient(); break;
            case 5: deletePatient(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}

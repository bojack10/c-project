#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define count 1330

void lib();
void stud();
void menu();
void MAIN();
void b_list();
void add();
void issue();
void search();

struct Library {
    char bname[30];
    char subj[20];
    int bno;
};

int main() {
    MAIN();
    return 0;
}

void MAIN() {
    int op;
    system("cls");
    printf("\t\t\t\t############### library management system ###############\n");
    printf("\t\t\t\t==========================================================\n");
    printf("\t\t\t\t1.LIBRARIAN LOGIN\n\n\t\t\t\t2.STUDENT LOGIN\n\n\t\t\t\t3.EXIT\n\n");
    printf("\t\t\t\tENTER YOUR CHOICE{1/2/3}: ");
    scanf("%d", &op);
    switch (op) {
        case 1:
            lib();
            break;
        case 2:
            stud();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n\t\t\t\tINVALID CHOICE!!\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE.");
            getch();
            MAIN();
            break;
    }
}

void lib() {
    system("cls");
    int i = 2;
    char pswd[8], p[] = "mite";
    printf("\n\n\t\t\t\t############### WELCOME TO LIBRARIAN LOGIN ###############\n");
a:
    printf("\n\n\t\t\t\tPLEASE ENTER PASSWORD: ");
    scanf("%s", pswd);
    int x = strcmp(pswd, p);

    if (x == 0)
        menu();
    else
        while (i > 0) {
            printf("\n\t\t\t\tWRONG PASSWORD!!\n\t\t\t\tONLY %d CHANCES LEFT!\n\n", i);
            i--;
            goto a;
        }
    if (i == 0) {
        printf("\t\t\t\tPLEASE TRY AFTER SOME TIME! :)\n");
        exit(0);
    }
}

void menu() {
    int op, x;
    char ch[] = "y", c[2];
    system("cls");
    printf("\t\t\t\t############### LIBRARY MENU ###############\n\n");
    printf("\t\t\t\t============================================\n");
    printf("\t\t\t\t1.BOOK AVAILABILITY\n\n\t\t\t\t2.ADD BOOK\n\n\t\t\t\t3.ISSUE BOOK");
    printf("\n\n\t\t\t\t4.GOTO MAIN MENU\n\n\t\t\t\t5.CLOSE APPLICATION\n");
    printf("\n\n\t\t\t\tENTER YOUR CHOICE{1/2/3/4/5}: ");
    scanf("%d", &op);
    switch (op) {
        case 1:
            b_list();
            break;
        case 2:
            add();
            break;
        case 3:
            issue();
            break;
        case 4:
            MAIN();
            break;
        case 5:
            printf("\t\t\t\tDO YOU REALLY WANT TO EXIT?(Y/N): ");
            scanf("%s", c);
            x = strcmp(ch, c);
            if (x == 0)
                exit(0);
            else
                menu();
            break;
        default:
            printf("\t\t\t\tYOU HAVE ENTERED INVALID CHOICE!\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE.");
            getch();
            menu();
            break;
    }
}

void b_list() {
    system("cls");
    printf("\t\t\t\t############### BOOK LIST ###############\n\n");
    printf("\t\t\t\tB.NO\t\tSUBJECT\t\tBOOK NAME\n");
    printf("\t\t\t\t=========================================\n");
    FILE *file;
    char data[100];
    file = fopen("book1.txt", "r");
    while (fgets(data, sizeof(data), file)) {
        printf("\t\t\t\t%s", data);
    }
    fclose(file);
}

void add() {
    system("cls");
    FILE *b_file;
    char subj[25], bname[20];
    int bno, op;
    b_file = fopen("book1.txt", "a");
    printf("\t\t\t\t############### BOOK ADDING MENU ###############\n");
    printf("\n\t\t\t\tENTER THE SUBJECT OF THE BOOK: ");
    scanf("%s", subj);
    printf("\n\n\t\t\t\tENTER THE NAME OF THE BOOK: ");
    scanf("%s", bname);
    printf("\t\t\t\tENTER THE BOOK NUMBER: ");
    scanf("%d", &bno);
    fprintf(b_file, "%s %s %d\n", subj, bname, bno);
    fclose(b_file);
    b_file = fopen("book1.txt", "r");
    if (b_file) {
        char data[100];
        while (fgets(data, sizeof(data), b_file)) {
            printf("\t\t\t\t%s", data);
        }
        fclose(b_file);
    }
a:
    printf("\n\n\t\t\t\tBOOK ADDED SUCCESSFULLY IN THE RECORD!!\n");
    printf("\n\t\t\t\t1.ADD MORE BOOKS\n\n\t\t\t\t2.GOTO MAIN MENU\n\n\t\t\t\t3.GOTO LIBRARIAN MENU\n");
    printf("\n\t\t\t\tENTER YOUR CHOICE{1/2/3}: ");
    scanf("%d", &op);
    if (op == 1) {
        add();
    } else if (op == 2) {
        MAIN();
    } else if (op == 3) {
        menu();
    } else {
        printf("\n\t\t\t\tINVALID INPUT!\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE.");
        getch();
        system("cls");
        goto a;
    }
}

void search() {
    system("cls");
    int op, bno;
    char name[25];
    printf("\t\t\t\t############### BOOK SEARCH MENU ###############\n");
    printf("\n\n\t\t\t\t1.SEARCH BY BOOK NUMBER\n\n\t\t\t\t2.SEARCH BY BOOK NAME\n");
    printf("\t\t\t\tENTER YOUR CHOICE{1/2}: ");
    scanf("%d", &op);
    if (op == 1) {
        printf("\n\n\t\t\t\tENTER BOOK NUMBER: ");
        scanf("%d", &bno);
        if (bno >= 1001 && bno <= 1330)
            printf("\n\n\t\t\t\tBOOK FOUND\n");
        else
            printf("\n\n\t\t\t\tBOOK NOT FOUND!!\n");
    } else if (op == 2) {
        printf("\n\n\t\t\t\tENTER BOOK NAME: ");
        scanf("%s", name);
    } else {
        system("cls");
        search();
    }
}

void stud() {
    system("cls");
    int op;
    printf("\t\t\t\t############### STUDENT MENU ###############\n\n");
    printf("\t\t\t\t1.VIEW BOOKS\n\n\t\t\t\t2.SEARCH BOOK\n\n\t\t\t\t3.GOTO MAIN MENU\n\n\t\t\t\t4.EXIT APPLICATION\n");
    printf("\n\t\t\t\tENTER YOUR CHOICE{1/2/3/4}: ");
    scanf("%d", &op);
    switch (op) {
        case 1:
            b_list();
            break;
        case 2:
            search();
            break;
        case 3:
            MAIN();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n\n\t\t\t\tINVALID CHOICE!!\n\n\t\t\t\tPRESS ANY KEY TO CONTINUE.");
            getch();
            stud();
            break;
    }
}

void issue() {
    system("cls");
    int bno, op;
    printf("\t\t\t\t############### BOOK ISSUING MENU ###############\n");
a:
    printf("\n\n\t\t\t\tENTER THE BOOK NUMBER: ");
    scanf("%d", &bno);
    if (bno > 1000 && bno <= 1330) {
        time_t now = time(0);
        char* dt = ctime(&now);
        printf("\n\n\t\t\t\tBOOK IS ISSUED ON: %s\n", dt);
        printf("\n\t\t\t\tBOOK SHOULD BE RETURNED AFTER 7 DAYS OF ISSUING!!!");
        printf("\n\t\t\t\tFOR LATE SUBMISSION FINE HAS TO BE PAID {Rs.2/DAY}");
        printf("\n\n\t\t\t\t1.GOTO MAIN MENU\n\n\t\t\t\t2.EXIT APPLICATION\n");
        printf("\n\t\t\t\tENTER YOUR CHOICE{1/2}: ");
        scanf("%d", &op);
        if (op == 1)
            MAIN();
        else
            exit(0);
    } else {
        system("cls");
        printf("\n\n\t\t\t\tBOOK NOT FOUND IN THE RECORD!! SEARCH AGAIN\n");
        goto a;
    }
}

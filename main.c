#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define DISCOUNT_1 0.05
#define DISCOUNT_2 0.10
#define DISCOUNT_3 0.15

void menuSelection();
void bookField();
void softwareBook();
void websiteBook();
void mobileBook();
void mainSystem();
void exitProgram();
void calculate();
void generateReport();

void menuSelection() {
    int select;
    do {
        printf("Select an option (1 = View Menu, 2 = Sales Order, 3 = Exit): ");
        scanf("%d", &select);
        freopen(NULL, "r", stdin);
        switch(select) {
            case 1:
                bookField();
                break;
            case 2:
                mainSystem();
                break;
            case 3:
                exitProgram();
                break;
            default:
                printf("Invalid input, function not found!\n");
                sleep(2);
        }
    } while(select != 1 && select != 2 && select != 3);
}

void bookField() {
    int select;
    do {
        printf("\nSelect a field to view:\n");
        printf("1 = Software Development Programming\n");
        printf("2 = Web Programming\n");
        printf("3 = Mobile Programming\n");
        printf("Input: ");
        scanf("%d", &select);
        freopen(NULL, "r", stdin);
        switch(select) {
            case 1:
                softwareBook();
                break;
            case 2:
                websiteBook();
                break;
            case 3:
                mobileBook();
                break;
            default:
                printf("Invalid input, book category not found!\n");
                sleep(2);
        }
    } while(select != 1 && select != 2 && select != 3);
}

void softwareBook() {
    printf("\nSoftware Development Programming Books:\n");
    printf("A = Beginning with Programming Logic and Design      RM69.00\n");
    printf("B = C Programming                                    RM70.00\n");
    printf("C = Programming Fundamentals                         RM55.50\n\n");
    printf("Press ENTER to continue!\n");
    getchar();
    menuSelection();
}

void websiteBook() {
    printf("\nWeb Programming Books:\n");
    printf("D = HTML and CSS Design                              RM58.00\n");
    printf("E = Web Programming                                  RM65.00\n");
    printf("F = ASP .NET Programming                             RM89.00\n\n");
    printf("Press ENTER to continue!\n");
    getchar();
    menuSelection();
}

void mobileBook() {
    printf("\nMobile Programming Books:\n");
    printf("G = Mobile Design and Programming                    RM73.50\n");
    printf("H = Building Mobile App                              RM80.00\n");
    printf("I = Android Programming                              RM50.00\n\n");
    printf("Press ENTER to continue!\n");
    getchar();
    menuSelection();
}

int quantity;
int salesNo = 1;
int totalBook = 0;
int bookCount[9];
int storeBookCount[9];
char selectBook;
char confirmOrder;
char nextOrder;
char bookName[9];
char bookNameList[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
double subtotal = 0;
double discount = 0;
double totalToPay = 0;
double totalAmount = 0;
double totalAmountOrder = 0;
double bookPrice[9];
double storeBookPrice[9];

void mainSystem() {
    printf("\nSales Order No: %d\n", salesNo);
    do {
        printf("Book A,B,C,D,E,F,G,H,I (X = Exit): ");
        scanf("%c", &selectBook);
        freopen(NULL, "r", stdin);
        selectBook = toupper(selectBook);
        switch(selectBook) {
            case 'A':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[0] = 'A';
                bookCount[0] = quantity;
                bookPrice[0] = 69.00;
                break;
            case 'B':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[1] = 'B';
                bookCount[1] = quantity;
                bookPrice[1] = 70.00;
                break;
            case 'C':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[2] = 'C';
                bookCount[2] = quantity;
                bookPrice[2] = 55.50;
                break;
            case 'D':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[3] = 'D';
                bookCount[3] = quantity;
                bookPrice[3] = 58.00;
                break;
            case 'E':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[4] = 'E';
                bookCount[4] = quantity;
                bookPrice[4] = 65.00;
                break;
            case 'F':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[5] = 'F';
                bookCount[5] = quantity;
                bookPrice[5] = 89.00;
                break;
            case 'G':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[6] = 'G';
                bookCount[6] = quantity;
                bookPrice[6] = 73.50;
                break;
            case 'H':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[7] = 'H';
                bookCount[7] = quantity;
                bookPrice[7] = 80.00;
                break;
            case 'I':
                printf("Quantity      : ");
                scanf("%d", &quantity);
                freopen(NULL, "r", stdin);
                bookName[8] = 'I';
                bookCount[8] = quantity;
                bookPrice[8] = 50.00;
                break;
            case 'X':
                do {
                    printf("Confirm the order? (Y = Yes, N = No): ");
                    scanf("%c", &confirmOrder);
                    freopen(NULL, "r", stdin);
                    confirmOrder = toupper(confirmOrder);
                    switch(confirmOrder) {
                        case 'Y':
                            calculate();
                            break;
                        case 'N':
                            mainSystem();
                            break;
                        default:
                            printf("Invalid input, please select 'Y' or 'N'!\n");
                            sleep(2);
                    }
                } while(confirmOrder != 'Y' && confirmOrder != 'N');
                break;
            default:
                printf("Invalid input, book not found!\n");
                sleep(2);
        }
    } while(confirmOrder != 'Y');
}

void calculate() {
    for(int i = 0; i < 10; i++) {
        if(bookName[i]) {
            printf("Book %c: %d @ RM %.2lf           =                 RM%6.2lf\n", bookName[i], bookCount[i], bookPrice[i], bookPrice[i] * bookCount[i]);
        }
        subtotal += bookPrice[i] * bookCount[i];
        storeBookCount[i] += bookCount[i];
        storeBookPrice[i] += bookPrice[i];
        totalAmountOrder += bookPrice[i] * storeBookCount[i];
        totalBook += bookCount[i];
    }
    if(subtotal >= 200 && subtotal < 300) {
        discount = subtotal * DISCOUNT_1;
    } else if(subtotal >= 300 && subtotal < 500) {
        discount = subtotal * DISCOUNT_2;
    } else if(subtotal >= 500) {
        discount = subtotal * DISCOUNT_3;
    }
    totalToPay = subtotal - discount;
    printf("                                                 ========\n");
    printf("Subtotal                       =                 RM%6.2lf\n", subtotal);
    printf("Discounts                      =                 RM%6.2lf\n", discount);
    printf("                                                 ========\n");
    printf("Total to Pay                   =                 RM%6.2lf\n\n", totalToPay);
    printf("             THANK YOU, HAVE A NICE DAY!!\n\n");
    do {
        printf("Next order? (Y = Yes, N = No): ");
        scanf("%c", &nextOrder);
        freopen(NULL, "r", stdin);
        nextOrder = toupper(nextOrder);
        switch(nextOrder) {
            case 'Y':
                for(int i = 0; i < 10; i++) {
                    bookName[i] = '\0';
                    bookCount[i] = 0;
                    bookPrice[i] = 0;
                }
                confirmOrder = '\0';
                subtotal = 0;
                discount = 0;
                totalToPay = 0;
                salesNo++;
                mainSystem();
                break;
            case 'N':
                generateReport();
                break;
            default:
                printf("Invaild input, please select 'Y' or 'N'!\n");
                sleep(2);
        }
    } while(nextOrder != 'Y' && nextOrder != 'N');
}

void generateReport() {
    system("clear");
    printf("          DAILY SALES ORDER SUMMARY REPORT\n\n");
    printf("Total Number of Sales Orders = %d\n", salesNo);
    printf("%-14s %-29s %-16s\n", "Book", "Quantity Sold Sales", "Amount");
    for(int i = 0; i < 9; i++) {
        printf("%-14c %11d %24.2lf\n", bookNameList[i], storeBookCount[i], storeBookPrice[i] * storeBookCount[i]);
    }
    printf("%26s %25s", "====", "=========\n");
    printf("Total   %18d %24.2lf\n", totalBook, totalAmountOrder);
}

void exitProgram() {
    system("clear");
    printf("Goodbye!\n");
    exit(0);
}

int main() {
    menuSelection();
    return 0;
}
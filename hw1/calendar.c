#include <stdio.h>


int is_leap(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int get_month_days(int month, int year) {
    int days_fo_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && is_leap(year))
        return 29;
    return days_fo_month[month - 1];
}

int get_month_first_day(int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int a = year % 100;
    int b = year / 100;
    int h = (13 * (month + 1)/5 + a + a/4 + b/4 + 5*b) % 7;
    
    return (h + 6) % 7;
}

int main() {
    int month, year;
    const char *months[] = {"January","February","March","April","May","June",
                            "July","August","September","October","November","December"};

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    printf("\n     %s %d\n", months[month-1], year);
    printf("Mo Tu We Th Fr Sa Su\n");

    int first_day = get_month_first_day(month, year);
    int days = get_month_days(month, year);

    for (int i = 0; i < first_day; i++)
        printf("   ");

    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((first_day + day) % 7 == 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}
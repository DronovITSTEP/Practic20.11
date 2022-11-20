#include <iostream>
#include <iomanip>

using namespace std;

/*void f(string str, string c) {
    cout << "***********\n"
        << "* " << setw(8) << left << str << "*\n"
        << "*         *\n"
        << "*         *\n"
        << "*" << setw(5) << right << c << setw(6) << "*\n"
        << "*         *\n"
        << "*         *\n"
        << "***********\n\n";
}*/

// проверка на високосность
bool IsLeap(int);

//ф-я для подсчета кол-ва дней от начала года до заданного месяца
int countOfDayInMonth(int);

// ф-я для подсчета кол-ва дней при разных годах
int coutOfDayInYear(int, int);

void countAllDays(int, int, int, int, int, int);


/*int avgArr(int arr[], int s) {
    int sum = 0;
    for (int i = 0; i < s; i++) {
        sum += arr[i];
    }
    return (sum / 10 > 0) ? s / 3 * 2 : s / 3;
}

void sortArr(int arr[], int s) {
    int n = avgArr(arr, s); // размер 1/3 или 2/3 массива
    // сортировка по возрастанию (метод пузырька)
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = t;
            }
        }
    }

    // сортировка в обратном порядке
    for (int i = n, j = s-1; i <= j; i++, j--) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
}*/

int main()
{
    /*int arr[2][5]{
        {5,7,9,1,6},
        {6,7,8,1,9},
    };

    int n = 3;

    
    //цикл для кол-во сдвигов
    for (int i = 0; i < n; i++) {
        //цикл сдивга вправо
        for (int j = 0; j < 2; j++) {
            int temp = arr[j][4];
            for (int k = 4; k > 0; k--) {                
                arr[j][k] = arr[j][k - 1];
            }
            arr[j][0] = temp;
        }
    }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        

    for (int i = 0; i < n; i++) {
        //цикл сдивгов влево
        for (int j = 0; j < 2; j++) {
            int temp = arr[j][0];
            for (int k = 0; k < 4; k++) {
                arr[j][k] = arr[j][k + 1];
            }
            arr[j][4] = temp;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    

    // цикл сдвига вверх
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < 5; j++) {
            int temp = arr[0][j];
            for (int i = 0; i < 1; i++) {
                arr[i][j] = arr[i+1][j];
            }
            arr[1][j] = temp;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //цикл сдвига вниз
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < 5; j++) {
            int temp = arr[1][j];
            for (int i = 1; i > 0; i--) {
                arr[i][j] = arr[i - 1][j];
            }
            arr[0][j] = temp;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/

    //f("krest", "9");
    //countAllDays(2015, 11, 20,
    //    2022, 8, 3);
    //countAllDays(2022, 8, 3,
    //    2015, 11, 20);

    //int arr[10]{ 4,-5,4,9,-8,6,-3,-7,5,6 };
    //sortArr(arr, 10);
}

// проверка на високосность
bool IsLeap(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

//ф-я для подсчета кол-ва дней от начала года до заданного месяца
int countOfDayInMonth(int month) {
    int sumDay = 0;
    for (int i = 1; i < month; i++) {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            sumDay += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            sumDay += 30;
            break;
        case 2:
            sumDay += 28;
            break;
        default:
            break;
        }
    }
    return sumDay;
}

// ф-я для подсчета кол-ва дней при разных годах
int coutOfDayInYear(int year1, int year2) {
    int sumDay = 0;
    for (int i = min(year1, year2); i < max(year1, year2); i++) {
        IsLeap(i) ? sumDay += 366 : sumDay += 365;
    }
    return sumDay;
}

void countAllDays(int year1, int month1, int day1,
    int year2, int month2, int day2) {

    int sumDay1 = countOfDayInMonth(month1),
        sumDay2 = countOfDayInMonth(month2);
    sumDay1 += day1;
    sumDay2 += day2;

    (year1 > year2) ?
        cout << abs(sumDay1 - sumDay2) + coutOfDayInYear(year1, year2) << endl :
        cout << coutOfDayInYear(year1, year2) - abs(sumDay1 - sumDay2) << endl;
}




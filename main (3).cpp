#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

void calendar(int year) {
    vector<int> plusArrJF;
    for (int i = 0; i < 650; i++) {
        if (i % 4 == 0) {
            plusArrJF.push_back(2);
        }
        else {
            plusArrJF.push_back(1);
        }
    }
    vector<int> plusArrOthers;
    for (int i = 0; i < 650; i++) {
        if (i % 4 == 0) {
            plusArrOthers.push_back(2);
        }
        else {
            plusArrOthers.push_back(1);
        }
    }
    vector<int> minusArrJF;
    for (int i = 1; i < 650; i++) {
        if (i % 4 == 0) {
            minusArrJF.push_back(5);
        }
        else {
            minusArrJF.push_back(6);
        }
    }
    vector<int> minusArrOthers;
    for (int i = 0; i < 650; i++) {
        if (i % 4 == 0) {
            minusArrOthers.push_back(5);
        }
        else {
            minusArrOthers.push_back(6);
        }
    }
    
    
    vector<vector<int>> monthes;
    for (int i = 0; i < 12; i++) {
        vector<int> month(700);
        for (int j = 5; j < 700; j++) {
            month[j] = j - 4;
        }
        monthes.push_back(month);
    }
    int originYear = 2000;
    int originweekday = 6;
    string originSpace = "               ";
    int difference = year - originYear;
    map<int, string> weekday;
    weekday[1] = "Mn";
    weekday[2] = "Ts";
    weekday[3] = "Wd";
    weekday[4] = "Th";
    weekday[5] = "Fr"; 
    weekday[6] = "St";
    weekday[7] = "Sn";
    map<int, string> months;
    months[1] = "Janary";
    months[2] = "February";
    months[3] = "March";
    months[4] = "April";
    months[5] = "May";
    months[6] = "June";
    months[7] = "July";
    months[8] = "August";
    months[9] = "September";
    months[10] = "October";
    months[11] = "November";
    months[12] = "December";
    for (int j = 0; j < 700; j++) {
        monthes[1][j] -= 3;
        if (monthes[1][j] < 0) {
            monthes[1][j] = 0;
        }
    }
    for (int j = 0; j < 700; j++) {
        monthes[2][j] -= 4;
        if (monthes[2][j] < 0) {
            monthes[2][j] = 0;
        }
    }
    for (int j = 0; j < 700; j++) {
        monthes[4][j] -= 2;
        if (monthes[4][j] < 0) {
            monthes[4][j] = 0;
        }
    }
    for (int j = 0; j < 700; j++) {
        monthes[5][j] -= 5;
        if (monthes[5][j] < 0) {
            monthes[5][j] = 0;
        }
    }
    for (int j = 0; j < 700; j++) {
        monthes[7][j] -= 3;
        if (monthes[7][j] < 0 ) {
            monthes[7][j] = 0;
        }
    }
    for (int j = 0; j < 700; j++) {
        monthes[8][j] -= 6;
        if (monthes[8][j] < 0) {
            monthes[8][j] = 0;
        }
    }
    for (int j = 0; j < 700; j++) {
        monthes[9][j] -= 1;
        if (monthes[9][j] < 0 ) {
            monthes[9][j] = 0;
        }
    }
    monthes[10] = monthes[2];
    monthes[11] = monthes[8];
    monthes[11][41] = 31;
    
    if (difference > 0) {
        for (int count = 0; count < difference; count++) {
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 650; j++) {
                    if (i == 0 or i == 1) {
                        monthes[i][j] -= plusArrJF[count] ; 
                    }
                    else {
                        monthes[i][j] -= plusArrOthers[count];
                    }
                }
            }
        }
    }
    else {
        difference = abs(difference);
        for (int count = 0; count < difference; count++) {
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 650; j++) {
                    if (i == 0 or i == 1) {
                        monthes[i][j] -= minusArrJF[count] ; 
                    }
                    else {
                        monthes[i][j] -= minusArrOthers[count];
                    }
                }
            }
        }
    }
        
    
    
    
    

    if (year % 4 == 0) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 700; j++) {
                if (i == 1 and monthes[i][j] > 29) {
                    monthes[i][j] = 0;  
                }
                else if ((i == 0 or i == 2 or i == 4 or i == 6 or i == 7 or i == 9 or i == 11) and monthes[i][j] > 31) {
                    monthes[i][j] = 0;
                }
                else if ((i == 3 or i == 5 or i == 8 or i == 10) and monthes[i][j] > 30) {
                    monthes[i][j] = 0;
                }
            }
        }
    }
    else {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 700; j++) {
                if (i == 1 and monthes[i][j] > 28) {
                    monthes[i][j] = 0;
                }
                else if ((i == 0 or i == 2 or i == 4 or i == 6 or i == 7 or i == 9 or i == 11) and monthes[i][j] > 31) {
                    monthes[i][j] = 0;
                }
                else if ((i == 3 or i == 5 or i == 8 or i == 10) and monthes[i][j] > 30) {
                        monthes[i][j] = 0;
                }
                
            }
        }
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 700; j++) {
            if (monthes[i][j] < 0) {
                monthes[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 12; i++) {
        cout << months[i+1] << endl;
        for (auto pair : weekday) {
            cout << pair.second << "   ";
        }
        cout << endl;
        for (int j = 0; j < 700; j += 7) {
            if (monthes[i][j] == 0 and  monthes[i][j+1] == 0 and  monthes[i][j+2] == 0 and  monthes[i][j+3] == 0 and monthes[i][j+4] == 0 and monthes[i][j+5] == 0 and monthes[i][j+6] == 0) {
            }
            else {
                printf ("%2d   %2d   %2d   %2d   %2d   %2d   %2d\n", monthes[i][j], monthes[i][j+1], monthes[i][j+2], monthes[i][j+3], monthes[i][j+4], monthes[i][j+5], monthes[i][j+6]);
            }
        }
        
    }
}


    
    

int main()
{
    int year;
    cout << "Введите год в диапазоне (1910-2050)" << endl;
    cin >> year;
    if (year > 1910 and year < 2050) {
        calendar(year);
    }
    else {
        cout << "Неправильный диапазон или неправильный формат ввода"
    }
}

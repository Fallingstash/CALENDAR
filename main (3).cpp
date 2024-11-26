#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

void calendar(int year) {
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
        if (monthes[1][j] < 0 or monthes[1][j] > 29) {
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
        if (monthes[3][j] > 30) {
            monthes[3][j] = 0;
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
        if (monthes[5][j] > 30 or monthes[5][j] < 0) {
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
        if (monthes[8][j] < 0 or monthes[8][j] > 30) {
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
    for (int j = 0; j < 700; j++) {
        if (monthes[10][j] > 30) {
            monthes[10][j] = 0;
        }
    }
    monthes[11] = monthes[8];
    monthes[11][41] = 31;
    
    if (difference > 0) {
        for (int i = 0; i < 12; i++ ) {
            
    }
    
    

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 700; j++) {
            if (monthes[i][j] > 31) {
                monthes[i][j] = 0;
            } 
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
            printf ("%2d   %2d   %2d   %2d   %2d   %2d   %2d\n", monthes[i][j], monthes[i][j+1], monthes[i][j+2], monthes[i][j+3], monthes[i][j+4], monthes[i][j+5], monthes[i][j+6]);
        }
        
    }
}


    
    

int main()
{
    int year;
    cout << "Введите год" << endl;
    cin >> year;
    calendar(year);
}

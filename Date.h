#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // Costruttori
    Date();
    Date(int d, int m, int y);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDate(int d, int m, int y);

    // Operatori
    bool operator==(const Date &other) const;
    bool operator<(const Date &other) const; // Nuovo: Serve per ordinare le date

    // Metodi
    std::string formatDate() const;
    bool isValid() const;
};

#endif
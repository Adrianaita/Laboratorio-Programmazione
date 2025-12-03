#include "Date.h"
#include <sstream>
#include <iomanip>

// Costruttore di default
Date::Date() : day(1), month(1), year(2024) {}

// Costruttore con parametri
Date::Date(int d, int m, int y)
{
    if (!isValid())
    {
        day = 1;
        month = 1;
        year = 2024;
    }
    else
    {
        day = d;
        month = m;
        year = y;
    }
}

// Getters
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

// Setter unico (sostituisce i vecchi setYear, setMonth...)
void Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

// Operatore di uguaglianza
bool Date::operator==(const Date &other) const
{
    return day == other.day && month == other.month && year == other.year;
}

// Operatore Minore (<) - NUOVO per il tuo progetto
bool Date::operator<(const Date &other) const
{
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

// Metodo formattazione (sostituisce il vecchio toString)
std::string Date::formatDate() const
{
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << day << "/"
       << std::setw(2) << std::setfill('0') << month << "/"
       << year;
    return ss.str();
}

// Verifica validità
bool Date::isValid() const
{
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}
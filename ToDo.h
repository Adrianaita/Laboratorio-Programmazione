#pragma once

#include "Date.h"
#include <string>

enum class Priority
{
    LOW,
    NORMAL,
    HIGH
};

class ToDo
{
private:
    std::string title;
    Date deadline;
    bool isDone;
    Priority priority;

public:
    // Costruttore

    ToDo(const std::string &text, const Date &date, Priority prio = Priority::NORMAL);

    // Getters
    std::string getTitle() const;
    Date getDeadline() const;
    bool getStatus() const;
    Priority getPriority() const;

    // Setters
    void setTitle(const std::string &text);
    void setDeadline(const Date &date);
    void setStatus(bool status);
    void setPriority(Priority prio);

    // Metodi

    std::string toString() const;
};
#include "ToDo.h"
#include <sstream>

// Costruttore

ToDo::ToDo(const std::string &text, const Date &date, Priority prio)
    : title(text), deadline(date), priority(prio), isDone(false)
{
}

// GETTERS

std::string ToDo::getTitle() const
{
    return title;
}

Date ToDo::getDeadline() const
{
    return deadline;
}

bool ToDo::getStatus() const
{
    return isDone;
}

Priority ToDo::getPriority() const
{
    return priority;
}

// SETTERS

void ToDo::setTitle(const std::string &text)
{
    title = text;
}

void ToDo::setDeadline(const Date &date)
{
    deadline = date;
}

void ToDo::setStatus(bool status)
{
    isDone = status;
}

void ToDo::setPriority(Priority prio)
{
    priority = prio;
}

// METODI

std::string ToDo::toString() const
{
    std::stringstream ss;

    ss << (isDone ? "[X] " : "[ ] ");

    ss << title << " (Scadenza: " << deadline.formatDate() << ")";

    ss << " [Priorità: ";
    switch (priority)
    {
    case Priority::HIGH:
        ss << "ALTA";
        break;
    case Priority::NORMAL:
        ss << "MEDIA";
        break;
    case Priority::LOW:
        ss << "BASSA";
        break;
    }
    ss << "]";

    return ss.str();
}
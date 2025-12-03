#include "ToDo.h"
#include <sstream>

// Costruttore
// Nota: Rispetto al vecchio, qui gestiamo anche la "Priority" e usiamo i nuovi nomi
ToDo::ToDo(const std::string &text, const Date &date, Priority prio)
    : title(text), deadline(date), priority(prio), isDone(false)
{
    // isDone parte sempre false (da fare)
}

// --- GETTERS (Corrispondono ai nomi nuovi nel .h) ---

std::string ToDo::getTitle() const
{
    return title; // Nel vecchio era "description"
}

Date ToDo::getDeadline() const
{
    return deadline; // Nel vecchio era "dueDate"
}

bool ToDo::getStatus() const
{
    return isDone; // Nel vecchio era "completed"
}

Priority ToDo::getPriority() const
{
    return priority; // QUESTO È NUOVO
}

// --- SETTERS ---

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

// --- METODI ---

// Questo sostituisce il vecchio "getInfo", ma lo abbiamo chiamato "toString"
// ed è molto più ordinato nella formattazione.
std::string ToDo::toString() const
{
    std::stringstream ss;

    // Mettiamo una casellina [X] o [ ] invece di scrivere "COMPLETATO"
    ss << (isDone ? "[X] " : "[ ] ");

    ss << title << " (Scadenza: " << deadline.formatDate() << ")";

    // Aggiungiamo la priorità alla stringa
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
#ifndef TODOLIST_H
#define TODOLIST_H

#include "ToDo.h"
#include <vector>
#include <string>

class ToDoList
{
private:
    std::vector<ToDo> tasks;
    std::string name;

public:
    // Costruttore
    explicit ToDoList(std::string listName = "La mia Lista");

    // --- Gestione Attività ---

    void addTodo(const std::string &taskTitle, const Date &date, Priority prio = Priority::NORMAL);

    // Rimuovi: Restituisce true se ha funzionato, false se l'indice era sbagliato
    bool removeTodo(int index);

    // Cambia stato (Fatto/Non fatto)
    bool toggleStatus(int index);

    void sortTasks(); // Ordina per data

    // --- Visualizzazione e File ---
    void display() const;

    // Salvataggio
    void save(const std::string &filename) const;
    void load(const std::string &filename);

    // Utility
    bool isEmpty() const;
    int size() const;
};

#endif
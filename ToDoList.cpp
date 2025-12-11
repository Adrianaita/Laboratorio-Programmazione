#include "ToDoList.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// FUNZIONE DI AIUTO PER L'ORDINAMENTO
// Questa funzione serve a dire a std::sort come mettere in ordine due compiti.
// Restituisce true se 'a' viene prima di 'b' (cioè se la data di 'a' è minore).
bool confrontaScadenze(const ToDo &a, const ToDo &b)
{
    return a.getDeadline() < b.getDeadline();
}

// Costruttore
ToDoList::ToDoList(string listName) : name(listName)
{
}

// Aggiungi un nuovo compito
void ToDoList::addTodo(const string &taskTitle, const Date &date, Priority prio)
{
    ToDo newItem(taskTitle, date, prio);
    tasks.push_back(newItem);
    cout << "Aggiunto: " << taskTitle << endl;
}

// Rimuovi un compito
bool ToDoList::removeTodo(int index)
{
    // Controllo se l'indice esiste
    if (index < 1 || index > tasks.size())
    {
        cout << "Errore: indice non valido." << endl;
        return false;
    }

    tasks.erase(tasks.begin() + (index - 1));

    cout << "Compito rimosso con successo." << endl;
    return true;
}

// Cambia stato (Fatto <-> Da fare)
bool ToDoList::toggleStatus(int index)
{
    if (index < 1 || index > tasks.size())
    {
        return false;
    }

    bool statoAttuale = tasks[index - 1].getStatus();
    tasks[index - 1].setStatus(!statoAttuale);

    return true;
}

// ORDINAMENTO
void ToDoList::sortTasks()
{
    if (tasks.empty())
    {
        return;
    }

    sort(tasks.begin(), tasks.end(), confrontaScadenze);

    cout << "Lista riordinata per data!" << endl;
}

// Mostra tutto a video
void ToDoList::display() const
{
    cout << "\n--- " << name << " ---" << endl;

    if (tasks.empty())
    {
        cout << "Lista vuota." << endl;
    }
    else
    {
        for (size_t i = 0; i < tasks.size(); i++)
        {

            cout << (i + 1) << ". " << tasks[i].toString() << endl;
        }
    }
    cout << "-------------------" << endl;
}

// Salvataggio su file
void ToDoList::save(const string &filename) const
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cout << "Errore nel salvare il file." << endl;
        return;
    }

    // Prima riga: nome della lista
    file << name << endl;
    // Seconda riga: quanti compiti ci sono
    file << tasks.size() << endl;

    // Poi salvo tutti i dati di ogni compito
    for (size_t i = 0; i < tasks.size(); i++)
    {
        ToDo t = tasks[i];
        file << t.getTitle() << endl;
        file << t.getDeadline().getDay() << " "
             << t.getDeadline().getMonth() << " "
             << t.getDeadline().getYear() << endl;
        // Salvo la priorità e se è completato
        file << (int)t.getPriority() << " " << t.getStatus() << endl;
    }

    file.close();
    cout << "Salvataggio riuscito!" << endl;
}

// Caricamento da file
void ToDoList::load(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Nessun file trovato, parto da zero." << endl;
        return;
    }

    tasks.clear(); // Pulisco la lista corrente

    // Leggo il nome della lista
    getline(file, name);

    int numeroCompiti;
    file >> numeroCompiti;
    file.ignore();

    for (int i = 0; i < numeroCompiti; i++)
    {
        string titolo;
        int d, m, y, prioritaInt, fatto;

        getline(file, titolo);
        file >> d >> m >> y;
        file >> prioritaInt >> fatto;
        file.ignore();

        // Ricostruisco l'oggetto
        Date data(d, m, y);
        Priority p = (Priority)prioritaInt;

        ToDo t(titolo, data, p);
        t.setStatus((bool)fatto);

        tasks.push_back(t);
    }

    file.close();
    cout << "Caricamento completato." << endl;
}

// Funzioni utili

bool ToDoList::isEmpty() const
{
    return tasks.empty();
}

int ToDoList::size() const
{
    return tasks.size();
}
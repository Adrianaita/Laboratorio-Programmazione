#include <iostream>
#include <string>
#include <limits> // Serve per pulire l'input
#include "ToDoList.h"
#include "Date.h"

using namespace std;

// FUNZIONI DI UTILITÀ (HELPER)

// Pulisce il buffer di input
void pulisciInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Funzione sicura per leggere un numero intero
int leggiIntero()
{
    int numero;
    while (true)
    {
        cin >> numero;
        if (cin.fail())
        {
            cout << " >> Input non valido. Inserisci un numero: ";
            pulisciInput();
        }
        else
        {
            pulisciInput(); // Rimuove il "newline" rimasto nel buffer
            return numero;
        }
    }
}

// Funzione per leggere una data dall'utente
Date leggiData()
{
    int g, m, a;
    cout << "   Inserisci Giorno: ";
    cin >> g;
    cout << "   Inserisci Mese:   ";
    cin >> m;
    cout << "   Inserisci Anno:   ";
    cin >> a;
    pulisciInput(); // Pulizia finale

    return Date(g, m, a);
}

// Funzione per chiedere la priorità
Priority leggiPriorita()
{
    int p;
    cout << "   Priorita' (0=Bassa, 1=Media, 2=Alta): ";
    cin >> p;
    pulisciInput();

    switch (p)
    {
    case 0:
        return Priority::LOW;
    case 2:
        return Priority::HIGH;
    default:
        return Priority::NORMAL; // 1 o qualsiasi altro numero
    }
}

// Mostra il menu a video
void mostraMenu()
{
    cout << "\n========= MENÙ PRINCIPALE =========" << endl;
    cout << "1. Aggiunta Veloce (Default: Oggi, Media)" << endl;
    cout << "2. Aggiunta Avanzata (Data e Priorita')" << endl;
    cout << "3. Visualizza Elenco" << endl;
    cout << "4. Cambia Stato (Fatto <-> Da Fare)" << endl;
    cout << "5. Rimuovi Task" << endl;
    cout << "6. Ordina per Scadenza (Feature Nuova!)" << endl;
    cout << "7. Salva su file" << endl;
    cout << "8. Carica da file" << endl;
    cout << "0. Esci" << endl;
    cout << "=================================" << endl;
    cout << "Scegli un'opzione: ";
}

// MAIN

int main()
{
    cout << "********** Benvenuto nella ToDo List! **********" << endl;

    // Creazione della lista (chiama il costruttore di ToDoList)
    ToDoList miaLista("La mia lista personale");

    int scelta = -1;

    while (scelta != 0)
    {
        mostraMenu();
        scelta = leggiIntero();

        switch (scelta)
        {
        case 1:
        {
            // AGGIUNTA VELOCE
            string titolo;
            cout << "Inserisci titolo task: ";
            getline(cin, titolo);

            miaLista.addTodo(titolo, Date(), Priority::NORMAL);
            break;
        }

        case 2:
        {
            // AGGIUNTA AVANZATA
            string titolo;
            cout << "Inserisci titolo task: ";
            getline(cin, titolo);

            cout << "[Imposta Scadenza]" << endl;
            Date dataScadenza = leggiData();

            Priority priorita = leggiPriorita();

            miaLista.addTodo(titolo, dataScadenza, priorita);
            break;
        }

        case 3:
            // VISUALIZZA
            miaLista.display();
            break;

        case 4:
        {
            // CAMBIA STATO
            if (miaLista.isEmpty())
            {
                cout << "Lista vuota, nulla da modificare." << endl;
                break;
            }
            miaLista.display();
            cout << "Inserisci il numero del task da segnare come Fatto/Da Fare: ";
            int indice = leggiIntero();
            miaLista.toggleStatus(indice);
            break;
        }

        case 5:
        {
            // RIMUOVI
            if (miaLista.isEmpty())
            {
                cout << "Lista vuota, nulla da rimuovere." << endl;
                break;
            }
            miaLista.display();
            cout << "Inserisci il numero del task da eliminare: ";
            int indice = leggiIntero();
            miaLista.removeTodo(indice);
            break;
        }

        case 6:
            // ORDINA
            miaLista.sortTasks();
            break;

        case 7:
        {
            // SALVA
            string nomeFile;
            cout << "Nome file per salvataggio (es. dati.txt): ";
            getline(cin, nomeFile);
            miaLista.save(nomeFile);
            break;
        }

        case 8:
        {
            // CARICA
            string nomeFile;
            cout << "Nome file da caricare: ";
            getline(cin, nomeFile);
            miaLista.load(nomeFile);
            break;
        }

        case 0:
            cout << "\nUscita dal programma. A presto!" << endl;
            break;

        default:
            cout << "Opzione non valida, riprova." << endl;
        }
    }

    return 0;
}
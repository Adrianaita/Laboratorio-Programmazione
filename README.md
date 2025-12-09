# ToDo List C++11 – Registro Attività (A.A. 2025–2026)

Applicazione da linea di comando per la gestione di una ToDo List, sviluppata in C++11 con architettura modulare e orientata agli oggetti. Permette di organizzare, monitorare e salvare attività personali tramite un menu testuale intuitivo.

## Funzionalità principali

- **Gestione completa delle attività**: aggiunta, modifica, rimozione e completamento.
- **Data di scadenza**: possibilità di associare una scadenza con validazione automatica.
- **Visualizzazione personalizzata**: elenco completo o filtrato per attività da completare.
- **Ordinamento**: attività ordinate per data di scadenza.
- **Persistenza dei dati**: salvataggio e caricamento su file.
- **Validazione input**: controllo avanzato per evitare errori.

## Struttura del progetto

```
TodoList/
├── main.cpp             # Interfaccia utente
├── ToDoList.{h,cpp}     # Gestione lista attività
├── ToDo.{h,cpp}         # Singola attività
├── Date.{h,cpp}         # Gestione date
├── CMakeLists.txt       # Build system
├── README.md            # Documentazione
└── test/
    ├── test_date.cpp
    ├── test_todo.cpp
    └── test_todolist.cpp
```

> Nota: Le cartelle `build/` e `cmake-build-debug/` sono generate automaticamente e possono essere eliminate per una build pulita. Ho aggiunto un file `.gitignore` per escludere questi file temporanei:
>
> ```
> build/
> cmake-build-debug/
> .idea/
> *.exe
> *.o
> *.obj
> *.a
> *.log
> ```

## Compilazione ed esecuzione

1. Apri la cartella `TodoList` in CLion (o un altro IDE compatibile con CMake).
2. Assicurati di avere una toolchain GCC/Clang (Linux) o MinGW (Windows).
3. Compila e lancia il programma (`myToDoList`) oppure esegui i test (`todo_tests`).
4. Per eseguire i test da terminale:
   ```bash
   cd build
   ctest
   ```

## Menu dell'applicazione

Il programma offre un menu numerato con 8 opzioni principali:

1. **Aggiunta veloce**: crea un'attività con scadenza oggi e priorità media.
2. **Aggiunta avanzata**: consente di specificare data e priorità.
3. **Visualizza elenco attività**: mostra tutte le attività.
4. **Cambia stato**: segna un'attività come completata o da completare.
5. **Rimuovi attività**: elimina un'attività dall'elenco.
6. **Ordina per scadenza**: organizza le attività in base alla data.
7. **Salva su file**: salva l'elenco corrente su file.
8. **Carica da file**: carica un elenco di attività da file.

## Testing

Ho scritto test unitari utilizzando Google Test per verificare il corretto funzionamento di tutte le classi principali. Per eseguire i test:

```bash
cd TodoList
cd build
cmake ..
cmake --build .
ctest
```

Google Test viene scaricato automaticamente tramite CMake e integrato nel processo di build.

## Autore

**Adriana Giuffrida** – Matricola 7077208  
Corso di Laurea in Ingegneria Informatica  
Esame di Laboratorio di Programmazione (A.A. 2025–2026)

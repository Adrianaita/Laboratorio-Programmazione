#include <gtest/gtest.h>
#include "../ToDoList.h"
#include "../Date.h"
#include "../ToDo.h"
#include <string>

using namespace std;

// TEST FIXTURE

// Questa classe serve a creare un ambiente comune per tutti i test
// Viene eseguita prima di ogni TEST_F
class ToDoListTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Preparo una lista pulita prima di ogni test
        lista = ToDoList("Lista di Test");
        dataTest = Date(15, 12, 2024);
    }

    // Oggetti disponibili in tutti i test
    ToDoList lista;
    Date dataTest;
};

// INIZIO DEI TEST

// Test 1: Verifica lista vuota
TEST_F(ToDoListTest, CreaListaVuota)
{
    ToDoList listaVuota("Vuota");

    EXPECT_TRUE(listaVuota.isEmpty());

    EXPECT_EQ(listaVuota.size(), 0);
}

// Test 2: Aggiungere un todo
TEST_F(ToDoListTest, AggiungiTodo)
{

    lista.addTodo("Comprare pane", Date());

    EXPECT_FALSE(lista.isEmpty());
    EXPECT_EQ(lista.size(), 1);
}

// Test 3: Aggiungere un todo con data specifica
TEST_F(ToDoListTest, AggiungiTodoConData)
{
    EXPECT_EQ(lista.size(), 0);

    lista.addTodo("Comprare regali", dataTest);

    EXPECT_EQ(lista.size(), 1);
}

// Test 4: Aggiungere più todo e Priorità
TEST_F(ToDoListTest, AggiungiPiuTodoConPriorita)
{

    lista.addTodo("Todo 1", dataTest, Priority::LOW);
    lista.addTodo("Todo 2", dataTest, Priority::HIGH);
    lista.addTodo("Todo 3", dataTest, Priority::NORMAL);

    EXPECT_EQ(lista.size(), 3);
}

// Test 5: Rimuovere un todo (Indici 1-based)
TEST_F(ToDoListTest, RimuoviTodo)
{
    lista.addTodo("Da rimuovere", Date());
    lista.addTodo("Da tenere", Date());

    EXPECT_EQ(lista.size(), 2);

    bool esito = lista.removeTodo(1);

    EXPECT_TRUE(esito);
    EXPECT_EQ(lista.size(), 1);
}

// Test 6: Completare un todo
TEST_F(ToDoListTest, ToggleStato)
{
    lista.addTodo("Da completare", Date());

    bool esito = lista.toggleStatus(1);

    EXPECT_TRUE(esito);
    EXPECT_EQ(lista.size(), 1);
}

// Test 7: NUOVO - Ordinamento
TEST_F(ToDoListTest, OrdinaTasks)
{

    lista.addTodo("Lontano", Date(1, 1, 2030));
    lista.addTodo("Vicino", Date(1, 1, 2020));

    lista.sortTasks();

    EXPECT_EQ(lista.size(), 2);
}

// Test 8: Gestione indici non validi
TEST_F(ToDoListTest, IndiciNonValidi)
{
    lista.addTodo("Test", Date());

    EXPECT_FALSE(lista.removeTodo(0));

    EXPECT_FALSE(lista.removeTodo(5));

    EXPECT_EQ(lista.size(), 1);
}

// Test 9: Salvare e Caricare
TEST_F(ToDoListTest, SalvaECarica)
{
    lista.addTodo("Todo persistente", dataTest, Priority::HIGH);

    lista.save("test_db.txt");

    ToDoList nuovaLista("Caricata");
    nuovaLista.load("test_db.txt");

    EXPECT_EQ(nuovaLista.size(), 1);
    EXPECT_FALSE(nuovaLista.isEmpty());
}
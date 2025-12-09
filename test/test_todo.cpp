#include <gtest/gtest.h>
#include "../ToDo.h"
#include "../Date.h"
#include <string>

using namespace std;

// Test 1: Creare un todo completo (Verifica costruttore e getter base)
TEST(ToDoTest, CreaTodoCompleto)
{
    Date data(25, 12, 2024);

    ToDo todo("Comprare regali", data, Priority::HIGH);

    EXPECT_EQ(todo.getTitle(), "Comprare regali");
    EXPECT_FALSE(todo.getStatus());
    EXPECT_EQ(todo.getPriority(), Priority::HIGH);

    Date dataSalvata = todo.getDeadline();
    EXPECT_TRUE(dataSalvata == data);
}

// Test 2: Cambiare il titolo
TEST(ToDoTest, CambiaTitolo)
{
    ToDo todo("Vecchio nome", Date(), Priority::NORMAL);

    todo.setTitle("Nuovo compito");

    EXPECT_EQ(todo.getTitle(), "Nuovo compito");
}

// Test 3: Cambiare lo stato (Fatto / Da fare)
TEST(ToDoTest, CambiaStato)
{
    ToDo todo("Test", Date(), Priority::NORMAL);

    EXPECT_FALSE(todo.getStatus());

    todo.setStatus(true);
    EXPECT_TRUE(todo.getStatus());

    todo.setStatus(false);
    EXPECT_FALSE(todo.getStatus());
}

// Test 4: Cambiare la data di scadenza
TEST(ToDoTest, CambiaData)
{
    ToDo todo("Test", Date(1, 1, 2024), Priority::NORMAL);
    Date nuovaData(1, 1, 2025);

    todo.setDeadline(nuovaData);

    Date dataCorrente = todo.getDeadline();
    EXPECT_TRUE(dataCorrente == nuovaData);
}

// Test 5: Test specifico per la Priorità
TEST(ToDoTest, CambiaPriorita)
{

    ToDo todo("Test Priority", Date(), Priority::LOW);
    EXPECT_EQ(todo.getPriority(), Priority::LOW);

    todo.setPriority(Priority::HIGH);
    EXPECT_EQ(todo.getPriority(), Priority::HIGH);
}

// Test 6: Ottenere le informazioni (toString)
TEST(ToDoTest, OttieniInfoStringa)
{
    Date data(25, 12, 2024);
    ToDo todo("Comprare regali", data, Priority::NORMAL);

    string info = todo.toString();

    EXPECT_FALSE(info.empty());

    EXPECT_NE(info.find("Comprare regali"), string::npos);

    EXPECT_NE(info.find("MEDIA"), string::npos);
}
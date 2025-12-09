#include <gtest/gtest.h>
#include "../Date.h"

// Test 1: Creare una data di default (Verifico che non sia 0/0/0 ma una data valida)
TEST(DateTest, CreaDataDefault)
{
    Date data;
    // Nel mio Date.cpp ho messo 1/1/2024 come default
    EXPECT_EQ(data.getDay(), 1);
    EXPECT_EQ(data.getMonth(), 1);
    EXPECT_EQ(data.getYear(), 2024);
}

// Test 2: Creare una data con valori specifici
TEST(DateTest, CreaDataConValori)
{
    Date data(15, 6, 2024);
    EXPECT_EQ(data.getDay(), 15);
    EXPECT_EQ(data.getMonth(), 6);
    EXPECT_EQ(data.getYear(), 2024);
}

// Test 3: Gestione data non valida (Il costruttore deve correggerla)
TEST(DateTest, CorrezioneDataInvalida)
{

    Date dataSbagliata(32, 13, 1999);

    EXPECT_TRUE(dataSbagliata.isValid());
    EXPECT_EQ(dataSbagliata.getDay(), 1);
}

// Test 4: Confrontare due date (Uguaglianza)
TEST(DateTest, ConfrontaUguaglianza)
{
    Date data1(15, 6, 2024);
    Date data2(15, 6, 2024);
    Date data3(16, 6, 2024);

    EXPECT_TRUE(data1 == data2);
    EXPECT_FALSE(data1 == data3);
}

// Test 5: Test per l'ordinamento (Operatore <)

TEST(DateTest, OperatoreMinore)
{
    Date dataPrima(1, 1, 2023);
    Date dataDopo(1, 1, 2024);

    EXPECT_TRUE(dataPrima < dataDopo);

    EXPECT_FALSE(dataDopo < dataPrima);
}

// Test 6: Convertire data in stringa (formatDate)
TEST(DateTest, DataInStringa)
{
    Date data(5, 3, 2024);
    std::string risultato = data.formatDate();

    // Mi aspetto che il formato sia con lo 0 davanti
    EXPECT_EQ(risultato, "05/03/2024");
}

// Test 7: Cambiare i valori della data (setDate)
TEST(DateTest, CambiaValori)
{
    Date data;

    data.setDate(10, 5, 2023);

    EXPECT_EQ(data.getDay(), 10);
    EXPECT_EQ(data.getMonth(), 5);
    EXPECT_EQ(data.getYear(), 2023);
}
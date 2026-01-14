package atm;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class TestBankDatabase {

    private BankDatabase bankDatabase;

    @BeforeEach
    void setUp() {
        // Il costruttore di BankDatabase crea automaticamente due account fissi:
        // 1) 12345 (PIN 54321)
        // 2) 98765 (PIN 56789)
        bankDatabase = new BankDatabase();
    }

    @Test
    void testAuthenticateUser() {
        // Utente esistente e PIN corretto
        assertTrue(bankDatabase.authenticateUser(12345, 54321));
        
        // Utente esistente ma PIN errato
        assertFalse(bankDatabase.authenticateUser(12345, 99999));
        
        // Utente inesistente
        assertFalse(bankDatabase.authenticateUser(11111, 54321));
    }

    @Test
    void testGetBalances() {
        // Verifichiamo i saldi dell'utente 12345
        assertEquals(1000.0, bankDatabase.getAvailableBalance(12345).getValue(), 0.001);
        assertEquals(1200.0, bankDatabase.getTotalBalance(12345).getValue(), 0.001);
    }

    @Test
    void testCredit() {
        // Aggiungiamo 500 Euro all'utente 12345
        bankDatabase.credit(12345, new Euro(500.0));

        // Il totale deve salire a 1200 + 500 = 1700
        assertEquals(1700.0, bankDatabase.getTotalBalance(12345).getValue(), 0.001);
    }

    @Test
    void testDebit() {
        // Preleviamo 100 Euro dall'utente 98765 (che ha 200/200)
        bankDatabase.debit(98765, new Euro(100.0));

        // Disponibile: 200 - 100 = 100
        assertEquals(100.0, bankDatabase.getAvailableBalance(98765).getValue(), 0.001);
        
        // Totale: 200 - 100 = 100
        assertEquals(100.0, bankDatabase.getTotalBalance(98765).getValue(), 0.001);
    }
}
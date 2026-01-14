package atm;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class TestAccount {

    private Account account;

    @BeforeEach
    void setUp() {
        account = new Account(12345, 54321, new Euro(1000.0), new Euro(1200.0));
    }

    @Test
    void testValidatePIN() {
        // Il PIN corretto deve restituire true
        assertTrue(account.validatePIN(54321));
        // Un PIN errato deve restituire false
        assertFalse(account.validatePIN(00000));
    }

    @Test
    void testGetAvailableBalance() {
        // Verifichiamo che il saldo disponibile sia 1000.0
        assertEquals(1000.0, account.getAvailableBalance().getValue(), 0.001);
    }

    @Test
    void testGetTotalBalance() {
        // Verifichiamo che il saldo totale sia 1200.0
        assertEquals(1200.0, account.getTotalBalance().getValue(), 0.001);
    }

    @Test
    void testCredit() {
        // Deposito di 200 Euro
        // Il deposito aumenta il saldo TOTALE, ma non subito quello disponibile (simulazione assegni/busta)
        account.credit(new Euro(200.0));

        // Il saldo totale deve passare da 1200 a 1400
        assertEquals(1400.0, account.getTotalBalance().getValue(), 0.001);
        
        // Il saldo disponibile deve rimanere invariato (1000)
        assertEquals(1000.0, account.getAvailableBalance().getValue(), 0.001);
    }

    @Test
    void testDebit() {
        // Prelievo di 200 Euro
        // Il prelievo diminuisce SIA il saldo disponibile CHE quello totale
        account.debit(new Euro(200.0));

        // Disponibile: 1000 - 200 = 800
        assertEquals(800.0, account.getAvailableBalance().getValue(), 0.001);
        
        // Totale: 1200 - 200 = 1000
        assertEquals(1000.0, account.getTotalBalance().getValue(), 0.001);
    }
}
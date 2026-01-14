package atm;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse; // aggiunto da noi
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


class TestEuro {

    private Euro euro1;
    private Euro euro2;

    @BeforeEach
    public void setUp() {
        euro1 = new Euro(530.5);
        euro2 = new Euro(100);
    }

    @Test
    void testSum() {
        // eseguiamo la somma: euro1 = euro1 + euro2
        euro1.sum(euro2);

        assertEquals(630.5, euro1.getValue(), 0.001); // 0.001 è la tolleranza per i numeri double
    }

    @Test
    void testDifference() {
        // eseguiamo la differenza: euro1 = euro1 - euro2
        euro1.subtract(euro2);

        assertEquals(430.5, euro1.getValue(), 0.001);
    }

    @Test
    void testEqualTo() {
        Euro stessoValore = new Euro(530.5);

        // deve essere True
        assertTrue(euro1.equalTo(stessoValore));

        // deve essere false
        assertFalse(euro1.equalTo(euro2));
    }

    @Test
    void testlessThan() {
        // deve essere false
        assertFalse(euro1.lessThan(euro2));

        // deve essere true
        assertTrue(euro2.lessThan(euro1));
    }

    @Test
    void testPrint() {
        assertEquals("530.5 euro", euro1.print());
    }
   
}

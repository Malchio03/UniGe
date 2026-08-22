public class Cioccolatini {
    public static void main(String[] args) {
        Scatola scatola = new Scatola();

        // Avvio pasticciere
        new Thread(new Pasticciere(scatola)).start();

        // Avvio 3 mangiatori
        for (int i = 1; i <= 3; i++) {
            new Thread(new Mangiatore(scatola, i)).start();
        }
    }
}

class Scatola {
    int quantita = 0;
    final int P = 5;
}

class Pasticciere implements Runnable {
    private Scatola scatola;

    public Pasticciere(Scatola scatola) {
        this.scatola = scatola;
    }

    @Override
    public void run() {
        try {
            while (true) {
                // Acquisizione del lock sulla scatola
                synchronized (scatola) {
                    while (scatola.quantita > 0) {
                        scatola.wait(); 
                    }
                    scatola.quantita = scatola.P;
                    System.out.println("Pasticciere ha riempito con " + scatola.P + " cioccolatini.");
                    
                    scatola.notifyAll(); // Sveglia i mangiatori
                }
                Thread.sleep(2000);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Mangiatore implements Runnable {
    private Scatola scatola;
    private int id;

    public Mangiatore(Scatola scatola, int id) {
        this.scatola = scatola;
        this.id = id;
    }

    @Override
    public void run() {
        try {
            while (true) {
                // Acquisizione del lock sulla scatola
                synchronized (scatola) {
                    // Aspetta se la scatola è vuota
                    while (scatola.quantita == 0) {
                        scatola.wait(); 
                    }
                    
                    scatola.quantita--;
                    System.out.println("Mangiatore " + id + " ha preso 1 cioccolatino. Rimasti: " + scatola.quantita);
                    
                    // Se ha svuotato la scatola, sveglia il pasticciere
                    if (scatola.quantita == 0) {
                        System.out.println("Scatola vuota!");
                        scatola.notifyAll(); 
                    }
                }
                Thread.sleep(800); 
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
import java.util.concurrent.Semaphore;

public class Piscina2 {
    public static void main(String[] args) {
        int nSpogliatoi = 4; // N_S
        int nArmadietti = 3; // N_C
        int nClienti = 9;

        Semaphore spogliatoi = new Semaphore(nSpogliatoi);
        Semaphore armadietti = new Semaphore(nArmadietti);

        for (int i = 1; i <= nClienti; i++) {
            new Thread(new Cliente(i, spogliatoi, armadietti)).start();
        }
    }
}

class Cliente implements Runnable {
    private int id;
    private Semaphore spogliatoi;
    private Semaphore armadietti;

    public Cliente(int id, Semaphore spogliatoi, Semaphore armadietti) {
        this.id = id;
        this.spogliatoi = spogliatoi;
        this.armadietti = armadietti;
    }

    @Override
    public void run() {
        try {
            armadietti.acquire(); 
            spogliatoi.acquire(); 
            System.out.println("Cliente " + id + " è nello spogliatoio.");
               
            // (c, d, e) Si cambia e mette vestiti nell'armadietto
            System.out.println("Cliente " + id + " si è cambiato e occupa l'armadietto.");
            spogliatoi.release(); // (f) Libera e ridà chiave spogliatoio

            System.out.println("Cliente " + id + " nuota."); // (g) Nuota
            Thread.sleep(1000); // Simula il tempo della nuotata

            spogliatoi.acquire(); // (h) Prende spogliatoio per uscire
            
            // (i, j) Recupera vestiti e si riveste
            System.out.println("Cliente " + id + " si riveste.");
            
            spogliatoi.release(); // (k, l) Libera spogliatoio
            armadietti.release(); // (l) Libera armadietto
            System.out.println("Cliente " + id + " esce dalla piscina.");

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
public class Main {
    public static void main(String[] args)
    {
        RWbasic rw = new RWbasic();
        int n = 50;

        Thread[] readers = new Thread[n];
        Thread[] writers = new Thread[n];

        for(int i = 0; i < n; ++i){
            readers[i] = new Thread(new Reader(rw), "Reader " + i);
            writers[i] = new Thread(new Writer(rw), "Writer " + i);
            
            readers[i].start(); // corrisponde a pthread create in C
            writers[i].start();
        }

        try {
            // join dei thread
            for(int i = 0; i < n; ++i) 
            {
                readers[i].join();
                writers[i].join();
            }
        } catch(Exception e) {
            System.out.println(e);
            e.printStackTrace();
        }
        // risultato finale
        System.out.println("\n--- RISULTATO FINALE ---");
        System.out.println("Scrittori totali lanciati: " + n);
        System.out.println("Valore finale di data: " + rw.read());
    }
}
package Esercizio2;

public class Writer implements Runnable {
    private RWexclusive rw; // Modificato tipo
    
    public Writer(RWexclusive rw) { // Modificato parametro
        this.rw = rw;
    }

    @Override
    public void run() {
        this.rw.write();
        System.out.println(Thread.currentThread().getName() + " ha scritto!");
    }
}
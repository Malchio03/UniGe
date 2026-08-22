package Esercizio3;

public class Writer implements Runnable {
    private RW rw; // Modificato tipo
    
    public Writer(RW rw) { // Modificato parametro
        this.rw = rw;
    }

    @Override
    public void run() {
        this.rw.write();
        System.out.println(Thread.currentThread().getName() + " ha scritto!");
    }
}
package Esercizio4;

public class Writer implements Runnable {
    private RWext rw; // Modificato tipo
    
    public Writer(RWext rw) { // Modificato parametro
        this.rw = rw;
    }

    @Override
    public void run() {
        this.rw.write();
        System.out.println(Thread.currentThread().getName() + " ha scritto!");
    }
}
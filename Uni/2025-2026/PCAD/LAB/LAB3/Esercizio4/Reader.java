package Esercizio4;

public class Reader implements Runnable {
    private RWext rw;
    
    public Reader(RWext rw){ 
        this.rw = rw;
    }
    
    @Override
    public void run() {
       String nome = Thread.currentThread().getName();
       System.out.println(nome + " ha letto: " + this.rw.read());
    }
}
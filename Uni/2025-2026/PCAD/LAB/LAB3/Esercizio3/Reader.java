package Esercizio3;

public class Reader implements Runnable {
    private RW rw;
    
    public Reader(RW rw){ 
        this.rw = rw;
    }
    
    @Override
    public void run() {
       String nome = Thread.currentThread().getName();
       System.out.println(nome + " ha letto: " + this.rw.read());
    }
}
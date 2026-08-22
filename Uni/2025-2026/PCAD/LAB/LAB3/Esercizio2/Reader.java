package Esercizio2;

public class Reader implements Runnable {
    private RWexclusive rw;
    
    public Reader(RWexclusive rw){ 
        this.rw = rw;
    }
    
    @Override
    public void run() {
       String nome = Thread.currentThread().getName();
       System.out.println(nome + " ha letto: " + this.rw.read());
    }
}
package Esercizio2;

public class RWexclusive extends RWbasic 
{
    public RWexclusive(){
        super();
    }
    @Override
    public synchronized int read() {
        return super.read();
    }

    @Override
    public synchronized void write() {
        super.write();
    }
}

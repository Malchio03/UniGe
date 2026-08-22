public class Reader implements Runnable
{
    private RWbasic rw;
    public Reader(RWbasic rw){
        this.rw = rw;
    }
    @Override
    public void run()
    {
       String nome = Thread.currentThread().getName();
       System.out.println(nome + " ha letto: " + this.rw.read());
    }
}
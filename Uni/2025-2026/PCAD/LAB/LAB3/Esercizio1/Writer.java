public class Writer implements Runnable
{
    private RWbasic rw;
    public Writer(RWbasic rw) {
        this.rw = rw;
    }

    @Override
    public void run()
    {
        String nome = Thread.currentThread().getName();
        this.rw.write();
        System.out.println(nome + " ha scritto!");
    }
}
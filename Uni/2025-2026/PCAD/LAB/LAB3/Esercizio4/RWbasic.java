package Esercizio4;

public class RWbasic
{
    private int data;

    public RWbasic()
    {
        this.data = 0;
    }

    public int read()
    {
        return this.data;
    }

    public void write()
    {
        try {

            int tmp = this.data;
            Thread.sleep(100);
            ++tmp;
            this.data = tmp;
        } catch (InterruptedException e) {
            System.err.println("Thread interrotto!");
        }
    }
}

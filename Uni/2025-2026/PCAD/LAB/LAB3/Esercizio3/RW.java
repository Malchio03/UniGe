package Esercizio3;

public class RW extends RWbasic {

    private int readersCount = 0; //  contatore che conta i lettori 
    private boolean isWriting = false;

    public RW() {
        super();
    }

    private synchronized void startRead() {
        try {
            while (isWriting) {
                wait(); 
            }
            readersCount++;
        } catch (InterruptedException e) {
            System.out.println(e);
            e.printStackTrace();
        }
    }

    private synchronized void endRead() {
        readersCount--;
        
        if (readersCount == 0) {
            notifyAll(); 
        }
    }

    @Override
    public int read() {
        startRead();
        int result = super.read(); 
        endRead();
        
        return result;
    }

    private synchronized void startWrite() {
        try {
            while (isWriting || readersCount > 0) {
                wait();
            }
            isWriting = true;
        } catch (InterruptedException e) {
            System.out.println(e);
            e.printStackTrace();
        }
    }

    private synchronized void endWrite() {
        isWriting = false;
        notifyAll();
    }

    @Override
    public void write() {
        startWrite();
        super.write(); 
        endWrite();
    }
}
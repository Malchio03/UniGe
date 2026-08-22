package Esercizio4;

public class RWext extends RWbasic {
    private int readersCount = 0;
    private boolean isWriting = false;
    private boolean hasBeenRead = true; 

    private synchronized void startRead() {
        try {
            while (isWriting || hasBeenRead) { 
                wait(); 
            }
            readersCount++;
        } catch (InterruptedException e) { e.printStackTrace(); }
    }

    private synchronized void endRead() {
        readersCount--;
        if (readersCount == 0) {
            hasBeenRead = true; 
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

    // metodo extra per il Main
    public synchronized int readFinal() {
        return super.read();
    }

    private synchronized void startWrite() {
        try {
            while (isWriting || readersCount > 0 || !hasBeenRead) {
                wait();
            }
            isWriting = true;
        } catch (InterruptedException e) { e.printStackTrace(); }
    }

    private synchronized void endWrite() {
        isWriting = false;
        hasBeenRead = false; 
        notifyAll();
    }

    @Override
    public void write() {
        startWrite();
        super.write();
        endWrite();
    }
}
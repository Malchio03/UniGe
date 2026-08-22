import java.util.LinkedList;

public class SharedFIFO {
    private final LinkedList<String> fifo = new LinkedList<>();
    private final int limit;

    public SharedFIFO(int limit) {
        this.limit = limit; 
    }

    public synchronized void insert(String item) throws InterruptedException {
        // Se la struttura è piena, il produttore attende
        while (fifo.size() == limit) {
            wait();
        }
        fifo.addLast(item);
        notifyAll(); // Sveglia i consumatori in attesa
    }

    public synchronized String extract() throws InterruptedException {
        // Se la struttura è vuota, il consumatore attende
        while (fifo.isEmpty()) {
            wait();
        }
        String item = fifo.removeFirst();
        notifyAll(); 
        return item;
    }
}
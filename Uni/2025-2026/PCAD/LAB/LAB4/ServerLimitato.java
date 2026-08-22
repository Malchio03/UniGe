import java.net.ServerSocket;
import java.net.Socket;

public class ServerLimitato {
    public static void main(String[] args) {
        try {
            SharedFIFO fifo = new SharedFIFO(5);
            ServerSocket server = new ServerSocket(4242);
            System.out.println("Server Limitato in ascolto sulla porta 4242...");
            
            while (true) {
                Socket socket = server.accept();
                new Thread(new ClientHandler(socket, fifo)).start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
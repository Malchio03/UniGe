import java.net.ServerSocket;
import java.net.Socket;

public class ServerIllimitato {
    public static void main(String[] args) {
        try {
            SharedFIFO fifo = new SharedFIFO(Integer.MAX_VALUE);
            ServerSocket server = new ServerSocket(4243); 
            System.out.println("Server Illimitato in ascolto sulla porta 4243...");
            
            while (true) {
                Socket socket = server.accept();
                new Thread(new ClientHandler(socket, fifo)).start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
import java.io.*;
import java.net.Socket;

public class ClientHandler implements Runnable {
    private Socket socket; 
    private SharedFIFO fifo;

    public ClientHandler(Socket s, SharedFIFO f) { 
        this.socket = s; 
        this.fifo = f; 
    }

    public void run() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
            
            String type = br.readLine();
            
            if ("producer".equals(type)) {
                pw.println("okprod");
                String data = br.readLine();
                fifo.insert(data);
                pw.println("okins");
            } else if ("consumer".equals(type)) {
                pw.println("okcons");
                String data = fifo.extract();
                pw.println(data);
            }
            
            br.close(); 
            pw.close(); 
            socket.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
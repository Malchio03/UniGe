import java.io.*;
import java.net.Socket;

public class ConsumerClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 4242);
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
            
            pw.println("consumer");
            
            if ("okcons".equals(br.readLine())) {
                String dato = br.readLine();
                System.out.println("Dato consumato: " + dato);
            }
            
            pw.close(); 
            br.close(); 
            socket.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
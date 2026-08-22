import java.io.*;
import java.net.Socket;

public class ProducerClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 4242);
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
            
            pw.println("producer");
            
            if ("okprod".equals(br.readLine())) {
                pw.println("StringaDiTestSenzaAcapo");
                String risposta = br.readLine();
                System.out.println("Conferma dal server: " + risposta); 
            }
            
            pw.close(); 
            br.close(); 
            socket.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
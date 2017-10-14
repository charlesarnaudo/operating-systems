import java.net.*;
import java.io.*;

public class Main {

    String[] haikus = {
            "",
            "",
            "",

    }

    public static void main(String[] args) {
        Socket sock  = null;
        try {
            ServerSocket client = new ServerSocket(5575);
            while (true) {
                client = sock.accept();
            }
        } catch (IOException e) {
            System.err.println(e);
        }
    }
}

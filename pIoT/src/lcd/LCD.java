package lcd;
import java.io.IOException;
import javax.swing.JOptionPane;
/**
 *
 * @author adria
 */
public class LCD {
    public static void main(String[] args) throws IOException {
        //String codigo = JOptionPane.showInputDialog("Código 128");
        //JOptionPane.showMessageDialog(null, codigo);
        ConexionArduino ca = new ConexionArduino();
        ca.conexion("com3", 9600);
        ca.busDatos();
        String msg = JOptionPane.showInputDialog("Mensage: ");
        ca.enviarDatos(msg);
        
    }
}

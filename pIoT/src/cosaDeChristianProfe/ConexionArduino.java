/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cosaDeChristianProfe;

import lcd.*;
import com.fazecast.jSerialComm.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author adria
 */
public class ConexionArduino {

    InputStream entrada = null;
    OutputStream salida = null;
    SerialPort puertoSerial;
    boolean trans = false;

    public void conexion(String puerto, int vel) throws IOException {
        puertoSerial = SerialPort.getCommPort(puerto);
        puertoSerial.setBaudRate(9600);
        puertoSerial.setNumDataBits(8);
        puertoSerial.setNumStopBits(1);
        puertoSerial.setParity(1);
        puertoSerial.openPort();
        System.out.println("Puerto conectado");
        busDatos();
    }

    public void cerrarConexion() {
        puertoSerial.closePort();
        System.out.println("Puerto desconectado");
    }

    public void busDatos() {
        salida = puertoSerial.getOutputStream();
        entrada = puertoSerial.getInputStream();
    }

    public void enviarDatos(String d) throws IOException {
        salida.write(d.getBytes());
        salida.flush();
    }

    public String recibirDatos() throws IOException {
        busDatos();
        String datos = "j";
        while (entrada.available() > 0) {
            char car = (char) entrada.read();
            datos += car;
        }
        return datos;
    }
}

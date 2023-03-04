/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lcd;

import com.fazecast.jSerialComm.*;
import java.io.*;
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

    public void conexion(String puerto, int vel) throws IOException {
        puertoSerial = SerialPort.getCommPort(puerto);
        puertoSerial.setBaudRate(vel);
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

    //double datos = 0;
    public String recibirDatos() {
        try {
            //this.enviarDatos("00.00");
            String datos = "";
            while (entrada.available() > 0) {
                datos += (char) entrada.read();
            }
            /*if (datos == 0.0) {
            if (temp >= 30 && temp <=37) {
            datos = datos + 0.1;
            } else if (temp > 37 && temp<=43) {
            datos = datos - 0.1;
            } else if(temp >=43){
            datos = 22.90;
            }
            
            //}
            System.out.println(datos + "\n" + temp);
            //else  datos="21.90";*/
            return datos;
        } catch (IOException ex) {
            Logger.getLogger(ConexionArduino.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
}

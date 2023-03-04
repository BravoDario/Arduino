/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package proyecto_dsm_piot;

import java.sql.*;

/**
 *
 * @author adria
 */
public class ConexionMySQL {

    Connection conn;

    //url (localizador de recursos uniforme)
    //TCP-IPs
    public Connection open(String user, String password,String url) {
        /*String user = "root";
        String password = "root";
        String url
                = "jdbc:mysql://127.0.0.1:3306/optiqalumnos?"
                +//protocolo:subprotocolo//servidor:puerto/subnombre o base de datos?Parametro
                "useSSL=false&"
                +//no se usan...
                "allowPublicKeyRetrieval=true&"
                + "useUnicode=true&"
                + "characterEncoding=utf-8";*/
        try {
            //registrar chofer
            Class.forName("com.mysql.cj.jdbc.Driver");//cargador de clase
            conn = DriverManager.getConnection(url, user, password);//Instanciando la clase que implementa el interfaz Driver
            //-ligne de code |v| Definir la propiedad jdbc.drivers
            //jdbc.drivers = gjt.mm.mysql.Driver:oracle.jdbc.driver.OracleDriver;
            System.out.println("Conectado");
            return conn;
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void close() {
        if (conn != null) {
            try {
                conn.close();
                System.out.println("Cerrado");
            } catch (Exception e) {
                e.printStackTrace();
                System.out.println("Exception controlada...");
            }
        }
    }
}

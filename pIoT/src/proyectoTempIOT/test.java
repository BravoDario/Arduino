/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package proyectoTempIOT;

import DWEET.ControllerDWEET;
import com.fazecast.jSerialComm.*;
import java.io.*;
import lcd.ConexionArduino;
import DWEET.DweetIO;
import DWEET.Dweet;
import com.google.gson.JsonObject;
import lcd.ConexionArduino;

/**
 *
 * @author adria
 */
public class test extends Thread{

    static int cont=0;
    public static void main(String[] args) throws IOException, InterruptedException{
        String datos = "";
        double dbdata;
        ControllerDWEET cd = new ControllerDWEET();
        while(true){
            ConexionArduino ca = new ConexionArduino();
            ca.conexion("COM10", 9600);
            //cd.enviarNube(String.valueOf(datos), "temperaturasF");
            //ca.enviarDatos("00.00");
            System.out.println(ca.recibirDatos());
            ca.cerrarConexion();
            System.out.println("-----");
            Thread.sleep(1000);
        }
    }
}
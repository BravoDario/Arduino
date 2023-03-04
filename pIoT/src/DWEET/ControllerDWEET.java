/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package DWEET;

import com.google.gson.JsonObject;
import java.io.IOException;

/**
 *
 * @author adria
 */
public class ControllerDWEET {
    public void enviarNube(String info, String lugar) throws IOException {
        String thingName = "darad";
        JsonObject json = new JsonObject();
        json.addProperty(lugar, info);
        DweetIO.publish(thingName, json);
        System.out.println("Enviado");
        System.out.println(json);
    }
}

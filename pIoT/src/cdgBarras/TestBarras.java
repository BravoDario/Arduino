/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cdgBarras;

import java.io.IOException;
import javax.swing.JOptionPane;

/**
 *
 * @author adria
 */
public class TestBarras {
    public static void main(String[] args) throws IOException {
        codigoBarras miB = new codigoBarras();
        String var = "221974803";
        miB.crear128(var);
        miB.crear39(var);
        JOptionPane.showInputDialog(miB);
    }
}

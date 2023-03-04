/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cdgBarras;
import net.sourceforge.jbarcodebean.JBarcodeBean;
import net.sourceforge.jbarcodebean.model.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.*;
/**
 *
 * @author adria
 */
public class codigoBarras {
    JBarcodeBean cb = new JBarcodeBean();
    
    public void crear128(String C) throws IOException{
        cb.setCodeType(new Code128());
        cb.setCode(C);
        BufferedImage bi = cb.draw(new BufferedImage(200, 100, BufferedImage.TYPE_INT_RGB));
        File f = new File("./src/cdgBarras/182_"+C+".png");
        ImageIO.write(bi, "jpg", f);
    }
    
    public void crear39(String C) throws IOException{
        cb.setCodeType(new Code39());
        cb.setCode(C);
        BufferedImage bi = cb.draw(new BufferedImage(200, 100, BufferedImage.TYPE_INT_RGB));
        File f = new File("./src/cdgBarras/39_"+C+".png");
        ImageIO.write(bi, "jpg", f);
    }
}
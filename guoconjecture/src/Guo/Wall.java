package Guo;
import java.awt.Graphics2D;
import java.awt.Rectangle;
class Wall {
    public Rectangle r;
    public int xpos, ypos, width, height;
    public Wall(int x, int y, int w, int h){
        xpos = x;
        ypos = y;
        width = w;
        height = h;
        r = new Rectangle(xpos, ypos, width, height);
    }
    public int getX(){
        return xpos;
    }
    public int getY(){
        return ypos;
    }
    public int getW(){
        return width;
    }
    public int getH(){
        return height;
    }
    public void paint(Graphics2D g2){
        g2.fill(r);
    }
}
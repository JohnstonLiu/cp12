package Guo;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;

class Ball {
    public void move(){
        r.setFrame(xpos, ypos, width, height);
        xpos = xpos + speed * xdir;
        ypos = ypos + speed * ydir;
    }
    public void changeXdir(int x){
        xdir = x;
    }
    public void stop(){
        r.setFrame(xpos, ypos, width, height);
        speed=0;
    }

    public void changeYdir(int y){
        ydir = y;
    }

    public boolean intersects(int x, int y, int w, int h){
        return r.intersects(x, y, w, h);
    }


    public Ellipse2D.Double r;
    public int xpos, ypos, width, height, speed, xdir, ydir;

    public Ball(int x, int y, int w, int h){

        xpos = x;
        ypos = y;
        width = w;
        height = h;
        speed = 10;
        xdir = 1;
        ydir = -1;


        r = new Ellipse2D.Double(xpos, ypos, width, height);
    }


    public void paint(Graphics2D g2){

        g2.fill(r);
    }
}
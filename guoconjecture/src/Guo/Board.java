package Guo;
import java.awt.Graphics;
import javax.swing.*;
import javax.swing.Timer;
import java.awt.geom.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionListener;
import java.util.*;
import java.awt.event.KeyListener;
import java.util.Random;

class Board extends JPanel{
    int x; int y;
    Wall topWall;
    Wall leftWall;
    Wall rightWall;
    Wall bottomWall;
    Ball ball;
    int score1;
    int score2;
    int count1;
    Timer t;
    public Board(int a, int b, JDialog frame) {
        x=a;
        y=b;
         topWall = new Wall(0, 0, x, 1);
         leftWall = new Wall (0,0,1,y);
         rightWall = new Wall (x,0,1,y);
         bottomWall = new Wall (0,y,x,1);
         ball = new Ball(0,y,10, 10);
        setFocusable(true);
        ActionListener s = new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                ball.move();
                //more game code will go here
                if (ball.intersects(topWall.getX(), topWall.getY(), topWall.getW(), topWall.getH())) {
                    ball.changeYdir(1);
                }
                if (ball.intersects(bottomWall.getX(), bottomWall.getY(), bottomWall.getW(), bottomWall.getH())) {
                    ball.changeYdir(-1);
                }
                if (ball.intersects(leftWall.getX(), leftWall.getY(), leftWall.getW(), leftWall.getH())) {
                    ball.changeXdir(1);
                }
                if (ball.intersects(rightWall.getX(), rightWall.getY(), rightWall.getW(), rightWall.getH())) {
                    ball.changeXdir(-1);
                }
                if(ball.intersects(0,0,1,1)){
                    ball.stop();
                    System.out.println("Top left: "+a+", "+b);
                    frame.dispose();
                }
                if(ball.intersects(0,y,1,1)){
                    ball.stop();
                    System.out.println("Bottom left: "+a+", "+b);
                    frame.dispose();

                }
                if(ball.intersects(x,0,1,1)){
                    ball.stop();
                    System.out.println("Top right: "+a+", "+b);
                    frame.dispose();

                }
                if(ball.intersects(x,y,1,1)){
                    ball.stop();
                    System.out.println("Bottom right: "+a+", "+b);
                    frame.dispose();
                }
                repaint();
            }
        };
        t = new Timer(10, s);
        t.start();
    }


    public void paint(Graphics g) {
        super.paint(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setColor(Color.BLACK);
        g2.setColor(Color.BLACK);
        topWall.paint(g2);
        leftWall.paint(g2);
        rightWall.paint(g2);
        bottomWall.paint(g2);
        ball.paint(g2);
    }
}

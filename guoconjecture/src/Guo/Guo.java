package Guo;
import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Guo extends JDialog {

    Board board;
    public Guo(int a,int b)
    {
        super((Window)null);
        setModal(true);
        board = new Board(a, b, this);
        add(board);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setSize(1000, 1000);
        setLocationRelativeTo(null);
        setVisible(true);
        dispose();
        setVisible(false);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[] primes={1, 2, 3, 5, 7, 9};
        for(int i=0; i<primes.length; ++i) {
            for(int j=i; j<primes.length; ++j) {
                new Guo(primes[i]*100, primes[j]*100);
            }
        }
    }
}
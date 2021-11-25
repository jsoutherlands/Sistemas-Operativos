//import java.util.io.*;
// 1 -> Búsqueda
// 2 -> Sumador
// 3 -> Morse

public class Main{
    public static void main(String args[]){
        long startTime = System.nanoTime();
        


       
        Busqueda hebra1 = new Busqueda(startTime);
        hebra1.start();
        
        
            
        Sumador hebra2 = new Sumador(startTime);
        hebra2.start();
        
            
        Morse hebra3 = new Morse(startTime);
        hebra3.start();


        
       
        
        
        long endTime = System.nanoTime();

        System.out.println("Tiempo total de ejecución: " + (endTime - startTime)+ " nanosegundos");

        
        
        
    }
}
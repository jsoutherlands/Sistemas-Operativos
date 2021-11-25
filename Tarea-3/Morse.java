import java.util.*;
import java.io.*;
/* README : un archivo morse.txt corresponderá a una frase*/
public class Morse extends Thread{
    long startTime;

    public Morse(long startTime){
        this.startTime = startTime;
    }

    @Override
	public void run(){
        
        String codigoMorse[] = {".-","-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        String abecedario[] = {"a","b", "c", "d","e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
        File archivo = null;
        FileReader fr = null;
        BufferedReader br = null;
        String resultado = "";

        try {
            // Apertura del fichero y creacion de BufferedReader para poder
            // hacer una lectura comoda (disponer del metodo readLine()).
            archivo = new File ("morse.txt");
            fr = new FileReader (archivo);
            br = new BufferedReader(fr);

            // Lectura del fichero
            String linea;
            ArrayList<String> moserList = new ArrayList<String>();
            
            while((linea=br.readLine())!=null){
				String[] parts = linea.split("\\ ");

                for(int i = 0; i < parts.length; i++){
                    for(int j = 0 ; j < codigoMorse.length; j++){
                        if (parts[i].equals(codigoMorse[j])){
                            resultado += abecedario[j];
                        }
                    }
                }
                resultado += " ";
                
               
			}
            
            
            System.out.println(resultado);
            long endTime3 = System.nanoTime();
            System.out.println("Thread3: " + (endTime3 - startTime)+ " nanosegundos");
        }
        catch(Exception e){
            e.printStackTrace();
        }finally{
            // En el finally cerramos el fichero, para asegurarnos
            // que se cierra tanto si todo va bien como si salta 
            // una excepcion.
            try{                    
                if( null != fr ){   
                fr.close();     
                }                  
            }catch (Exception e2){ 
                e2.printStackTrace();
            }
        }

        
        
    }
  
}
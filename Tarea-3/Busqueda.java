import java.util.Arrays;
// README ---> imprime eiffel por la primera eiffel que encuentra
import java.io.*;
public class Busqueda extends Thread{
    long startTime;

	public Busqueda(long startTime){
        this.startTime = startTime;
	}

	//public static void LecturaArchivos()



	@Override
	public void run(){
        //long startTime1 = System.nanoTime();
        File archivo = null;
        FileReader fr = null;
        BufferedReader br = null;
        

        try {
            // Apertura del fichero y creacion de BufferedReader para poder
            // hacer una lectura comoda (disponer del metodo readLine()).
            archivo = new File ("palabras.txt");
            fr = new FileReader (archivo);
            br = new BufferedReader(fr);

            // Lectura del fichero
            String linea;
            while((linea=br.readLine())!=null){
				String[] parts = linea.split("\\ ");
				//System.out.println(Arrays.asList(parts));
				for(int i = 0; i < parts.length; i++){
					if (parts[i].equals("eiffel")){
						System.out.println("eiffel");
					}
				}
               
			}
            long endTime1 = System.nanoTime();
            System.out.println("Thread1: " + (endTime1 - startTime)+ " nanosegundos");
                
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
            // Contabilizar el tiempo que se demora.
            
           
            
            
        }
        
        
        
    }
   
// }
}
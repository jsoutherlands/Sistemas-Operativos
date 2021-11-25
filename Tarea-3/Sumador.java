import java.util.*;

import java.io.*;
public class Sumador extends Thread{
    long startTime;
	

	public Sumador(long startTime){
        this.startTime = startTime;
	}

	@Override
	public void run(){
        
		
        File archivo = null;
        FileReader fr = null;
        BufferedReader br = null;
        String resultado = "";
        

        try {
            // Apertura del fichero y creacion de BufferedReader para poder
            // hacer una lectura comoda (disponer del metodo readLine()).
            archivo = new File ("numeros.txt");
            fr = new FileReader (archivo);
            br = new BufferedReader(fr);

            // Lectura del fichero
            String linea;
            ArrayList<String> testList = new ArrayList<String>();
            
            while((linea=br.readLine())!=null){
				String[] parts = linea.split("\\ ");
                
                for(int k = 0; k < parts.length; k++){
                    testList.add(parts[k]);
                }

			}
            
            List<Integer> partsInt= new ArrayList<Integer>();
            for(int k = 0; k < testList.size(); k++){
               
               partsInt.add(Integer.parseInt(testList.get(k)));
            }
            
            for(int i = 0; i < partsInt.size(); i++){
               
                for (int j = 0; j < partsInt.size(); j++){
                    
                    if(i < j){
                        if(partsInt.get(i)+partsInt.get(j) == 65){
                            resultado += partsInt.get(i) + " " + partsInt.get(j) + "\n";
                            
                        }
                    }
                }
            }
            System.out.print(resultado);
             long endTime2 = System.nanoTime();
            System.out.println("Thread2: " + (endTime2 - startTime)+ " nanosegundos");
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
    
// }
}
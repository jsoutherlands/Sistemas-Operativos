import java.util.Arrays;
import java.io.*;
public class Busqueda extends Thread{
	long startTime;

	public Busqueda(long startTime){
		this.startTime = startTime;
	}

	@Override
	/****************************************************************
	 * public void run
	 * **************************************************************
	 * Descripción:
	 * La función se encarga de leer el archivo "palabras.txt", que 
	 * contiene 10 palabras por línea y una cantidad N de líneas.
	 * Las palabras son guardadas por separado en una lista, y luego
	 * se recorre la lista buscando la concidencia entre la palabra 
	 * "eiffel" y alguna de las palabras almacenadas en la lista.
	 * Cuando se encuentra la primera coincidencia, se imprime por
	 * pantalla la palabra "eiffel" y se hace un break que termina
	 * con la búsqueda.
	 * Finalmente se imprime por pantalla el tiempo que demora la
	 * hebra 1 en realizar la tarea y se cierra el archivo.
	****************************************************************/
	public void run(){
		File archivo = null;
		FileReader fr = null;
		BufferedReader br = null;
		

		try {
		   
			archivo = new File ("palabras.txt");
			fr = new FileReader (archivo);
			br = new BufferedReader(fr);

			
			String linea;
			int flag = 0;
			while((linea=br.readLine())!=null){
				String[] parts = linea.split("\\ ");
				
				for(int i = 0; i < parts.length; i++){
					if (parts[i].equals("eiffel")){
						System.out.println("eiffel");
						flag = 1;
						break;
					}
				}

				if(flag == 1){
					break;
				}
			   
			}
			long endTime1 = System.nanoTime();
			System.out.println("Hebra 1: " + (endTime1 - startTime) + " nanosegundos");
				
		}
	   catch(Exception e){
			e.printStackTrace();
		}finally{
		   
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
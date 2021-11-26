import java.util.*;
import java.io.*;

public class Morse extends Thread{
	long startTime;

	public Morse(long startTime){
		this.startTime = startTime;
	}

	@Override
	/****************************************************************
	 * public void run
	 * **************************************************************
	 * Descripción: 
	 * La función lee el archivo "morse.txt", que recibe una frase en
	 * código Morse, con palabras escritas línea por línea cuyas letras
	 * se encuentran separadas por espacios. La función lee línea por
	 * línea, separa cada letra y la almacena en una lista. Esta lista
	 * es comparada con el arreglo codigoMorse[], que contiene cada
	 * letra en Código Morse. Cuando la encuentra, se imprime la letra
	 * almacenada en abecedario[] cuyo índice coincide con el índice
	 * de la letra almacenada en codigoMorse[].
	 * Luego de la impresión de una palabra, se imprime un espacio.
	 * Luego de la impresión de la frase completa, se imprime un "\n".
	 * Finalmente se imprime por pantalla el tiempo que demora la
	 * hebra 3 en realizar la tarea y se cierra el archivo.
	****************************************************************/
	public void run(){
		
		String codigoMorse[] = {".-","-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
		String abecedario[] = {"a","b", "c", "d","e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
		File archivo = null;
		FileReader fr = null;
		BufferedReader br = null;

		try {
		  
			archivo = new File ("morse.txt");
			fr = new FileReader (archivo);
			br = new BufferedReader(fr);

	
			String linea;
			
			while((linea=br.readLine())!=null){
				String[] parts = linea.split("\\ ");

				for(int i = 0; i < parts.length; i++){
					for(int j = 0 ; j < codigoMorse.length; j++){
						if (parts[i].equals(codigoMorse[j])){
							System.out.print(abecedario[j]);
						}
					}
				}
				System.out.print(" ");
				
			   
			}
			
			
			System.out.println("");
			long endTime3 = System.nanoTime();
			System.out.println("Hebra 3: " + (endTime3 - startTime)+ " nanosegundos");
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
  
}
import java.util.*;
import java.io.*;
public class Sumador extends Thread{
	long startTime;
	

	public Sumador(long startTime){
		this.startTime = startTime;
	}

	@Override
	/****************************************************************
	 * public void run
	 * **************************************************************
	 * Descripción:
	 * Se abrirá el archivo "numeros.txt" y será leído línea por línea,
	 * donde cada línea será almacenada temporalmente en "parts". 
	 * Todo el contenido de "numeros.txt" quedará en "testList" el
	 * cual es un ArrayList que posteriomente será recorrido para poder
	 * agregar los números en forma de entero en "partsInt", ya que 
	 * debemos realizar la suma de dos números no necesariamente 
	 * consecutivos pertenecientes al archivo y ver si su resultado es
	 * 65. En caso de serlo, se imprime por pantalla ambos números.
	 * Finalmente se imprime por pantalla el tiempo que demora la
	 * hebra 2 en realizar la tarea y se cierra el archivo.
	****************************************************************/
	public void run(){
		
		
		File archivo = null;
		FileReader fr = null;
		BufferedReader br = null;
		
		
		try {
			
			archivo = new File ("numeros.txt");
			fr = new FileReader (archivo);
			br = new BufferedReader(fr);

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
			int flag = 0;
			for(int i = 0; i < partsInt.size(); i++){
				for (int j = 0; j < partsInt.size(); j++){
					if(i < j){
						if(partsInt.get(i)+partsInt.get(j) == 65){
							System.out.println(partsInt.get(i) + " " +  partsInt.get(j));
							flag = 1;
						}
					}
				}
				if(flag == 1){
					break;
				}
			}
			long endTime2 = System.nanoTime();
			System.out.println("Hebra 2: " + (endTime2 - startTime)+ " nanosegundos");
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
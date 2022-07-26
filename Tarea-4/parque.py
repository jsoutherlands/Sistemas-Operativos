import threading
import datetime
import time
import random

class Hilo(threading.Thread):
	def __init__(self, id): #Constructor de la clase
		threading.Thread.__init__(self, target=zonaComun, args=()) #Hilo
		self.id = id # ID del Hilo (asignado en el for)
		self.nombre = "Persona" + str(id) # Nombre

# Creación de archivos

archivozonacomun = open('ZonaComun.txt', 'w')
archivosalida = open('Salida.txt', 'w')
archivobarcopirata = open('BarcoPirata.txt', 'w')
archivomontanarusa = open('MontañaRusa.txt', 'w')
archivocasaterror = open('CasaTerror.txt', 'w')
archivotiroblanco = open('TiroBlanco.txt', 'w')
archivozonacomun.close()

# Creación de Semáforos, Variables de Condición y Locks

bloqueaIngreso = threading.Lock()

FilaBarcoPirata = threading.Semaphore(15)
listosParaBarco = threading.Semaphore(5)
deBarcoASalida = threading.Condition()

FilaMontanaRusa = threading.Semaphore(10)
listosParaRusa = threading.Semaphore(10)
deRusaASalida = threading.Condition()

FilaCasaTerror = threading.Semaphore(8)
listosParaTerror = threading.Semaphore(2)
deTerrorASalida = threading.Condition()

FilaTiroBlanco = threading.Semaphore(5)
listosParaTiro = threading.Semaphore(1)
deTiroASalida = threading.Condition()


def zonaComun():
	x = random.randint(1,4)
	print(x)
	if x == 1: # Barco Pirata
		zonacomuntxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", Barco Pirata, "
		# escribe el archivo
		
		FilaBarcoPirata.acquire()
		zonacomuntxt += str(datetime.datetime.now()) + "\n"
		archivozonacomun = open('ZonaComun.txt', 'a')
		archivozonacomun.write(zonacomuntxt)
		archivozonacomun.close()
		bloqueaIngreso.release()
		filaBarcoPirata()
	elif x == 2: # Montaña Rusa
		zonacomuntxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", Montaña Rusa, "
		# escribe el archivo
		
		FilaMontanaRusa.acquire()
		zonacomuntxt += str(datetime.datetime.now()) + "\n"
		archivozonacomun = open('ZonaComun.txt', 'a')
		archivozonacomun.write(zonacomuntxt)
		archivozonacomun.close()
		bloqueaIngreso.release()
		filaMontanaRusa()
	elif x == 3: # Casa del Terror
		zonacomuntxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", Casa del Terror, "
		# escribe el archivo
		
		FilaCasaTerror.acquire()
		zonacomuntxt += str(datetime.datetime.now()) + "\n"
		archivozonacomun = open('ZonaComun.txt', 'a')
		archivozonacomun.write(zonacomuntxt)
		archivozonacomun.close()
		bloqueaIngreso.release()
		filaCasaTerror()
	elif x == 4: # Tiro al Blanco
		zonacomuntxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", Tiro al Blanco, "
		# escribe el archivo
		FilaTiroBlanco.acquire()
		zonacomuntxt += str(datetime.datetime.now()) + "\n"
		archivozonacomun = open('ZonaComun.txt', 'a')
		archivozonacomun.write(zonacomuntxt)
		archivozonacomun.close()
		bloqueaIngreso.release()
		filaTiroBlanco()

# BARCO PIRATA

def filaBarcoPirata():
	barcopiratatxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", "

	listosParaBarco.acquire()

	barcopiratatxt += str(datetime.datetime.now()) + "\n"

	archivobarcopirata = open('BarcoPirata.txt', 'a')
	archivobarcopirata.write(barcopiratatxt)
	archivobarcopirata.close()

	FilaBarcoPirata.release()
	barcoPirata()

def barcoPirata():
	deBarcoASalida.acquire()

	if listosParaBarco._value > 0:
		deBarcoASalida.wait()
	else:
		deBarcoASalida.notify_all()
	deBarcoASalida.release()
	time.sleep(7)
	salidatxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + "\n"
	archivosalida = open('Salida.txt', 'a')
	archivosalida.write(salidatxt)
	archivosalida.close()
	listosParaBarco.release()

# MONTAÑA RUSA

def filaMontanaRusa():
	montanarusatxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", "

	listosParaRusa.acquire()

	montanarusatxt += str(datetime.datetime.now()) + "\n"

	archivomontanarusa = open('MontañaRusa.txt', 'a')
	archivomontanarusa.write(montanarusatxt)
	archivomontanarusa.close()

	FilaMontanaRusa.release()
	montanaRusa()

def montanaRusa():
	deRusaASalida.acquire()

	if listosParaRusa._value > 0:
		deRusaASalida.wait()
	else:
		deRusaASalida.notify_all()
	deRusaASalida.release()
	time.sleep(5)
	salidatxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + "\n"
	archivosalida = open('Salida.txt', 'a')
	archivosalida.write(salidatxt)
	archivosalida.close()
	listosParaRusa.release()

# CASA DEL TERROR

def filaCasaTerror():
	casaterrortxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", "

	listosParaTerror.acquire()

	casaterrortxt += str(datetime.datetime.now()) + "\n"

	archivocasaterror = open('CasaTerror.txt', 'a')
	archivocasaterror.write(casaterrortxt)
	archivocasaterror.close()

	FilaCasaTerror.release()
	casaTerror()

def casaTerror():
	deTerrorASalida.acquire()

	if listosParaTerror._value > 0:
		deTerrorASalida.wait()
	else:
		deTerrorASalida.notify_all()
	deTerrorASalida.release()
	time.sleep(3)
	salidatxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + "\n"
	archivosalida = open('Salida.txt', 'a')
	archivosalida.write(salidatxt)
	archivosalida.close()
	listosParaTerror.release()

# TIRO AL BLANCO

def filaTiroBlanco():
	tiroblancotxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + ", "

	listosParaTiro.acquire()

	tiroblancotxt += str(datetime.datetime.now()) + "\n"

	archivotiroblanco = open('TiroBlanco.txt', 'a')
	archivotiroblanco.write(tiroblancotxt)
	archivotiroblanco.close()

	FilaTiroBlanco.release()
	tiroBlanco()

def tiroBlanco():
	time.sleep(2)
	salidatxt = "Persona" + str(threading.get_ident()) + ", " + str(datetime.datetime.now()) + "\n"
	archivosalida = open('Salida.txt', 'a')
	archivosalida.write(salidatxt)
	archivosalida.close()
	listosParaTiro.release()

# Creación de hilos --modificar en range()
# falta mandarlos aleatoriamente

hilos = []
for n in range(150):
	hilo = Hilo(n+1)
	hilos.append(hilo)
	bloqueaIngreso.acquire()
	hilo.start()
for hilo in hilos:
	hilo.join()

import threading
import random
import time

class Cola:
	def __init__(self):
		self.items = []
	def estaVacia(self):
		return self.items == []
	def agregar(self,item):
		self.items.insert(0,item)
	def avanzar(self):
		return self.items.pop()
	def tamano(self):
		return len(self.items)

class Juego:
	def __init__(self):
		self.qFila = Cola()
		self.qJuego = Cola()

def montanaRusa():
	print('entramos wi !')
def casaDelTerror():
	print("Entramos, buuuuu, soy un fantasma c:")
def barcoPirata():
	print("Ajoy!")
def tiroAlBlanco():
	print("Tira al blanco")
	
def zonaComun():
	rand = random.randint(1,4)
	if (rand == 1):
		montanaRusa()
	elif(rand == 2):
		casaDelTerror()
	elif(rand == 3):
		barcoPirata()
	elif(rand == 4):
		tiroAlBlanco()

hilos = []
for n in range(10):
	hilo  = threading.Thread(target=zonaComun)
	hilos.append(hilo)

for hilo in hilos:
	hilo.start()
#print(hilos[9])
for hilo in hilos:
    hilo.join()
#print(hilos)
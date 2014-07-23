Statie de lipit
=======================

Schema logica

+---------------+		+---------------+ 24Vcc	+---------------+	+---------------+
|		|     24Vca	|  Stabilizator	|======>|    Comanda	|	|     Letcon	|
|Transformator	| ============>	|  de tensiune	|	|   incalzire	|	+---------------+
|		|		|		|  /===>|		|==\	|    Element 	|
|---------------+		+---------------+  ||	+---------------+  \===>|   incalzire	|
					||	   ||				|		|
					||5Vcc	   ||				+---------------+
					\/	   ||				|     Senzor	|
+---------------+		+---------------+  ||	+---------------+   /===|  temperatura	|
|   Terminal	|      UART	| Microprocesor |===/	|   Convertor	|<==/	|		|
|    Serial	|==============>|    Atmega 8	| SPI/ V|  Temperatura	|	+---------------+
|		|		|		|<======| Tensiune/Biti |
+---------------+		+---------------+	+---------------+
				   ||	     /\	
				   ||	     ||
				   \/	     ||
			+---------------+    ||	+---------------+
			|     Afisaj    |    ||	|    Butoane/	|
			|  LCD/7segment |    \==|Encoder rotativ|
			| 		|	| /Potentiometru|
			+---------------+	+---------------+

Design modular
 -Circuitistica statiei de lipit este impartita in patru placi:
	-Alimentare si comanda incalzire
	-Microprocesor
	-Achizitie si conversie temperatura
	-Afisaj si input
 -Placile au dimensiunea de 2,4x1,5inch(6x3,8cm) si au 4 gauri de montare in colturi.

Model asezare placi:

	        +----------+     +     +     +     +
	       /	  /|====/|====/|====/|====/|
	      /		 / |   / |   / |   / |   / |
	     /		/  |  /	 |  /  |  /  |  /  |
	    /	       /   | /	 | /   | /   | /   |
	   /          /	   |/	 |/    |/    |/    | 
	  /	     /	   /	 /     /     /     +
	 /	    /	  /	/     /     /     /
	+----------+     +     +     +     +     /
	|	   |=====|=====|=====|=====|    /
	|	   |	/|    /|     |     |   /
	|   traf   |   / |   / |     |     |  /
	|	   |  /	 |  /  |     |     | /
	|	   |=====|=====|=====|=====|/ 
	+----------+     +     +     +     +
	
			 ^     ^     ^	   ^placa afisaj si butoane
			 |     |     placa microprocesor
		  	 |	placa achizitie temperatura	
			 placa stabilizare tensiune si control incalzire

Design frontal statie lipit:

	+----------------------------+
        |			     |
	| +---------------+	     |
	| |		  |   #####  |
	| |	LCD/	  |   #PWR#  |
	| |   7segmente	  |   #####  |
	| |		  |          |
	| +---------------+	     |
	|  /-\   /-\   /-\    #####  |
	|  \-/   \-/   \-/    #Con#  |
	|		      #####  |
        +-----------------------------





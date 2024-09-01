# Integral-imaging-synthetic-aperture
Repositorio con todo el material generado a lo largo de mi pasantía en el laboratorio de óptica aplicada en el Instituto de Física de la Facultad de Ingeniería bajo la supervisión de la Dra. Julia Alonso

## Estructura del repo

Hay varias carpetas que pueden tener cosas de utilidad:
- Documentos: Carpeta que tiene informes presentados para validar la pasantía como pasantía de Ing. Electrica, informe presentado a PEDECIBA, poster de IdM y poster presentado en el Workshop on Adaptive Compressive and Computational Imaging 2022. También hay un pdf que se llama links que es todo lo que acumule en el desarrollo de todo esto, puede servir para hacer troubleshooting en algun caso.
- Código: Esta carpeta tiene los archivos necesarios para utilizar la estructura que saca fotos mientras mueve la camara.
- Notebooks: Notebooks generados para realizar el procesamiento de las imagenes integrales. Este codigo no esta del todo prolijo pero puede servir como punto de partida para procesar las imagenes. 

## Funcionamiento:

La idea es que desde python se controla la camara y se le avisa al Arduino x puerto serial que se puede mover la camara, el Arduino mueve los motores y cuando termina le avisa a python que puede sacar otra foto. 

## Instrucciones de uso:

Para empezar se necesitan dos softwares instalados en la computadora que va a correr los programas. El primero es el software asociado a la cámara que se puede descargar de [este link](https://www.flir.com/products/spinnaker-sdk/). Es plug and play, es decir una vez que se conecta la camara el software la capta directamente y te permite tomar fotos ahí mismo. SIEMPRE hay que conectar la camara y abrir este software, si no los siguientes pasos no funcionan. 

El segundo software es uno para mover los motores sin codigo, este sirve para chequear que los motores funcionan para eso hay que conectar el cable de arduino a la compu y la fuente a la electricidad. En este software algunas veces hay que indicarle en que puerto se conecto el arduino. Se puede descargar de [este link](https://drive.google.com/file/d/12w0aJEAhwovQf3WCCmGwqNnhMwnoQ3hO/view). 

Motores y Arduino:  Todo se basa en [este video](https://www.youtube.com/watch?v=zUb8tiFCwmk) que en la descripcion te da el código para mover los motores, en resumen tenes que instalar la libreria GRBL de [este link](https://drive.google.com/file/d/12w0aJEAhwovQf3WCCmGwqNnhMwnoQ3hO/view) para poder mandarle el codigo Arduino. 

Python y camara: Para eso hay que usar [PySpin](https://pypi.org/project/EasyPySpin/), acá recuerdo haber tenido problemas de Wheel por la version de Windows, se soluciono embocandole a la version correcta pero no fue sencillo encontrarla. PySpin lo que hace es sacar la foto a traves de Python. También es necesario PySerial para hacer la comunicación serial, esa se instala con pip sin problema.

### Instalación:

1. Instalar el SDK.
2. Instalar Arduino y la librería GRBL.
3. Hacer un venv o un ambiente de Conda que contenga PySpin y PySerial.

### Uso:

1. Conectar la camara y abrirla con el SDK si se ve todo OK cerrar el programa.
2. Conectar el Arduino y mandarle el programa Movement.ino .
3. Activar el ambiente virtual desde una terminal y correr el programa Acquisition.py.
4. Dar OK en la terminal para que comience a tomar imágenes.

## Comentarios:

Todo lo anterior esta chequeado que funciona para Windows 10. La parte mas compleja es la de la instalación de PySpin, lo otro debería funcionar bastante directo.

Sobre la estructura hay que tratarla con cariño, para mover los motores al comienzo todo tiene que estar desconectadoy se mueven las guias respectivas, algunas veces pueden quedar desalineadas y si eso sucede el movimiento de los motores va a andar mal. Los motores agarran temperatura, se la bancan bien pero algunas veces por precaución entre toma y toma (si estas fueron largas) es mejor desconectar todo y esperar a que baje la temperatura. 

## Contacto

Cualquier duda o problema abrir un issue, contactarme a través de Julia o directamente a mi mail jumpierrez@fing.edu.uy 



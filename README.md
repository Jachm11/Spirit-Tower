# Spirit-Tower

## Detalles del Programa 
* El juego fue diseñado para el sistema operativo Windows 10
* El servidor fue diseñado y ejecutado con el editor de Visual Studio 2019 v.16.6.3
* La interfaz del juego fue diseñada con el motor de juegos Unity, especificamente con la versión 2019.14.1f1
* Los componentes necesarios con los que debe contar Visual Studio son los siguientes: c# y Visual Basic, caracteristicas principales de c++, IntelliCode, Actualizacion de C++ redistributable, herramientas de Cmake en c++ para windows, compiladores Roslyn para c# y Visual Basic, Herramientas de compilación MSVC v142-VS2019 c++ para x64/x86(v14.26), MsBuild.addresSanitizer c++, herramientas de generación de perfiles de c++, entorno de tiempo de ejecucion de C para windows Universal y últimas herramientas de compilación ATL de c++ para v142

## Instrucciones de Clonación del Repositorio

* En la sección de código se debe selecionar el boton code, para poder clonar el repositorio, se puede hacer de dos formas: descargando el archivo comprimido y descomprimirlo o clonandolo con una herramienta externa, en este caso GitKraken.

![](https://github.com/Jachm11/Spirit-Tower/blob/master/clone.png)

### Clonar con GitKraken
* Si no se cuenta con GitKraken y desea clonar el repositorio por este medio puede instalarlo aqui: [Instalar GitKraken](https://support.gitkraken.com/how-to-install/)
* Se copia el Link de clonación de github, y se dirige a GitKraken a la sección de clonación 

![](https://github.com/Jachm11/Spirit-Tower/blob/master/clone%20git.png)

* Se accede a la opción de clonar, se pega el link y listo!

![](https://github.com/Jachm11/Spirit-Tower/blob/master/clone%202.png)

# Pasos para trabajar como Desarrollador del Juego 
Si se desea modificar el juego y añadir funcionalidades debe de seguir los siguientes pasos...
## Instrucciones de Instalación del ambiente.

Para toda la ejecución de este juego se debe clonar todo el repositorio, ya sea mediante un zip o una herramienta externa como gitKraken.
* **IMPORTANTE:** Visual Studio se instala inmediatamente con la instalación de Unity, pero más adelante se especifica como se puede instalar por aparte.

### Unity 
Si se desea modificar el juego se deben de seguir los siguientes pasos:
* Instalar Unity Hub en el siguiente Link 
[Unity Hub ](https://unity3d.com/es/get-unity/download)

![](https://github.com/Jachm11/Spirit-Tower/blob/master/Unity%20hub.png)

* Una vez en Unity Hub se debe de activar la licencia de Unity, para más ayuda puede seguir la siguiente infromación:
[Activar Licencia Unity](https://docs.unity3d.com/es/530/Manual/OnlineActivationGuide.html)

* Una vez en Unity Hub se debe agregar el proyecto a Unity Hub. Esto en la sección "projects", "add" y se selecciona la carpeta "JuegoUnity" de la carpeta "SpiritTower" que clonó del respositorio. 

![](https://github.com/Jachm11/Spirit-Tower/blob/master/Abrir%20U%20(2).png)

![](https://github.com/Jachm11/Spirit-Tower/blob/master/Abrir%20U%20(1).png)


* Posteriormente, se debe posicionar en el icono de advertencia que aparece sobre el proyecto para proceder con la instalación de la versión de Unity necesaria, los pasos se muestran a continuación:

![](https://github.com/Jachm11/Spirit-Tower/blob/master/Version%20Unity.png)

![](https://github.com/Jachm11/Spirit-Tower/blob/master/Version%20Unity%202.png)

* En el proceso de instalación de la versión de unity el instalador ofrece la posibilidad de instalar Visual Studio realizando el siguiente procedimiento

![](https://github.com/Jachm11/Spirit-Tower/blob/master/VS%20con%20Unity.png)

![](https://github.com/Jachm11/Spirit-Tower/blob/master/VS%20con%20Unity%202.png)


* Finalmente ya puede abrir, dando click dos veces sobre el nombre del mismo en la pantalla de "projects" en Unity Hub. Una vez abierto ya puede continuar y modificar el proyecto a su parecer.

### Visual Studio
* Debe de instalar Visual Studio v.16.6.3. Puede utilizar el siguiente enlace:

[Download VS](https://docs.microsoft.com/en-us/visualstudio/releases/2019/release-notes)

* Una vez instalado se debe comprobar en que cuente todos los componentes  mencionados en los detalles del programa. Esto se puede hacer mediante el installer de Visual Studio, en la versión solicitada se dirige a al opción modificar y luego a la sección de componentes. Allí podra instalar los componentes restantes.

* Para realizar modificaciones en la parte del servidor dirijase a la carpeta donde haya clonado el juego e ingrese a "Spirit-Tower" -> "Server" -> "ServerVS" , donde ser muestran los archivos correspondientes al servidor, su codigo main se encuentra con el nombre de ServerVS.cpp en el cual se pueden realizar pruebas de la ejecucion del servidor

![]()

# Pasos para solo ejecutar el juego
En caso de no querer modificar el juego y solo ejecutarlo se deben de seguir los siguientes pasos.
## Instrucciones de Instalación del ambiente.
### Visual Studio
* Debe de instalar Visual Studio v.16.6.3.  Puede utilizar el siguiente enlace:

[Download VS](https://docs.microsoft.com/en-us/visualstudio/releases/2019/release-notes)

* Una vez instalado se debe comprobar en que cuente todos los componentes  mencionados en los detalles del programa. Esto se puede hacer mediante el installer de Visual Studio, en la versión solicitada de dirige a al opción modificar y luego a la sección de componentes. Allí podra instalar los componentes restantes.



## Instrucciones de ejecución del Juego

* **IMPORTANTE:** Este paso es necesario ya sea si se trabaja como desarrollador o simplemente como jugador.

* Una vez realizada la instalción del ambiente de Visual Studio  se debe dirigir a la carpeta "Spirit-Tower" -> "Server" -> "ServerVS" -> se abre el archivo "ServerVS.vcxproj" 

![](https://github.com/Jachm11/Spirit-Tower/blob/master/abrir%20Visual.png)

* Con el proyecto abierto en Visual Studio se busca el archivo ServerVS.cpp y se ejecuta (Esto antes de correr el juego).

![](https://github.com/Jachm11/Spirit-Tower/blob/master/Ejecutar%20el%20Server.png)

* IMPORTANTE: para ejecutar el juego se debe de entrar a la carpeta "JuegoUnity" -> "build" -> "spiritTowerGame.exe"

## Instrucciones del juego

* Movimiento del jugador: para poder desplazarse con el jugador se utlizan las flechas del teclado (↑,↓,→,←).
* Ataque: para el ataque se debe usar la barra espaciadora.
* Escudo: para habilitar el escudo se presiona la tecla de shift izquierda. Este se deshabilita automáticamente.
* Las zonas celestes son zonas seguras, por lo que al entrar en ellas los espectros no dejan de perseguir al jugador.
* Los espectros tienen su punto debil en la espalda, si estos te atacan te quitan todos los corazones.

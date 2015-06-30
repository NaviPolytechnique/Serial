# Serial
Simple serial class to interact with serial devices on Unix systems


@ Cette classe permet, sur une machine UNIX (Mac OS X ou Linux -  avec le formalisme issu de POSIX pour la communication série) de communiquer avec un device de type Serial.


@ Pour utiliser sous Windows, allez utiliser une autre classe - je me suis inspiré de la classe SerialLib (LIEN) que vous pouvez directement installer. 
Il existe d'autre librairie en OpenSource qui peuvent être utilisées également.


@ Cette classe dispose de plusieurs méthodes, toutes bien détaillées dans le header file (.h)
  
	- Constructeur : Serial( const char*, const long int ) qui instancie un objet de la classe. Il faut indiquer le nom du port ainsi que le BAUDRATE du device, sachant que seuls certains BAUDRATES sont acceptables (voir .h) : 

	- Destructeur : ~Serial() : Ferme le port

	- Lire et écrire un string sur le port
	- Lire une ligne depuis le port (comme dans RXTX pour Java) et qui arrête la lecture lorsqu'un caractère d’arrêt (ie '\n') est lu
	- Ecrire ou lire un tableau de bytes (il faut connaître la taille du tableau)
	- Récupérer le nom du port (TODO : conversion de const std::string à const char* à faire)


@ Regarder le programme test.cpp pour comprendre comment marche ces différentes fonctions. LIRE LE HEADER SI DOUTES


@ //!!\\ ATTENTION : pas encore de TimeOut implémenté, le programme attendra indéfiniment qu'un ligne,string,char ou byte arrive par le port.. TimeOutSerial à venir !


@ La classe utilise une classe d’exception spécifique (serial_exception) définie dans un header.hpp


@ Pour compiler la classe, il suffit de rentrer les commandes suivantes : 
            cd <root_directory_of_Serial_class>
            make
            make clean

  make clean étant optionnel (enlever les fichiers .o inutiles)


@ ATTENTION : Selon votre version de g++, il y a peut-être des choses qu'il ne va pas aimer dans le main de test.cpp. Pour régler le problème, il faut juste enlever le "serial_exception::" lors de la construction de l'exception (on ne peut pas appeler le constructeur sur un objet déjà créé)


@ Lors des opérations de lecture, il se peut que selon le nom de votre port (en fait sous Linux c'est un fichier) - par exemple pour ACM0 - l’exécution vous retourne quelque chose comme : 
		"Permission Denied"
	Deux solutions : 
		- Faire un alias du port :
			sudo ln -s /dev/ttyACMx /dev/ttyS8x
		- Autre solution, changer les droits de l'user sur les ports (cf Google, je vais pas tout recopier ;) )


Minimum Requirements:
	Microsoft Visual C++ Redistributable für Visual Studio 2015
	Windows 8.1

Engine Snipped:
	Enthält Codeausschnitte aus der Engine

Example Code:
	!!!Wichtig:!!! 
	Damit fehlerfrei kompiliert werden kann muss die Datei BAMEngine.lib.7z im Verzeichnis Lib
	an selbiges Verzeichnis entpackt werden.  
	
	Enthält ein Visual Studio Projekt mit Beispielcode
	Hierbei können in der Klasse Game, in der Methode Init zwei Szenen ausgewählt werden.
	Hierzu den Parameter für SetActiveScene in Zeile 29 entweder GAME_BREAK_OUT_2D oder Scene_3D wählen.

	-> GAME_BREAK_OUT_2D
	Einfaches 2D Spiel das sich mit den Pfeiltasten und der Leertaste steuern lässt
		
		[Space] Spiel starten oder Ball von Player lösen

	-> SCENE_3D
	Eine 3D Scene mit Features der Engine. Kann mit WASD und Pfeiltasten gesteuert werden.
	Weiter:
		[O] und [I] Anzahl an Partikeln verändert
		[P} Toggling der Parallax Occlusion
	

Executeables:
	Enthält die zwei Scenen als Excecutables.	
	




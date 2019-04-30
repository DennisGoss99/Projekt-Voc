# Vokable Trainer

## Ein Projekt von Dennis G. und Jonas E.

Dies ist unser Ablschussprojekt, es ist ein Vokabeltrainer der auf einem zentralen Server liegt, auf den sich dann unterschiedlich User von unterschiedlichen Standorten anmelden können. Welche unabhängig von einander arbeiten können. Da dies unsere Aufgabenstellung nicht zulässt, muss jeder Client einen seperaten MysqlServer während der Anwendung auf seinem Rechner laufen lassen. Zusätzlich muss man noch ODBC konfigurieren. 

![](https://github.com/DennisGoss99/Projekt-Voc/blob/master/Resources/pictures/MianFormBeispielBild.PNG?raw=true "MianFormBeispielBild")
## Anleitung / Hilfe

### Hauptfenster

#### Die Anmeldung

Um das Programm in vollen ausmahße nutzen zu können, muss man sich erstmal oben Rechts in der Ecke einloggen. Hierzu stehen auch folgende Accounts zu verfügung:
* **Benutzername:** TestUser1 **Passwort:** 1234 	*+ Beispiel Vokabeln*	
* **Benutzername:** Root 	**Passwort:** (Kein Passwort)

Da die Software dazu ausgelegt ist, dass nur ein Administrator Benutzer über den Zentralserver verwalten kann, können Sie selber nur Benutzer dierekt über die lokale Datenbank verwalten (anlegen / löschen / bearbeiten).  
*Hierzu können sie entweder phpmyadmin / Mysql-shell verwenden*
 
#### Statistik 

Unsere Statistik, welche als Säulendiagramm fungiert, die Sie nach dem zweiten Anmelden sehen können, funktioniert wie folgt: 

* X-Achse: gespeicherte Benutzerstatistik nach jeder Abmeldung  
* Y-Achse: ungefährer Messindikator für die Vokabelanzahl  
* Farbe Blau: Noch nicht bearbeitete Vokabeln
* Farbe Grün: Richtig beantwortete Vokabeln
* Farbe Rot: Falsch beantwortete Vokabeln

Unter der Statistik finden Sie die aktuelle Benutzerstatistik, in form von Drei Labels. 

### Bearbeitungs Fenster (Units / Vokabeln)

#### Vokabeln und Untis bearbeiten

Mit dem Button "Kärtchen manuell eingeben >" öffnet sich ein neues Form, in dem Sie Units und Vokabeln bearbeiten können. 

Um eine Unit zu entfernen, wählen Sie die zu löschende Unit aus und drücken sie oben Rechts auf das X.
Außerdem können Sie den Namen/ die Sprache der Unit im gleichen Abschnitt ändern.
Zudem kann man neue Units hinzufügen, indem sie den Menüpunkt "--hinzufügen--" in der ersten ComboBox auswählen und diese zu dem gewünschten Unitnamen ändern.

Sobald man eine Unit ausgewählt / eingefügt hat, kann man nun über die Drei Editfelder, in der unteren hälfte die Vokabeln einfügen. 
Dazu gibt man in dem ersten Editfeld die Vokabel unübersetzt ein, daneben die Übersetztung und falls man möchte kann man im letzten Editfeld auch noch ein Glossar zu der Vokabel hinzufügen. Nach dem vollendetem ausüllen einer Vokabel (2 bis 3 Editfelder), drücken Sie auf den Button hinzufügen. 

Wenn Sie eine Vokabel aus der Unit löschen wollen, dann drücken Sie auf die Vokabel in einer der Listboxen und drücken Sie dann den Button "Löschen".

Auch im nachhinnein ist es immer möglich Vokabeln zu bearbeiten.
Wenn Sie fertig sind, können Sie alles über den Button Speichern bestätigen oder falls sie es doch nicht machen wollen oder etwas falsches gelöscht haben können Sie den Button abbrechen drücken.  
*Ausgenommen: (Unit entfernen)*

### Vokabelabfrage Fenster

#### Die Vokabel abfrage

Um die Vokabelabfrage zu starten, betätigen Sie den Button "Start Vokabeln".
Nun wird Ihnen auf der linken Seite die Vokabel in der unübersetzten Sprache angezeigt und Sie müssen nun auf der rechten Seite die korrekte Übersetzung eingeben. 
TIPP: *Falls sie nicht dierekt auf die Vokabel kommen, können sie auch noch das Glossar öffnen*

Wenn Sie die Übersetzung eingetragen haben, dann drücken sie auf "Überprüfen". Daraufhin wird Ihnen zum Beispiel durch das Bild oben rechts in der Ecke angezeigt, ob Sie richtig oder falsch liegen. Dies wird ausßerdem in der Statistik wiedergespiegelt.
Danach ändert sich der Text des Buttons und um auf die nächste Vokabel zu gelangen müssen sie Ihn erneut drücken.

Sie können sich immer dazu entscheiden die Unit zu unterbrechen und machen beim nächsten mal nur mit den noch nicht bearbeiteten und falsch beantworteten Vokabeln weiter. Nach der komplett korrekten bearbeitung wird die Unit zurückgesetzt und ist für die erneute Bearbeitung bereit. 

### Nützeliche Infos

Unter dem Menüpunkt "Hilfe/Log", können sie die Logdatei öffnen und den Log ein und Ausschalten, um die ausgeführten MySQL-Befehle einsehen zu können.

![](https://github.com/DennisGoss99/Projekt-Voc/blob/master/Diagramme/Use%20case.png "Use case Diagramm")

![](https://github.com/DennisGoss99/Projekt-Voc/blob/master/Diagramme/Erdiagramm.png "ER Diagramm")

![](https://github.com/DennisGoss99/Projekt-Voc/blob/master/Diagramme/Klassendiagramm.png "Klassendiagramm")


### Kontaktdaten

Bei Rückfragen bitte melden:

### SSC
#### CEO / CBDO : Dennis Gossler
	email: dennisgossler98@gmail.com
	tel:   +49 157 82518921 
	
	Zuständig für:  Firmenchef, Business Development, Projekt Management


#### CKO / CTO  : Jonas Eller
	email: jonasnr8eller@aol.de
	tel:	+49 172 4693868
	
	Zuständig für: Time Management, Wissensmanagement, Development
	
	


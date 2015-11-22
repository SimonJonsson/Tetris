Readme/instruktioner version 2
Som det är nu är det bara source filer vi delar. Därför får man första gången man ska koda på en ny dator skapa ett eget projekt och sen pulla alla source filer till detta tomma projekt.

Dvs
För att starta projektet för första gången.
1) Starta nytt sfml projekt i codeblocks.
2) gå till mappen ni har projektet i.
3) Clonea repot till mappen.
4) Ni har era lokala filer som tetris.layout och bin/obj mappen och det enda som pullats från repot är source filerna som är samma för alla.
-----
Första gången
-----
0) Öppna terminal i mapp du vill ha projektet i
1) git config --global user.name "Grayson Webb"
2) git config --global user.email "gralo184@student.liu.se"
3) git clone https://gralo184@github.com/SimonJonsson/Tetris
4) cd Tetris
5) Öppna code blocks -> new project ->sfml-> se till att Tetris.cbp skapas i git mapp
-> ersätt inte main.cpp ->compile and run

----
Varje gång man ändrar skit
-----
6)Ändra skit
7) git status - se vilka filer som ändrats
8) git diff - se kod som ändrats
9) (låt säga man ändrat readme.md och main.cpp)
git add readme.md main.cpp (var försiktig med git add ., lägger till allt)
10) git status (visar grönt på filer man lagt till)
11) git commit -m "vad har jag gjort"
12) git pull (updatera innan du pushar ändringar)
13) git push (mata in lösenord till github konto)


git rm fil.namn (tar bort fil)
git mv fil.namn mappnamn (flyttar fil)
dessa ändringar måste även committas


q för att komma ut



--------------------------
Kodmall.
https://www.ida.liu.se/~TDDC76/2014/project/kodmallar.sv.shtml#Dokumentationen%20av%20program

echo on
set mysqlpath=C:\Users\Admin\Documents\XAMPP\mysql\bin\
set DB_USER='root'
set DB_PASSWD=''

set DB_NAME=VOKABELTRAINER
set TABLE='User'

%mysqlpath%mysql.exe --user=%DB_USER% %DB_NAME% < Start.txt

echo 

INSERT INTO `%TABLE%` (`Surname`, `Name`, `Username`, `Email`, `Password`, `CreationDate`) VALUES ('Test', 'Test', 'TEst', 'fds@dfh', '', now());

echo hallo
PAUSE

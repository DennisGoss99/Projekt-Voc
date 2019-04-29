Use `VOKABELTRAINER`;

INSERT INTO `language` (`Language`, `Contraction`) VALUES
( 'German', 'DE'),
( 'English', 'GB'),
( 'Spanish', 'ES'),
( 'Italian', 'IT'),
( 'Swedish', 'SE'),
( 'Finnish', 'FI'),
( 'Japanese', 'JP');

INSERT INTO `user` (`Surname`, `Name`, `Username`, `Email`, `Password`, `CreationDate`) VALUES ('root', 'root', 'root', 'root@root', PASSWORD(''), now());
INSERT INTO `user` (`Surname`, `Name`, `Username`, `Email`, `Password`, `CreationDate`) VALUES ('root', 'root', 'Peter42', 'root@root', PASSWORD('1234'), now());

INSERT INTO `unit` (`UnitName`, `LastEdit`, `User_idUser`, `Language_idLanguage`) VALUES ( 'BeispielUnit', now(), 1, 2);

INSERT INTO `vocabulary` (`Word`, `WordTranslated`, `IsFinished`, `Unit_idUnit`, `Glossary`) VALUES
( 'Ja', 'yes', -1, 1, ' to agree with'),
( 'Nein', 'no', -1, 1, 'a vote not in favor, or opposing a proposition'),
( 'Vielleicht', 'maybe', -1, 1, 'Something that is possibly true.'),
( 'Bitte', 'please', -1, 1, 'to afford or give pleasure or satisfaction'),
( 'Danke', 'thank you', -1, 1, 'a polite expression of ones gratitude'),
( 'Entschuldigung', 'sorry', -1, 1, 'feeling sorrow, regret, or penitence'),
( 'Ich verstehe (nicht)', 'I (do not) understand', -1, 1, ''),
( 'Sprechen Sie Deutsch?', 'Do you speak German?', -1, 1, ''),
( 'Ich spreche kein Englisch', 'I dont speak English', -1, 1, ''),
( 'Hilfe!', 'Help!', -1, 1, 'to give assistance or support to');

	
	
	
	

	

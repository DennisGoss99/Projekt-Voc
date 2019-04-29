-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 29, 2019 at 07:35 PM
-- Server version: 10.1.38-MariaDB
-- PHP Version: 7.3.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `vokabeltrainer`
--

-- --------------------------------------------------------

--
-- Table structure for table `language`
--

CREATE TABLE `language` (
  `idLanguage` int(11) NOT NULL,
  `Language` varchar(45) NOT NULL,
  `Contraction` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `language`
--

INSERT INTO `language` (`idLanguage`, `Language`, `Contraction`) VALUES
(1, 'German', 'DE'),
(2, 'English', 'GB'),
(3, 'Spanish', 'ES'),
(4, 'Italian', 'IT'),
(5, 'Swedish', 'SE'),
(6, 'Finnish', 'FI'),
(7, 'Japanese', 'JP');

-- --------------------------------------------------------

--
-- Table structure for table `statistic`
--

CREATE TABLE `statistic` (
  `idStatistic` int(11) NOT NULL,
  `LastVisite` date DEFAULT NULL,
  `TotalWords` int(11) DEFAULT NULL,
  `TotalUnits` int(11) DEFAULT NULL,
  `precessedWords` int(11) DEFAULT NULL,
  `FailedWords` int(11) DEFAULT NULL,
  `User_idUser` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `unit`
--

CREATE TABLE `unit` (
  `idUnit` int(11) NOT NULL,
  `UnitName` varchar(45) NOT NULL,
  `LastEdit` date DEFAULT NULL,
  `User_idUser` int(11) NOT NULL,
  `Language_idLanguage` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `unit`
--

INSERT INTO `unit` (`idUnit`, `UnitName`, `LastEdit`, `User_idUser`, `Language_idLanguage`) VALUES
(1, 'BeispielUnit', '2019-04-29', 1, 2);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `idUser` int(11) NOT NULL,
  `Surname` varchar(45) NOT NULL,
  `Name` varchar(45) NOT NULL,
  `Username` varchar(45) NOT NULL,
  `Email` varchar(45) NOT NULL,
  `Password` varchar(45) DEFAULT NULL,
  `CreationDate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`idUser`, `Surname`, `Name`, `Username`, `Email`, `Password`, `CreationDate`) VALUES
(1, 'root', 'root', 'root', 'root@root', '', '2019-04-29'),
(2, 'root', 'root', 'Peter42', 'root@root', '*A4B6157319038724E3560894F7F932C8886EBFCF', '2019-04-29');

-- --------------------------------------------------------

--
-- Table structure for table `vocabulary`
--

CREATE TABLE `vocabulary` (
  `idVocabulary` int(11) NOT NULL,
  `Word` varchar(100) NOT NULL,
  `WordTranslated` varchar(100) NOT NULL,
  `IsFinished` tinyint(4) NOT NULL DEFAULT '0',
  `Glossary` varchar(100) NOT NULL,
  `Unit_idUnit` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `vocabulary`
--

INSERT INTO `vocabulary` (`idVocabulary`, `Word`, `WordTranslated`, `IsFinished`, `Glossary`, `Unit_idUnit`) VALUES
(1, 'Ja', 'yes', -1, ' to agree with', 1),
(2, 'Nein', 'no', -1, 'a vote not in favor, or opposing a proposition', 1),
(3, 'Vielleicht', 'maybe', -1, 'Something that is possibly true.', 1),
(4, 'Bitte', 'please', -1, 'to afford or give pleasure or satisfaction', 1),
(5, 'Danke', 'thank you', -1, 'a polite expression of ones gratitude', 1),
(6, 'Entschuldigung', 'sorry', -1, 'feeling sorrow, regret, or penitence', 1),
(7, 'Ich verstehe (nicht)', 'I (do not) understand', -1, '', 1),
(8, 'Sprechen Sie Deutsch?', 'Do you speak German?', -1, '', 1),
(9, 'Ich spreche kein Englisch', 'I dont speak English', -1, '', 1),
(10, 'Hilfe!', 'Help!', -1, 'to give assistance or support to', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `language`
--
ALTER TABLE `language`
  ADD PRIMARY KEY (`idLanguage`);

--
-- Indexes for table `statistic`
--
ALTER TABLE `statistic`
  ADD PRIMARY KEY (`idStatistic`),
  ADD KEY `User_idUser` (`User_idUser`);

--
-- Indexes for table `unit`
--
ALTER TABLE `unit`
  ADD PRIMARY KEY (`idUnit`),
  ADD KEY `User_idUser` (`User_idUser`),
  ADD KEY `Language_idLanguage` (`Language_idLanguage`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`idUser`);

--
-- Indexes for table `vocabulary`
--
ALTER TABLE `vocabulary`
  ADD PRIMARY KEY (`idVocabulary`),
  ADD KEY `Unit_idUnit` (`Unit_idUnit`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `language`
--
ALTER TABLE `language`
  MODIFY `idLanguage` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `statistic`
--
ALTER TABLE `statistic`
  MODIFY `idStatistic` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `unit`
--
ALTER TABLE `unit`
  MODIFY `idUnit` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `idUser` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `vocabulary`
--
ALTER TABLE `vocabulary`
  MODIFY `idVocabulary` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `statistic`
--
ALTER TABLE `statistic`
  ADD CONSTRAINT `statistic_ibfk_1` FOREIGN KEY (`User_idUser`) REFERENCES `user` (`idUser`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `unit`
--
ALTER TABLE `unit`
  ADD CONSTRAINT `unit_ibfk_1` FOREIGN KEY (`User_idUser`) REFERENCES `user` (`idUser`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `unit_ibfk_2` FOREIGN KEY (`Language_idLanguage`) REFERENCES `language` (`idLanguage`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `vocabulary`
--
ALTER TABLE `vocabulary`
  ADD CONSTRAINT `vocabulary_ibfk_1` FOREIGN KEY (`Unit_idUnit`) REFERENCES `unit` (`idUnit`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

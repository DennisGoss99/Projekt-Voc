-- MySQL Script generated by MySQL Workbench
-- Thu Apr  4 22:30:43 2019
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema VOKABELTRAINER
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema VOKABELTRAINER
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `VOKABELTRAINER` DEFAULT CHARACTER SET utf8 ;
USE `VOKABELTRAINER` ;

-- -----------------------------------------------------
-- Table `VOKABELTRAINER`.`User`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `VOKABELTRAINER`.`User` (
  `idUser` INT NOT NULL AUTO_INCREMENT,
  `Surname` VARCHAR(45) NOT NULL,
  `Name` VARCHAR(45) NOT NULL,
  `Username` VARCHAR(45) NOT NULL,
  `Email` VARCHAR(45) NOT NULL,
  `Password` VARCHAR(45) NULL,
  `CreationDate` DATE NOT NULL,
  PRIMARY KEY (`idUser`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `VOKABELTRAINER`.`Language`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `VOKABELTRAINER`.`Language` (
  `idLanguage` INT NOT NULL AUTO_INCREMENT,
  `Language` VARCHAR(45) NOT NULL,
  `Contraction` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idLanguage`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `VOKABELTRAINER`.`Unit`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `VOKABELTRAINER`.`Unit` (
  `idUnit` INT NOT NULL AUTO_INCREMENT,
  `UnitName` VARCHAR(45) NOT NULL,
  `LastEdit` DATE NULL,
  `User_idUser` INT NOT NULL,
  `Language_idLanguage` INT NOT NULL,
  PRIMARY KEY (`idUnit`),
    FOREIGN KEY (`User_idUser`)
    REFERENCES `VOKABELTRAINER`.`User` (`idUser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
    FOREIGN KEY (`Language_idLanguage`)
    REFERENCES `VOKABELTRAINER`.`Language` (`idLanguage`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `VOKABELTRAINER`.`Vocabulary`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `VOKABELTRAINER`.`Vocabulary` (
  `idVocabulary` INT NOT NULL AUTO_INCREMENT,
  `Word` VARCHAR(100) NOT NULL,
  `WordTranslated` VARCHAR(100) NOT NULL,
  `IsFinished` TINYINT NOT NULL DEFAULT 0,
  `Glossary` VARCHAR(100) NOT NULL,
  `Unit_idUnit` INT NOT NULL,
  PRIMARY KEY (`idVocabulary`),
    FOREIGN KEY (`Unit_idUnit`)
    REFERENCES `VOKABELTRAINER`.`Unit` (`idUnit`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `VOKABELTRAINER`.`Statistic`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `VOKABELTRAINER`.`Statistic` (
  `idStatistic` INT NOT NULL AUTO_INCREMENT,
  `LastVisite` DATE NULL,
  `TotalWords` INT NULL,
  `TotalUnits` INT NULL,
  `precessedWords` INT NULL,
  `FailedWords` INT NULL,
  `User_idUser` INT NOT NULL,
  PRIMARY KEY (`idStatistic`),
    FOREIGN KEY (`User_idUser`)
    REFERENCES `VOKABELTRAINER`.`User` (`idUser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

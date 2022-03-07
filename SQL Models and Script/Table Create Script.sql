-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema tictactoedb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema tictactoedb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `tictactoedb` DEFAULT CHARACTER SET utf8 ;
USE `tictactoedb` ;

-- -----------------------------------------------------
-- Table `tictactoedb`.`account`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tictactoedb`.`account` (
  `accountID` INT NOT NULL AUTO_INCREMENT,
  `firstName` VARCHAR(45) NOT NULL,
  `lastName` VARCHAR(45) NOT NULL,
  `avatar_path` VARCHAR(255) NULL,
  PRIMARY KEY (`accountID`)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tictactoedb`.`passwords`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tictactoedb`.`passwords` (
  `accountID` INT NOT NULL,
  `varchar(255)` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`accountID`, `varchar(255)`),
  CONSTRAINT `accountID`
    FOREIGN KEY (`accountID`)
    REFERENCES `tictactoedb`.`account` (`accountID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tictactoedb`.`stats`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tictactoedb`.`stats` (
  `accountID` INT NOT NULL,
  `wins` INT NOT NULL DEFAULT 0,
  `loses` INT NOT NULL DEFAULT 0,
  `draws` INT NOT NULL DEFAULT 0,
  PRIMARY KEY (`accountID`, `wins`, `loses`, `draws`),
  CONSTRAINT `accountID`
    FOREIGN KEY ()
    REFERENCES `tictactoedb`.`account` ()
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tictactoedb`.`game`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tictactoedb`.`game` (
  `gameID` INT NOT NULL AUTO_INCREMENT,
  `date` DATETIME NOT NULL,
  `status` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`gameID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tictactoedb`.`account_to_game_list`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tictactoedb`.`account_to_game_list` (
  `account_accountID` INT NOT NULL,
  `game_gameID` INT NOT NULL,
  `role` INT NOT NULL,
  PRIMARY KEY (`account_accountID`, `game_gameID`),
  INDEX `fk_account_has_game_game1_idx` (`game_gameID` ASC) VISIBLE,
  INDEX `fk_account_has_game_account1_idx` (`account_accountID` ASC) VISIBLE,
  CONSTRAINT `fk_account_has_game_account1`
    FOREIGN KEY (`account_accountID`)
    REFERENCES `tictactoedb`.`account` (`accountID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_account_has_game_game1`
    FOREIGN KEY (`game_gameID`)
    REFERENCES `tictactoedb`.`game` (`gameID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `tictactoedb`.`game_result`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `tictactoedb`.`game_result` (
  `gameID` INT NOT NULL,
  `result` INT NULL,
  PRIMARY KEY (`gameID`),
  INDEX `result_idx` (`result` ASC) VISIBLE,
  CONSTRAINT `gameID`
    FOREIGN KEY (`gameID`)
    REFERENCES `tictactoedb`.`game` (`gameID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `result`
    FOREIGN KEY (`result`)
    REFERENCES `tictactoedb`.`account` (`accountID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

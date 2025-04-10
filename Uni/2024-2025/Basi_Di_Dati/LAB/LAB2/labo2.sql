---------------------------------------------
-- Interrogazioni su singola relazione     --
---------------------------------------------

--1--
set search_path to "unicorsi";
SELECT Matricola, Cognome, Nome
FROM Studenti
Where Iscrizione < 2007
    AND Laurea IS NULL
    AND Relatore IS NULL;

--2--
set search_path to "unicorsi";
SELECT Facolta, Denominazione
FROM CorsiDiLaurea
WHERE Attivazione < '2006/2007'
    OR Attivazione > '2009/2010'
ORDER BY Facolta, Denominazione;

--3--
set search_path to "unicorsi";
SELECT Matricola, Cognome, Nome
FROM Studenti
WHERE (Cognome NOT IN ('Serra', 'Melogno', 'Giunchi')
       OR Residenza IN ('Genova', 'La Spezia', 'Savona'))
ORDER BY Matricola DESC;

---------------------------------------------
-- Interrogazioni su più relazioni         --
---------------------------------------------

--1--
set search_path to "unicorsi";
SELECT S.Matricola
FROM Studenti S
JOIN CorsiDiLaurea C ON S.CorsoDiLaurea = C.id
WHERE C.Denominazione = 'Informatica'
  AND S.Laurea < '11-01-2009';

--2--
set search_path to "unicorsi";
Select S.Cognome, S.Nome, R.Cognome AS CognomeRelatore
FROM Studenti S
JOIN Professori R ON S.Relatore = R.id
ORDER BY S.Cognome, S.Nome;

--3--
set search_path to "unicorsi";
SELECT S.Cognome, S.Nome
FROM Studenti S
JOIN CorsiDiLaurea C ON S.CorsoDiLaurea = C.id
JOIN PianiDiStudio P ON S.Matricola = P.Studente
WHERE C.Denominazione = 'Informatica'
    AND P.AnnoAccademico = 2011
    AND P.Anno = 5
    AND S.Relatore IS NOT NULL
ORDER BY S.Cognome DESC, S.Nome DESC;

---------------------------------------------
-- Operazioni insiemistiche                --
---------------------------------------------

--1--
set search_path to "unicorsi";

SELECT Cognome, Nome, 'Studente' AS Qualifica
FROM Studenti
UNION
SELECT Cognome, Nome, 'Professore' AS Qualifica
FROM Professori
ORDER BY Cognome, Nome;

--2--
set search_path to "unicorsi";

SELECT Matricola
FROM Studenti
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' 
    AND Voto >= 18 AND Corsi.Denominazione = 'Basi Di Dati 1' 
    AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010'

EXCEPT

SELECT Matricola
FROM Studenti 
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' 
    AND Voto >= 18 AND Corsi.Denominazione = 'Interfacce Grafiche' 
    AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010';

--3--
set search_path to "unicorsi";

SELECT Matricola
FROM Studenti
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' 
    AND Voto >= 18 AND Corsi.Denominazione = 'Basi Di Dati 1' 
    AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010'

INTERSECT

SELECT Matricola
FROM Studenti 
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' 
    AND Voto >= 18 AND Corsi.Denominazione = 'Interfacce Grafiche' 
    AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010';

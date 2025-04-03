-- Errori inerenti a INSERT INTO Professori VALUES :

    --INSERT INTO Professori VALUES (5, 'Rossi','Daniele', 123456.78, FALSE); 
    -- UniqueViolation: duplicate key value violates unique constraint "professori_nome_key"
    --DETAIL:  Key (nome)=(Daniele) already exists.

    --INSERT INTO Professori VALUES (55555, 'CIaooooooooooooooooooooooooooooooooooooooooooo','Daniele', 123456.78, FALSE); 
    --StringDataRightTruncation: value too long for type character varying(20)

    --INSERT INTO Professori VALUES (5, 'Rossi','Daniele', 1234566.78, FALSE); 
    --NumericValueOutOfRange: numeric field overflow
    --DETAIL:  A field with precision 8, scale 2 must round to an absolute value less than 10^6.

    --INSERT INTO Professori VALUES (5, 'Rossi','Daniele', 123456.78, 3); 
   -- DatatypeMismatch: column "incongedo" is of type boolean but expression is of type integer
    --LINE 2: ...NTO Professori VALUES (5, 'Rossi','Daniele', 123456.78, 3);                                                              ^
    --HINT:  You will need to rewrite or cast the expression.

-- Errori inerenti a UDPATE e DELETE

    --UPDATE Professori SET id = 43000 WHERE id = 54661;
    --ForeignKeyViolation: update or delete on table "professori" violates foreign key constraint "corsi_professore_fkey" on table "corsi"
    --DETAIL:  Key (id)=(54661) is still referenced from table "corsi".

    --DELETE FROM Professori WHERE id = 54661;
    --ForeignKeyViolation: update or delete on table "professori" violates foreign key constraint "corsi_professore_fkey" on table "corsi"
    --DETAIL:  Key (id)=(54661) is still referenced from table "corsi".

    --DELETE FROM Professori WHERE stipendio = 123456.78;
    --ForeignKeyViolation: update or delete on table "professori" violates foreign key constraint "corsi_professore_fkey" on table "corsi"
    --DETAIL:  Key (id)=(54661) is still referenced from table "corsi".
    

-- CODICE

set search_path to "corsi";
CREATE TABLE Professori
        (id  NUMERIC(5) PRIMARY KEY,
        Cognome VARCHAR(20) UNIQUE NOT NULL,
        Nome VARCHAR(20) UNIQUE NOT NULL,
        Stipendio NUMERIC(8,2) DEFAULT 15000,
        InCongedo BOOLEAN DEFAULT FALSE);

CREATE TABLE Corsi 
        (id VARCHAR(10) PRIMARY KEY,
        CorsoDiLaurea VARCHAR(30) NOT NULL,
        Nome VARCHAR(50) NOT NULL,
        Professore NUMERIC(5),
        Attivato BOOLEAN DEFAULT FALSE,
        FOREIGN KEY (Professore) REFERENCES Professori(id));

-- sezione insert Professori
INSERT INTO Professori VALUES (54661, 'Nota','Daniele', 123456.78, FALSE); 
INSERT INTO Professori VALUES (40284, 'Chiola','giovanni', 50000.00, FALSE); 
INSERT INTO Professori VALUES (56805, 'Malchiodi','Riccardo', 123456.79, TRUE); 
INSERT INTO Professori VALUES (52010, 'Sorcinelli','Filippo', 700000.36, TRUE);

-- sezione insert Corsi
INSERT INTO Corsi VALUES('57069', 'Informatica', 'Calculus1', 52010, TRUE);
INSERT INTO Corsi VALUES('72027', 'Informatica', 'Algebra', 56805, TRUE);
INSERT INTO Corsi VALUES('80299', 'Informatica', 'Programmazione', 54661, TRUE);

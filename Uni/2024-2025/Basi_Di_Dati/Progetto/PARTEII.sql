--- Progetto BD 24-25 (12CFU)
--- Numero gruppo 37
--- Nomi e matricole componenti Riccardo Malchiodi s5680500, Andrei Dorin Sandu s6483324, Giulia Ponassi s6145273

--- PARTE 2 
/* il file deve essere file SQL ... cioè formato solo testo e apribili ed eseguibili in pgAdmin */

/*************************************************************************************************************************************************************************/
--1a. Schema
/*************************************************************************************************************************************************************************/

CREATE TABLE Utenti (
  email VARCHAR(255),
  username VARCHAR(100),
  password VARCHAR(100) NOT NULL,
  numeroBaudi INTEGER CHECK (numeroBaudi >= 0),
  PRIMARY KEY (email, username)
);

CREATE TABLE Leghe (
  nome VARCHAR(255) 
  proprietario VARCHAR(255) NOT NULL,
  tipo VARCHAR(50),
  amministratori VARCHAR(255),
  richiesteIscrizione VARCHAR(255),
  classifica VARCHAR(255),
  FOREIGN KEY (proprietario) REFERENCES Utenti(email)
);

CREATE TABLE Squadra (
  nome VARCHAR(255) PRIMARY KEY,
  punteggioFantasanremo INTEGER,
  posizioneCampionatoMondiale INTEGER,
  capitano VARCHAR(100),
  titolari VARCHAR(255),
  riserve VARCHAR(255)
);

CREATE TABLE Crea (
  email_Utenti VARCHAR(255),
  username_Utenti VARCHAR(100),
  nome_Squadra VARCHAR(255),
  dataLimite DATE,
  fasceOrarie VARCHAR(100),
  PRIMARY KEY (email_Utenti, username_Utenti),
  FOREIGN KEY (email_Utenti, username_Utenti) REFERENCES Utenti(email, username),
  FOREIGN KEY (nome_Squadra) REFERENCES Squadra(nome)
);

CREATE TABLE Partecipazione (
  nome_Squadra VARCHAR(255),
  nome_Leghe VARCHAR(255),
  PRIMARY KEY (nome_Squadra, nome_Leghe),
  FOREIGN KEY (nome_Squadra) REFERENCES Squadra(nome),
  FOREIGN KEY (nome_Leghe) REFERENCES Leghe(nome)
);

CREATE TABLE Punteggio (
  ID SERIAL PRIMARY KEY,
  tipo VARCHAR(50)
);

CREATE TABLE Riceve (
  id_Punteggio INTEGER,
  nome_Squadra VARCHAR(255),
  PRIMARY KEY (id_Punteggio, nome_Squadra),
  FOREIGN KEY (id_Punteggio) REFERENCES Punteggio(ID),
  FOREIGN KEY (nome_Squadra) REFERENCES Squadra(nome)
);

CREATE TABLE Artista (
  nome VARCHAR(255) PRIMARY KEY,
  genereMusicale VARCHAR(50),
  provenienza VARCHAR(100),
  mediaVoto FLOAT,
  biografia VARCHAR(500),
  posizioneClassificaFestival INTEGER
);

CREATE TABLE PartecipazioniPassate (
  nome_Artista VARCHAR(255),
  edizione CHAR(4),
  posizioneInClassifica INTEGER,
  PRIMARY KEY (nome_Artista),
  FOREIGN KEY (nome_Artista) REFERENCES Artista(nome)
);

CREATE TABLE GeneratoDa (
  id_Punteggio INTEGER,
  nome_Artista VARCHAR(255),
  PRIMARY KEY (id_Punteggio, nome_Artista),
  FOREIGN KEY (id_Punteggio) REFERENCES Punteggio(ID),
  FOREIGN KEY (nome_Artista) REFERENCES Artista(nome)
);

CREATE TABLE Serata (
  dataS DATE PRIMARY KEY,
  ordineEsibizione INTEGER
);

CREATE TABLE Esibizione (
  data_Serata DATE,
  orario VARCHAR(10),
  PRIMARY KEY (data_Serata, orario),
  FOREIGN KEY (data_Serata) REFERENCES Serata(dataS)
);

CREATE TABLE Partecipa (
  data_Serata DATE,
  nome_Artista VARCHAR(255),
  PRIMARY KEY (data_Serata, nome_Artista),
  FOREIGN KEY (data_Serata) REFERENCES Serata(dataS),
  FOREIGN KEY (nome_Artista) REFERENCES Artista(nome)
);

CREATE TABLE Compositore (
  nome VARCHAR(255) PRIMARY KEY
);

CREATE TABLE Brano (
  titolo VARCHAR(255),
  autore VARCHAR(255),
  durata INTEGER,
  genereMusicale VARCHAR(50),
  PRIMARY KEY (autore, titolo),
  FOREIGN KEY (autore) REFERENCES Artista(nome)
);

CREATE TABLE Compone (
  nome_Compositore VARCHAR(255),
  titolo_Brano VARCHAR(255),
  PRIMARY KEY (nome_Compositore, titolo_Brano),
  FOREIGN KEY (nome_Compositore) REFERENCES Compositore(nome),
  FOREIGN KEY (titolo_Brano) REFERENCES Brano(titolo)
);

CREATE TABLE Cantato (
  nome_Artista VARCHAR(255),
  titolo_Brano VARCHAR(255),
  data_Serata DATE,
  orario VARCHAR(10),
  PRIMARY KEY (nome_Artista, titolo_Brano, data_Serata, orario),
  FOREIGN KEY (nome_Artista) REFERENCES Artista(nome),
  FOREIGN KEY (titolo_Brano) REFERENCES Brano(titolo),
  FOREIGN KEY (data_Serata, orario) REFERENCES Esibizione(data_Serata, orario)
);


/*************************************************************************************************************************************************************************/ 
--1b. Popolamento 
/*************************************************************************************************************************************************************************/ 

CREATE OR REPLACE VIEW VistaStatisticheLeghe AS
SELECT 
  L.nome AS nome_lega,
  L.proprietario,
  COUNT(DISTINCT P.nome_Squadra) AS numero_squadre,
  AVG(S.punteggioFantasanremo) AS media_punteggio_squadre,
  MAX(S.punteggioFantasanremo) AS punteggio_massimo,
  MIN(S.punteggioFantasanremo) AS punteggio_minimo
FROM 
  Leghe L
  JOIN Partecipazione P ON L.nome = P.nome_Leghe
  JOIN Squadra S ON P.nome_Squadra = S.nome
GROUP BY 
  L.nome, L.proprietario;


/*************************************************************************************************************************************************************************/ 
--2. Vista
/* Creare una vista che mostri, per ogni artista, il numero totale di brani che ha cantato, la durata media dei brani cantati 
e il punteggio totale ricevuto dalla squadra che ha schierato quei brani nelle esibizioni. */
/*************************************************************************************************************************************************************************/ 

CREATE OR REPLACE VIEW VistaStatisticheArtisti AS
SELECT
  A.nome AS nome_artista,
  COUNT(DISTINCT C.titolo_Brano) AS numero_brani_cantati,
  AVG(B.durata) AS durata_media_brani,
  SUM(P.id) AS punteggio_totale
FROM
  Artista A
  JOIN Cantato C ON A.nome = C.nome_Artista
  JOIN Brano B ON C.titolo_Brano = B.titolo AND B.autore = A.nome
  LEFT JOIN GeneratoDa G ON B.titolo = G.nome_Artista AND G.nome_Artista = A.nome
  LEFT JOIN Punteggio P ON G.id_Punteggio = P.ID
GROUP BY
  A.nome;

/*************************************************************************************************************************************************************************/ 
--3. Interrogazioni
/*************************************************************************************************************************************************************************/ 

/*************************************************************************************************************************************************************************/ 
/* 3a (interrogazione con operazione insiemistica)															 */
/* Elencare i nomi delle squadre che partecipano ad almeno una lega, oppure che hanno creato una formazione, anche se non partecipano a nessuna lega. */                                                            */
/*************************************************************************************************************************************************************************/ 

SELECT nome_Squadra
FROM Partecipazione

UNION

SELECT nome_Squadra
FROM Crea;



/*************************************************************************************************************************************************************************/ 
/* 3b (interrogazione di divisione)                                                                                                                                      */
/* Trovare i nomi delle squadre che hanno partecipato a tutte le leghe presenti nel sistema.                                                                   */
/*************************************************************************************************************************************************************************/ 

SELECT S.nome
FROM Squadra S
WHERE NOT EXISTS (
  SELECT L.nome
  FROM Leghe L
  EXCEPT
  SELECT P.nome_Leghe
  FROM Partecipazione P
  WHERE P.nome_Squadra = S.nome
);

/*************************************************************************************************************************************************************************/ 
/* 3b (interrogazione con sottointerrogazione correlata)                                                                                                                 */
/* Elencare i nomi delle squadre il cui punteggio Fantasanremo è superiore alla media dei punteggi di tutte le squadre.                                                               */
/*************************************************************************************************************************************************************************/ 

SELECT nome
FROM Squadra S
WHERE S.punteggioFantasanremo > (
  SELECT AVG(S2.punteggioFantasanremo)
  FROM Squadra S2
);

/*************************************************************************************************************************************************************************/ 
--4. Funzioni
/*************************************************************************************************************************************************************************/ 

/*************************************************************************************************************************************************************************/ 
/* 4a: operazione di inserimento non banale, effettuando tutti gli opportuni controlli e calcoli di dati derivati.                                                       */
/* inserire una nuova squadra solo se: il nome non esiste già nella tabella Squadra e il capitano è presente nella tabella Artista.                                                           */
/*************************************************************************************************************************************************************************/ 

CREATE OR REPLACE FUNCTION InserisciSquadra_Condizionale(
  p_nome VARCHAR,
  p_punteggioFantasanremo INTEGER,
  p_posizioneCampionatoMondiale INTEGER,
  p_capitano VARCHAR
) RETURNS VOID AS $$
BEGIN
  -- Inserisce solo se: il capitano esiste E il nome squadra non esiste già
  INSERT INTO Squadra(nome, punteggioFantasanremo, posizioneCampionatoMondiale, capitano, titolari, riserve)
  SELECT p_nome, p_punteggioFantasanremo, p_posizioneCampionatoMondiale, p_capitano, '', ''
  WHERE EXISTS (
    SELECT 1 FROM Artista WHERE nome = p_capitano
  ) AND NOT EXISTS (
    SELECT 1 FROM Squadra WHERE nome = p_nome
  );
END;
$$ LANGUAGE plpgsql;

/************************************************************************************************************************************************************************************/ 
/* 4b: calcolo di un’informazione derivata rilevante e non banale, che richieda l’accesso a diverse tabelle e un’aggregazione                                            */
/* Funzione che calcola il numero di leghe a cui partecipa una squadra.                                                             */
/************************************************************************************************************************************************************************************/ 

CREATE OR REPLACE FUNCTION ContaLegheSquadra(p_nome_squadra VARCHAR)
RETURNS INTEGER AS
$$
BEGIN
  RETURN (
    SELECT COUNT(*)
    FROM Partecipazione
    WHERE nome_Squadra = p_nome_squadra
  );
END;
$$ LANGUAGE plpgsql;

/*************************************************************************************************************************************************************************/ 
--5. Trigger
/*************************************************************************************************************************************************************************/ 

/*************************************************************************************************************************************************************************/ 
/* 5a: trigger per la verifica di un vincolo che non sia implementabile come vincolo CHECK                                                                               */                                                                          
/* Non è permesso a un utente (identificato da email e username) creare più di 3 squadre tramite la tabella Crea.                                                                        */
/*************************************************************************************************************************************************************************/ 

CREATE OR REPLACE FUNCTION limite_creazione_squadre()
RETURNS TRIGGER AS
$$
BEGIN
  IF (SELECT COUNT(*) FROM Crea
      WHERE email_Utenti = NEW.email_Utenti
        AND username_Utenti = NEW.username_Utenti) >= 3 THEN
    RETURN NULL;
  END IF;

  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_limite_squadre
BEFORE INSERT ON Crea
FOR EACH ROW
EXECUTE FUNCTION limite_creazione_squadre();


/*************************************************************************************************************************************************************************/ 
/* 5b: trigger per il mantenimento di informazione derivata o per l'implementazione di una regola di dominio                                                             */                                                                          
/*  Ogni volta che viene inserito un punteggio per una squadra (cioè una riga nella tabella Riceve), aggiorna il campo punteggioFantasanremo della squadra corrispondente,
 sommando il valore del punteggio inserito                                                                                           */
/*************************************************************************************************************************************************************************/ 

CREATE OR REPLACE FUNCTION aggiorna_punteggio_squadra()
RETURNS TRIGGER AS
$$
BEGIN
  UPDATE Squadra
  SET punteggioFantasanremo = punteggioFantasanremo + (
    SELECT ID FROM Punteggio WHERE ID = NEW.id_Punteggio
  )
  WHERE nome = NEW.nome_Squadra;

  RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_aggiorna_punteggio
AFTER INSERT ON Riceve
FOR EACH ROW
EXECUTE FUNCTION aggiorna_punteggio_squadra();




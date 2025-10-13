--- Progetto BD 24-25 (12 CFU)
--- Numero gruppo: 37
--- Nomi e matricole componenti: Riccardo Malchiodi s5680500, Andrei Dorin Sandu s6483324, Giulia Ponassi s6145273


--- PARTE III 
/* il file deve essere file SQL ... cio� formato solo testo e apribili ed eseguibili in pgAdmin */



/*************************************************************************************************************************************************************************/ 
--1b. Schema per popolamento in the large
/*************************************************************************************************************************************************************************/ 


/* per ogni relazione R coinvolta nel carico di lavoro, inserire qui i comandi SQL per creare una nuova relazione R_CL con schema equivalente a R ma senza vincoli di chiave primaria, secondaria o esterna e con eventuali attributi dummy */
CREATE TABLE Utenti_CL (
  email VARCHAR(255),
  username VARCHAR(100),
  password VARCHAR(100),
  numeroBaudi INTEGER
);

CREATE TABLE Squadra_CL (
  nome VARCHAR(255),
  punteggioFantasanremo INTEGER,
  posizioneCampionatoMondiale INTEGER,
  capitano VARCHAR(100),
  titolari VARCHAR(255),
  riserve VARCHAR(255)
);

CREATE TABLE Crea_CL (
  email_Utenti VARCHAR(255),
  username_Utenti VARCHAR(100),
  nome_Squadra VARCHAR(255),
  dataLimite DATE,
  fasceOrarie VARCHAR(100)
);

/*************************************************************************************************************************************************************************/
--1c. Carico di lavoro
/*************************************************************************************************************************************************************************/ 


/*************************************************************************************************************************************************************************/ 
/* Q1: Query con singola selezione e nessun join */
/*************************************************************************************************************************************************************************/ 


/* inserire qui i comandi SQL per la creazione della query, in modo da visualizzarne piane di esecuzione e tempi di esecuzione */ 
EXPLAIN ANALYZE 
SELECT * FROM Squadra_CL WHERE posizioneCampionatoMondiale = 1


/*************************************************************************************************************************************************************************/ 
/* Q2: Query con condizione di selezione complessa e nessun join */
/*************************************************************************************************************************************************************************/ 


/* inserire qui i comandi SQL per la creazione della query, in modo da visualizzarne piane di esecuzione e tempi di esecuzion */ 
EXPLAIN ANALYZE 
SELECT * FROM Utenti_CL WHERE numeroBaudi > 5 AND username LIKE 'A%';

/*************************************************************************************************************************************************************************/ 
/* Q3: Query con almeno un join e almeno una condizione di selezione */
/*************************************************************************************************************************************************************************/ 


/* inserire qui i comandi SQL per la creazione della query, in modo da visualizzarne piane di esecuzione e tempi di esecuzione */ 
EXPLAIN ANALYZE 
SELECT u.email, s.nome, s.punteggioFantasanremo
FROM Utenti_CL u
JOIN Crea_CL c ON u.email = c.email_Utenti
JOIN Squadra_CL s ON c.nome_Squadra = s.nome
WHERE s.punteggioFantasanremo > 50;




/*************************************************************************************************************************************************************************/
--1e. Schema fisico
/*************************************************************************************************************************************************************************/ 


/* inserire qui i comandi SQL per cancellare tutti gli indici gi� esistenti per le tabelle coinvolte nel carico di lavoro */
DROP INDEX IF EXISTS idx_posizione;
DROP INDEX IF EXISTS idx_username_baudi;
DROP INDEX IF EXISTS idx_email_squadra;
DROP INDEX IF EXISTS idx_squadra_nome;

/* inserire qui i comandi SQL perla creazione dello schema fisico della base di dati in accordo al risultato della fase di progettazione fisica per il carico di lavoro. */
CREATE INDEX idx_posizione ON Squadra_CL(posizioneCampionatoMondiale);
CREATE INDEX idx_username_baudi ON Utenti_CL(numeroBaudi, username);
CREATE INDEX idx_email_squadra ON Crea_CL(email_Utenti);
CREATE INDEX idx_squadra_nome ON Squadra_CL(nome);





/*************************************************************************************************************************************************************************/ 
--2. Controllo dell'accesso 
/*************************************************************************************************************************************************************************/ 

/* inserire qui i comandi SQL per la definizione della politica di controllo dell'accesso della base di dati  (definizione ruoli, gerarchia, definizione utenti, assegnazione privilegi) in modo che, dopo l'esecuzione di questi comandi, 
le operazioni corrispondenti ai privilegi delegati ai ruoli e agli utenti sia correttamente eseguibili. */

-- Ruoli
CREATE ROLE amministratore_fantasanremo;
CREATE ROLE utente_premium;
CREATE ROLE amministratore_lega;
CREATE ROLE proprietario_lega;

-- Gerarchia
GRANT amministratore_lega TO amministratore_fantasanremo;
GRANT proprietario_lega TO amministratore_lega;
GRANT utente_premium TO proprietario_lega;

-- Utente d'esempio
CREATE USER riccardo WITH PASSWORD 'password';
GRANT amministratore_fantasanremo TO riccardo;

-- Privilegi specifici (esempi)
GRANT SELECT, INSERT, UPDATE ON Utenti TO utente_premium;
GRANT SELECT, INSERT, UPDATE ON Squadra TO amministratore_lega;
GRANT ALL PRIVILEGES ON Crea TO amministratore_fantasanremo;
GRANT INSERT ON Crea TO proprietario_lega;

/* il codice mostrato sopra (il punto 2 ovvero il controllo dell'accesso) ci da solo piccoli problemi riguardo alcuni permessi in quanto non siamo super user. Abbiamo
provato a chiedere a chatGPT e ci ha consigliato di modificare quest'ultima parte. Alleghiamo il codice:


-- Crea i ruoli solo se non esistono (evita quelli che danno errore)
DO $$
BEGIN
  IF NOT EXISTS (SELECT FROM pg_roles WHERE rolname = 'utente_premium') THEN
    CREATE ROLE utente_premium;
  END IF;
END $$;

-- Crea l'utente solo se non esiste
DO $$
BEGIN
  IF NOT EXISTS (SELECT FROM pg_roles WHERE rolname = 'riccardo') THEN
    CREATE USER riccardo WITH PASSWORD 'password';
  END IF;
END $$;

-- Assegna ruolo all'utente
GRANT utente_premium TO riccardo;

-- Assegna privilegi diretti al ruolo
GRANT SELECT, INSERT, UPDATE ON Utenti_CL TO utente_premium;
GRANT SELECT, INSERT, UPDATE ON Squadra_CL TO utente_premium;
GRANT SELECT, INSERT, UPDATE ON Crea_CL TO utente_premium;


*/








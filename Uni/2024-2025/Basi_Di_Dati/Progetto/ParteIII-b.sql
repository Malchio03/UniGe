--- Progetto BD 24-25 (12 CFU)
--- Numero gruppo: 37
--- Nomi e matricole componenti: Riccardo Malchiodi s5680500, Andrei Dorin Sandu s6483324, Giulia Ponassi s6145273

--- PARTE III 
/* il file deve essere file SQL ... cio� formato solo testo e apribili ed eseguibili in pgAdmin */





/*************************************************************************************************************************************************************************/ 
--1f. Popolamento in the large
/*************************************************************************************************************************************************************************/ 


/* inserire qui i comandi SQL per il popolamento 'in the large' delle relazioni coinvolte nel carico di lavoro  */

-- Popolamento della tabella Utenti_CL
INSERT INTO Utenti_CL VALUES
('anna@email.com', 'Anna03', 'password1', 3),
('luca@email.com', 'Luca04', 'password2', 10),
('giorgio@email.com', 'GioR', 'password3', 7),
('marta@email.com', 'Marta01', 'password4', 1),
('alessio@email.com', 'Alessio99', 'password5', 12),
('giulia@email.com', 'GiulyPony', 'password6', 4),
('andrei@email.com', 'Andrei03', 'password7', 0),
('chiola@email.com', 'ChiolaX', 'password8', 8),
('alice@email.com', 'Alice45', 'password9', 9),
('malchio@email.com', 'Malchio03', 'password10', 6);

-- Popolamento della tabella Squadra_CL
INSERT INTO Squadra_CL VALUES
('I Baudi Volanti', 65, 1, 'Malchio03', 'Malchio03, Andrei03', 'GiulyPony'),
('The Best', 40, 4, 'Marta01', 'Marta01, GiulyPony', 'Alice45'),
('Musica Libera', 55, 2, 'GioR', 'GioR, Alessio99', 'Marta01'),
('I TCP', 33, 5, 'ChiolaX', 'ChiolaX, Anna03', 'Luca04'),
('Sanremo Stars', 72, 3, 'Alessio99', 'Alessio99, Alice45', 'Marta01'),
('Note Ribelli', 25, 6, 'Andrei03', 'Andrei03, ChiolaX', 'GioR'),
('Gli Ultimi', 10, 8, 'Anna03', 'Anna03, Luca04', 'Alessio99'),
('I Fantastici 4', 50, 7, 'GiulyPony', 'GiulyPony, Anna03', 'Malchio03');

-- Popolamento della tabella Crea_CL
INSERT INTO Crea_CL VALUES
('luca@email.com', 'Luca04', 'I Baudi Volanti', '2025-01-10', 'Mattina'),
('marta@email.com', 'Marta01', 'The Best', '2025-01-11', 'Pomeriggio'),
('giorgio@email.com', 'GioR', 'Musica Libera', '2025-01-09', 'Sera'),
('chiola@email.com', 'ChiolaX', 'I TCP', '2025-01-12', 'Mattina'),
('giulia@email.com', 'GiulyPony', 'Sanremo Stars', '2025-01-10', 'Pomeriggio'),
('andrei@email.com', 'Andrei03', 'Note Ribelli', '2025-01-10', 'Sera'),
('anna@email.com', 'Anna03', 'Gli Ultimi', '2025-01-11', 'Sera'),
('giulia@email.com', 'GiulyPony', 'I Fantastici 4', '2025-01-12', 'Pomeriggio'),
('alice@email.com', 'Alice45', 'Sanremo Stars', '2025-01-09', 'Mattina'),
('alessio@email.com', 'Alessio99', 'The Best', '2025-01-08', 'Sera'),
('malchio@email.com', 'Malchio03', 'I Baudi Volanti', '2025-01-10', 'Mattina'),
('chiola@email.com', 'ChiolaX', 'Note Ribelli', '2025-01-11', 'Pomeriggio');

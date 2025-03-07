% Dati
nodi = 11; 
A = zeros(nodi);

% --- Parte (a) ---


% Tutti collegamenti di ciascun nodo


% 1

A(2,1) = 1;
A(7,1) = 1;
A(3,1) = 1;
A(4,1) = 1;
A(5,1) = 1;
A(6,1) = 1;

% 2

A(1,2) = 1;

% 3

A(1, 3) = 1;
A(10, 3) = 1;

% 4

A(10, 4) = 1;
A(5, 4) = 1;
A(1, 4) = 1;

% 5 

A(4,5) = 1;
A(1, 5) = 1;
A(6, 5) = 1;
A(8, 5) = 1;

% 6

A(8, 6) = 1;
A(5, 6) = 1;
A(1, 6) = 1;

% 7 

A(1, 7) = 1;

% 8 

A(9,8) = 1;
A(6,8) = 1;
A(5, 8) = 1;

% 9 

A(8, 9) = 1;

% 10

A(11 , 10) = 1;
A(4, 10) = 1;
A(3, 10) = 1;

% 11

A(10, 11) = 1;

% --- Parte (b) ---


D = diag([6 1 2 3 4 3 1 3 1 3 1]);  

G = A * (D^-1);

% Calcolo degli autovalori e autovettori
[autovettori, autovalori] = eig(G);

autovalori_diagonale = diag(autovalori);

disp(autovalori_diagonale);














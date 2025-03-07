% Dati
d0 = 4; 
d1 = 2; 

% Calcolo di n
n = 10 * (d1 + 1) + d0;

% Dichiarazione Matrici
A = diag(ones(1, n-1), 1) + eye(n);

E = zeros(n);
E(n, 1) = 2^(-n);   

B = A + E;


% --- Parte (a) ---


% Calcolo degli autovalori
VA = eig(A); 
VB = eig(B);

disp("parte a");

% Confronto puntuale
puntuale_diff = abs(VA - VB); % Differenza assoluta tra autovalori
disp('Stampa confronto puntuale: ')
disp(puntuale_diff);

% Confronta con norma
norma1 = norm(B - A) / norm(A); % facciamo riferimento al testo dell'esercizio
norma2 = norm(VB - VA) / norm(VA); % facciamo riferimento al testo dell'esercizio

%disp(['Risultato norma di "norm(B - A)/norm(A)": ', num2str(norma1)]);
%disp(['Risultato norma di "norm(VB - VA)/norm(VA)": ', num2str(norma2)]);

% --- Parte (b) ---

disp("parte b");

% Calcolo delle trasposte 
ATA = transpose(A) * A;
BTB = transpose(B) * B;

% Calcolo degli autovalori
VATA = eig(ATA); 
VBTB = eig(BTB);

% Confronto puntuale
puntuale_diff_2 = abs(VATA - VBTB); % Differenza assoluta tra autovalori

%disp('Stampa confronto puntuale: ')
%disp(puntuale_diff_2);


% Confronta con norma
norma3=norm(BTB - ATA) / norm(ATA); % facciamo riferimento al testo dell'esercizio
norma4=norm(VBTB - VATA) / norm(VATA); % facciamo riferimento al testo dell'esercizio

%disp(['Risultato norma di "norm(BTB - ATA)/norm(ATA)": ', num2str(norma3)]);
%disp(['Risultato norma di "norm(VBTB-VATA)/norm(VATA)": ', num2str(norma4)]);


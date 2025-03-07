% Dati
d0 = 4; 
d1 = 2; 

m = 10 * (d0 + 1) + d1;

% Matrice A
A = zeros(m, 3); 
for i = 1:m
    A(i, 1) = 1;         
    A(i, 2) = i / m;     
    A(i, 3) = (i / m)^2;  
end


% --- Parte (a) ---

% Decomposizione SVD di A, S sarebbe sigma
[U, S, V] = svd(A);

% Decomposizione SVD di A^T
[UT, ST, VT] = svd(A');

disp("Valori singolari di A:");
disp(diag(S));

disp("Valori singolari di AT:");
disp(diag(ST));

% Verifica che l'espressione A = USVT sia verificata
A_ricostruita = U * S * V';  % Ricostruzione di A

% --- Parte (b) ---

% Matrici AAt e AtA
AAt = A * A';  
AtA = A' * A;  

% Calcolo degli autovalori
eig_AAt = eig(AAt);  % Autovalori di A A^T
eig_AtA = eig(AtA);  % Autovalori di A^T A

disp("Autovalori di AAT");
disp(eig_AAt);

disp("Autovalori di ATA");
disp(eig_AtA);

% --- Parte (c) ---

% Base ortonormale dell'immagine di A e A^T
ImA = orth(A);       
ImAT = orth(A');     

disp("ImA ");
disp(ImA);

disp("ImAT ");
disp(ImAT);

% --- Parte (d) ---

% calcolo nucleo
KerA = null(A);
KerAT = null(A');

disp("Ker di A")
disp(KerA);


disp("Ker di A")
disp(KerAT)
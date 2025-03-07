for n = 1:5  % Itera su valori di n crescenti
    % Costruzione della matrice B
    B = zeros(n);
    for i = 1:n
        for j = 1:n
            if i == j
                B(i, j) = 1;
            elseif i < j
                B(i, j) = -1;
            end
        end
    end
    
    % Calcolo e visualizzazione
    fprintf('Matrice B per n = %d:\n', n);
    disp(B);
    
    % Calcolo della matrice B'B e SVD
    BTB = B' * B;
    [U, S, V] = svd(B);

    % --- Parte (a) ---
    
    % Valori singolari
    disp("Valori singolari di B:");
    disp(diag(S));


    % --- Parte (b) ---

    % Estrazione dei valori singolari
    valori_singolari = diag(S);
    disp("Condizionamento in norma 2");
    disp(cond(B,2));


end

    % --- Parte (c) ---

    % Perturbazione dell'elemento bn,1
    perturbazione = 10^(-2 - n); 
    B(n, 1) = B(n, 1) + perturbazione;

    % Visualizzazione della matrice perturbata
    fprintf('Matrice B perturbata per n = %d:\n', n);
    disp(B);
    
    % Calcolo degli autovalori della matrice perturbata
    autovalori = eig(B);
    
    % Visualizzazione degli autovalori
    fprintf("Autovalori di B perturbata:\n");
    disp(autovalori);
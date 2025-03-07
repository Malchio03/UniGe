clear

% --- Parte (a) ---

A = [1, -1, 2; -2, 0, 5; 6, -3, 6];

% Vettori iniziali
v1 = [1; 1; 1];
v2 = [3; 10; 4];

% Parametri di convergenza
tolerance = 1e-6; 
max_iter = 1000;  

% Metodo delle potenze con il primo vettore iniziale
[autovalore_1, autovettore_1, iter_1] = power_method(A, v1, tolerance, max_iter);

% Metodo delle potenze con il secondo vettore iniziale
[autovalore_2, autovettore_2, iter_2] = power_method(A, v2, tolerance, max_iter);

% Funzione del metodo delle potenze
function [lambda, x, iter] = power_method(A, v, tol, max_iter)
    x = v / norm(v); % Normalizza il vettore iniziale
    lambda_old = 0;  % Inizializza il vecchio autovalore
    for iter = 1:max_iter
        v_next = A * x;      % Moltiplica la matrice per il vettore corrente
        lambda = (x' * v_next) / (x' * x); % Stima dell'autovalore
        x_next = v_next / norm(v_next);    % Normalizza il nuovo vettore
        if abs(lambda - lambda_old) < tol  % Controlla la convergenza dell'autovalore
            break;
        end
        x = x_next;
        lambda_old = lambda;
    end
end

% --- Parte (b) ---

% Stima iniziale dell'autovalore
mu = 10;

% Metodo delle potenze inverse con il primo vettore iniziale
[lambda_inv, autovettore_inv, iter_inv] = inverse_power_method(A, v1, mu, tolerance, max_iter);

% Funzione del metodo delle potenze inverse
function [lambda, x, iter] = inverse_power_method(A, v, mu, tol, max_iter)
    n = size(A, 1);
    I = eye(n);         % Matrice identità
    x = v / norm(v);    % Normalizza il vettore iniziale
    lambda_old = mu;    % Inizializza l'autovalore
    
    for iter = 1:max_iter
        % Risolvi il sistema lineare (A - mu*I) * y = x
        y = (A - mu * I) \ x;
        
        % Normalizza y per ottenere il nuovo vettore
        x_next = y / norm(y);
        
        % Stima dell'autovalore
        lambda = mu + (x_next' * A * x_next) / (x_next' * x_next);
        
        % Controllo della convergenza
        if abs(lambda - lambda_old) < tol
            break;
        end
        
        x = x_next;
        lambda_old = lambda;
    end
    
    x = x_next; % Autovettore finale normalizzato
end

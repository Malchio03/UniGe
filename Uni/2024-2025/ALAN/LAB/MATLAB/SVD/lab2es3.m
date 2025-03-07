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

% Vettore y
y = zeros(m, 1); 
for i = 1:m
    y(i) = sin(2 * pi * (i / m)); 
end

% --- Parte (a) ---
[U, S, V] = svd(A);
c_svd = V * (S \ (U' * y)); 

% --- Parte (b) ---
[Q, R] = qr(A);
c_qr = R \ (Q' * y);

% --- Parte (c) ---
c_normali = (A' * A) \ (A' * y); 

% --- Parte (d) ---
c_direct = A \ y; 

fprintf('Soluzione SVD:\n');
disp(c_svd);

fprintf('Soluzione QR:\n');
disp(c_qr);

fprintf('Soluzione Equazioni Normali:\n');
disp(c_normali);

fprintf('Soluzione Diretta:\n');
disp(c_direct);


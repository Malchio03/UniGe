(****************************************************************)
                        (*Esercizio 1*)
(****************************************************************)
let catAll ls =
    let rec loop acc = function
            | hd :: tl -> loop (acc + hd) tl
            | [] -> acc //caso lista vuota, restituisco accumulatore
            
    loop "" ls //inizializzo l'accumulatore con stringa vuota e inizio ricorsione

assert (catAll ("This" :: " is " :: "awesome!"::[]) = "This is awesome!")

(****************************************************************)
                        (*Esercizio 2*)
(****************************************************************)
let catAllFold ls =
    List.fold (fun acc elem -> acc + elem) "" ls

assert (catAllFold ("This" :: " is " :: "awesome!"::[]) = "This is awesome!")

(****************************************************************)
                        (*Esercizio 3*)
(****************************************************************)
let zip ls1 ls2 =
    let rec loop acc ls1 ls2 = 
        match ls1, ls2 with
        | hd1 :: tl1 , hd2 :: tl2 -> loop ((hd1, hd2) :: acc) tl1 tl2 //CASO COMUNE: richiamo loop aggiornando l'accumulatore e passando come liste tl1 e tl2
        | [], [] -> acc //caso base: o liste vuote a rrivato alla fine, restituisco acc
        | hd1 :: tl1 , [] -> failwith "different lenght" //caso negativo: size.ls1>size.ls2
        | [] , hd2 ::tl2 -> failwith "different lenght" //caso negativo: size.ls2>size.ls1
    //  | _ -> failwith "different lenght" //riassume entrambi i casi negativi in una sola linea di codice
     
    loop [] ls1 ls2

assert (zip [] [] = [])

assert (zip (1 :: 2 :: 3 :: []) ("a" :: "b" :: "c" :: []) = (1, "a") :: (2, "b") :: (3, "c") :: [])

assert
 ((try
     zip (1 :: 2 :: []) ("a" :: "b" :: "c" :: [])
   with
   | Failure "different length" -> []) = [])

(****************************************************************)
                        (*Esercizio 4*)
(****************************************************************)
let minEl l =
    let rec aux l acc =
        match l with
        | [] -> Some acc                   // Caso base: ritorna il minimo trovato
        | head::tail -> aux tail (min head acc)      // Continua la ricerca del minimo
    match l with
    | [] -> None                           // Caso lista vuota: ritorna None
    | head::tail -> aux tail head                    // Inizia con il primo elemento come accumulatore

assert (minEl [] = None)
assert (minEl (3 :: 4 :: 6 :: -1 :: []) = Some -1)
assert (minEl ("orange" :: "apple" :: "banana" :: []) = Some "apple")

(****************************************************************)
                        (*Esercizio 5*)
(****************************************************************)

let minElFold list =
    match list with
    | [] -> None                               // Caso lista vuota: ritorna None
    | head::tail -> Some (List.fold min head tail)       // Usa List.fold per trovare il minimo

assert (minElFold [3; 4; 6; -1] = Some -1)

(****************************************************************)
                        (*Esercizio 6*)
(****************************************************************)

type direction = 
    | North 
    | East 
    | South 
    | West

(****************************************************************)
                        (*Esercizio 7*)
(****************************************************************)
let versor direction = 
    match direction with
    | North -> (0, 1)
    | East -> (1, 0)
    | South -> (0, -1)
    | West -> (-1, 0)

assert (versor North = (0, 1))
assert (versor East = (1, 0))
assert (versor South = (0, -1))
assert (versor West = (-1, 0))

(****************************************************************)
                        (*Esercizio 8*)
(****************************************************************)

type action = 
    | Turn of direction 
    | Step of int

(****************************************************************)
                        (*Esercizio 9*)
(****************************************************************)

// funzioni ausiliarie 

let scalar k (x, y) = (k * x, k * y)

let add (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)

// dir = direzione corrente
// (x, y) = posizione 
// action = l’azione da eseguire (Turn o Step, definiti nel type)
let move (dir, (x, y)) action =
    match action with

    // Se action è Turn, aggiorna la direzione a newDirection mantenendo la posizione (x, y)
    | Turn newDirection -> (newDirection, (x, y))

    // Se action è Step
    | Step n ->
        // Ottiene il versore vx, vy della direzione corrente chiamando versor dir
        let (vx, vy) = versor dir
        // Calcola il movimento moltiplicando il versore per n usando scalar n (vx, vy)
        let movement = scalar n (vx, vy)
        // Aggiorna la posizione sommandola al movimento calcolato, usando add (x, y) movement
        (dir, add (x, y) movement)

assert (move (North, (0, 0)) (Turn South) = (South, (0, 0)))
assert (move (North, (0, 0)) (Step 2) = (North, (0, 2)))
assert (move (North, (0, 0)) (Step -1) = (North, (0, -1)))
assert (move (North, (0, 0)) (Step 0) = (North, (0, 0)))


(****************************************************************)
                        (*Esercizio 10*)
(****************************************************************)

// List.fold applica in sequenza la funzione move a ciascuna azione presente nella lista actions
// (initialDirection, initialPosition) = stato iniziale
//  actions = lista di azioni da eseguire

let doAll (initialDirection, initialPosition) actions =
    List.fold move (initialDirection, initialPosition) actions
    
assert
(doAll
    (North, (0, 0))
    (Step 2
        :: Turn East
            :: Step 2
            :: Step -1 :: Turn South :: Step 3 :: Step 0 :: []) = (South, (1, -1)))
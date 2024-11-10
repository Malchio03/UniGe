(****************************************************************)
                        (*Esercizio 1*)
(****************************************************************)

let rec mulAll ls =
    match ls with
    | hd :: tl -> hd * mulAll tl 
    | [] -> 1       // caso base, elemento neutro del prodotto

assert (mulAll (2 :: 4 :: 3 :: []) = 24)


(****************************************************************)
                        (*Esercizio 2*)
(****************************************************************)

let isIn el ls =
    let rec isInAux ls = 
        match ls with
        | hd :: tl -> el = hd || isInAux tl
        | [] -> false
    isInAux ls

assert isIn 3 (2 :: 4 :: 3 :: [])
assert not (isIn 5 (2 :: 4 :: 3 :: []))

(****************************************************************)
                        (*Esercizio 3*)
(****************************************************************)

let rec insert el ls = 
    match ls with
    | hd :: tl ->
        if hd = el then ls  else hd :: insert el tl
    | [] -> [el]    // caso lista vuota

assert (insert 0 (2 :: 4 :: 3 :: []) = 2 :: 4 :: 3 :: 0 :: [])
assert (insert 3 (2 :: 4 :: 3 :: []) = 2 :: 4 :: 3 :: [])

(****************************************************************)
                        (*Esercizio 4*)
(****************************************************************)

let insert2 el ls =
    let rec aux ls =
        match ls with
        | hd :: tl ->
            if hd = el then ls  else hd :: aux tl
        | [] -> [el]
    aux ls

assert (insert2 0 (2 :: 4 :: 3 :: []) = 2 :: 4 :: 3 :: 0 :: [])
assert (insert2 3 (2 :: 4 :: 3 :: []) = 2 :: 4 :: 3 :: [])

(****************************************************************)
                        (*Esercizio 5*)
(****************************************************************)

let rec odd ls=
    match ls with
    // _ primo elemento della lista 0, che ignoro. quindi l'elemento successivo è 1 (dispari)
    | _ :: el2 :: tl -> el2 :: odd tl
    | _ :: [] -> []         // caso 1 elemento o ultimo elemento con index pari
    | [] -> []

assert (odd (7 :: 3 :: 4 :: 1 :: 2 :: 5 :: []) = 3 :: 1 :: 5 :: [])

(****************************************************************)
                        (*Esercizio 6*)
(****************************************************************)

let rec ordInsert el ls=
    match ls with
    // elemento minore di head -> l'elemento viene inserito davanti al resto della lista
    | hd :: tl -> 
        if el < hd then el :: ls
    // elemento già nella lista -> ritorno la lista, perchè la lista non ha ripetizioni
        elif el = hd then ls        (*elif = else if*)
    // elemento maggiore di head -> ordino tail ricorsivamente
        else hd :: ordInsert el tl 
    | [] -> [el]        // caso lista vuota, inserisco l'elemento 

assert (ordInsert 0 (1 :: 2 :: 4 :: 5 :: []) = 0 :: 1 :: 2 :: 4 :: 5 :: [])
assert (ordInsert 3 (1 :: 2 :: 4 :: 5 :: []) = 1 :: 2 :: 3 :: 4 :: 5 :: [])
assert (ordInsert 7 (1 :: 2 :: 4 :: 5 :: []) = 1 :: 2 :: 4 :: 5 :: 7 :: [])
assert (ordInsert 2 (1 :: 2 :: 4 :: 5 :: []) = 1 :: 2 :: 4 :: 5 :: [])

(****************************************************************)
                        (*Esercizio 7*)
(****************************************************************)

let ordInsert2 el ls =
    let rec auxOrd ls =
        match ls with
        | hd :: tl ->
            if el < hd then el :: ls //aggiunta el in pos
            elif el = hd then ls //caso già presente
            else hd :: auxOrd tl //elem maggiore di head -> ricorsivo
        | [] -> [el] //caso lista vuota, inserisco elem
    auxOrd ls

assert (ordInsert2 0 (1 :: 2 :: 4 :: 5 :: []) = 0 :: 1 :: 2 :: 4 :: 5 :: [])
assert (ordInsert2 3 (1 :: 2 :: 4 :: 5 :: []) = 1 :: 2 :: 3 :: 4 :: 5 :: [])
assert (ordInsert2 7 (1 :: 2 :: 4 :: 5 :: []) = 1 :: 2 :: 4 :: 5 :: 7 :: [])
assert (ordInsert2 2 (1 :: 2 :: 4 :: 5 :: []) = 1 :: 2 :: 4 :: 5 :: [])

(****************************************************************)
                        (*Esercizio 8*)
(****************************************************************)
let rec merge (ls1, ls2) =
    match ls1, ls2 with
    | hd1 :: tl1, hd2 :: tl2 -> //caso hd1 e hd2 da discutere
        if hd1 < hd2 then hd1 :: merge(tl1, ls2) //Caso hd1<hd2, rimane hd1 e rec su tl1 e ls2
        elif hd1 = hd2  then hd1 :: merge(tl1, tl2) //Caso hd1=hd2, rimane hd1 (hd1 o hd2 è uguale) e rec su tl1 e tl2
        else hd2 :: merge(ls1, tl2) //Caso hd1>hd2, rimane hd2 e rec su ls1 e tl2
    | hd1 :: tl1, [] ->  hd1 :: merge(tl1, []) //Caso ls1 con hd1 e ls2=[]
    | [], hd2 :: tl2 -> hd2 :: merge([], tl2) //Caso ls2 con hd2 e ls1=[]
    | [], [] -> [] // Caso ls1=[] e ls2=[]

assert (merge ((1 :: 3 :: 5 :: []), (2 :: 4 :: 6 :: [])) = 1 :: 2 :: 3 :: 4 :: 5 :: 6 :: [])
assert (merge ((1 :: 2 :: 3 :: []), (4 :: 5 :: [])) = 1 :: 2 :: 3 :: 4 :: 5 :: [])
assert (merge ((3 :: []), (1 :: 2 :: 4 :: 5 :: [])) = 1 :: 2 :: 3 :: 4 :: 5 :: [])

(****************************************************************)
                        (*Esercizio 9*)
(****************************************************************)

let rec curriedMerge ls1 ls2 =
    match ls1, ls2 with
    | hd1 :: tl1, hd2 :: tl2 -> //caso hd1 e hd2 da discutere
        if hd1 < hd2 then hd1 :: curriedMerge tl1 ls2 //Caso hd1<hd2, rimane hd1 e rec su tl1 e ls2
        elif hd1 = hd2  then hd1 :: curriedMerge tl1 tl2 //Caso hd1=hd2, rimane hd1 (hd1 o hd2 è uguale) e rec su tl1 e tl2
        else hd2 :: curriedMerge ls1 tl2 //Caso hd1>hd2, rimane hd2 e rec su ls1 e tl2
    | hd1 :: tl1, [] ->  hd1 :: curriedMerge tl1 [] //Caso ls1 con hd1 e ls2=[]
    | [], hd2 :: tl2 -> hd2 :: curriedMerge [] tl2 //Caso ls2 con hd2 e ls1=[]
    | [], [] -> [] // Caso ls1=[] e ls2=[]

assert (curriedMerge (1 :: 3 :: 5 :: []) (2 :: 4 :: 6 :: []) = 1 :: 2 :: 3 :: 4 :: 5 :: 6 :: [])
assert (curriedMerge (1 :: 2 :: 3 :: []) (4 :: 5 :: []) = 1 :: 2 :: 3 :: 4 :: 5 :: [])
assert (curriedMerge (3 :: []) (1 :: 2 :: 4 :: 5 :: []) = 1 :: 2 :: 3 :: 4 :: 5 :: [])

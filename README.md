# Cpp08 - C++ Templates & Containers

Questo progetto è parte del curriculum della scuola 42 e copre concetti avanzati di C++ relativi ai **template di funzione**, ai **contenitori STL** e ai **template di classe**.

## 📋 Struttura del Progetto

Il progetto è suddiviso in tre esercizi progressivi:

### **Ex00: EasyFind**

Una funzione template generica che implementa una ricerca all'interno di contenitori STL.

**Caratteristiche:**
- Template di funzione `easyfind<T>()` che funziona con qualsiasi contenitore STL (vector, list, deque, ecc.)
- Ricerca lineare di un elemento tramite `std::find()`
- Gestione delle eccezioni: lancia `std::runtime_error` se l'elemento non è trovato
- Ritorna un iteratore all'elemento trovato

**File principali:**
- `easyfind.hpp` - Implementazione del template
- `main.cpp` - Esempi di utilizzo con vector e list

**Utilizzo:**
```cpp
std::vector<int> v = {0, 1, 2, 3, 4};
auto it = easyfind(v, 3);  // Trova e ritorna iteratore
```

---

### **Ex01: Span**

Una classe che gestisce un array di numeri interi con limiti di capacità e calcola gli "span" (differenze tra elementi).

**Caratteristiche:**
- Capacità massima definita al momento della creazione
- Metodo `addNumber()` per aggiungere un elemento alla volta
- Metodo `addRange()` per aggiungere elementi in intervalli:
  - Versione con parametri int (da min a max)
  - Versione con iteratori (da begin a end)
- Metodo `shortestSpan()` - Ritorna la differenza minima tra due elementi
- Metodo `longestSpan()` - Ritorna la differenza massima tra due elementi
- Sistema di eccezioni personalizzato con la classe `Error`
- Metodo `printArray()` per visualizzare il contenuto

**File principali:**
- `Span.hpp` - Dichiarazione della classe
- `Span.cpp` - Implementazione dei metodi

**Utilizzo:**
```cpp
Span sp(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

unsigned int shortest = sp.shortestSpan();  // Differenza minima
unsigned int longest = sp.longestSpan();    // Differenza massima
```

---

### **Ex02: MutantStack**

Un template di classe che estende `std::stack` rendendolo iterabile, aggiungendo i metodi di iterazione di un contenitore standard.

**Caratteristiche:**
- Eredita da `std::stack<T>` preservando il comportamento LIFO (Last In First Out)
- Aggiunge iteratori bidirezionali tramite typedef:
  - `iterator` e `reverse_iterator`
  - `const_iterator` e `const_reverse_iterator`
- Implementa 8 metodi di iterazione:
  - `begin()`, `end()`
  - `rbegin()`, `rend()`
  - `cbegin()`, `cend()`
  - `crbegin()`, `crend()`
- Permette di iterare su uno stack come fosse un vector o una list

**File principali:**
- `MutantStack.hpp` - Dichiarazione del template
- `MutantStack.tpp` - Implementazione dei metodi (incluso da .hpp)

**Utilizzo:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);

for (auto it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << std::endl;
```

---

## 🛠️ Compilazione

Ogni esercizio ha il suo `Makefile`:

```bash
cd ex00 && make    # Compila ex00
cd ex01 && make    # Compila ex01
cd ex02 && make    # Compila ex02
```

Puoi anche usare:
```bash
make clean     # Rimuove i file oggetto
make fclean    # Rimuove eseguibili e file oggetto
make re        # Ricompila da zero
```

---

## 🎓 Concetti Chiave

| Concetto | Esercizio | Descrizione |
|----------|-----------|-------------|
| **Templates di funzione** | Ex00 | Genericità a livello di funzione |
| **STL Containers** | Ex00, Ex01 | Utilizzo di vector, list e altri contenitori |
| **Iteratori** | Ex00, Ex02 | Navigazione attraverso contenitori |
| **Classe template** | Ex01, Ex02 | Genericità a livello di classe |
| **Ereditarietà template** | Ex02 | Estensione di template di classe |
| **Gestione eccezioni** | Ex00, Ex01 | Throwable exceptions personalizzate |
| **Template Implementation** | Ex02 | Separazione dichiarazione/implementazione con .tpp |

---

## 📝 Note Implementative

### Ex00
- Utilizza `std::find()` dall'header `<algorithm>`
- Supporta qualsiasi tipo di dato T e qualsiasi contenitore STL
- Lancia eccezione con messaggio descrivivo se l'elemento non è trovato

### Ex01
- La classe `Error` è una custom exception che eredita da `std::exception`
- La capacità `_N` diminuisce ad ogni `addNumber()` aggiunto
- Gli span vengono calcolati su interi non ordinati
- Il metodo di aggiunta con iteratori offre versatilità nella sorgente dei dati

### Ex02
- Il file `MutantStack.tpp` contiene l'implementazione inline dei template
- Gli iteratori permettono di trattare uno stack come un contenitore lineare
- Mantiene la semantica LIFO dello stack pur aggiungendo funzionalità di iterazione

---

## 📚 Risorse Utili

- [cppreference.com - Templates](https://en.cppreference.com/w/cpp/language/templates)
- [cppreference.com - Standard Library Containers](https://en.cppreference.com/w/cpp/container)
- [cppreference.com - Iterators](https://en.cppreference.com/w/cpp/iterator)

---

**Autore:** Livi-maker  
**Repository:** Cpp08  
**Versione:** C++98/C++11

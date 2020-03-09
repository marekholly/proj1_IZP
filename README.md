# Projekt 1 - Práce s textem
### Popis projektu
Cílem projektu je vytvořit program, který by emuloval zjednodušený algoritmus hledání kontaktů zadaných pomocí posloupnosti číslic. Vstupem programu je posloupnost číslic. Výstup programu bude obsahovat seznam kontaktů, které odpovídají zadanému číselnému filtru.

### Detailní specifikace
Program implementujte ve zdrojovém souboru proj1.c. Vstupní data budou čtena ze standardního vstupu (stdin), výstup bude tisknut na standardní výstup (stdout).

## Syntax spuštění
Program se spouští v následující podobě: (./proj1 značí umístění a název programu):
```
./proj1 CISLO
```
CISLO zde představuje hledané kritérium, sekvenci číslic 0 až 9, které reprezentují sekvenci hledaných znaků.

Pokud je program spuštěn bez argumentů, program se bude chovat, jako by hledanému kritériu odpovídal každý kontakt se seznamu.

## Implementační detaily
### Vstupní telefonní seznam
Telefonní seznam jsou ASCII textová data. Každý záznam o kontaktu obsahuje dva řádky: jméno osoby a jeho telefonní číslo. Každý řádek obsahuje maximálně 100 znaků, jinak se jedná o neplatná data. Seznam kontaktů je neuspořádaný. U všech dat nezáleží na velikosti písmen (tzv. case insensitive). Program musí podporovat alespoň 42 kontaktů.

### Kritérium nalezení kontaktu
Pro zjednodušení budeme v tomto projektu uvažovat hledání nepřerušené posloupnosti zadaných znaků/číslic v telefonním kontaktu. Nepřerušenou posloupností znaků se myslí takový podřetězec, u kterého se na každé pozici vyskytuje znak, který odpovídá jednomu ze znaků, které reprezentuje číslice na stejné pozici v zadaném řetězci. Každá číslice kromě sebe sama reprezentuje ještě následující znaky: 2 (abc), 3 (def), 4 (ghi), 5 (jkl), 6 (mno), 7 (pqrs), 8 (tuv), 9 (wxyz), 0 (+).

### Výstup programu
Výstup programu může být dvojího druhu:

* žádný kontakt nenalezen,
* nalezen jeden a více kontaktů.
#### Kontakt nenalezen
```
Not found
```
Pokud v telefonním seznamu neexistuje kontakt, u něhož by nějaká část odpovídala hledanému řetězci CISLO, vytiskne program toto hlášení.

#### Kontakt(y) nalezen(y)
Každý kontakt, který odpovídá hledanému kritériu, program vytiskne na jeden řádek ve formátu JMENO, TELCISLO, kde JMENO je jméno kontaktu z telefonního seznamu a TELCISLO je záznam o telefonním čísle. Program tiskne všechny kontakty, které kritériu odpovídají. Na pořadí řádků nezáleží. Stejně tak nezáleží ani na velikosti písmen.

## Příklady vstupů a výstupů (premiove zadanie!)
Pomocný soubor telefonního seznamu:
```
$ cat seznam.txt
Petr Dvorak
603123456
Jana Novotna
777987654
Bedrich Smetana ml.
541141120
```
Příklad hledání:
```
$ ./proj1 <seznam.txt
Petr Dvorak, 603123456
Jana Novotna, 777987654
Bedrich Smetana ml., 541141120
```
```
$ ./proj1 12 <seznam.txt
Petr Dvorak, 603123456
Bedrich Smetana ml., 541141120
```
```
$ ./proj1 686 <seznam.txt
Jana Novotna, 777987654
Bedrich Smetana ml., 541141120
```
```
$ ./proj1 38 <seznam.txt
Petr Dvorak, 603123456
Bedrich Smetana ml., 541141120
```
```
$ ./proj1 113 <seznam.txt
Not found
```
### Priority funkcionality
1. Vyhledání kontaktů, jejichž telefonní čísla začínají zadaným číslem.
2. Vyhledání kontaktů, jejichž jména začínají znaky, které zadané číslo reprezentuje.
3. (prémiové) Hledání přerušených posloupností znaků. Program najde i takové kontakty, u který mezi každými dvěma nalezenými znaky může být libovolná posloupnost jiných znaků. Důležité je, že nalezený řetězec (jména nebo telefonního čísla) musí obsahovat všechny znaky, které číslovky reprezentují, a ve stejném pořadí.

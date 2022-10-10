# Datasets

Het gedrag en de performantie van een datastructuur is zeer afhankelijk van het soort data die men er aan toevoegt. Om een ijkpunt te hebben, voorzien we een dataset met bestanden die je kan gebruiken om je implementaties mee te testen en te benchmarken.

Je kan deze dataset downloaden en uitpakken met het volgende commando:

```bash
curl https://users.ugent.be/~rbmaerte/ad3/blokgrafen.tar.bz2 | tar xjf -
```

## Inhoud

De bestanden bevatten een verzameling blokgrafen in [graph6](https://users.cecs.anu.edu.au/~bdm/data/formats.txt)-formaat. Elke lijn beschrijft één graaf.

In het bijzonder gaat het hier om blok-circulante Ramsey grafen. Blok-circulant betekent dat de graaf de unie is van enkele circulante grafen van gelijke grootte, die op gepaste manier met elkaar worden verbonden. Twee verschillende blok-circulante grafen die met hetzelfde blok beginnen zullen dus ook vrij veel overlap hebben in hun graph6-string.
Dat het Ramsey grafen zijn betekent dat ze een laag kliekgetal hebben, en tegelijk ook een laag co-kliekgetal. De stelling van Ramsey garandeert dat er zo (voor vaste keuze van kliek- en co-kliekgetal) slechts eindig veel zijn.

## Bestanden schudden

Er is één origineel bestand: `blokgrafen.g6`. Door de manier waarop de grafen gegenereerd worden, lijken opeenvolgende grafen sterk op elkaar. Hierdoor kan jouw implementatie beter (of slechter!) presteren.

Omdat het originele bestand relatief groot is, en we de data graag in willekeurige volgorde willen toevoegen, is het mogelijk om een steekproef uti dit bestand te nemen met het volgende commando:

```bash
 sort -R blokgrafen.txt | head -n 1000 > blokgrafen_tiny.txt
 ```

 Bovenstaand commando selecteert de eerste 1000 grafen uit de geschudde lijst van blokgrafen.

 We voorzien al een aantal geschudde selecties uit het originele bestand. Zo kan je de performantie uit die bestanden ook onderling vergelijken.


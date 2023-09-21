# 2nd

## számok sorban

```PsudoCode
Ciklus i = 1től 10ig
    Leírom hogy {i}, új sor
    Vége
```

```PsudoCode
Gondolom az 1es számot
Leírom a gondolt számot
Megnövelem a számot
Ha a szám <11 akkor ugrás #2
Vége
```

```PsudoCode
Gondolok az 1es számra (N)
Ismételd:
    Leírom N számot, sortörés
    Növelem N számot
Újra ha N < 10
Vége
```

```PsudoCode
N = 1
Amíg N < 10
    Leírom N, sortörés
    N = N + 1
Ismétlés vége
Vége
```

```PsudoCode
X = 1
Amíg x <=100
    Ha x Mod 3 =/= 0 és x Mod 5 =/= 0
        Leírom x, sortörés
    x = x + 1
Vége
```

## számok összeadása

```PsudoCode
Bekérek 2 számot: a, b
#kiszámolom hosszukat
ah = floor(Log10(a)) + 1
bh = floor(Log10(b)) + 1
I = 1
vsz = 0
amíg I <= max(ah, bh)
    szj = a mod 10^I + a mod 10^I - a mod 10^(I-1) - b mod 10^(I-1)
    T = 0
    ha szj >= 10, akkor
        T = szj - szj mod 10
        szj = szj - T
        b = b + T
    vsz = vsz + szj * 10^(I-1)
    bh = floor(log10(b)) + 1
    I = I + 1
Vége
```

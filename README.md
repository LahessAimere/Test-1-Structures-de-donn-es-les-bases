# Algorithmique avancée : Test n°1

## Question 1 : Plus petit écart

#### 1) Serait-il intéressant de trier le tableau en amont de l’algorithme de recherche sur tableau non trié ?

- Même si trier le tableau ajoute une étape à l'algorithme, cela simplifie ensuite la recherche de la plus petite différence.

### Taux de compléxité pour un tableau trié : *O(n)*
```bash
  Name: SmallestGapWithSortedArray
  Result: Donne la valeur la plus petite entre deux nombres du tableau
  Begin
    let smallestGap = tab[1] - tab[0]

    for i = 0 to size of tab[i]-1; i++
        let diff = tab[i + 1] - tab[i]

        if diff < smallestGap
            smallestGap = diff
        end if
    end for

    return smallestGap
End
```
### Taux de compléxité pour un tableau non trié : *O(n²)*
```bash
  Begin
    let smallestGap = tab[1] - tab[0]

    for i = 0 to size - 1; i++
        for j = i + 1 to size; j++
            let diffBetweenTab = abs(tab[i] - tab[j])

            if diffBetweenTab < smallestGap
                smallestGap = diffBetweenTab
            end if
        end for
    end for

    return smallestGap
End
```
## Question 2 : Sous-ensemble avec somme donnée
```bash
```
## Question 3 : reverse()
### Taux de compléxité d'un tableau de chaîne inversé : *0()*
```bash
```
## Question 4 : concat()
```bash
```
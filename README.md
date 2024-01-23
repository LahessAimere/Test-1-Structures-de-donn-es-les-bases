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
  Name: SmallGapWithUnsortedArray
  Result: Donne la valeur la plus petite entre deux nombres du tableau
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
Name: SubsetSumExistsOrNot
Result: Détermine s’il existe un sous-ensemble du tableau dont la somme est égale à la somme cible
Begin
    let sum

    for i = 0 to size - 1; i++
        for j = i + 1 to size; j++
            if tab[i] + tab[j] = sum
            return true
            end if
        end for
    end for

    return false
End
```
## Question 3 : reverse()
### Taux de compléxité d'un tableau de chaîne inversé : *0(n)*
```bash
Name: Reverse
Result: Inverse le chaînage d'une liste chaînée
Begin
    let current = head
    let prev = null
    let next = null

    while current is not null
        next = current.next    
        current.next = prev 

        prev = current
        current = next
    end while

    tail = head
    head = prev
End
```
## Question 4 : concat()
```bash
Name: Concat
Result: Concatène la liste L1 avec une autre liste L2
Begin
    let L1
    let L2

    if L2._head == null
        return
    end if

    if L1._tail != null
        L1._tail._next = L2._head;
        L1._tail = L2._tail;
    end if
    else
        L1._head = L2._head;
        L1._tail = L2._tail;
    end else
    
    L1.reverse()
    L1.reverse() 
End
```
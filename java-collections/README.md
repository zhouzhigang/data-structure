# Java Collections

## Introduction to Collections

### What is Collections Framework?


## Interfaces

+ `Collection` a group of objects known as its elements
    * `Set` can't contain duplicate elements
        - `SortedSort` a Set maintains its elements in ascending order
    * `List` an ordered collection(sequence)
    * `Queue` a collection used to hold multiple elements prior to processing, FIFO
    * `Deque` can be both as FIFO and LIFO
+ `Map` an object that maps key to valued
    * `Sortedmap` a Map that maintains its mappings in ascending order

## Implementations

General-purpose Implementations

|Interface|Hash table Impl.|Resizable array Impl.|Tree Impl.|Linked list Impl.|Hash table + Linked list Impl.|
|---------|----------------|---------------------|----------|-----------------|------------------------------|
|`Set`|`HashSet`||`TreeSet`||`LinkedHashSet`|
|`List`||`ArrayList`||`LinkedList`||
|`Queue`||||||
|`Deque`||`ArrayDeque`||`LinkedList`||
|`Map`|`HashMap`||`TreeMap`||`LinkedHashMap`|


## References


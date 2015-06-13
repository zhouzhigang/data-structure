# List in Java

## API Design

## Examples


## Implementation in Java Collection
`java.util.LinkedList`

### Inheritance

    `Object`
        `AbstractCollection`
            `AbstractList`
            `ArrayList`
            `AbstractSequentialList`
                `LinkedList`

### Methods

#### common methods

`void clear()`

`Object clone()`

`boolean contains(Object o)`

`int size()`

`boolean isEmpty()` - `ArrayList` overwrite the method in `AbstractCollection`

#### add methods

`void add(E e)`

`void add(int index, E element)`

`boolean addAll(Collection<? extends E> c)`

`boolean addAll(int index, Collection<? extends E> c)`

`void addFirst(E e)` - `LinkedList`

`void addLast(E e)` - `LinkedList`

#### get methods

`E element()` - `LinkedList`

`E get(int index)`

`E getFirst()` - `LinkedList`

`E getLast()` - `LinkedList`

#### search methods

`int indexOf(Object o)`

`int lastIndexOf(Object o)` - `LinkedList`

`Iterator<E> iterator()`

`ListIterator<E> listIterator()` - `ArrayList` overwrite the method in `AbstractList`

`ListIterator<E> listIterator(int index)`

#### remove methods

`E remove()` - `LinkedList`

`E remove(int index)`

`boolean remove(Object o)`

`boolean removeAll(Collection<?> c)` - `ArrayList` overwrite the method in `AbstractCollection` 

`boolean removeIf(Predicate<? super E> filter` - `ArrayList`

`boolean removeRange(int fromIndex, int toIndex)` - `ArrayList`

`E removeFirst()` - `LinkedList`

`boolean removeFirstOccurrence(Object o)` - `LinkedList`

`E removeLast()` - `LinkedList`

`boolean removeLastOccurrence(Object o)` - `LinkedList`

#### update

`E set(int index, E element)`


#### collection related methods

`Spliterator<E> spliterator()`

`List<E> subList(int fromIndex, int toIndex)` - `ArrayList` overwrite the method in `AbstractList`

#### array related methods

`Object[] toArray()`

`<T> T[] toArray(T[] a)`

`void trimToSize()` - `ArrayList`

#### special methods

`void ensureCapacity(int minCapacity)` - `ArrayList`

`void forEach(Consumer<? super E> action) - `ArrayList`

`sort(Comparator<? super E> c)` - `ArrayList`

`boolean offer(E e)` - `LinkedList`

`boolean offerFirst(E e)` - `LinkedList`

`boolean offerLast(E e)` - `LinkedList`

`E peek()` - `LinkedList`

`E peekFirst()` - `LinkedList`

`E peekLast()` - `LinkedList`

`E poll()` - `LinkedList`

`E pollFirst()` - `LinkedList`

`E pollLast()` - `LinkedList`

`E pop()` - `LinkedList`

`void push(E e)` - `LinkedList`



### Inherited from AbstractSequentialList
`iterator`

### Inherited from AbstractList
`equals`, `hashCode`, `listIterator`, `removeRange`, `subList`

### Inherited from AbstractCollection
`containsAll`, `isEmpty`, `removeAll`, `retainAll`, `toString`

### Inherited from Object
`finalize`, `getClass`, `notify`, `notifyAll`, `wait`

## Reference
* [The Java Turorial - List Implementations](http://docs.oracle.com/javase/tutorial/collections/implementations/list.html)
* [Java ArrayList API](http://docs.oracle.com/javase8/docs/java/uutil/ArrayList.html)
* [Java LinkedList API](http://docs.oracle.com/javase8/docs/java/uutil/LinkedList.html)


# ArrayList

    public class ArrayList<E> extends AbstractList<E>
        implements List<E>, RandomAccess, Cloneable, java.io.Serializable


## Fields:

    private static final int DEFAULT_CAPACITY = 10;
    transient Object[] elementData; // non-private to simplify nested class access
    private int size; // the number of elements it contains

## Constructors

There are three constructors: empty list; with specified size; with specified collection.

    public ArrayList() {
        this.elementData = DEFAULTCAPACITY_EMPTY_ELEMENTDATA; // default empty: {}
    }

    public ArrayList(int initialCapacity) {
        if (initialCapacity > 0) {
            this.elementData = new Object[initialCapcity];
        } else if (initialCapacity == 0) {
            this.elementData = EMPTY_ELEMENTDATA; // empty data: {}
        } else {
            throw new IllegalArgumentException("Illegal Capacity: "+ initialCapcity);
        }
    }

    public ArrayList(Collection<? extends E> c) {
        elementData = c.toArray();
        if ((size = elementData.length) != 0) {
            // c.toArray might (incorrectly) not return Object[] (see 6260652)
            if (elementData.getClass() != Object[].class)
                elementData = Arrays.copuOf(elementData, size, Object[].class);
        } else {
            // replace with empty array
            this.elementData = EMPTY_ELEMENTDATA;
        }
    }


## Methods

### Add methods

`add(E)`, `add(int, E)`, `addAll(Collection<? extends E>)`, `addAll(int, Collection<? extends E>)`

    // Appends the specified element to the end of this list
    public boolean add(E e) {
        ensureCapacityInternal(size+1); // Increments modeCount!!
        elementData[size++] = e;
        return true;
    }

    // Insert the specified element at the specified position
    // need check index and need move data(LinkedList is better when insert)
    public void add(int index, E element) {
        rangeCheckForAdd(index);

        ensureCapacityInternal(size + 1); // Increments modCount!!
        System.arrayCopy(elementData, index, elementData, index + 1, size - index);
        elementData[index] = element;
        size++;
    }

    private void ensureCapacityInternal(int minCapcity) {
        if (elementData == DEFAULTCAPCITY_EMPTY_ELEMENTDATA) {
            minCapacity = Math.max(DEFAULT_CAPCITY, minCapacity);
        }

        ensureExplicitCapacity(minCapcity);
    }

    private void ensureExplicitCapacity(int minCapacity) {
        modCount++;

        // overflow-conscious code
        if (minCapacity - elementData.length > 0)
            grow(minCapacity);
    }

    private void grow(int minCapacity) {
        // overflow-conscious code
        int oldCapacity = elementData.length;
        int newCapacity = oldCapacity + (oldCapacity >> 1); // 1.5
        if (newCapacity - minCapacity < 0)
            newCapacity = minCapacity;
        if (newCapacity - MAX_ARRAY_SIZE > 0) // MAX_ARRAY_SIZE = Integer.MAX_VALUE - 8;
            newCapacity = hugeCapacity(minCapacity);
        // minCapacity is usually close to size, so this is win:
        elementData = Arrays.copyOf(elementData, newCapacity);
    }

### Remove methods
`remove(int)`, `remove(Object)`, `removeRange(int, int)`, `removeAll(Collection<?>)`, `retainAll(Collection<?>)`

    // Removes the element at the specified position
    public E remove(int index) {
        rangeCheck(index);

        modCount++;
        E oldValue = elementData(index);
        
        // why not call fastRemove(index) ??
        int numMoved = size - index - 1;
        if (numMoved > 0)
            System.arrayCopy(elementData, index+1, elementData, index, numMoved);
        elementData[--size] = null; // clear to let GC do its work

        return oldValue;
    }

    // Removes the first occurrence of the specified element
    public boolean remove(Object o) {
        if (o == null) {
            for (int index = 0; index < size; index++)
                if (elementData[index] == null) {
                    fastRemove(index);
                    return true;
                }
        } else {
            for (int index = 0; index < size; index++)
                if (o.equals(elementData[index])) {
                    fastRemove(index);
                    return true;
                }
        }
        return false;
    }

    private void fastRemove(int index) {
        modCount++;
        int numMoved = size - index - 1;
        if (numMoved > 0)
            System.arraycopy(elementData, index+1, elementData, index, numMoved);
        elementData[--size] = null;// clear to let GC do its work
    }

### Serialization

    // Save the state of the ArrayList instance to a stream(serialize)
    private void writeObject(java.io.ObjectOutputStream s) throws java.io.IOException {
        // write out element count, and any hidden stuff
        int expectedModCount = modCount;
        s.defaultWriteObject();

        // Write out size as capacity for behavioural compatibility
        s.writeInt(size);

        // Write out all elements in the proper order
        for (int i = 0; i < size; i++) {
            s.writeObject(elementData[i]);
        }

        if (modeCount != expectedModeCount) {
            throw new ConcurrentModificationException();
        }
    }
    
    // Reconstitute the ArrayList instance from a stream(deserialize)
    private void readObject(java.io.ObjectInputStream s) throws java.io.IOException, ClassNotFoundException {
        elementData = EMPTY_ELEMENTDATA;

        // Read in size, and any hidden stuff
        s.defaultReadObject();

        // Read in capacity
        s.readInt(); // ignored

        if (size > 0) {
            // be like clone(), allocate array based upon size not capacity
            ensureCapacityInternal(size);

            Object[] a = elementData;
            // Read in all elements in the proper order
            for (int i = 0; i < size; i++) {
                a[i] = s.readObject();
            }
        }
    }


### subList

    public List<E> subList(int fromIndex, int toIndex) {
        subListRangeCheck(fromIndex, toIndex, size);
        return new SubList(this, 0, fromIndex, toIndex);
    }

    private class SubList extends AbstractList<E> implements RandomAccess {
        private final AbastractList<E> parent;
        private final int parentOffset;
        private final int offset;
        int size;

        Sublist(AbstractList<E> parent, int offset, int fromIndex, int toIndex) {
            this.parent = parent;
            this.parentOffset = fromIndex;
            this.offset = offset + fromIndex;
            this.size = toIndex - fromIndex;
            this.modCount = ArrayList.this.modCount;
        }
    }


### clone method

    public Object clone() {
        try {
            ArrayList<?> v = (ArrayList<?>) super.clone();
            // shadow copy, copy reference
            v.elementData = Arrays.copyOf(elementData, size);
            v.modCount = 0;
            return v;
        } catch (CloneNotSupportedException e) {
            // this shouldn't happen, since we are Cloneable
            throw new InternalError(e);
        }
    }


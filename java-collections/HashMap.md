# HashMap

Provides all of the optional map operations, and permits `null` values and `null` key.
Roughly equivalent to `hashtable`, except that it is unsynchronized and permits nulls.

This map usually acts as a binned (bucketed) hash table, but when bins get too large, they are transformed into bins of TreeNodes, each structured similarly to those in `TreeMap`.

## Signature

    public class HashMap<K,V> extends AbstractMap<K,V>
        implements Map<K,V>, Cloneable, Serializable


Why HashMap extends AbstractMap and implement Map?
Technically, it is completely redundant. It was done for "documentation" reasons.
[Why would both a parent and child class implement the same interface?](http://stackoverflow.com/questions/5668429/why-would-both-a-parent-and-child-class-implement-the-same-interface)



## Attributes

Two parameters affect its performance: `initialCapacity` and `loadFactor`.

    // The table, initialized on first use, and resized as necessary.
    transient Node<K,V>[] table;
    // The number of key-value mappings contained in this map.
    transient int size;
    // The number of times this HashMap has been modified. fail-fast
    transient int modCount;
    // The next size value at which to resize (capacity * load factor).
    int threshold;
    // How full the hash table is allowed to get before its capacity is automatically increased
    final float loadFactor;

Some other static constants

    // initial capacity - must be a power of two
    static final int DEFAULT_INITIAL_CAPACITY = 1 << 4; // aka 16
    static final int MAXIMUM_CAPACITY = 1 << 30;
    // offers a good tradeoff between time and space costs
    static final float DEFAULT_LOAD_FACTOR = 0.75f;
    static final int TREEIFY_THRESHOLD = 8;
    static final int UNTREEIFY_THRESHOLD = 6;
    static final int MIN_TREEIFY_CAPACITY = 64;

## Internal Structure

    static class Node<K,V> implements Map.Entry<K,V> {
        final int hash;
        final K key;
        V value;
        node<K,V> next;

        // get
        // setValue

        public final int hashcode() {
            return Objects.hashCode(key) ^ Objects.hashCode(value);
        }

        public final boolean equals(Object o) {
            if (o == this)
                return ture;
            if (o instancof Map.Entry) {
                Map.Entry<?,?> e = (Map.Entry<?,?>)o;
                if (Objects.equals(key, e.getkey()) &&
                    Objects.equals(value, e.getValue()))
                    return true;
            }
            return false;
        }
    }

    static final class TreeNode<K,V> extends LinkedHashMap.Entry<K,V> {
        TreeNode<K,V> parent;  // red-black tree links
        TreeNode<K,V> left;
        TreeNode<K,V> right;
        TreeNode<K,V> prev;    // needed to unlink next upon deletion
        boolean red;
    }

## Static utilites

`hash` method

    // Computes key.hashCode() and spreads (XORs) higher bits of hash to lower.
    // Because the table uses power-of-two masking, sets of hashes that vary only in bits above the current mask will always collide
    static final int hash(Object key) {
        int h;
        return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
    }

## Methods

Basic operations `get` and `put`

### get method

    public V get(Object key) {
        Node<K,V> e;
        return (e = getNode(hash(key), key) == null ? null : e.value;
    }

    final Node<K,V> getNode(int hash, Object key) {
        Node<K,V>[] tab; Node<K,V> first, e; int n; K k;
        if ((tab = table) != null && (n = tab.length) > 0 &&
            (first = tab[(n-1) & hash]) != null) {
            if (first.hash == hash && // alway check first node
                (k = first.key) == key || (key != null && key.equals(k)))
                return first;
            if ((e = first.next) != null) {
                if (first.instanceof TreeNode)
                    return ((TreeNode<K,V>first).getTreeNode(hash, key);
                do {
                    if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k)))
                        return e;
                } while ((e = e.next) != null);
            }
            return null;
        }
    }


### put method

    // put a specified value in the map, if exist, replaced the old value
    public V put(K key, V value) {
        return putVal(hash(key), key, value, false, true);
    }

    // onlyIfAbsent if true, don't change existing value
    // evict if false, the table is in creation mode.
    final putVal(int hash, K key, V value, boolean onlyIfAbsent, boolean evict) {
        Node<K,V>[] tab; Node<K,V> p; int n, i;
        if ((tab = table) == null || (n = tab.length) == 0)
            tab[i] = newNode(hash, key, value, null);
        else {
            Node<K,V> e; K k;
            if (p.hash == hash &&
                ((k = p.key) == key || (key != null && key.equals(k))))
                e = p;
            else if (p instanceof TreeNode)
                e = ((TreeNode<K,V>)p).putTreeVal(this, tab, hash, key, value);
            else {
                for (int binCount = 0; ; ++binCount) {
                    if ((e = p.next) == null) {
                        p.next = newNode(hash, key, value, null);
                        if (binCount >= TREEIFY_THRESHOLD - 1) // -1 for 1st
                            treeifyBin(tab, hash);
                        break;
                    }
                    if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k))))
                        break;
                    p = e;
                }
            }
            if (e != null) { // existing mapping for key
                V oldValue = e.value;
                if (!onlyIfAbsent || oldValue == null)
                    e.value = value;
                afterNodeAccess(e);
                return oldValue;
            }
        }
        ++modCount;
        if (++size > threshold)
            resize();
        afterNodeInsertion(evict);
        return null;
    }

    // Initializes or doubles table size.
    final Node<K,V>[] resize() {
        Node<K,V>[] oldTab = table;
        int oldCap = (oldTab == null) ? 0 : oldTab.length;
        int oldThr = threshold;
        int newCap, newThr = 0;
        if (oldCap > 0) {
            if (oldCap >= MAXIMUM_CAPACITY) {
                threshold = Integer.MAX_VALUE;
                return oldTab;
            }
            else if ((newCap = oldCap << 1) < MAXIMUM_CAPACITY &&
                oldCap >= DEFAULT_INITIAL_CAPACITY)
                newThr = oldThr << 1; // double threshold
        }
        else if (oldThr > 0) // initial capacity was placed in threshold
            newCap = oldThr;
        else {               // zero initial threshold signifies using defaults
            newCap = DEFAULT_INITIAL_CAPACITY;
            newThr = (int)(DEFAULT_LOAD_FACTOR * DEFAULT_INITIAL_CAPACITY);
        }
        if (newThr == 0) {
            float ft = (float)newCap * loadFactor;
            newThr = (newCap < MAXIMUM_CAPACITY && ft < (float)MAXIMUM_CAPACITY ?
                (int)ft : Integer.MAX_VALUE);
        }
        threshold = newThr;
        @SuppressWarnings({"rawtypes","unchecked"})
        Node<K,V>[] newTab = (Node<K,V>[])new Node[newCap];
        table = newTab;
        if (oldTab != null) {
            for (int j = 0; j < oldCap; ++j) {
                Node<K,V> e;
                if ((e = oldTab[j]) != null) {
                    oldTab[j] = null;
                    if (e.next == null)
                        newTab[e.hash & (newCap - 1)] = e;
                    else if (e instanceof TreeNode)
                        ((TreeNode<K,V>)e).split(this, newTab, j, oldCap);
                    else { // preserve order
                        Node<K,V> loHead = null, loTail = null;
                        Node<K,V> hiHead = null, hiTail = null;
                        Node<K,V> next;
                        do {
                            next = e.next;
                            if ((e.hash & oldCap) == 0) {
                                if (loTail == null)
                                    loHead = e;
                                else
                                    loTail.next = e;
                                loTail = e;
                            }
                            else {
                                if (hiTail == null)
                                    hiHead = e;
                                else
                                    hiTail.next = e;
                            }
                        } while ((e = next) != null);
                        if (loTail != null) {
                            loTail.next = null;
                            newTab[j] = loHead;
                        }
                        if (hiTail != null) {
                            hiTail.next = null;
                            newTab[j + oldCap] = hiHead;
                        }
                    }
                }
            }
        }
        return newTab;
    }

### Clone

Why the table is `transient`?

    transient Node<K,V>[] table;



## Reference
* [Algorithms - 3.4   Hash Tables](http://algs4.cs.princeton.edu/34hash/)
* [Java HashMap Analysis](http://liujiacai.net/blog/2015/09/03/java-hashmap/)
* [JEP 180: Handle Frequent HashMap Collisions with Balanced Trees](http://openjdk.java.net/jeps/180)

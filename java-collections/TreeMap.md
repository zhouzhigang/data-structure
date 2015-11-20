# TreeMap

A Red-Black tree based `NavigableMap` implementation.
The map is sorted according to the `Comparable` natural ordering of its keys or by a `Comparator` provided at map creation time, depending on which constructor is used.

# Signture

    public class TreeMap<K,V>
        extends AbstractMap<K,V>
        implements NavigableMap<K,V>, Cloneable, java.io.Serializable

    public interface NavigableMap<K,V> extends SortedMap<K,V>
    public interface SortedMap<K,V> extends Map<K,V>

## Read-Black Tree
A __red-black tree__ is a kind of self-balancing binary search tree.

* A node is either red or black.
* The root is black. This rule is sometimes omitted.
* All leaves (NIL) are black.
* If a node is red, then both its children are black.
* Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes.

These constraints enforce a critical property of red–black trees: __the path from the root to the farthest leaf is no more than twice as long as the path from the root to the nearest leaf.__

## Fields

    private final Comparator<? super K> comparator;
    private transient Entry<K,V> root;
    private transient int size = 0;
    private transient int modCount = 0;

## Constructors

    public TreeMap() {
        comparator = null;
    }

    public TreeMap(Comparator<? super K> comparator) {
        this.comparator = comparator;
    }
    
    public TreeMap(Map<? extends K, ? extends V> m) {
        comparator = null;
        putAll(m);
    }

    public TreeMap(SortedMap<K, ? extends V> m) {
        comparator = m.comparator();
        try {
            buildFromSorted(m.size(), m.entrySet().iterator(), null, null);
        } catch (java.io.IOException cannotHappen) {
        } catch (ClassNotFoundException cannotHappen) {
        }
    }

## Methods


## Reference
* [Red–black tree - Wikipedia](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)


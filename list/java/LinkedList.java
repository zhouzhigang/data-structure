public class LinkedList {
    private ListNode header;

    public LinkedList() {
        header = new ListNode(null);
    }

    public boolean isEmpty() {
        return header.next == null;
    }

    public void makeEmpty() {
        header.next = null;
    }

    /**
     * Get iterator of header node.
     */
    public LinkedListItr zeroth() {
        return new LinkedListItr(header);
    }

    /**
     * Get iterator of first node.
     */
    public LinkedListItr first() {
        return new LinkedListItr(header.next);
    }
    
    /**
     * Return iterator corresponding to the first node containing an item.
     * @param x the item to search for.
     * @return an iterator; iterator isPastEnd if the item is not found.
     */
    public LinkedListItr find(Object x) {
        ListNode itr = header.next;
        while (itr != null && !itr.element.equals(x)) {
            itr = itr.next;
        }
        return new LinkedListItr(itr);
    }

    /**
     * Remove the first occurrence of an item.
     * @param x the item to remove.
     */
    public void remove(Object x) {
        LinkedListItr p = findPrevious(x);
        if (p.current.next != null) {
            p.current.next = p.current.next.next;
        }
    }

    /**
     * Return iterator prior to the first node containing an item.
     * @param x the item to search for.
     * @return approriate iterator if the item is found, otherwise,
     * the iterator corresponding to the last element in the list is returned.
     */
    public LinkedListItr findPrevious(Object x) {
        ListNode itr =  header;
        while (itr.next != null && !itr.next.element.equals(x)) {
            itr = itr.next;
        }
        return new LinkedListItr(itr);
    }

    public void insert(Object x, LinkedListItr p) {
        if (p != null && p.current != null) {
            p.current.next= new ListNode(x, p.current.next);
        }
    }

    /**
     * Print the list.
     */
    public static void printList(LinkedList theList) {
        if (theList.isEmpty()) {
            System.out.println("Empty List");
        } else {
            LinkedListItr itr = theList.first();
            for( ; !itr.isPastEnd(); itr.advance()) {
                System.out.println(itr.retrieve() + " ");
            }
        }
    }
}

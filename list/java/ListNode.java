/**
 * List Node.
 *
 * Some other lists:
 *  Double List;
 *  Loop List;
 *  Skip List;
 *
 */
class ListNode {

    Object element;
    ListNode next;

    /**
     * Constructor with element.
     */
    ListNode(Object theElement) {
        this(theElement, null); // call other constructor
    }

    /**
     * Constructor with element and next node.
     */
    ListNode(Object theElement, ListNode n) {
        element = theElement;
        next = n;
    }
}

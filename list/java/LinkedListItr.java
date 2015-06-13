/**
 * Linked List Iterator.
 *
 * Thinking:
 *  Why we need Iterator?
 */
public class LinkedListItr {
    /**
     * Current position.
     */
    ListNode current;

    LinkedListItr(ListNode theNode) {
        current = theNode;
    }

    /**
     * Check has next.
     */
    public boolean isPastEnd() {
        return current == null;
    }

    /**
     * Get current element.
     */
    public Object retrieve() {
        return isPastEnd() ? null : current.element;
    }

    /**
     * Move to next.
     */
    public void advance() {
        if (!isPastEnd()) {
            current = current.next;
        }
    }
}

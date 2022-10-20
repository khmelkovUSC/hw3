#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    smaller = NULL;
    larger = NULL;
    llpivotrecurse(head, smaller, larger, pivot);
}

void llpivotrecurse(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == NULL) return;
    // Add to smaller
    else if (head->val <= pivot) {
        Node* temp = head->next;
        if (smaller == NULL) {
            smaller = head;
            smaller->next = NULL;
            llpivotrecurse(temp, smaller, larger, pivot);
        }
        else {
            smaller->next = head;
            smaller->next->next = NULL;
            llpivotrecurse(temp, smaller->next, larger, pivot);
        }
    }
    // Add to larger
    else if (head-> val > pivot) {
        Node* temp = head->next;
        if (larger == NULL) {
            larger = head;
            larger->next = NULL;
            llpivotrecurse(temp, smaller, larger, pivot);
        }
        else {
            larger->next = head;
            larger->next->next = NULL;
            llpivotrecurse(temp, smaller, larger->next, pivot);
        }
    }
    head = NULL;
}
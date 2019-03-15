#include<iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
};


int main() {

    return 0;
}

int get_length(struct node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }

    return length;
}

struct node* get_nth(struct node* head, int n) {
    if (n < 0) {
        return NULL;
    }

    int index = 0;
    while (head != NULL && index < n) {
        index++;
        head = head->next;
    }

    return head;
}

void append_data(struct node** headRef, int data) {
    assert(headRef != NULL);
    if (*headRef == NULL) {
        *headRef = (struct node*)malloc(sizeof(struct node));
        (*headRef)->data = data;
        (*headRef)->next = NULL;
        return;
    }

    struct node* head = *headRef;
    while (head->next != NULL) {
        head = head->next;
    }

    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = data;
    head->next->next = NULL;
}

int pop(struct node** headRef) {
    assert(headRef != NULL);

    if (*headRef != NULL) {
        printf("Freeing: %d", (*headRef)->data);
        struct node* next = (*headRef)->next;
        int data = (*headRef)->data;
        (*headRef)->next = NULL;
        free(*headRef);
        
        *headRef = next;
        return data;
    }
    assert(0);
}

void delete_list(struct node** headRef) {
    assert(headRef != NULL);

    struct node* head = *headRef;
    struct node* next = NULL;

    while (head != NULL) {
        printf("Freeing: %d", (*headRef)->data);
        next = head->next;
        head->next = NULL;
        free(head);
        head = next;
    }
}

void insert_nth(struct node** headRef, int data, int n) {
    assert(headRef != NULL);
    assert(n >= 0);

    if (n == 0 || *headRef == NULL) {
        struct node* headNode = create_node(data);
        headNode->next = *headRef;
        *headRef = headNode;
        return; 
    }

    int index = 0;
    struct node* head = *headRef;
    struct node* prev = *headRef;

    while (head != NULL && index < n) {
        prev = head;
        head = head->next;
        index++;
    }

    if (prev != NULL) {
        prev->next = create_node(data);
        prev->next->next = head;
    }
}

struct node* create_node(int data) {
    return NULL;
}

void sorted_insert(struct node** headRef, int data) {
    assert(headRef != NULL);

    struct node* head = *headRef;
    struct node* prev = NULL;

    while (head != NULL && data > head->data) {
        prev = head;
        head = head->next;
    }

    struct node* newNode = create_node(data);

    if (prev != NULL) {
        prev->next = newNode;
    } else {
        *headRef = newNode;
    }

    newNode->next = newNode;
}

void append_second_list(struct node** list_a, struct node** list_b) {
    assert(list_a != NULL && list_b != NULL);

    if (*list_a == NULL) {
        *list_a = *list_b;
        *list_b = NULL;
        return;
    }

    struct node* head = *list_a;
    while (head->next != NULL) {
        head = head->next;
    }

    head->next = *list_b;
    *list_b = NULL;
}

void front_back_split(struct node* source, struct node** frontRef, struct node** backRef) {
    assert(frontRef != NULL && backRef != NULL);

    if (source == NULL) {
        *frontRef = NULL;
        *backRef = NULL;
        return;
    }

    if (source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct node* fast = source;
    struct node* slow = source;
    while (fast != NULL) {
        fast = fast->next;
        if (fast == NULL) {
            break;
        }
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
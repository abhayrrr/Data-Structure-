struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    struct ListNode *p = list1, *q = list1;
    int i;

    for (i = 0; i < a - 1; i++)
        p = p->next;

    for (i = 0; i <= b; i++)
        q = q->next;

    p->next = list2;

    while (list2->next != NULL)
        list2 = list2->next;

    list2->next = q;

    return list1;
}
Node *removeDuplicatesBrute(Node *first)
{
    unordered_set<int> seen;

    Node *temp = first;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        if (seen.find(temp->data) != seen.end())
        {
            Node *duplicate = temp;

            prev->next = temp->next;
            temp = temp->next;

            delete duplicate;
        }
        else
        {
            seen.insert(temp->data);

            prev = temp;
            temp = temp->next;
        }
    }

    return first;
}
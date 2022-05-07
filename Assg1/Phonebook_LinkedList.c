#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

// struct to store personal contact list
struct personal_node
{
    char firstname[20];
    char lastname[20];
    uint64_t number;
    char email[30];
    char type[20];
    struct personal_node *next;
};

// struct to store professional contact list
struct proff_node
{
    char firstname[20];
    char lastname[20];
    uint64_t number;
    char email[30];
    char officeNo[10];
    char address[100];
    char office[50];
    char type[20];
    struct proff_node *next;
};

struct personal_node *start_pers = NULL;
struct proff_node *start_proff = NULL;

// Function prototypes
struct personal_node *get_personal_node();
struct proff_node *get_proff_node();

void create_pers();
void create_proff();

void insert_pers(struct personal_node **start_pers, struct personal_node *new_pers);
void insert_proff(struct proff_node **start_proff, struct proff_node *new_proff);

void display_pers(struct personal_node *start_pers);
void display_proff(struct proff_node *start_proff);

void delete_pers(struct personal_node **start_pers);
void delete_proff(struct proff_node **start_proff);
void delete_pers_List(struct personal_node **start_pers);
void delete_proff_List(struct proff_node **start_proff);

void search_pers();
void search_proff();

void sort_des_pers(struct personal_node **start_pers);
void sort_des_proff(struct proff_node **start_proff);

void modify_pers();
void modify_proff();

void removeDuplicates_proff(struct proff_node *start_proff);
void removeDuplicates_pers(struct personal_node *start_pers);

int main()
{
    int op, ch, op2;
    struct personal_node *res;
    do
    {
        printf("-------Welcome--------\n");
        printf("1.Create or Insert\n2.Edit\n3.Delete\n4.Search\n5.Sort\n6.Display\n7.Remove duplicates\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Press 1 to insert or create personal contact or 2 to insert or create professional contact\n");
            scanf("%d", &op2);
            if (op2 == 1)
                create_pers(); // inserts the personal contacts in ascending order
            else if (op2 == 2)
                create_proff(); // inserts the professional contact in ascending order
            else
                printf("Invalid option\n");
            break;
        case 2:
            printf("Press 1 to edit personal contact or 2 to edit professional contact \n");
            scanf("%d", &op2);
            if (op2 == 1)
                modify_pers();
            else if (op2 == 2)
                modify_proff();
            else
                printf("Invalid option\n");
            break;
        case 3:
            printf("Press 1 to delete personal contact or 2 to delete professional contact \n");
            scanf("%d", &op2);
            if (op2 == 1)
                delete_pers(&start_pers);
            else if (op2 == 2)
                delete_proff(&start_proff);
            else
                printf("Invalid option\n");
            break;
        case 4:
            printf("Press 1 to search personal contact or 2 to search professional contact \n");
            scanf("%d", &op2);
            if (op2 == 1)
                search_pers();
            else if (op2 == 2)
                search_proff();
            else
                printf("Invalid option\n");
            break;
        case 5:
            int op3;
            printf("Press 1 to sort personal contact list or 2 to sort professional contact list\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                printf("Press 1 for sorted list in ascending order and 2 for sorted list in descending order\n");
                scanf("%d", &op3);
                switch (op3)
                {
                case 1:
                    display_pers(start_pers); // the list is already in ascending order
                    break;
                case 2:
                    sort_des_pers(&start_pers); // reversing the current list which is in ascending order
                    display_pers(start_pers);
                    // reversing the list again to maintain the logic of the insert function
                    sort_des_pers(&start_pers);
                    break;
                default:
                    printf("Invalid option.\n");
                    break;
                }
            }
            else if (op2 == 2)
            {
                printf("Press 1 for sorted list in ascending order and 2 for sorted list in descending order\n");
                scanf("%d", &op3);
                switch (op3)
                {
                case 1:
                    display_proff(start_proff); // the list is already in ascending order
                    break;
                case 2:
                    sort_des_proff(&start_proff); // reversing the current list which is in ascending order
                    display_proff(start_proff);
                    // reversing the list again to maintain the logic of the insert function
                    sort_des_proff(&start_proff);
                    break;
                default:
                    printf("Invalid option.\n");
                    break;
                }
            }
            else
                printf("Invalid option\n");
            break;
        case 6:
            printf("Press 1 to display personal contact list or 2 to display professional contact list\n");
            scanf("%d", &op2);
            if (op2 == 1)
                display_pers(start_pers);
            else if (op2 == 2)
                display_proff(start_proff);
            else
                printf("Invalid option\n");
            break;
        case 7:
            printf("Press 1 to remove duplicates from personal contact list or 2 to remove duplicates from professional contact list\n");
            scanf("%d", &op2);
            if (op2 == 1)
                removeDuplicates_pers(start_pers);
            else if (op2 == 2)
               removeDuplicates_proff(start_proff);
            else
                printf("Invalid option\n");
            break;
        }
        printf("Do you want to quit ? 1 for no / 0 for yes:");
        scanf("%d", &op);
    } while (op != 0);
    // deletes complete personal contact list
    delete_pers_List(&start_pers);
    // deletes complete professional contact list
    delete_proff_List(&start_proff);
    return 0;
}

struct personal_node *get_personal_node()
{
    return ((struct personal_node *)malloc(sizeof(struct personal_node)));
}
struct proff_node *get_proff_node()
{
    return ((struct proff_node *)malloc(sizeof(struct proff_node)));
}
void insert_pers(struct personal_node **start_pers, struct personal_node *new_pers)
{
    struct personal_node *current;
    /* Special case for the head end */
    if (*start_pers == NULL || strcmp(strlwr((*start_pers)->firstname), strlwr(new_pers->firstname)) > 0)
    {
        new_pers->next = *start_pers;
        *start_pers = new_pers;
    }
    else if (strcmp(strlwr((*start_pers)->firstname), strlwr(new_pers->firstname)) == 0 && strcmp(strlwr((*start_pers)->lastname), strlwr(new_pers->lastname)) > 0)
    {
        new_pers->next = *start_pers;
        *start_pers = new_pers;
    }
    else if (strcmp(strlwr((*start_pers)->firstname), strlwr(new_pers->firstname)) == 0 && strcmp(strlwr((*start_pers)->lastname), strlwr(new_pers->lastname)) == 0 && (*start_pers)->number > new_pers->number)
    {
        new_pers->next = *start_pers;
        *start_pers = new_pers;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *start_pers;
        int status = 0;
        while (current->next != NULL && status == 0)
        {
            if (strcmp(strlwr(current->next->firstname), strlwr(new_pers->firstname)) < 0)
                current = current->next;
            else if (strcmp(strlwr(current->next->firstname), strlwr(new_pers->firstname)) == 0 && strcmp(strlwr(current->next->lastname), strlwr(new_pers->lastname)) < 0)
                current = current->next;
            else if (strcmp(strlwr(current->next->firstname), strlwr(new_pers->firstname)) == 0 && strcmp(strlwr(current->next->lastname), strlwr(new_pers->lastname)) == 0 && current->next->number < new_pers->number)
                current = current->next;
            else
                status = 1;
        }
        new_pers->next = current->next;
        current->next = new_pers;
    }
    printf("Personal contact is inserted.\n");
}
void insert_proff(struct proff_node **start_proff, struct proff_node *new_proff)
{
    struct proff_node *current;
    /* Special case for the head end */
    if (*start_proff == NULL || strcmp(strlwr((*start_proff)->firstname),strlwr(new_proff->firstname)) > 0)
    {
        new_proff->next = *start_proff;
        *start_proff = new_proff;
    }
    else if (strcmp(strlwr((*start_proff)->firstname), strlwr(new_proff->firstname)) == 0 && strcmp(strlwr((*start_proff)->lastname), strlwr(new_proff->lastname)) > 0)
    {
        new_proff->next = *start_proff;
        *start_proff = new_proff;
    }
    else if (strcmp(strlwr((*start_proff)->firstname),strlwr(new_proff->firstname)) == 0 && strcmp(strlwr((*start_proff)->lastname), strlwr(new_proff->lastname)) == 0 && (*start_proff)->number >= new_proff->number)
    {
        new_proff->next = *start_proff;
        *start_proff = new_proff;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *start_proff;
        int status = 0;
        while (current->next != NULL && status == 0)
        {
            if (strcmp(strlwr(current->next->firstname),strlwr(new_proff->firstname)) < 0)
                current = current->next;
            else if (strcmp(strlwr(current->next->firstname), strlwr(new_proff->firstname)) == 0 && strcmp(strlwr(current->next->lastname), strlwr(new_proff->lastname)) < 0)
                current = current->next;
            else if (strcmp(strlwr(current->next->firstname), strlwr(new_proff->firstname)) == 0 && strcmp(strlwr(current->next->lastname), strlwr(new_proff->lastname)) == 0 && current->next->number < new_proff->number)
                current = current->next;
            else
                status = 1;
        }
        new_proff->next = current->next;
        current->next = new_proff;
    }
    printf("Professional contact is inserted.\n");
}
void create_pers()
{
    struct personal_node *new_pers;

    new_pers = get_personal_node();

    printf("Enter First name:\n");
    scanf("%s", &new_pers->firstname);

    printf("Enter Last name:\n");
    scanf("%s", &new_pers->lastname);

    printf("Enter number:\n");
    scanf("%llu", &new_pers->number);

    printf("Enter email:\n");
    scanf("%s", &new_pers->email);

    printf("Enter type:\n");
    scanf("%s", &new_pers->type);
    new_pers->next = NULL;
    insert_pers(&start_pers, new_pers);
}

void create_proff()
{
    struct proff_node *new_proff;
    new_proff = get_proff_node();

    printf("Enter First name:\n");
    scanf("%s", &new_proff->firstname);

    printf("Enter Last name:\n");
    scanf("%s", &new_proff->lastname);

    printf("Enter number:\n");
    scanf("%llu", &new_proff->number);

    printf("Enter email:\n");
    scanf("%s", &new_proff->email);

    printf("Enter office no.:(without spaces)\n");
    scanf("%s", &new_proff->officeNo);

    printf("Enter address:\n");
    fflush(stdin);
    gets(new_proff->address);
    fflush(stdin);

    printf("Enter Office/institute name:\n");
    fflush(stdin);
    gets(new_proff->office);
    fflush(stdin);

    printf("Enter type:\n");
    scanf("%s", &new_proff->type);

    new_proff->next = NULL;
    insert_proff(&start_proff, new_proff);
}
void search_pers()
{
    if (start_pers == NULL)
    {
        printf("Personal contact list is empty.\n");
        return;
    }
    struct personal_node *temp;
    char f[20], l[20];
    temp = start_pers;
    int op;
    uint64_t phno;
    printf("Enter 1 to search by name or enter 2 to search by phone number.\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Enter name to be searched (First name - last name):\n");
        scanf("%s", f);
        scanf("%s", l);
        int status=0;
        while (temp != NULL)
        {
            if (strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0)
            {
                printf("First Name-%s\n", temp->firstname);
                printf("Last Name-%s\n", temp->lastname);
                printf("Phone Number-%llu\n", temp->number);
                printf("email id-%s\n", temp->email);
                printf("Type-%s\n", temp->type);

                temp = temp->next;
                status=1;
            }
            else
                temp = temp->next;
        }
        if (status==0)
            printf("Contact not found.\n");
        else
            printf("Contact searched.\n");
        break;
    case 2:
        printf("Enter the phone number to be searched:\n");
        scanf("%llu", &phno);
        status=0;
        while (temp != NULL)
        {
            if (phno == temp->number)
            {
                printf("First Name-%s\n", temp->firstname);
                printf("Last Name-%s\n", temp->lastname);
                printf("Phone Number-%llu\n", temp->number);
                printf("email id-%s\n", temp->email);
                printf("Type-%s\n", temp->type);
                temp = temp->next;
                status=1;
            }
            else
                temp = temp->next;
        }
        if (status==0)
            printf("Contact not found.\n");
        else
            printf("Contact searched.\n");
        break;
    }
}
void search_proff()
{
    if (start_proff == NULL)
    {
        printf("Professional contact list is empty.\n");
        return;
    }
    struct proff_node *temp;
    char f[20], l[20];
    temp = start_proff;
    int op;
    uint64_t phno;
    printf("Enter 1 to search by name or enter 2 to search by phone number.\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Enter name to be searched (First name - last name):\n");
        scanf("%s", f);
        scanf("%s", l);
        int status=0;
        while (temp != NULL)
        {
            if (strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0)
            {
                printf("First Name-%s\n", temp->firstname);
                printf("Last Name-%s\n", temp->lastname);
                printf("Phone Number-%llu\n", temp->number);
                printf("email id-%s\n", temp->email);
                printf("Office no.-%s\n", temp->officeNo);

                printf("Address-");
                puts(temp->address);

                printf("Office/Institute-");
                puts(temp->office);

                printf("Type-%s\n", temp->type);

                temp = temp->next;
                status=1;
            }
            else
                temp = temp->next;
        }
        if (status==0)
            printf("Contact not found.\n");
        else
            printf("Contact searched.\n");
        break;
    case 2:
        printf("Enter the phone number to be searched:\n");
        scanf("%llu", &phno);
        status=0;
        while (temp != NULL)
        {
            if (phno == temp->number)
            {
                printf("First Name-%s\n", temp->firstname);
                printf("Last Name-%s\n", temp->lastname);
                printf("Phone Number-%llu\n", temp->number);
                printf("email id-%s\n", temp->email);
                printf("Office no.-%s\n", temp->officeNo);

                printf("Address-");
                puts(temp->address);

                printf("Office/Institute-");
                puts(temp->office);

                printf("Type-%s\n", temp->type);
                status=1;
                temp = temp->next;
            }
            else
                temp = temp->next;
        }
        if (status==0)
            printf("Contact not found.\n");
        else
            printf("Contact searched.\n");
        break;
    }
}
//reverses the personal contact list which is in acending order
void sort_des_pers(struct personal_node **start_pers)
{
    struct personal_node *prev = NULL, *current = *start_pers, *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *start_pers = prev;
}
//reverses the professional contact list which is in acending order
void sort_des_proff(struct proff_node **start_proff)
{
    struct proff_node *prev = NULL, *current = *start_proff, *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *start_proff = prev;
}
void display_pers(struct personal_node *start_pers)
{
    if (start_pers == NULL)
    {
        printf("Personal contact list is empty\n");
        return;
    }

    struct personal_node *temp;
    temp = start_pers;

    printf("Personal Contact List:\n");
    while (temp != NULL)
    {
        printf("\n");
        printf("First Name-%s\n", temp->firstname);
        printf("Last Name-%s\n", temp->lastname);
        printf("Phone Number-%llu\n", temp->number);
        printf("email id-%s\n", temp->email);
        printf("Type-%s\n", temp->type);

        temp = temp->next;
    }
}
void display_proff(struct proff_node *start_proff)
{
    if (start_proff == NULL)
    {
        printf("Professional contact list is empty\n");
        return;
    }
    struct proff_node *temp;
    temp = start_proff;
    printf("professional Contact List:\n");
    while (temp != NULL)
    {
        printf("\n");
        printf("First Name-%s\n", temp->firstname);
        printf("Last Name-%s\n", temp->lastname);
        printf("Phone Number-%llu\n", temp->number);
        printf("email id-%s\n", temp->email);
        printf("Office no.-%s\n", temp->officeNo);

        printf("Address-");
        puts(temp->address);

        printf("Office/Institute-");
        puts(temp->office);

        printf("Type-%s\n", temp->type);

        temp = temp->next;
    }
}
void delete_pers(struct personal_node **start_pers)
{
    if (*start_pers == NULL)
    {
        printf("Personal contact list is empty\n");
        return;
    }
    char f[20], l[20];
    uint64_t phno;
    printf("Enter name :");
    scanf("%s %s", f, l);

    printf("Enter phone number :");
    scanf("%llu", &phno);

    // Store head node
    struct personal_node *temp = *start_pers, *prev;
    if (temp != NULL && strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0 && (temp->number == phno))
    {
        *start_pers = temp->next; // Changed head
        free(temp);               // free old head
        printf("Personal contact was deleted.\n");
        return;
    }

    while (temp != NULL)
    {
        if (strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0 && (temp->number == phno))
        {
            prev->next = temp->next;
            free(temp);
            printf("Personal contact was deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Personal contact was not found.\n");
        return;
    }
}
void delete_proff(struct proff_node **start_proff)
{
    if (*start_proff == NULL)
    {
        printf("Professional contact list is empty\n");
        return;
    }

    char f[20], l[20];
    uint64_t phno;
    printf("Enter name :");
    scanf("%s %s", f, l);

    printf("Enter phone number :");
    scanf("%llu", &phno);

    // Store head node
    struct proff_node *temp = *start_proff, *prev;
    if (temp != NULL && strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0 && (temp->number == phno))
    {
        *start_proff = temp->next; // Changed head
        free(temp);                // free old head
        printf("Professional contact was deleted.\n");
        return;
    }

    while (temp != NULL)
    {
        if (strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0 && (temp->number == phno))
        {
            prev->next = temp->next;
            free(temp);
            printf("Professional contact was deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Professional contact was not found.\n");
        return;
    }
}
void delete_pers_List(struct personal_node **start_pers)
{
    struct personal_node *current = *start_pers;
    struct personal_node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *start_pers = NULL;
}
void delete_proff_List(struct proff_node **start_proff)
{
    struct proff_node *current = *start_proff;
    struct proff_node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *start_proff = NULL;
}
void modify_pers()
{
    struct personal_node *temp;
    int op, status = 0;
    char f[20], l[20], new_email[30], new_type[10];
    uint64_t phno;
    temp = start_pers;
    if (start_pers == NULL)
    {
        printf("Personal contact list is empty.\n");
        return;
    }
    printf("Enter name (First Name Last Name):\n");
    scanf("%s %s", f, l);
    printf("Enter Phone no:\n");
    scanf("%llu", &phno);
    while (temp != NULL && status == 0)
    {
        if (strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0 && temp->number == phno)
        {
            printf("Fields that can be modified:\n1.Email\n2.Type\nEnter your choice :");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                printf("Enter new email:\n");
                scanf("%s", new_email);
                strcpy(temp->email, new_email);
                break;
            case 2:
                printf("Enter new type:\n");
                scanf("%s", new_type);
                strcpy(temp->type, new_type);
                break;
            }
            status = 1;
        }
        else
            temp = temp->next;
    }
    if (status == 1)
        printf("Contact modified.\n");
    else
        printf("Contact not found.\n");
}
void modify_proff()
{
    struct proff_node *temp;
    int op, status = 0;
    char f[20], l[20], new_email[30], new_type[10], new_officeNo[10], new_address[100], new_office[50];
    uint64_t phno;
    temp = start_proff;
    if (start_proff == NULL)
    {
        printf("Professional contact list is empty.\n");
        return;
    }
    printf("Enter name (First Name Last Name):\n");
    scanf("%s %s", f, l);
    printf("Enter Phone no:\n");
    scanf("%llu", &phno);
    while (temp != NULL && status == 0)
    {
        if (strcmp(strlwr(temp->firstname), strlwr(f)) == 0 && strcmp(strlwr(temp->lastname), strlwr(l)) == 0 && temp->number == phno)
        {
            printf("Fields that can be modified:\n1.Email\n2.Type\n3.Office No.\n4.Address\n5.Office/Institute\nEnter your choice :");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                printf("Enter new email:\n");
                scanf("%s", new_email);
                strcpy(temp->email, new_email);
                break;
            case 2:
                printf("Enter new type:\n");
                scanf("%s", new_type);
                strcpy(temp->type, new_type);
                break;
            case 3:
                printf("Enter new Office no:\n");
                scanf("%s", new_officeNo);
                strcpy(temp->officeNo, new_officeNo);
                break;
            case 4:
                printf("Enter new Address:\n");
                fflush(stdin);
                gets(new_address);
                fflush(stdin);
                strcpy(temp->address, new_address);
                break;
            case 5:
                printf("Enter new office/institute:\n");
                fflush(stdin);
                gets(new_office);
                fflush(stdin);
                strcpy(temp->office, new_office);
                break;
            }
            status = 1;
        }
        else
            temp = temp->next;
    }
    if (status == 1)
        printf("Contact modified.\n");
    else
        printf("Contact not found.\n");
}
void removeDuplicates_proff(struct proff_node *start_proff)
{
    /* Pointer to traverse the linked list */
    struct proff_node *current = start_proff;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct proff_node *next_next;
    int status = 0;

    /* do nothing if the list is empty */
    if (current == NULL)
    {
        printf("Prfessional contact list is empty.\n");
        return;
    }

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
        /* Compare current node with next node */
        if (strcmp(strlwr(current->firstname), strlwr(current->next->firstname)) == 0 && strcmp(strlwr(current->lastname), strlwr(current->next->lastname)) == 0 && current->number == current->next->number)
        {
            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
            status = 1;
        }
        else /* only advance if no deletion */
        {
            current = current->next;
        }
    }
    if (status == 1)
        printf("Duplicates are removed.\n");
    else
        printf("No duplicates found.\n");
}
void removeDuplicates_pers(struct personal_node *start_pers)
{
    /* Pointer to traverse the linked list */
    struct personal_node *current = start_pers;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct personal_node *next_next;
    int status = 0;

    /* do nothing if the list is empty */
    if (current == NULL)
    {
        printf("Personal contact list is empty.\n");
        return;
    }

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
        /* Compare current node with next node */
        if (strcmp(strlwr(current->firstname), strlwr(current->next->firstname)) == 0 && strcmp(strlwr(current->lastname), strlwr(current->next->lastname)) == 0 && current->number == current->next->number)
        {
            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
            status = 1;
        }
        else /* only advance if no deletion */
        {
            current = current->next;
        }
    }
    if (status == 1)
        printf("Duplicates are removed.\n");
    else
        printf("No duplicates found.\n");
}
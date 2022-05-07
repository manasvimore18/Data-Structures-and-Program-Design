#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>

// An AVL tree node to store personal contact details
typedef struct per_node
{
    char firstname[20], lastname[20];
    uint64_t number;
    char email[30];
    char type[20];
    struct per_node *left, *right;
    int ht;
} personal;

// An AVL tree node to store professional contact details
typedef struct pro_node
{
    char firstname[20];
    char lastname[20];
    uint64_t number;
    char email[30];
    char officeNo[10];
    char address[100];
    char office[50];
    char type[20];
    struct pro_node *left, *right;
    int ht;
} professional;

personal *get_per_node();
professional *get_pro_node();

personal *minValueNode_per(personal *per_root);
professional *minValueNode_pro(professional *pro_root);

int max(int a, int b);
professional *create_pro(professional *pro_root);

int height_per(personal *per_root);
int height_pro(professional *pro_root);

personal *rotateright_per(personal *per_root);
professional *rotateright_pro(professional *pro_root);

personal *RR_per(personal *per_root);
professional *RR_pro(professional *pro_root);

personal *LL_per(personal *per_root);
professional *LL_pro(professional *pro_root);

personal *LR_per(personal *per_root);
professional *LR_pro(professional *pro_root);

personal *RL_per(personal *per_root);
professional *RL_pro(professional *pro_root);

int BF_per(personal *per_root);
int BF_pro(professional *pro_root);

personal *rotateleft_per(personal *per_root);
professional *rotateleft_pro(professional *pro_root);

personal *insert_per(personal *per_root, char *fn, char *ln, uint64_t phn, char *email, char *type);
professional *insert_pro(professional *pro_root, char *fn, char *ln, uint64_t phn, char *email, char *ofno, char *add, char *of, char *type);
personal *insert_phone(personal *per_root, char *fn, char *ln, uint64_t phn, char *email, char *type);

void inorder_per(personal *per_root);
void inorder_rev_per(personal *per_root);
void inorder_pro(professional *pro_root);
void inorder_rev_pro(professional *pro_root);

void print_per(personal *per_root);
void print_pro(professional *pro_root);

int search_name_per(personal *per_root, char *f, char *l);
int search_phone_per(personal *per_root, uint64_t phone);
int search_name_pro(professional *pro_root, char *f, char *l);
int search_phone_pro(professional *pro_root, uint64_t phone);

int modify_per(personal *per_root, uint64_t phn);
int modify_pro(professional *pro_root, uint64_t phn);

personal *delete_per(personal *per_root, uint64_t phno);
professional *delete_pro(professional *pro_root, uint64_t phno);

void delete_Tree_per(personal* node);
void delete_Tree_pro(professional* node);

void range_search_per(personal *per_root, uint64_t low, uint64_t high);
void range_search_pro(professional *pro_root, uint64_t low, uint64_t high);

int main()
{
    int op, ch, op2;
    personal *per_root = NULL, *root = NULL;
    professional *pro_root = NULL;
    do
    {
        printf("-------Welcome--------\n");
        printf("1.Create or Insert\n2.Edit\n3.Delete\n4.Search\n5.Sort according to phone number\n6.Display\n7.Range search\n8.Sort according to name\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Press 1 to insert or create personal contact or 2 to insert or create professional contact\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                char fn[20], ln[20], email[30], type[20];
                uint64_t phn;

                printf("Enter First name:\n");
                scanf("%s", fn);

                printf("Enter Last name:\n");
                scanf("%s", ln);

                printf("Enter number:\n");
                scanf("%lu", &phn);

                printf("Enter email:\n");
                scanf("%s", email);

                printf("Enter type:\n");
                scanf("%s", type);

                // inserts data considering phone number as key
                per_root = insert_per(per_root, fn, ln, phn, email, type);

                // inserts data considering name as key and if name is same, considers phone number as key(for Q8)
                root = insert_phone(root, fn, ln, phn, email, type);
                printf("Personal contact is created/inserted.\n");
            }
            else if (op2 == 2)
            {
                pro_root = create_pro(pro_root);
                printf("Professional contact is created/inserted.\n");
            }
            else
                printf("Invalid option\n");
            break;
        case 2:
            printf("Press 1 to edit personal contact or 2 to edit professional contact \n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                if (per_root == NULL)
                {
                    printf("Personal contact tree is empty.\n");
                }
                else
                {
                    int res;
                    uint64_t phn;

                    printf("Enter the phone number of the contact you want to modify :");
                    scanf("%lu", &phn);

                    res = modify_per(per_root, phn);
                    if (res == 1)
                    {
                        printf("Contact modified\n");
                    }
                    else
                        printf("Contact not found.\n");
                }
            }
            else if (op2 == 2)
            {
                if (pro_root == NULL)
                {
                    printf("Professional contact tree is empty.\n");
                }
                else
                {
                    int res;
                    uint64_t phn;

                    printf("Enter the phone number of the contact you want to modify :");
                    scanf("%lu", &phn);

                    res = modify_pro(pro_root, phn);
                    if (res == 1)
                    {
                        printf("Contact modified\n");
                    }
                    else
                        printf("Contact not found.\n");
                }
            }
            else
                printf("Invalid option\n");
            break;
        case 3:
            printf("Press 1 to delete personal contact or 2 to delete professional contact \n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                uint64_t phno;

                if (per_root == NULL)
                {
                    printf("Personal contact tree is empty.\n");
                }
                else
                {
                    printf("Enter phone number :");
                    scanf("%lu", &phno);

                    per_root = delete_per(per_root, phno);
                }
            }
            else if (op2 == 2)
            {
                uint64_t phno;

                if (pro_root == NULL)
                {
                    printf("Professional contact tree is empty.\n");
                }
                else
                {
                    printf("Enter phone number :");
                    scanf("%lu", &phno);

                    pro_root = delete_pro(pro_root, phno);
                }
            }
            else
                printf("Invalid option\n");
            break;
        case 4:
            printf("Press 1 to search personal contact or 2 to search professional contact \n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                int op3, res;
                if (per_root == NULL)
                {
                    printf("Personal contact tree is empty.\n");
                }
                else
                {
                    printf("1.Search via Name (FIRST NAME LAST NAME)\n2.Search Via phone number\nEnter your choice : ");
                    scanf("%d", &op3);
                    if (op3 == 1)
                    {
                        char f[20], l[20];

                        printf("Enter first name :");
                        scanf("%s", f);
                        printf("Enter last name :");
                        scanf("%s", l);

                        res = search_name_per(per_root, f, l);

                        if (res == 1)
                            printf("Contact searched\n");
                        else
                            printf("Contact not found\n");
                    }
                    else if (op3 == 2)
                    {
                        int res;
                        uint64_t phno;

                        printf("Enter phone number :");
                        scanf("%lu", &phno);

                        res=search_phone_per(per_root,phno);
                        if (res == 1)
                            printf("Contact searched\n");
                        else
                            printf("Contact not found\n");
                    }
                    else
                        printf("Invalid option.\n");
                }
            }
            else if (op2 == 2)
            {
                if (pro_root == NULL)
                {
                    printf("Professional contact tree is empty.\n");
                }
                else
                {
                    int op3, res;
                    printf("1.Search via Name (FIRST NAME LAST NAME)\n2.Search Via phone number\nEnter your choice : ");
                    scanf("%d", &op3);

                    if (op3 == 1)
                    {
                        char f[20], l[20];

                        printf("Enter first name :");
                        scanf("%s", f);
                        printf("Enter last name :");
                        scanf("%s", l);

                        res = search_name_pro(pro_root, f, l);

                        if (res == 1)
                            printf("Contact searched\n");
                        else
                            printf("Contact not found\n");
                    }
                    else if (op3 == 2)
                    {
                        int res;
                        uint64_t phno;

                        printf("Enter phone number :");
                        scanf("%lu", &phno);

                        res = search_phone_pro(pro_root, phno);
                        if (res == 1)
                            printf("Contact searched\n");
                        else
                            printf("Contact not found\n");
                    }
                    else
                        printf("Invalid option.\n");
                }
            }
            else
                printf("Invalid option\n");
            break;
        case 5:
            printf("Press 1 to sort personal contacts or 2 to sort professional contacts\n");
            scanf("%d", &op2);
            int op3;
            if (op2 == 1)
            {
                if (per_root == NULL)
                {
                    printf("Personal contact tree is empty.\n");
                }
                else
                {
                    printf("Press 1 for sorted contacts in ascending order and 2 for sorted contacts in descending order\n");
                    scanf("%d", &op3);
                    switch (op3)
                    {
                    case 1:
                        inorder_per(per_root); // inorder traversal gives ascending order (key-phone number)
                        break;
                    case 2:
                        inorder_rev_per(per_root); // reversing the inorder traversal for descending order
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                    }
                }
            }
            else if (op2 == 2)
            {
                if (pro_root == NULL)
                {
                    printf("Professional contact tree is empty.\n");
                }
                else
                {
                    printf("Press 1 for sorted contacts in ascending order and 2 for sorted contacts in descending order\n");
                    scanf("%d", &op3);
                    switch (op3)
                    {
                    case 1:
                        inorder_pro(pro_root); // inorder traversal gives ascending order
                        break;
                    case 2:
                        inorder_rev_pro(pro_root); // reversing the inorder traversal for descending order
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                    }
                }
            }
            else
                printf("Invalid option\n");
            break;
        case 6:
            printf("Press 1 to display personal contacts or 2 to display professional contacts\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                if (per_root == NULL)
                {
                    printf("Personal contact tree is empty.\n");
                }
                else
                    inorder_per(per_root);
            }
            else if (op2 == 2)
            {
                if (pro_root == NULL)
                {
                    printf("Professional contact tree is empty.\n");
                }
                else
                    inorder_pro(pro_root);
            }
            else
                printf("Invalid option\n");
            break;
        case 7:
            printf("Press 1 to range search personal contacts or 2 to range search professional contacts\n");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                if (per_root == NULL)
                {
                    printf("Personal contact tree is empty.\n");
                }
                else
                {
                    uint64_t low, high;
                    printf("Enter From-Mobile-Number :");
                    scanf("%lu", &low);
                    printf("Enter To-Mobile-Number :");
                    scanf("%lu", &high);
                    range_search_per(per_root, low, high);
                }
            }
            else if (op2 == 2)
            {
                if (pro_root == NULL)
                {
                    printf("Professional contact tree is empty.\n");
                }
                else
                {
                    uint64_t low, high;

                    printf("Enter From-Mobile-Number :");
                    scanf("%lu", &low);
                    printf("Enter To-Mobile-Number :");
                    scanf("%lu", &high);

                    range_search_pro(pro_root, low, high);
                }
            }
            else
                printf("Invalid Option.\n");
            break;
        case 8:
            // displays sorted personal contact tree based on name and if names are same then according to phone number
            if (root == NULL)
                printf("Phone database is empty.\n");
            else
                inorder_per(root);
        }
        printf("Do you want to quit ? 1 for no / 0 for yes:");
        scanf("%d", &op);
    } while (op != 0);
    
    delete_Tree_per(per_root);
    delete_Tree_per(root);
    per_root= NULL;
    root= NULL;
    printf("Personal Tree deleted.\n");

    delete_Tree_pro(pro_root);
    pro_root= NULL;
    printf("Professional Tree deleted.\n");

    return 0;
}

// function to create a new node of type personal*
personal *get_per_node()
{
    return ((personal *)malloc(sizeof(personal)));
}

// function to create a new node of type professional*
professional *get_pro_node()
{
    return ((professional *)malloc(sizeof(professional)));
}

// function to take input from user for professional contact, then we pass these inputs as arguments to insert_pro() along with pro_root* as a parameter
professional *create_pro(professional *pro_root)
{
    char fn[20], ln[20], email[30], ofno[10], add[100], of[50], type[20];
    uint64_t phn;

    printf("Enter First name:\n");
    scanf("%s", fn);

    printf("Enter Last name:\n");
    scanf("%s", ln);

    printf("Enter number:\n");
    scanf("%lu", &phn);

    printf("Enter email:\n");
    scanf("%s", email);

    printf("Enter office no.:(without spaces)\n");
    scanf("%s", ofno);

    printf("Enter address:\n");
    fflush(stdin);
    gets(add);
    fflush(stdin);

    printf("Enter Office/institute name:\n");
    fflush(stdin);
    gets(of);
    fflush(stdin);

    printf("Enter type:\n");
    scanf("%s", type);

    pro_root = insert_pro(pro_root, fn, ln, phn, email, ofno, add, of, type);

    return pro_root;
}

// inserting personal contact considering phone number as the key
// Recursive function to insert data in the subtree rooted with per_root and returns the new root of the subtree.
personal *insert_per(personal *per_root, char *fn, char *ln, uint64_t phn, char *email, char *type)
{
    if (per_root == NULL)
    {
        per_root = get_per_node();

        strcpy(per_root->firstname, fn);
        strcpy(per_root->lastname, ln);
        strcpy(per_root->email, email);
        strcpy(per_root->type, type);
        per_root->number = phn;

        per_root->left = per_root->right = NULL;
    }
    else if (phn > per_root->number)
    {
        per_root->right = insert_per(per_root->right, fn, ln, phn, email, type);

        if (BF_per(per_root) == -2)
            if (phn > per_root->right->number)
                per_root = RR_per(per_root);
            else
                per_root = RL_per(per_root);
    }
    else if (phn < per_root->number)
    {
        per_root->left = insert_per(per_root->left, fn, ln, phn, email, type);

        if (BF_per(per_root) == 2)
            if (phn < per_root->left->number)
                per_root = LL_per(per_root);
            else
                per_root = LR_per(per_root);
    }

    // Update height of this ancestor node
    per_root->ht = height_per(per_root);
    return per_root;
}

// inserting contact and sort according to name and if names are same then according to phone number for Q8
// Recursive function to insert data in the subtree rooted with per_root and returns the new root of the subtree.
personal *insert_phone(personal *per_root, char *fn, char *ln, uint64_t phn, char *email, char *type)
{
    if (per_root == NULL)
    {
        per_root = get_per_node();

        strcpy(per_root->firstname, fn);
        strcpy(per_root->lastname, ln);
        strcpy(per_root->email, email);
        strcpy(per_root->type, type);
        per_root->number = phn;

        per_root->left = per_root->right = NULL;
    }
    else if (strcasecmp(fn, per_root->firstname) > 0 || (strcasecmp(fn, per_root->firstname) == 0 && strcasecmp(ln, per_root->lastname) > 0) || (strcasecmp(fn, per_root->firstname) == 0 && strcasecmp(ln, per_root->lastname) == 0 && phn > per_root->number))
    {
        per_root->right = insert_per(per_root->right, fn, ln, phn, email, type);

        if (BF_per(per_root) == -2)
            if (strcasecmp(fn, per_root->right->firstname) > 0 || (strcasecmp(fn, per_root->right->firstname) == 0 && strcasecmp(ln, per_root->right->lastname) > 0) || (strcasecmp(fn, per_root->right->firstname) == 0 && strcasecmp(ln, per_root->right->lastname) == 0 && phn > per_root->right->number))
                per_root = RR_per(per_root);
            else
                per_root = RL_per(per_root);
    }
    else if (strcasecmp(fn, per_root->firstname) < 0 || (strcasecmp(fn, per_root->firstname) == 0 && strcasecmp(ln, per_root->lastname) < 0) || (strcasecmp(fn, per_root->firstname) == 0 && strcasecmp(ln, per_root->lastname) == 0 && phn < per_root->number))
    {
        per_root->left = insert_per(per_root->left, fn, ln, phn, email, type);
        if (BF_per(per_root) == 2)
            if (strcasecmp(fn, per_root->left->firstname) < 0 || (strcasecmp(fn, per_root->left->firstname) == 0 && strcasecmp(ln, per_root->left->lastname) < 0) || (strcasecmp(fn, per_root->left->firstname) == 0 && strcasecmp(ln, per_root->left->lastname) == 0 && phn < per_root->left->number))
                per_root = LL_per(per_root);
            else
                per_root = LR_per(per_root);
    }
    per_root->ht = height_per(per_root);
    return per_root;
}

// function to get the height of the personal contact tree
int height_per(personal *per_root)
{
    int lh, rh;
    if (per_root == NULL)
        return (0);
    if (per_root->left == NULL)
        lh = 0;
    else
        lh = 1 + per_root->left->ht;
    if (per_root->right == NULL)
        rh = 0;
    else
        rh = 1 + per_root->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}

// A utility function to right rotate subtree rooted with per_root
personal *rotateright_per(personal *per_root)
{
    personal *y=per_root->left;
    personal *temp=y->right;
    // perform rotation
    y->right = per_root;
    per_root->left = temp;

    // update heights
    per_root->ht = height_per(per_root);
    y->ht = height_per(y);

    // return new root
    return (y);
}

// A utility function to left rotate subtree rooted with per_root
personal *rotateleft_per(personal *per_root)
{
    personal *y=per_root->right;
    personal *temp=y->left;
    // perform rotation
    y->left = per_root;
    per_root->right=temp;

    // update heights
    per_root->ht = height_per(per_root);
    y->ht = height_per(y);

    // return new root
    return (y);
}

// Right Right case (personal)
personal *RR_per(personal *per_root)
{
    per_root = rotateleft_per(per_root);
    return (per_root);
}

// Left Left Case (personal)
personal *LL_per(personal *per_root)
{
    per_root = rotateright_per(per_root);
    return (per_root);
}

// Left Right Case (personal)
personal *LR_per(personal *per_root)
{
    per_root->left = rotateleft_per(per_root->left);
    per_root = rotateright_per(per_root);
    return (per_root);
}

// Right Left Case (personal)
personal *RL_per(personal *per_root)
{
    per_root->right = rotateright_per(per_root->right);
    per_root = rotateleft_per(per_root);
    return (per_root);
}

// Get Balance factor of node per_root
int BF_per(personal *per_root)
{
    int lh, rh;
    if (per_root == NULL)
        return (0);

    if (per_root->left == NULL)
        lh = 0;
    else
        lh = 1 + per_root->left->ht;

    if (per_root->right == NULL)
        rh = 0;
    else
        rh = 1 + per_root->right->ht;

    return (lh - rh);
}

// function to print personal contact data
void print_per(personal *per_root)
{
    printf("\n");
    printf("First Name-%s\n", per_root->firstname);
    printf("Last Name-%s\n", per_root->lastname);
    printf("Phone Number-%lu\n", per_root->number);
    printf("email id-%s\n", per_root->email);
    printf("Type-%s\n", per_root->type);
    printf("\n");
}

// function to print professional contact data
void print_pro(professional *pro_root)
{
    printf("\n");
    printf("First Name-%s\n", pro_root->firstname);
    printf("Last Name-%s\n", pro_root->lastname);
    printf("Phone Number-%lu\n", pro_root->number);
    printf("email id-%s\n", pro_root->email);
    printf("Office no.-%s\n", pro_root->officeNo);

    printf("Address-");
    puts(pro_root->address);

    printf("Office/Institute-");
    puts(pro_root->office);
    printf("Type-%s\n", pro_root->type);
    printf("\n");
}

// A utility function to print inorder traversal of the personal tree.(ascending)
void inorder_per(personal *per_root)
{
    if (per_root != NULL)
    {
        inorder_per(per_root->left);
        print_per(per_root);
        inorder_per(per_root->right);
    }
}

// Searches personal conatct via name in personal tree
int search_name_per(personal *per_root, char *f, char *l)
{

    while (per_root != NULL)
    {
        if (strcasecmp(f, per_root->firstname) == 0 && strcasecmp(l, per_root->lastname) == 0)
        {
            print_per(per_root);
            return 1;
        }
        else if (strcasecmp(f, per_root->firstname) < 0 || strcasecmp(f, per_root->firstname) == 0 && strcasecmp(l, per_root->lastname) < 0)
        {
            per_root = per_root->left;
        }
        else
        {
            per_root = per_root->right;
        }
    }
    return -1;
}

// Searches personal conatct via phone number in personal tree
int search_phone_per(personal *per_root, uint64_t phn)
{

    while (per_root != NULL)
    {
        if (phn == per_root->number)
        {
            print_per(per_root);
            return 1;
        }
        else if (phn < per_root->number)
        {
            per_root = per_root->left;
        }
        else
        {
            per_root = per_root->right;
        }
    }
    return -1;
}

// Searches professional conatct via name in professional tree
int search_name_pro(professional *pro_root, char *f, char *l)
{

    while (pro_root != NULL)
    {
        if (strcasecmp(f, pro_root->firstname) == 0 && strcasecmp(l, pro_root->lastname) == 0)
        {
            print_pro(pro_root);
            return 1;
        }
        else if (strcasecmp(f, pro_root->firstname) < 0 || strcasecmp(f, pro_root->firstname) == 0 && strcasecmp(l, pro_root->lastname) < 0)
        {
            pro_root = pro_root->left;
        }
        else
        {
            pro_root = pro_root->right;
        }
    }
    return -1;
}

// Searches professional conatct via phone number in professional tree
int search_phone_pro(professional *pro_root, uint64_t phn)
{

    while (pro_root != NULL)
    {
        if (phn == pro_root->number)
        {
            print_pro(pro_root);
            return 1;
        }
        else if (phn < pro_root->number)
        {
            pro_root = pro_root->left;
        }
        else
        {
            pro_root = pro_root->right;
        }
    }
    return -1;
}

// reverse of inorder traversal for Personal tree (descending order)
void inorder_rev_per(personal *per_root)
{
    if (per_root != NULL)
    {
        inorder_rev_per(per_root->right);
        print_per(per_root);
        inorder_rev_per(per_root->left);
    }
}

// inserting professional contact considering phone number as the key
// Recursive function to insert data in the subtree rooted with pro_root and returns the new root of the subtree.
professional *insert_pro(professional *pro_root, char *fn, char *ln, uint64_t phn, char *email, char *ofno, char *add, char *of, char *type)
{
    if (pro_root == NULL)
    {
        pro_root = get_pro_node();

        strcpy(pro_root->firstname, fn);
        strcpy(pro_root->lastname, ln);
        strcpy(pro_root->email, email);
        strcpy(pro_root->type, type);
        strcpy(pro_root->officeNo, ofno);
        strcpy(pro_root->office, of);
        strcpy(pro_root->address, add);
        pro_root->number = phn;

        pro_root->left = pro_root->right = NULL;
    }
    else if (phn > pro_root->number)
    {
        pro_root->right = insert_pro(pro_root->right, fn, ln, phn, email, ofno, add, of, type);

        if (BF_pro(pro_root) == -2)
            if (phn > pro_root->right->number)
                pro_root = RR_pro(pro_root);
            else
                pro_root = RL_pro(pro_root);
    }
    else if (phn < pro_root->number)
    {
        pro_root->left = insert_pro(pro_root->left, fn, ln, phn, email, ofno, add, of, type);

        if (BF_pro(pro_root) == 2)
            if (phn < pro_root->left->number)
                pro_root = LL_pro(pro_root);
            else
                pro_root = LR_pro(pro_root);
    }

    // Update height of this ancestor node
    pro_root->ht = height_pro(pro_root);
    return pro_root;
}

// function to get the height of the professional contact tree
int height_pro(professional *pro_root)
{
    int lh, rh;
    if (pro_root == NULL)
        return (0);
    if (pro_root->left == NULL)
        lh = 0;
    else
        lh = 1 + pro_root->left->ht;
    if (pro_root->right == NULL)
        rh = 0;
    else
        rh = 1 + pro_root->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}

// A utility function to right rotate subtree rooted with pro_root
professional *rotateright_pro(professional *pro_root)
{
    professional *y=pro_root->left;
    professional *temp=y->right;
    // perform rotation
    y->right = pro_root;
    pro_root->left = temp;

    // update heights
    pro_root->ht = height_pro(pro_root);
    y->ht = height_pro(y);

    // return new root
    return (y);
}

// A utility function to left rotate subtree rooted with pro_root
professional *rotateleft_pro(professional *pro_root)
{
    professional *y=pro_root->right;
    professional *temp=y->left;
    // perform rotation
    y->left = pro_root;
    pro_root->right=temp;

    // update heights
    pro_root->ht = height_pro(pro_root);
    y->ht = height_pro(y);

    // return new root
    return (y);
}

// Right Right case (professional)
professional *RR_pro(professional *pro_root)
{
    pro_root = rotateleft_pro(pro_root);
    return (pro_root);
}

// Left Left case (professional)
professional *LL_pro(professional *pro_root)
{
    pro_root = rotateright_pro(pro_root);
    return (pro_root);
}

// Left Right case (professional)
professional *LR_pro(professional *pro_root)
{
    pro_root->left = rotateleft_pro(pro_root->left);
    pro_root = rotateright_pro(pro_root);
    return (pro_root);
}

// Right Left case (professional)
professional *RL_pro(professional *pro_root)
{
    pro_root->right = rotateright_pro(pro_root->right);
    pro_root = rotateleft_pro(pro_root);
    return (pro_root);
}

// Get Balance factor of node pro_root
int BF_pro(professional *pro_root)
{
    int lh, rh;
    if (pro_root == NULL)
        return (0);

    if (pro_root->left == NULL)
        lh = 0;
    else
        lh = 1 + pro_root->left->ht;

    if (pro_root->right == NULL)
        rh = 0;
    else
        rh = 1 + pro_root->right->ht;

    return (lh - rh);
}

void range_search_per(personal *per_root, uint64_t low, uint64_t high)
{
    if (per_root == NULL)
        return;
    if (per_root->number >= low && per_root->number <= high)
        print_per(per_root);
    range_search_per(per_root->left, low, high);
    range_search_per(per_root->right, low, high);
}

void range_search_pro(professional *pro_root, uint64_t low, uint64_t high)
{
    if (pro_root == NULL)
        return;
    if (pro_root->number >= low && pro_root->number <= high)
        print_pro(pro_root);
        
    range_search_pro(pro_root->left, low, high);
    range_search_pro(pro_root->right, low, high);
}

personal *minValueNode_per(personal *per_root)
{
    personal *current = per_root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to delete personal contact as a whole for the phone number given by the user
personal *delete_per(personal *per_root, uint64_t number)
{
    // STEP 1: PERFORM STANDARD BST DELETE
    if (per_root == NULL)
        return per_root;

    // If the number to be deleted is smaller than the per_root's number, then it lies in left subtree
    if (number < per_root->number)
        per_root->left = delete_per(per_root->left, number);

    // If the number to be deleted is greater than the per_root's number, then it lies in right subtree
    else if (number > per_root->number)
        per_root->right = delete_per(per_root->right, number);

    // if number is same as per_root's number, then This is the node to be deleted
    else
    {
        // node with only one child or no child
        if ((per_root->left == NULL) || (per_root->right == NULL))
        {
            personal *temp = per_root->left ? per_root->left : per_root->right;

            // No child case
            if (temp == NULL)
            {
                temp = per_root;
                per_root = NULL;
            }
            else                   // One child case
                *per_root = *temp; // Copy the contents of the non-empty child
            printf("Contact deleted.\n");
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            personal *temp = minValueNode_per(per_root->right);

            // Copy the inorder successor's data to this node
            per_root->number = temp->number;

            // Delete the inorder successor
            per_root->right = delete_per(per_root->right, temp->number);
        }
    }

    // If the tree had only one node then return
    if (per_root == NULL)
        return per_root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    per_root->ht = 1 + max(height_per(per_root->left), height_per(per_root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = BF_per(per_root);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && BF_per(per_root->left) >= 0)
        return LL_per(per_root);

    // Left Right Case
    if (balance > 1 && BF_per(per_root->left) < 0)
    {
        return LR_per(per_root);
    }
    // Right Right Case
    if (balance < -1 && BF_per(per_root->right) <= 0)
        return RR_per(per_root);

    // Right Left Case
    if (balance < -1 && BF_per(per_root->right) > 0)
    {
        return RL_per(per_root);
    }
    return per_root;
}

professional *minValueNode_pro(professional *pro_root)
{
    professional *current = pro_root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete professional contact as a whole for the phone number given by the user
professional *delete_pro(professional *pro_root, uint64_t number)
{
    // STEP 1: PERFORM STANDARD BST DELETE
    if (pro_root == NULL)
        return pro_root;

    // If the number to be deleted is smaller than the pro_root's number, then it lies in left subtree
    if (number < pro_root->number)
        pro_root->left = delete_pro(pro_root->left, number);

    // If the number to be deleted is greater than the pro_root's number, then it lies in right subtree
    else if (number > pro_root->number)
        pro_root->right = delete_pro(pro_root->right, number);

    // if number is same as pro_root's number, then This is the node to be deleted
    else
    {
        // node with only one child or no child
        if ((pro_root->left == NULL) || (pro_root->right == NULL))
        {
            professional *temp = pro_root->left ? pro_root->left : pro_root->right;

            // No child case
            if (temp == NULL)
            {
                temp = pro_root;
                pro_root = NULL;
            }
            else                   // One child case
                *pro_root = *temp; // Copy the contents of the non-empty child
            printf("Contact deleted.\n");
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            professional *temp = minValueNode_pro(pro_root->right);

            // Copy the inorder successor's data to this node
            pro_root->number = temp->number;

            // Delete the inorder successor
            pro_root->right = delete_pro(pro_root->right, temp->number);
        }
    }

    // If the tree had only one node then return
    if (pro_root == NULL)
        return pro_root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    pro_root->ht = 1 + max(height_pro(pro_root->left), height_pro(pro_root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
    int balance = BF_pro(pro_root);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && BF_pro(pro_root->left) >= 0)
        return LL_pro(pro_root);

    // Left Right Case
    if (balance > 1 && BF_pro(pro_root->left) < 0)
    {
        return LR_pro(pro_root);
    }
    // Right Right Case
    if (balance < -1 && BF_pro(pro_root->right) <= 0)
        return RR_pro(pro_root);

    // Right Left Case
    if (balance < -1 && BF_pro(pro_root->right) > 0)
    {
        return RL_pro(pro_root);
    }
    return pro_root;
}
// inorder traversal for professional tree (ascending order)
void inorder_pro(professional *pro_root)
{
    if (pro_root != NULL)
    {
        inorder_pro(pro_root->left);
        print_pro(pro_root);
        inorder_pro(pro_root->right);
    }
}

// reverse of inorder traversal for Professional tree (descending order)
void inorder_rev_pro(professional *pro_root)
{
    if (pro_root != NULL)
    {
        inorder_rev_pro(pro_root->right);
        print_pro(pro_root);
        inorder_rev_pro(pro_root->left);
    }
}

// An utility function to modify personal contact for the phone number provided by the user
int modify_per(personal *per_root, uint64_t phn)
{

    while (per_root != NULL)
    {
        if (phn == per_root->number)
        {
            int op;
            char f[20], l[20], email[30], type[20];
            printf("Fields that can be modified:\n1.Firstname\n2.Lastname\n3.email\n4.type\nEnter your choice :");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                printf("Enter new first name :");
                scanf("%s", f);
                strcpy(per_root->firstname, f);
                break;
            case 2:
                printf("Enter new last name :");
                scanf("%s", l);
                strcpy(per_root->lastname, l);
                break;
            case 3:
                printf("Enter new email :");
                scanf("%s", email);
                strcpy(per_root->email, email);
                break;
            case 4:
                printf("Enter new type :");
                scanf("%s", f);
                strcpy(per_root->type, type);
                break;
            default:
                printf("Invalid Option.\n");
                break;
            }
            return 1;
        }
        else if (phn < per_root->number)
        {
            per_root = per_root->left;
        }
        else
        {
            per_root = per_root->right;
        }
    }
    return -1;
}

// An utility function to modify professional contact for the phone number provided by the user
int modify_pro(professional *pro_root, uint64_t phn)
{

    while (pro_root != NULL)
    {
        if (phn == pro_root->number)
        {
            int op;
            char f[20], l[20], email[30], ofno[10], off[50], add[100], type[20];
            printf("Fields that can be modified:\n1.Firstname\n2.Lastname\n3.email\n4.Office no.\n5.Office/Institute\n6.Address\n7.type\nEnter your choice :");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                printf("Enter new first name :");
                scanf("%s", f);
                strcpy(pro_root->firstname, f);
                break;
            case 2:
                printf("Enter new last name :");
                scanf("%s", l);
                strcpy(pro_root->lastname, l);
                break;
            case 3:
                printf("Enter new email :");
                scanf("%s", email);
                strcpy(pro_root->email, email);
                break;
            case 4:
                printf("Enter new Office Number :");
                scanf("%s", ofno);
                strcpy(pro_root->officeNo, ofno);
                break;
            case 5:
                printf("Enter new Office/Institute Name:\n");
                fflush(stdin);
                gets(off);
                fflush(stdin);
                strcpy(pro_root->office, off);
                break;
            case 6:
                printf("Enter new Address:\n");
                fflush(stdin);
                gets(add);
                fflush(stdin);
                strcpy(pro_root->address, add);
                break;
            case 7:
                printf("Enter new type :");
                scanf("%s", f);
                strcpy(pro_root->type, type);
                break;
            default:
                printf("Invalid Option.\n");
                break;
            }
            return 1;
        }
        else if (phn < pro_root->number)
        {
            pro_root = pro_root->left;
        }
        else
        {
            pro_root = pro_root->right;
        }
    }
    return -1;
}

//An utility function to delete entire personal tree 
void delete_Tree_per(personal* node)
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    delete_Tree_per(node->left);
    delete_Tree_per(node->right);
   
    free(node);
}

//An utility function to delete entire professional tree 
void delete_Tree_pro(professional* node)
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    delete_Tree_pro(node->left);
    delete_Tree_pro(node->right);
   
    free(node);
}
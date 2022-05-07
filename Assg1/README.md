## Phonebook_LinkedList.c

A phonebook is implemented as 2 linked list of data structures for personal and professional contacts where each node is represented as first name, last name, mobile number and additional nodes like e-mail, office no., address, etc for every contact. Personal contact list has first name, last name, mobile number, email and type as it's nodes. Professional contact list has first name, last name, mobile number, email, office number, address,institute/office and type as it's nodes. The lists are sorted based on names. If names in two records are same, then such records are ordered based on mobile number (by considering its integer value).

**The following functions/operations are implemented for personal and professional linked lists:**

1. **Insert/create contact:**  
A new contact is inserted in the list. Made sure that there is no restriction for the contact with same name.  
i/p: all the field related to insertion on a new contact  is inserted  
o/p: A message showing that contact is created

2. **Edit**:  
Edit option is provided to modify the details.  
i/p: all the fields that can be modified  
o/p: message showing that contact is modified

3. **Delete:**  
Contact is deleted as a whole  
i/p: field to search for contact that is to be deleted  
o/p: message showing contact is deleted

4. **Search:**  
provided searching contact via name, mobile number and any other if you like  
i/p: provide options to search using name and mobile no.  
o/p: contact searched

5. **Sort:**  
Sorting in ascending /descending, professional/personal  
i/p: Given unsorted list of records, provide the options for sorting i.e. using
switch cases like ascending, descending.  
o/p: sorted list according to the choice of user

6. **Display all:**  
Display personal list: only personal contacts to be displayed  
Display professional list: only professional contacts to be displayed  
i/p: option asking to show contacts  
o/p: list as per option selected

7. **Remove duplicates:**  
i/p: enter the list of records sorted based on name/mobile-number  
o/p: linked list without duplicates  

In the end both the Personal and Professional Contact lists are deleted.

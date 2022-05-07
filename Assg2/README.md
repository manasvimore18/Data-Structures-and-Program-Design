## Phonebook_AVL.c

A phonebook is implemented as two AVL trees for Personal annd Professional contacts each where each node is represented as first name, last name and mobile number and additional nodes like e-mail, office no., address, etc for every contact. Personal contact list has first name, last name, mobile number, email, type as it's nodes and professional contact list has first name, last name, mobile number, email, office number, address,institute/office and type as it's nodes. Mobile number (considered as integer) is considered as key of the record.

**The following functions/operations are implemented for both personal and professional AVL tree:**

1. **Insert/create contact:**  
A new contact is inserted in the database. There is no restriction for the contact with same name.  
i/p: all the field related to insertion on a new contact  
o/p: A message showing that contact is created

2. **Edit:**  
Edit option is provided to modify the details.  
i/p: all the fields that can be modified  
o/p: message showing that contact is modified

3. **Delete:**  
Contact is deleted as a whole  
i/p: field to search for contact that is to be deleted  
o/p: message showing contact is deleted

4. **Search:**  
Provided searching contact via name and mobile number
i/p: provided options to search using name and mobile no.  
o/p: contact searched

5. **Sort:**  
Sorted in ascending /descending, professional/personal  
i/p: Given the database implemented using trees, provided the options for displaying after sorting in a particular manner i.e. using switch cases like ascending, descending.  
o/p: sorted list according to the choice of user

6. **Display all:**  
Display personal list: only personal contacts to be displayed  
Display professional list: only professional contacts to be displayed  
i/p: option asking to show contacts  
o/p: list as per option selected

7. **Range Search**:  
Given two mobile numbers, From-Mobile-Number and To-Mobile-Number, displayed the set of records having mobile number (as integer) between the range of From-Mobile-Numbe upto To-Mobile-Number (both inclusive)

8. Sorted the records in the phone database (i.e. tree) based on first-name. If first-name is same for multiple people, then the records are sorted based on mobile number.  

In the end both the AVL trees created for personal and professional contacts are deleted.

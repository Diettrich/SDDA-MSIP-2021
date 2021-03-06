//
//  contact.h
//  SDDA-MSIP
//
//  Created by Zougrar Anouar on 3/5/21.
//  Copyright © 2021 Zougrar Anouar. All rights reserved.
//

#ifndef contact_h
#define contact_h

struct contact
{
    char caractere;
    char telephone[14];
    int isEmpty;
    struct contact *fils;
    struct contact *frere;
    struct contact *pere;
};

typedef struct contact *contact;

int create_contact_node(contact, char, char[]);
int create_empty_node(contact, char);
int search_node_by_name(contact, contact*, char[]);
int search_node(contact, contact*, char);
int add_node(contact, contact*, char);
int create_new_contact(contact, char[], char[]);
void show_sorted_tree(contact, contact);
void print_name(contact, contact);
int name_len(contact, contact);
int delete_contact(contact, char[]);


#endif /* contact_h */

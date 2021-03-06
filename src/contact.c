//
//  contact.c
//  SDDA-MSIP
//
//  Created by Zougrar Anouar on 3/5/21.
//  Copyright © 2021 Zougrar Anouar. All rights reserved.
//

#include "../header/contact.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int create_contact_node(contact current, char caractere, char telephone[])
{
    current->caractere = caractere;
    current->isEmpty = 0;
    memcpy(current->telephone, telephone, strlen(telephone) + 1);
    current->fils = NULL;
    current->frere = NULL;

    return 1;
}

int create_empty_node(contact current, char caractere)
{
    current->caractere = caractere;
    // strcpy(current->telephone, telephone);
    current->isEmpty = 1;
    current->fils = NULL;
    current->frere = NULL;

    return 1;
}

int search_node_by_name(contact head, contact *result, char name[]) // hada khasni ntestih mzl ma9estochay
{
    contact temp = head->fils;
    int len = (int)strlen(name);
    int i = 0;

    do
    {
        if (name[i] == temp->caractere)
        {
            if (i == len - 1)
            {
                *result = temp;
                return 1;
            }
            if (temp->fils == NULL)
            {
                return 0;
            }
            temp = temp->fils;
            i++;
        }
        else
        {
            if (temp->frere == NULL)
            {
                return 0;
            }
            temp = temp->frere;
        }
    } while (i < len);

    return 1;
}

int search_node(contact head, contact* result, char character)
{
    if (head->fils == NULL) {
        *result = NULL;
        return 0;
    }
    contact temp = head->fils;
    if (temp->caractere == character) {
        *result = temp;
        return 1;
    }
    while (temp->frere != NULL) {
        temp = temp->frere;
        if (temp->caractere == character) {
            *result = temp;
            return 1;
        }
    }
    *result = NULL;
    return 0;
}

int add_node(contact head, contact* result, char charactere)
{
    if (head->fils == NULL) {
        contact new_space = (contact)malloc(sizeof(contact));
        create_empty_node(new_space, charactere);
        head->fils = new_space;
        new_space->pere = head;
        *result = new_space;
        return 1;
    }
    contact temp = head->fils;
    
    if (temp->caractere >= charactere) {
        contact new_space = (contact)malloc(sizeof(contact));
        create_empty_node(new_space, charactere);
        head->fils = new_space;
        new_space->pere = head;
        new_space->frere = temp;
        *result = new_space;
        return 1;
    }
    
    while (temp->frere != NULL && temp->frere->caractere < charactere)
    {
        temp = temp->frere;
    }
    contact new_space = (contact)malloc(sizeof(contact));
    create_empty_node(new_space, charactere);
    new_space->frere = temp->frere;
    new_space->pere = head;
    temp->frere = new_space;
    *result = new_space;
    return 1;
}

int create_new_contact(contact head, char name[], char telephone[])
{
    contact temp = head;
    contact* temp_ptr = &head;
    int new_name = 0;
    int len = (int)strlen(name);
    
    for (int i = 0; i < len; i++)
    {
        if (!new_name && search_node(temp, temp_ptr, name[i])) {
            temp = *temp_ptr;
            if (temp->fils == NULL && i == len && temp->isEmpty == 0) {
                return 3; // 3 means contact already exist
            } else if (temp->fils == NULL && i == len && temp->isEmpty == 1) {
                temp->isEmpty = 0;
                strcpy(temp->telephone, telephone);
                return 2; // 2 means something wrong i can feel it
            } else if (temp->fils != NULL && i == len) {
                temp->isEmpty = 0;
                strcpy(temp->telephone, telephone);
                return 1;
            }
        } else {
            new_name = 1;
            if (i == len - 1) {
                add_node(temp, temp_ptr, name[i]);
                temp = *temp_ptr;
                create_contact_node(temp, name[i], telephone);
            } else {
                add_node(temp, temp_ptr, name[i]);
                temp = *temp_ptr;
            }
        }
    }
    return 1;
 }

void print_name(contact node, contact root)
{
    if (node == root) {
        return;
    }
    print_name(node->pere, root);
    printf("%c", node->caractere);
}

int name_len(contact node, contact root)
{
    int res = 0;
    while(node != root)
    {
        res++;
        node = node->pere;
    }
    return res;
}

void show_sorted_tree(contact head, contact root)
{
    if (head != NULL)
    {
        if (!head->isEmpty) {
            print_name(head, root);
            int space = name_len(head, root);
            printf("%*c", 25 - space, ' ');
            printf("%s\n", head->telephone);
        }
        show_sorted_tree(head->fils, root);
        show_sorted_tree(head->frere, root);
    }
}

int delete_contact(contact root, char name[])
{
    contact temp;
    contact* temp_ptr;
    temp_ptr = &temp;
    
    if (search_node_by_name(root, temp_ptr, name)) {
        (*temp_ptr)->isEmpty = 1;
        strcpy((*temp_ptr)->telephone, "");
        puts("contact suprimé");
        return 1;
    } else {
        puts("contact introuvable");
        return 0;
    }
}
















    
//    contact temp = head;
//    const int len = (int)strlen(name);
//
//    for (int i = 0; i < len; i++)
//    {
//        char current_char = name[i];
//
//        if (current_char == temp->caractere)
//        {
//            temp = temp->fils;
//            continue;
//        }
//
//        while (current_char < temp->caractere)
//        {
//            if (temp->frere == NULL) // si le noeud n'a pas de frere
//            {
//                contact new_space = (contact)malloc(sizeof(contact));
//                temp->frere = new_space;
//                create_empty_node(new_space, current_char);
//            }
//            temp = temp->frere;
//            if (current_char == temp->caractere)
//            {
//                /* code */
//            }
//        }
//    }
//    return 1;

